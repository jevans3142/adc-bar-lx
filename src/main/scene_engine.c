// Scene engine module
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "freertos/semphr.h"

#include "scene_engine.h"

SemaphoreHandle_t Scene_No_Mutex = NULL;
int Scene_No = 1; //NB: This variable is 1 indexed

static void htp_512(void)
{
    
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
                current_fade_timeout = millis() + fade_time*1000;
                copy_512(current_state, last_fade_state);
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

void scene_calc_task(void)
{

    /*
    States: 
    0 - Sat in scene in 'to' variabl
    1 - Fading

    Variable with current state of 
     */

    if (true) //If fading
    {
        
    }

    if (true) //If DMX Input active
    {
        //Get background values
        //HTP with current output 
    }

}