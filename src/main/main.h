//LX Controller header
//--------------------

//Task setup

#define DMX_OUTPUT_TASK_STACK_SIZE    4096
#define DMX_OUTPUT_TASK_PRIO          10

#define DMX_INPUT_TASK_STACK_SIZE    2048
#define DMX_INPUT_TASK_PRIO          10

#define BUTTON_POLL_TASK_STACK_SIZE    16384
#define BUTTON_POLL_TASK_PRIO          10

#define DISPLAY_TIMEOUT_TASK_STACK_SIZE    2048
#define DISPLAY_TIMEOUT_TASK_PRIO          10

#define S2L_METER_REFRESH_TASK_STACK_SIZE    2048
#define S2L_METER_REFRESH_TASK_PRIO          10

extern TaskHandle_t DMX_Output_Task_Handle;
extern TaskHandle_t DMX_Input_Task_Handle;
extern TaskHandle_t Button_Poll_Task_Handle;
extern TaskHandle_t Display_Timeout_Task_Handle;
extern TaskHandle_t S2l_Meter_Refresh_Handle;