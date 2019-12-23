// Button polling bits
//-----------------------------------

#include "driver/uart.h"
#include "driver/gpio.h"

#include "button_polling.h"

static void menu_button_do(void)
{

}

static void set_button_do(void)
{
    
}

static void up_button_do(void)
{
    
}

static void down_button_do(void)
{
    
}

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
