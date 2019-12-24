//LX Controller header
//--------------------

#include "freertos/semphr.h"

//Task setup

#define DMX_OUT_TASK_STACK_SIZE    (2048)
#define DMX_OUT_TASK_PRIO          (10)

extern SemaphoreHandle_t Screen_No_Mutex;
extern int Screen_No;