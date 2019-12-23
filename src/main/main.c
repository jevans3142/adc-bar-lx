#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
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

void app_main(void)
{
    xTaskCreate(dmx_output_task, "dmx_output_task", DMX_OUT_TASK_STACK_SIZE, NULL, DMX_OUT_TASK_PRIO, NULL);
    xTaskCreate(button_poll_task, "button_poll_task", DMX_OUT_TASK_STACK_SIZE, NULL, DMX_OUT_TASK_PRIO, NULL);
    enable_display();
    vTaskDelay(200);
    redraw_screen(0);
    vTaskDelay(200);
    redraw_screen(1);
}
