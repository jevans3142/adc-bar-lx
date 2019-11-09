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

void refresh_display(void);
void enable_display(void);
void disable_display(void);

#endif  