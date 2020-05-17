// Scene engine module
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "scene_engine.h"

SemaphoreHandle_t Scene_No_Mutex = NULL;
SemaphoreHandle_t Scene_Engine_Settings_Mutex = NULL;
int Scene_No = 1; //NB: This variable is 1 indexed
int Scene_State = SCENE_STATE_STATIC;
uint8_t last_fade_state[513] = {};
uint8_t current_state[513] = {};
uint8_t scenes[NUMBER_OF_SCENES][513] = {};
int fade_time = 5; //TODO: not this as default
float fade_proportion = 0;
unsigned long current_fade_timeout = 0;
int rawval = 0;

struct Scene_Engine_Settings_Struct Scene_Engine_Settings;

static unsigned long IRAM_ATTR millis()
{
    return (unsigned long) (esp_timer_get_time() / 1000ULL);
}

static void htp_513(uint8_t* first, uint8_t* second)
{
    for(int i=0; i<513;i++)
    {
        if (*first<*second) 
        { 
            *first = *second;
        }
        first++;
        second++;
    }
}

static void copy_513(uint8_t* source, uint8_t* dest)
{
    for(int i=0; i<513;i++)
    {
        *dest=*source;
        source++;
        dest++;
    }
}

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

void setup_scene_mutexs(void)
{
    Scene_No_Mutex = xSemaphoreCreateMutex();
    Scene_Engine_Settings_Mutex = xSemaphoreCreateMutex();

    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = PIN_SCENE_LEDS_MASK;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);

    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_4,ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_7,ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_11);
    adc1_config_channel_atten(ADC1_CHANNEL_3,ADC_ATTEN_DB_11);

    gpio_set_level(PIN_SCENE_LEDS_BIT_1, 1);
    gpio_set_level(PIN_SCENE_LEDS_BIT_2, 0);
    gpio_set_level(PIN_SCENE_LEDS_BIT_4, 0);

    Scene_Engine_Settings.s2l_enable[3] = pdTRUE;
    Scene_Engine_Settings.s2l_mode = S2L_MODE_PULSE; //TODO - remove
    Scene_Engine_Settings.sel_low_ch = 2; //TODO - remove these pretend numbers
    Scene_Engine_Settings.sel_midlow_ch = 3;
    Scene_Engine_Settings.sel_midhigh_ch = 4;
    Scene_Engine_Settings.sel_high_ch = 5;


    //TODO: Setup fade time
    
    //TEST CODE==============
    for (int j=0;j<NUMBER_OF_SCENES;j++)
    {
        for (int i=0;i<513;i++)
        {
            scenes[j][i]=0x00;
        }
    }
    scenes[0][1]=0xFF;
    scenes[0][2]=0xFF;

    scenes[1][1]=0xFF;
    scenes[1][3]=0xFF;

    scenes[2][1]=0xFF;
    scenes[2][4]=0xFF;

    scenes[3][1]=0xFF;
    Scene_Engine_Settings.s2l_enable[3] = pdTRUE;  
    //=======================  
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
                current_fade_timeout = millis() + ((unsigned long) fade_time)*1000ULL;
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

// void set_scene_engine_settings(struct Scene_Engine_Settings_Struct new_Scene_Engine_Settings)
// {
//     if( Scene_Engine_Settings_Mutex != NULL )
//     {
//         if( xSemaphoreTake( Scene_Engine_Settings_Mutex, ( TickType_t ) 10 ) == pdTRUE )
//         {
//             Scene_Engine_Settings = new_Scene_Engine_Settings;
//             xSemaphoreGive( Scene_Engine_Settings_Mutex );
//         }
//     }
// }

// struct Scene_Engine_Settings_Struct get_scene_engine_settings(void)
// {
//     if( Scene_Engine_Settings_Mutex != NULL )
//     {
//         if( xSemaphoreTake( Scene_Engine_Settings_Mutex, ( TickType_t ) 10 ) == pdTRUE )
//         {
//             struct Scene_Engine_Settings_Struct returnval = Scene_Engine_Settings;
//             xSemaphoreGive( Scene_Engine_Settings_Mutex );
//             return returnval;
//         }
//     }
//     return NULL;
// }

void scene_calc_task(uint8_t* output)
{
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
            fade_proportion = ((float)(current_fade_timeout-millis()))/((float)(1000*fade_time));
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
        //Get background values
        //HTP with current state
        
    }

    //TODO: Make this work with fading?
    if((Scene_Engine_Settings.s2l_enable[get_scene()-1]==pdTRUE) && (Scene_Engine_Settings.s2l_mode == S2L_MODE_PULSE)) //If Sound to light active on this scene
    {
        rawval = adc1_get_raw(ADC1_CHANNEL_3);
        if (current_state[Scene_Engine_Settings.sel_low_ch]<rawval) 
        { 
            current_state[Scene_Engine_Settings.sel_low_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
        }

        rawval = adc1_get_raw(ADC1_CHANNEL_6);
        if (current_state[Scene_Engine_Settings.sel_midlow_ch]<rawval) 
        { 
            current_state[Scene_Engine_Settings.sel_midlow_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
        }

        rawval = adc1_get_raw(ADC1_CHANNEL_7);
        if (current_state[Scene_Engine_Settings.sel_midhigh_ch]<rawval) 
        { 
            current_state[Scene_Engine_Settings.sel_midhigh_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
        }

        rawval = adc1_get_raw(ADC1_CHANNEL_4);
        if (current_state[Scene_Engine_Settings.sel_high_ch]<rawval) 
        { 
            current_state[Scene_Engine_Settings.sel_high_ch] = (uint8_t) (((float)rawval/(float)4096)*255);
        }
    }

    current_state[0]=0x00; // Make sure that we're outputting a dimmer frame just in case
    copy_513(current_state,output);
    return NULL;
}
