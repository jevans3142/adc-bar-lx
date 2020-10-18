// Scene engine module
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "scene_engine.h"
#include "storage.h"

SemaphoreHandle_t Scene_No_Mutex = NULL;
SemaphoreHandle_t Scene_Engine_Settings_Mutex = NULL;
SemaphoreHandle_t DMX_Input_Buffer_Mutex = NULL;

uint8_t Scene_No = 1; //NB: This variable is 1 indexed
uint8_t Scene_State = SCENE_STATE_STATIC;
uint8_t last_fade_state[513] = {}; //TODO: remove magic number 
uint8_t current_state[513] = {};
uint8_t dmx_in_buffer[513] = {};
uint8_t scenes[NUMBER_OF_SCENES][513] = {};
float fade_proportion = 0;
unsigned long current_fade_timeout = 0;
int rawval = 0;

struct Scene_Engine_Settings_Struct Scene_Engine_Settings;
struct Scene_Engine_Settings_Struct Scene_Engine_Settings_temp;

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
    DMX_Input_Buffer_Mutex = xSemaphoreCreateMutex();

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

    //Temp code ==========
    Scene_Engine_Settings_temp.fade_time = 5;
    Scene_Engine_Settings_temp.dmx_input_mode = DMX_MODE_OFF;
    Scene_Engine_Settings_temp.s2l_enable[3] = pdTRUE;
    Scene_Engine_Settings_temp.s2l_mode = S2L_MODE_PULSE; 
    Scene_Engine_Settings_temp.sel_low_ch = 2;
    Scene_Engine_Settings_temp.sel_midlow_ch = 3;
    Scene_Engine_Settings_temp.sel_midhigh_ch = 4;
    Scene_Engine_Settings_temp.sel_high_ch = 5;
    //=====================

    set_scene_engine_settings(Scene_Engine_Settings_temp);

    //TODO: Read in settings from SD card
    
    //Read in scenes from SD card
    for (int i=0;i<NUMBER_OF_SCENES;i++)
    {
        read_scene(i+1,scenes[i]);
    }
}

void set_scene(int new_scene_no)
{
    //Sanity bounds check
    if (new_scene_no>NUMBER_OF_SCENES || new_scene_no<1)
    {
        new_scene_no = 1;
    }
    if( Scene_No_Mutex != NULL )
    {
        if( xSemaphoreTake( Scene_No_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            if (Scene_No != new_scene_no)
            {
                Scene_No = new_scene_no;
                xSemaphoreGive( Scene_No_Mutex );
                current_fade_timeout = millis() + ((unsigned long) get_scene_engine_settings().fade_time)*1000ULL;
                copy_513(current_state, last_fade_state);
                Scene_State = SCENE_STATE_FADING;
                gpio_set_level(PIN_SCENE_LEDS_BIT_1, (new_scene_no & 1));
                gpio_set_level(PIN_SCENE_LEDS_BIT_2, (new_scene_no & 2));
                gpio_set_level(PIN_SCENE_LEDS_BIT_4, (new_scene_no & 4));
            }
            else
            {
                xSemaphoreGive( Scene_No_Mutex );
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
    // Read a copy of the current scene settings
    Scene_Engine_Settings_temp = get_scene_engine_settings();

    //TODO: Should we take Scene_No Mutex here to lock any attempt to change scene while doing this?
    if (Scene_State == SCENE_STATE_FADING)
    {
        if (((long)millis()-(long)current_fade_timeout) >= 0) 
        {
            //Time to end the fade
            Scene_State = SCENE_STATE_STATIC; 
        }
        else
        {
            //Then we're still in the middle of the fade
            fade_proportion = ((float)(current_fade_timeout-millis()))/((float)(1000*Scene_Engine_Settings_temp.fade_time));
            proportion_513(last_fade_state, scenes[get_scene()-1], current_state, fade_proportion);
        }
    }
    if (Scene_State == SCENE_STATE_STATIC)
    {
        //Static
        copy_513(scenes[get_scene()-1],current_state);
    }

    if (true) //If DMX Input active
    {
        htp_513(current_state,dmx_in_buffer);
    }

    //TODO: Make this work with fading?
    if((Scene_Engine_Settings_temp.s2l_enable[get_scene()-1]==pdTRUE) && (Scene_Engine_Settings_temp.s2l_mode == S2L_MODE_PULSE)) //If Sound to light active on this scene
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

    current_state[0]=0x00; // DMX start code must be 0x00 for 'dimmer data'
    copy_513(current_state,output);
}

void record_scene(uint8_t scene)
{
    //TODO: Take mutexs for scene no and scene data and dmx data
    //TODO: Should this not work if DMX input is not live?
    copy_513(dmx_in_buffer,scenes[scene-1]);
    write_scene(scene,dmx_in_buffer);
}

void store_dmx_input_value(uint16_t address, uint8_t value)
{
    //TODO; make threadsafe 
    //xSemaphoreTake(DMX_Input_Buffer_Mutex, ( TickType_t ) 10 );
    dmx_in_buffer[address] = value;
}