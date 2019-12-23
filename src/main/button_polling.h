// Button polling bits
//-----------------------------------

#ifndef BUTTON_POLLING_H_INCLUDED
#define BUTTON_POLLING_H_INCLUDED

#include "freertos/FreeRTOS.h"

#define BUTTON_POLL_INTERVAL_MS ( 10 / portTICK_PERIOD_MS)

#define PIN_MENU_BUTTON 15
#define PIN_SET_BUTTON 2
#define PIN_UP_BUTTON 4
#define PIN_DOWN_BUTTON 16

#define PIN_BUTTONS_MASK  ((1ULL<<PIN_MENU_BUTTON) | (1ULL<<PIN_SET_BUTTON) | (1ULL<<PIN_UP_BUTTON) | (1ULL<<PIN_DOWN_BUTTON))

#define BUTTON_DEBOUNCE_TICKS 4

void button_poll_task(void);

#endif  