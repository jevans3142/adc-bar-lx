// Scene engine module
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "scene_engine.h"

SemaphoreHandle_t Scene_No_Mutex = NULL;
int Scene_No = 1; //NB: This variable is 1 indexed
int Scene_State = SCENE_STATE_STATIC;
uint8_t last_fade_state[512] = {};
uint8_t current_state[512] = {};
uint8_t scenes[7][512] = {};
int fade_time = 5;
float fade_proportion = 0;
unsigned long current_fade_timeout = 0;

static unsigned long IRAM_ATTR millis()
{
    return (unsigned long) (esp_timer_get_time() / 1000ULL);
}

static void htp_512(uint8_t* first, uint8_t* second)
{
    for(int i=0; i<512;i++)
    {
        if (*first<*second) 
        { 
            *first = *second;
        }
        else
        first++;
        second++;
    }
}

static void copy_512(uint8_t* source, uint8_t* dest)
{
    for(int i=0; i<512;i++)
    {
        *dest=*source;
        source++;
        dest++;
    }
}

static void proportion_512(uint8_t* first, uint8_t* second, uint8_t* output, float progress)
{
    for(int i=0; i<512;i++)
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
    
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = PIN_SCENE_LEDS_MASK;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);

    gpio_set_level(PIN_SCENE_LEDS_BIT_1, 1);
    gpio_set_level(PIN_SCENE_LEDS_BIT_2, 0);
    gpio_set_level(PIN_SCENE_LEDS_BIT_4, 0);

    //TODO: Setup fade time
    
    //TEST CODE==============
    for (int j=0;j<7;j++)
    {
        for (int i=0;i<512;i++)
        {
            scenes[j][i]=0x00;
        }
    }
    scenes[0][0]=0xFF;
    scenes[0][1]=0x55;
    scenes[1][0]=0x22;
    scenes[1][1]=0x44;
    //=======================  
}

void set_scene(int new_scene_no)
{
    //Sanity bounds check
    if (new_scene_no>7 || new_scene_no<1)
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
                copy_512(current_state, last_fade_state);
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

void transfer_scene_data(uint8_t* output)
{
    scene_calc_task();
    copy_512(current_state,output);
            
    return NULL;
}

void scene_calc_task(void)
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
            proportion_512(last_fade_state, scenes[get_scene()-1], current_state, fade_proportion);
        }
    }
    if (Scene_State == SCENE_STATE_STATIC)
    {
        //Static
        copy_512(scenes[get_scene()-1],current_state);
    }

    if (true) //If DMX Input active
    {
        //Get background values
        //HTP with current state
    }

    if(true) //If Sound to light active on this scene
    {
        //Sample sound to light ADC values
        //HTP with current state
    }

}
