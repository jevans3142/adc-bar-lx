// DMX Input/Output module
//-----------------------------------

#ifndef DMX_IO_H_INCLUDED
#define DMX_IO_H_INCLUDED

//Pin defs

//Not using RDM so simplex output only
#define PIN_DMX_OUT (2)
#define PIN_DMX_OUT_RTN UART_PIN_NO_CHANGE
#define PIN_DMX_OUT_RTS UART_PIN_NO_CHANGE
#define PIN_DMX_OUT_CTS UART_PIN_NO_CHANGE

//UART setup
#define DMX_BAUD_RATE (250000)
#define DMX_OUT_PORT (UART_NUM_2)
#define DMX_OUT_BUFFER_SIZE (513)

//Timings from DMX specification
#define DMX_OUT_START_BREAK_US (92)
#define DMX_OUT_MARK_AFTER_BREAK (12)
#define DMX_OUT_INTER_SLOT_PAUSE_MS ( 30 / portTICK_PERIOD_MS)

#define NOP() asm volatile ("nop")

void dmx_output_task(void);

#endif  