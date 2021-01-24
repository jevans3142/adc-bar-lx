// Low-level screen driver module
//-----------------------------------

#ifndef SCREEN_DRIVER_H_INCLUDED
#define SCREEN_DRIVER_H_INCLUDED

#include "freertos/FreeRTOS.h"

#define PIN_I2C_SCL (22)               
#define PIN_I2C_SDA (21)              
#define I2C_NUM I2C_NUM_0        
#define I2C_FREQ 400000     
#define I2C_TX_BUFFER 0                     
#define I2C_RX_BUFFER 0                          
#define I2C_DISPLAY_ADDRESS 0x3c
#define I2C_WRITE_BIT I2C_MASTER_WRITE  
#define I2C_ACK_CHECK_EN 0x1            

#define SH1106_SETLOWCOLUMN 0x00
#define SH1106_SETHIGHCOLUMN 0x10
#define SH1106_SETSTARTLINE 0x40
#define SH1106_LCDWIDTH 128
#define SH1106_LCDHEIGHT 64

//Pixel type, fill type
#define BLACK 0
#define WHITE 1
#define INVERT 2
#define LEAVE 3

#define NORMAL_SIZE 0
#define DOUBLE_SIZE 1

void setup_display_mutexs(void);
void refresh_display(void);
void enable_display(void);
void reenable_display(void);
void disable_display(void);
void clear_display(void);
void draw_pixel(uint8_t x, uint8_t y, uint8_t type);
void draw_line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t type);
void draw_rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t outline, uint8_t fill);
void draw_string(uint8_t x, uint8_t y, const char* s, uint8_t scaling, uint8_t type);

#endif