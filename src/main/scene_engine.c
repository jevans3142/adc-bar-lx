// Scene engine module
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"


#include "scene_engine.h"
#include "storage.h"

SemaphoreHandle_t Scene_No_Mutex = NULL;
// protects:
uint8_t Scene_No = 1; //NB: This variable is 1 indexed
uint8_t Scene_State = SCENE_STATE_STATIC;
float fade_proportion = 0;
unsigned long current_fade_timeout = 0;

SemaphoreHandle_t Scene_Engine_Settings_Mutex = NULL;
// protects:
struct Scene_Engine_Settings_Struct Scene_Engine_Settings;

SemaphoreHandle_t DMX_Buffer_Mutex = NULL;
// protects:
uint8_t last_fade_state[513] = {}; //TODO: remove magic number 
uint8_t current_state[513] = {};
uint8_t dmx_in_buffer[513] = {};
uint8_t scenes[NUMBER_OF_SCENES][513] = {};

static const char *TAG = "screen_engine";

static unsigned long IRAM_ATTR millis()
{
    return (unsigned long) (esp_timer_get_time() / 1000ULL);
}

//Overwrites values in first buffer with value from the second if higher
static void htp_513(uint8_t* first, uint8_t* second)
{
    for(int i=0; i<513;i++) //TODO: remove magic number 
    {
        if (*first<*second) 
        { 
            *first = *second;
        }
        first++;
        second++;
    }
}

//Copies values from one buffer to another
static void copy_513(uint8_t* source, uint8_t* dest)
{
    for(int i=0; i<513;i++)
    {
        *dest=*source;
        source++;
        dest++;
    }
}

//Performs a proportional mix of values from one buffer to another
static void proportion_513(uint8_t* first, uint8_t* second, uint8_t* output, float progress)
{
    for(int i=0; i<513;i++)
    {
        *output = (uint8_t)((*first)*(progress)+(*second)*(1-progress));
        first++;
        second++;
        output++;
    }
}

