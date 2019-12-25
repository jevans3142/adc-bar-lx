// Button polling bits
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "freertos/task.h"

#include "button_polling.h"
#include "redraw_screen.h"

static void menu_button_do(void)
{   

    switch (get_screen())
    {
        case SCREEN_MAIN_STATUS :
            set_screen(SCREEN_MAIN_MENU,0);
            break;
        case SCREEN_MAIN_MENU :
            set_screen(SCREEN_MAIN_STATUS,0);
            break;

        case SCREEN_RECORD_SCENE :
        case SCREEN_FADE_TIME : 
        case SCREEN_DMX_MODE : 
        case SCREEN_S2L_MENU :
        case SCREEN_LOCK_CTRLS : 
            set_screen(SCREEN_MAIN_MENU,get_screen()-10);
            break;
        
        case SCREEN_S2L_MODE :
        case SCREEN_S2L_H_CH : 
        case SCREEN_S2L_MH_CH : 
        case SCREEN_S2L_ML_CH : 
        case SCREEN_S2L_L_CH :  
            set_screen(SCREEN_S2L_MENU,get_screen()-20);
            break;

    }
}

static void set_button_do(void)
{
     switch (get_screen())
    {
        case SCREEN_MAIN_STATUS : //No action
            break;
        case SCREEN_MAIN_MENU :
            set_screen(get_menu_selected()+10,0);
            break;
        case SCREEN_S2L_MENU :
            set_screen(get_menu_selected()+20,0);
            break;

        case SCREEN_RECORD_SCENE :
            
            break;
        case SCREEN_FADE_TIME : 
            
            break;
        case SCREEN_DMX_MODE : 
            
            break;
        case SCREEN_LOCK_CTRLS : 
            
            break;

        case SCREEN_S2L_MODE : 
            
            break;
        case SCREEN_S2L_H_CH :
           
            break;
        case SCREEN_S2L_MH_CH : 
            
            break;
        case SCREEN_S2L_ML_CH : 
            
            break;
        case SCREEN_S2L_L_CH :  

            break;
    }
}

static void up_button_do(void)
{
    switch (get_screen())
    {
        case SCREEN_MAIN_STATUS : // No action
            break;
        case SCREEN_MAIN_MENU : 
        case SCREEN_S2L_MENU : 
            if (get_menu_selected()<1)
            {
                set_menu_selected(4);
            }
            else
            {
                set_menu_selected(get_menu_selected()-1);
            }
            redraw_screen(get_screen());
            break;

        case SCREEN_RECORD_SCENE :
            
            break;
        case SCREEN_FADE_TIME : 
            
            break;
        case SCREEN_DMX_MODE : 
            
            break;
        case SCREEN_LOCK_CTRLS : 
            
            break;

        case SCREEN_S2L_MODE : 
            
            break;
        case SCREEN_S2L_H_CH :
           
            break;
        case SCREEN_S2L_MH_CH : 
            
            break;
        case SCREEN_S2L_ML_CH : 
            
            break;
        case SCREEN_S2L_L_CH :  

            break;
    }
}

static void down_button_do(void)
{
switch (get_screen())
    {
        case SCREEN_MAIN_STATUS : //No action
            break;
        case SCREEN_MAIN_MENU :
        case SCREEN_S2L_MENU :
            if (get_menu_selected()<4)
            {
                set_menu_selected((get_menu_selected()+1));
            }
            else
            {
                set_menu_selected(0);
            }
            redraw_screen(get_screen());
            break;

        case SCREEN_RECORD_SCENE :
            
            break;
        case SCREEN_FADE_TIME : 
            
            break;
        case SCREEN_DMX_MODE : 
            
            break;
        case SCREEN_LOCK_CTRLS : 
            
            break;

        case SCREEN_S2L_MODE : 
            
            break;
        case SCREEN_S2L_H_CH :
           
            break;
        case SCREEN_S2L_MH_CH : 
            
            break;
        case SCREEN_S2L_ML_CH : 
            
            break;
        case SCREEN_S2L_L_CH :  

            break;
    }
}

/*static void button_debounce()
{
    if (gpio_get_level(PIN_MENU_BUTTON))
    {
        menu_counter = 0;
        if (menu_state != 0)
        {
            menu_state = 0;
            menu_button_do();
        }       
    }
    else
    {
        menu_counter++;
    }
    if (menu_counter >= BUTTON_DEBOUNCE_TICKS)
    {
        menu_state = 1;   
    }
}*/

void button_poll_task(void)
{
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = PIN_BUTTONS_MASK;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);

    int menu_counter = 0;
    int set_counter = 0;
    int up_counter = 0;
    int down_counter = 0;

    int menu_state = 0;
    int set_state = 0;
    int up_state = 0;
    int down_state = 0;

    while(1) 
    {
        //MENU
        if (gpio_get_level(PIN_MENU_BUTTON))
            {
                menu_counter = 0;
                if (menu_state != 0)
                    {
                        menu_state = 0;
                        menu_button_do();
                    }       
            }
        else
            {
                menu_counter++;
            }
        if (menu_counter >= BUTTON_DEBOUNCE_TICKS)
            {
                menu_state = 1;   
            }

        //SET
        if (gpio_get_level(PIN_SET_BUTTON))
            {
                set_counter = 0;
                if (set_state != 0)
                    {
                        set_state = 0;
                        set_button_do();
                    }       
            }
        else
            {
                set_counter++;
            }
        if (set_counter >= BUTTON_DEBOUNCE_TICKS)
            {
                set_state = 1;   
            }

        //UP
        if (gpio_get_level(PIN_UP_BUTTON))
            {
                up_counter = 0;
                if (up_state != 0)
                    {
                        up_state = 0;
                        up_button_do();
                    }       
            }
        else
            {
                up_counter++;
            }
        if (up_counter >= BUTTON_DEBOUNCE_TICKS)
            {
                up_state = 1;   
            }

        //DOWN
        if (gpio_get_level(PIN_DOWN_BUTTON))
            {
                down_counter = 0;
                if (down_state != 0)
                    {
                        down_state = 0;
                        down_button_do();
                    }       
            }
        else
            {
                down_counter++;
            }
        if (down_counter >= BUTTON_DEBOUNCE_TICKS)
            {
                down_state = 1;   
            }

        vTaskDelay(BUTTON_POLL_INTERVAL_MS);
    }      
}
