#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "freertos/queue.h" 

#include "main.h"
#include "dmx_io.h"
#include "screen_driver.h"
#include "button_polling.h"
#include "redraw_screen.h"

//Define state and mutex
SemaphoreHandle_t Screen_No_Mutex = NULL;
int Screen_No = 0; 


void app_main(void)
{
    Screen_No_Mutex = xSemaphoreCreateMutex();
    
    xTaskCreate(dmx_output_task, "dmx_output_task", DMX_OUT_TASK_STACK_SIZE, NULL, DMX_OUT_TASK_PRIO, NULL);
    xTaskCreate(button_poll_task, "button_poll_task", DMX_OUT_TASK_STACK_SIZE, NULL, DMX_OUT_TASK_PRIO, NULL);

    enable_display();
    vTaskDelay(200);
    redraw_screen(0);
}
