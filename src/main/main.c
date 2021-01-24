#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "freertos/queue.h" 

#include "main.h"
#include "dmx_io.h"
#include "screen_driver.h"
#include "button_polling.h"
#include "redraw_screen.h"
#include "scene_engine.h"
#include "storage.h"

TaskHandle_t DMX_Output_Task_Handle = NULL;
TaskHandle_t DMX_Input_Task_Handle = NULL;
TaskHandle_t Button_Poll_Task_Handle = NULL;
TaskHandle_t Display_Timeout_Task_Handle = NULL;
TaskHandle_t S2l_Meter_Refresh_Handle = NULL;

void app_main(void)
{
    vTaskDelay(100); //Pause to allow display to boot properly first
    init_sd_spi();
    setup_menu_mutexs();
    setup_scene_engine();
    setup_display_mutexs();

    //TODO: Adjust buffers and priorities 
    xTaskCreate(dmx_output_task, "dmx_output_task", DMX_OUTPUT_TASK_STACK_SIZE, NULL, DMX_OUTPUT_TASK_PRIO, &DMX_Output_Task_Handle);
    xTaskCreate(dmx_input_task, "dmx_input_task", DMX_INPUT_TASK_STACK_SIZE, NULL, DMX_INPUT_TASK_PRIO, &DMX_Input_Task_Handle);
    xTaskCreate(button_poll_task, "button_poll_task", BUTTON_POLL_TASK_STACK_SIZE, NULL, BUTTON_POLL_TASK_PRIO, &Button_Poll_Task_Handle);
    xTaskCreate(display_timeout_task, "display_timeout_task", DISPLAY_TIMEOUT_TASK_STACK_SIZE, NULL, DISPLAY_TIMEOUT_TASK_PRIO, &Display_Timeout_Task_Handle);
    
    enable_display();
    vTaskDelay(200);
    set_screen(SCREEN_MAIN_STATUS,0);
    xTaskCreate(s2l_meter_refresh_task, "s2l_meter_refresh_task", S2L_METER_REFRESH_TASK_STACK_SIZE, NULL, S2L_METER_REFRESH_TASK_PRIO, &S2l_Meter_Refresh_Handle);
}

