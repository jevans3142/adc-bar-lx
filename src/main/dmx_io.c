// DMX Input/Output module
//-----------------------------------

#include "driver/uart.h"

#include "dmx_io.h"


//Functions to provide microsecond delays 

static unsigned long IRAM_ATTR micros()
{
    return (unsigned long) (esp_timer_get_time());
}

static void IRAM_ATTR delay_microseconds(uint32_t us)
{
    uint32_t m = micros();
    if(us)
    {
        uint32_t e = (m + us);
        if(m > e){ //overflow
            while(micros() > e)
            {
                NOP();
            }
        }
        while(micros() < e)
        {
            NOP();
        }
    }
}

// DMX Output setup and loop 

void dmx_output_task(void)
{
    // Configure UART parameters

    const int uart_num = DMX_OUT_PORT;
    uart_config_t uart_config = {
        .baud_rate = DMX_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_2,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 122,
    };

    uart_param_config(uart_num, &uart_config);
    
    uart_set_pin(uart_num, PIN_DMX_OUT, PIN_DMX_OUT_RTN, PIN_DMX_OUT_RTS, PIN_DMX_OUT_CTS);

    // Allocate buffers for UART
    uint8_t* data = (uint8_t*) malloc(DMX_OUT_BUFFER_SIZE);
    
    //TEST CODE==============
    for (int i=0;i<512;i++)
    {
        data[i]=0x00;
    }
    data[1]=0xFF;
    data[2]=0x55;
    data[511]=0x22;
    data[512]=0x44;
    //=======================

    uart_driver_install(uart_num, DMX_OUT_BUFFER_SIZE * 2, DMX_OUT_BUFFER_SIZE * 2, 0, NULL, 0);
    uart_set_mode(uart_num, UART_MODE_RS485_HALF_DUPLEX);


    while(1) 
    {
        //Send DMX star-of-frame signal 
        uart_set_line_inverse(uart_num,UART_INVERSE_TXD);
        delay_microseconds(DMX_OUT_START_BREAK_US);
        uart_set_line_inverse(uart_num,UART_INVERSE_DISABLE);
        delay_microseconds(DMX_OUT_MARK_AFTER_BREAK );

        uart_write_bytes(uart_num, (const char*)data,513);
        vTaskDelay(DMX_OUT_INTER_SLOT_PAUSE_MS);
    }
}
