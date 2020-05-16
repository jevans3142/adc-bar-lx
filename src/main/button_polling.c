// Button polling bits
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "freertos/task.h"

#include "button_polling.h"
#include "redraw_screen.h"
#include "scene_engine.h"

static void menu_button_do(void)
{   
    if (reset_display_active_status() == 1)
    {
        return;
    }

    switch (get_screen())
    {
        case SCREEN_MAIN_STATUS :
            set_screen(SCREEN_MAIN_MENU,0);
            break;
        case SCREEN_MAIN_MENU :
            set_screen(SCREEN_MAIN_STATUS,0);
            break;

        case SCREEN_RECALL_SCENE :
        case SCREEN_RECORD_SCENE :
        case SCREEN_FADE_TIME : 
        case SCREEN_S2L_MENU :
        case SCREEN_DMX_MODE : 
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
    if (reset_display_active_status() == 1)
    {
        return;
    }
    
    switch (get_screen())
    {
        case SCREEN_MAIN_STATUS : //No action
            break;
        case SCREEN_MAIN_MENU :
            set_screen(get_menu_selected()+10,0);
            break;

        case SCREEN_RECALL_SCENE :
            set_scene(get_screen_selected_value());
            set_screen(SCREEN_MAIN_MENU, SCREEN_RECALL_SCENE - 10);
            break;
        case SCREEN_RECORD_SCENE :
            //TODO
            set_screen(SCREEN_MAIN_MENU, SCREEN_RECORD_SCENE - 10);
            break;
        case SCREEN_FADE_TIME :
            //TODO 
            set_screen(SCREEN_MAIN_MENU, SCREEN_FADE_TIME - 10);
            break;
        case SCREEN_S2L_MENU :
            set_screen(get_menu_selected()+20,0);
            break;
        case SCREEN_DMX_MODE : 
            //TODO
            set_screen(SCREEN_MAIN_MENU, SCREEN_DMX_MODE - 10);
            break;
        case SCREEN_LOCK_CTRLS : 
            //TODO
            set_screen(SCREEN_MAIN_STATUS, 0);
            break;

        case SCREEN_S2L_MODE : 
            //TODO
            set_screen(SCREEN_S2L_MENU, SCREEN_S2L_MODE - 20);
            break;
        case SCREEN_S2L_H_CH :
            //TODO
            set_screen(SCREEN_S2L_MENU, SCREEN_S2L_H_CH  - 20);
            break;
        case SCREEN_S2L_MH_CH : 
            //TODO
            set_screen(SCREEN_S2L_MENU, SCREEN_S2L_MH_CH - 20);
            break;
        case SCREEN_S2L_ML_CH :
            //TODO 
            set_screen(SCREEN_S2L_MENU, SCREEN_S2L_ML_CH  - 20);
            break;
        case SCREEN_S2L_L_CH : 
            //TODO 
            set_screen(SCREEN_S2L_MENU, SCREEN_S2L_L_CH - 20);
            break;
    }
}

static void up_button_do(void)
{
    if (reset_display_active_status() == 1)
    {
        return;
    }
    
    switch (get_screen())
    {
        case SCREEN_MAIN_STATUS : // No action
            break;
        case SCREEN_MAIN_MENU : 
            set_menu_selected_dec(5);
            redraw_screen(get_screen());
            break;
        case SCREEN_RECALL_SCENE :
            set_screen_selected_value_inc(7,1);
            redraw_screen(get_screen());
            break;
        case SCREEN_RECORD_SCENE :
            set_screen_selected_value_inc(7,1);
            redraw_screen(get_screen());
            break;
        case SCREEN_FADE_TIME : 
            set_screen_selected_value_inc(59,1);
            redraw_screen(get_screen());
            break;
        case SCREEN_S2L_MENU : 
            set_menu_selected_dec(4);
            redraw_screen(get_screen());
            break;
        case SCREEN_DMX_MODE : 
            set_screen_selected_value_inc(1,0);
            redraw_screen(get_screen());
            break;
        case SCREEN_LOCK_CTRLS : 
            set_screen_selected_value_inc(999,0);
            redraw_screen(get_screen());
            break;

        case SCREEN_S2L_MODE : 
            set_screen_selected_value_inc(1,0);
            redraw_screen(get_screen());
            break;
        case SCREEN_S2L_H_CH :
        case SCREEN_S2L_MH_CH : 
        case SCREEN_S2L_ML_CH : 
        case SCREEN_S2L_L_CH :  
            set_screen_selected_value_inc(512,1);
            redraw_screen(get_screen());
            break;
    }
}

static void down_button_do(void)
{
    if (reset_display_active_status() == 1)
    {
        return;
    }

    switch (get_screen())
    {
        case SCREEN_MAIN_STATUS : //No action
            break;
        case SCREEN_MAIN_MENU :
            set_menu_selected_inc(5);
            redraw_screen(get_screen());
            break;
        case SCREEN_RECALL_SCENE :
            set_screen_selected_value_dec(7,1);
            redraw_screen(get_screen());
            break;
        case SCREEN_RECORD_SCENE :
            set_screen_selected_value_dec(7,1);
            redraw_screen(get_screen());
            break;
        case SCREEN_FADE_TIME : 
            set_screen_selected_value_dec(59,1);
            redraw_screen(get_screen());
            break;
        case SCREEN_S2L_MENU :
            set_menu_selected_inc(4);
            redraw_screen(get_screen());
            break;
        case SCREEN_DMX_MODE : 
            set_screen_selected_value_dec(1,0);
            redraw_screen(get_screen());
            break;
        case SCREEN_LOCK_CTRLS : 
            set_screen_selected_value_dec(999,0);
            redraw_screen(get_screen());
            break;

        case SCREEN_S2L_MODE : 
            set_screen_selected_value_dec(1,0);
            redraw_screen(get_screen());
            break;
        case SCREEN_S2L_H_CH :
        case SCREEN_S2L_MH_CH : 
        case SCREEN_S2L_ML_CH : 
        case SCREEN_S2L_L_CH :  
            set_screen_selected_value_dec(512,1);
            redraw_screen(get_screen());
            break;
    }
}

int scene_button_decode(void)
{
    return ( (1 * !gpio_get_level(PIN_SCENE_BUTTONS_BIT_1)) + (2 * !gpio_get_level(PIN_SCENE_BUTTONS_BIT_2)) + (4 * !gpio_get_level(PIN_SCENE_BUTTONS_BIT_4)) );
}

static void button_debounce(int button_pin, int* state, int* counter, void (*button_do)())
{
    if (gpio_get_level(button_pin))
    {
        *counter = 0;
        if (*state != 0)
        {
            *state = 0;
            button_do();
        }       
    }
    else
    {
        *counter = *counter + 1;
    }
    if (*counter >= BUTTON_DEBOUNCE_TICKS)
    {
        *state = 1;   
    }
}

void button_poll_task(void)
{
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = PIN_MENU_BUTTONS_MASK;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);

    io_conf.pin_bit_mask = PIN_SCENE_BUTTONS_MASK;
    gpio_config(&io_conf);

    int menu_counter = 0;
    int set_counter = 0;
    int up_counter = 0;
    int down_counter = 0;
    int scene_counter = 0; 


    int menu_state = 0;
    int set_state = 0;
    int up_state = 0;
    int down_state = 0;
    int scene_state = 0;

    int scene_number = 0; 


    while(1) 
    {
        button_debounce(PIN_MENU_BUTTON, &menu_state, &menu_counter, menu_button_do);
        button_debounce(PIN_SET_BUTTON, &set_state, &set_counter, set_button_do);
        button_debounce(PIN_UP_BUTTON, &up_state, &up_counter, up_button_do);
        button_debounce(PIN_DOWN_BUTTON, &down_state, &down_counter, down_button_do);

        // Scene buttons
        int current_button_selected = scene_button_decode();
        if (current_button_selected == 0)
        {
            if (scene_state != 0)
            {
                scene_state = 0;
                set_scene(scene_number);
                if (get_screen()==0)
                {
                    redraw_screen(0);
                }
            }
            scene_counter = 0;
            scene_number = 0;             
        }
        else
        {
            if (current_button_selected==scene_number)
            {
                scene_counter++;
            }
            else
            {
                scene_counter = 0;
                scene_number = current_button_selected;
            }

        }
        if (scene_counter >= BUTTON_DEBOUNCE_TICKS)
        {
            scene_state = 1;   
        }

    
        

        vTaskDelay(BUTTON_POLL_INTERVAL_MS);
    }      
}
