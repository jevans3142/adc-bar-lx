// Low-level screen driver module
//-----------------------------------

#ifndef SCREEN_DRIVER_H_INCLUDED
#define SCREEN_DRIVER_H_INCLUDED

#define PIN_I2C_SCL (22)               
#define PIN_I2C_SDA (21)              
#define I2C_NUM I2C_NUM_0        
#define I2C_FREQ 100000        
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


void refresh_display(void);
void enable_display(void);
void disable_display(void);
void clear_display(void);
void draw_pixel(int16_t x, int16_t y, uint16_t type);
void draw_line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t type);
void draw_rect(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t outline, uint16_t fill);
void draw_circle(int16_t xc, int16_t yc, int16_t r, uint16_t outline, uint16_t fill);
void draw_string(uint_fast8_t x, uint_fast8_t y, const char* s, uint_fast8_t scaling, uint_fast8_t type);

#endif  