void setup_scene_engine(void)
{
    //Create mutexes 
    Scene_No_Mutex = xSemaphoreCreateMutex();
    Scene_Engine_Settings_Mutex = xSemaphoreCreateMutex();
    DMX_Buffer_Mutex = xSemaphoreCreateMutex();

    //Set up GPIO for remote panel LEDs and buttons
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = PIN_SCENE_LEDS_MASK;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);
    
    //Set initial remote panel LEDs
    gpio_set_level(PIN_SCENE_LEDS_BIT_1, 1);
    gpio_set_level(PIN_SCENE_LEDS_BIT_2, 0);
    gpio_set_level(PIN_SCENE_LEDS_BIT_4, 0);

    //Set up ADCs for sound to light
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_4,ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_7,ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_3,ADC_ATTEN_DB_11);

    if( Scene_Engine_Settings_Mutex != NULL )
    {
        if( xSemaphoreTake( Scene_Engine_Settings_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            Scene_Engine_Settings = read_settings();
            xSemaphoreGive( Scene_Engine_Settings_Mutex );
        }
    }
    
    //Read in scenes from SD card
    if( DMX_Buffer_Mutex != NULL )
    {
        if( xSemaphoreTake( DMX_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            for (int i=0;i<NUMBER_OF_SCENES;i++)
            {
                read_scene(i+1,scenes[i]);
            }

            xSemaphoreGive( DMX_Buffer_Mutex );
        }
    }
}

void set_scene(int new_scene_no)
{
    //Sanity bounds check
    if (new_scene_no>NUMBER_OF_SCENES || new_scene_no<1)
    {
        new_scene_no = 1;
    }
    if( (Scene_No_Mutex != NULL) && (DMX_Buffer_Mutex != NULL) )
    {
        if( (xSemaphoreTake( Scene_No_Mutex, ( TickType_t ) 10 ) == pdTRUE) && (xSemaphoreTake( DMX_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE) )
        {
            if (Scene_No != new_scene_no)
            {
                Scene_No = new_scene_no;
                current_fade_timeout = millis() + ((unsigned long) get_scene_engine_settings().fade_time)*1000ULL;
                Scene_State = SCENE_STATE_FADING;
                xSemaphoreGive( Scene_No_Mutex );
                copy_513(current_state, last_fade_state);
                xSemaphoreGive( DMX_Buffer_Mutex );
                gpio_set_level(PIN_SCENE_LEDS_BIT_1, (new_scene_no & 1));
                gpio_set_level(PIN_SCENE_LEDS_BIT_2, (new_scene_no & 2));
                gpio_set_level(PIN_SCENE_LEDS_BIT_4, (new_scene_no & 4));
            }
            else
            {
                xSemaphoreGive( Scene_No_Mutex );
                xSemaphoreGive( DMX_Buffer_Mutex );
            }
        }
    }
}

int get_scene(void)
{
    if( Scene_No_Mutex != NULL )
    {
        if( xSemaphoreTake( Scene_No_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            int returnval = Scene_No;
            xSemaphoreGive( Scene_No_Mutex );
            return returnval;
        }
    }
    ESP_LOGW(TAG,"Get scene getter func fail");
    return NULL;
}

void set_scene_engine_settings(struct Scene_Engine_Settings_Struct new_Scene_Engine_Settings)
{
    if( Scene_Engine_Settings_Mutex != NULL )
    {
        if( xSemaphoreTake( Scene_Engine_Settings_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            Scene_Engine_Settings = new_Scene_Engine_Settings;
            xSemaphoreGive( Scene_Engine_Settings_Mutex );
            write_settings(new_Scene_Engine_Settings);
        }
    }
}

struct Scene_Engine_Settings_Struct get_scene_engine_settings(void)
{
    if( Scene_Engine_Settings_Mutex != NULL )
    {
        if( xSemaphoreTake( Scene_Engine_Settings_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            struct Scene_Engine_Settings_Struct returnval = Scene_Engine_Settings;
            xSemaphoreGive( Scene_Engine_Settings_Mutex );
            return returnval;
        }
    }
    struct Scene_Engine_Settings_Struct null_s = {};
    return null_s;
}

void scene_calc_task(uint8_t* output)
{   
    int rawval = 0;
    uint8_t temp_scene_no;

    temp_scene_no = get_scene();

    struct Scene_Engine_Settings_Struct Scene_Engine_Settings_temp;

    if (DMX_Buffer_Mutex != NULL)
    {
        if (xSemaphoreTake( DMX_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE)
        {
            // Read a copy of the current scene settings
            Scene_Engine_Settings_temp = get_scene_engine_settings();

            if (Scene_State == SCENE_STATE_FADING)
            {
                // We're currently fading between scenes
                if (((long)millis()-(long)current_fade_timeout) >= 0) 
                {
                    // Time to end the fade
                    Scene_State = SCENE_STATE_STATIC; 
                }
                else
                {
                    // Then we're still in the middle of the fade
                    fade_proportion = ((float)(current_fade_timeout-millis()))/((float)(1000*Scene_Engine_Settings_temp.fade_time));
                    proportion_513(last_fade_state, scenes[temp_scene_no-1], current_state, fade_proportion);
                }
            }
            if (Scene_State == SCENE_STATE_STATIC)
            {
                // We're sitting in a static scene, not fading
                copy_513(scenes[get_scene()-1],current_state);
            }

            if (Scene_Engine_Settings_temp.dmx_input_mode == DMX_MODE_HTP)
            {
                // DMX input is currently in HTP mode
                htp_513(current_state,dmx_in_buffer);
            }

            //TODO: Make this work with fading?
            if((Scene_Engine_Settings_temp.s2l_enable[temp_scene_no-1]==pdTRUE) && (Scene_Engine_Settings_temp.s2l_mode == S2L_MODE_PULSE))
            {
                // Sound to light is active on this scene
                rawval = adc1_get_raw(ADC1_CHANNEL_3);
                if (current_state[Scene_Engine_Settings_temp.sel_low_ch]<rawval) 
                { 
                    current_state[Scene_Engine_Settings_temp.sel_low_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
                }

                rawval = adc1_get_raw(ADC1_CHANNEL_6);
                if (current_state[Scene_Engine_Settings_temp.sel_midlow_ch]<rawval) 
                { 
                    current_state[Scene_Engine_Settings_temp.sel_midlow_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
                }

                rawval = adc1_get_raw(ADC1_CHANNEL_7);
                if (current_state[Scene_Engine_Settings_temp.sel_midhigh_ch]<rawval) 
                { 
                    current_state[Scene_Engine_Settings_temp.sel_midhigh_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
                }

                rawval = adc1_get_raw(ADC1_CHANNEL_4);
                if (current_state[Scene_Engine_Settings_temp.sel_high_ch]<rawval) 
                { 
                    current_state[Scene_Engine_Settings_temp.sel_high_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
                }
            }
            current_state[0]=0x00; // Force the DMX start code to be 0x00 for 'dimmer data'
            copy_513(current_state,output);
            xSemaphoreGive( DMX_Buffer_Mutex );
        }
    }
}

void record_scene(uint8_t scene)
{
    //TODO: Should this not work if DMX input is not live?
    if( DMX_Buffer_Mutex != NULL )
    {
        if( xSemaphoreTake( DMX_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            copy_513(dmx_in_buffer,scenes[scene-1]);
            write_scene(scene,dmx_in_buffer);
            xSemaphoreGive( DMX_Buffer_Mutex );
        }
    }
}

void store_dmx_input_value(uint16_t address, uint8_t value)
{
    if( DMX_Buffer_Mutex != NULL )
    {
        if( xSemaphoreTake( DMX_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            dmx_in_buffer[address] = value;
            xSemaphoreGive( DMX_Buffer_Mutex );
        }
    }
}