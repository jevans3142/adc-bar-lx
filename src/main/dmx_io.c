// DMX Input/Output module
//-----------------------------------

#include "driver/uart.h"

#include "dmx_io.h"
#include "scene_engine.h"

#include "esp_err.h"
#include "esp_log.h"

QueueHandle_t dmx_input_queue;

#define DMX_IDLE 0
#define DMX_BREAK 1
#define DMX_DATA 2

uint8_t dmx_state = DMX_IDLE;
uint16_t current_rx_addr = 0;
long last_dmx_packet = 0;

static const char *TAG = "dmx_io";

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

    uart_driver_install(uart_num, DMX_OUT_BUFFER_SIZE * 2, DMX_OUT_BUFFER_SIZE * 2, 0, NULL, 0);
    uart_set_mode(uart_num, UART_MODE_RS485_HALF_DUPLEX);


    while(1) 
    {
        scene_calc_task(data);

        //Send DMX start-of-frame signal 
        uart_set_line_inverse(uart_num,UART_INVERSE_TXD);
        delay_microseconds(DMX_OUT_START_BREAK_US);
        uart_set_line_inverse(uart_num,UART_INVERSE_DISABLE);
        delay_microseconds(DMX_OUT_MARK_AFTER_BREAK );

        uart_write_bytes(uart_num, (const char*)data,513);
        vTaskDelay(DMX_OUT_INTER_SLOT_PAUSE_MS);
    }
}

void dmx_input_task(void)
{
    // Configure UART parameters

    const int uart_num = DMX_IN_PORT;
    uart_config_t uart_config = {
        .baud_rate = DMX_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_2,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 122,
    };

    uart_param_config(uart_num, &uart_config);
    
    uart_set_pin(uart_num, PIN_DMX_IN_RTN, PIN_DMX_IN, PIN_DMX_IN_RTS, PIN_DMX_IN_CTS);
    
    uart_driver_install(uart_num, DMX_IN_BUFFER_SIZE * 2, DMX_IN_BUFFER_SIZE * 2, 20, &dmx_input_queue, 0);
    uart_set_mode(uart_num, UART_MODE_RS485_HALF_DUPLEX);

    uart_event_t event;
    uint8_t* dtmp = (uint8_t*) malloc(1024);

    while(1)
    {
        // wait for data in the dmx_queue
        if(xQueueReceive(dmx_input_queue, (void * )&event, ( TickType_t ) 10))
        {
            for (int i=0;i<1025;i++)
            {
                dtmp[i]=0;
            }
            switch(event.type)
            {
                case UART_DATA:
                    // read the received data
                    uart_read_bytes(DMX_IN_PORT, dtmp, event.size, ( TickType_t ) 10);
                    // check if break detected
                    if(dmx_state == DMX_BREAK)
                    {
                        // if not 0, then RDM or custom protocol
                        if(dtmp[0] == 0)
                        {
                        dmx_state = DMX_DATA;
                        // reset dmx adress to 0
                        current_rx_addr = 0;
                        //xSemaphoreTake(DMX_Input_Buffer_Mutex, ( TickType_t ) 10 );
                        // store received timestamp
                        //TODO - this is the timing thing
                        last_dmx_packet = xTaskGetTickCount();
                        //xSemaphoreGive(DMX_Input_Buffer_Mutex);
                        }
                    }
                    // check if in data receive mode
                    if(dmx_state == DMX_DATA)
                    {
                        // copy received bytes to dmx data array
                        for(int i = 0; i < event.size; i++)
                        {
                            if(current_rx_addr < 513)
                            {
                                //TODO: This takes the mutex loads of times... can we do better?
                                store_dmx_input_value(current_rx_addr++, dtmp[i]);
                            }
                        }
                    }
                    break;
                case UART_BREAK:
                    // break detected
                    // clear queue und flush received bytes                    
                    uart_flush_input(DMX_IN_PORT);
                    xQueueReset(dmx_input_queue);
                    dmx_state = DMX_BREAK;
                    break;
                case UART_FRAME_ERR:
                case UART_PARITY_ERR:
                case UART_BUFFER_FULL:
                case UART_FIFO_OVF:
                default:
                    // error recevied, going to idle mode
                    uart_flush_input(DMX_IN_PORT);
                    xQueueReset(dmx_input_queue);
                    dmx_state = DMX_IDLE;
                    break;
            }
        }
    }
}
