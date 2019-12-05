// Button polling bits
//-----------------------------------

#include "driver/gpio.h"

#include "button_polling.h"

void button_poll_task(void)
{
    
    
    while(1) 
    {
    
    
        vTaskDelay(BUTTON_POLL_INTERVAL_MS);
    }      
}