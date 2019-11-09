// Low-level screen driver module
//-----------------------------------

#include "driver/i2c.h"

#include "screen_driver.h"

//ADC logo - TEST CODE
static uint8_t buffer[SH1106_LCDHEIGHT * SH1106_LCDWIDTH / 8] = { 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xe0,  0xf0,  0xf8,  0xf0,  0xf0,  0xf8,  0xfc,  0xfc,  0xfc,  0xfe,  0xfe,  0xfe,  0xfc,  0xf8,  0xf8,  0xf0,  0xe0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xc0,  0xc0,  0x40,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xf8,  0xfc,  0xfe,  0xe4,  0xf0,  0xe0,  0xc0,  0x80,  0x80,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xf0,  0xf8,  0xfc,  0xfe,  0xfc,  0xfc,  0xf8,  0x10,  0x80,  0x80,  0xc0,  0xc0,  0x80,  0x0,  0x80,  0xc0,  0xe0,  0xf8,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x3e,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfd,  0xf8,  0xfc,  0xff,  0xff,  0xff,  0xff,  0x3e,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xf8,  0xfc,  0xf0,  0xf0,  0xf8,  0xe0,  0x80,  0x0,  0x80,  0xc0,  0xc0,  0xe0,  0xf0,  0xfc,  0xfe,  0xff,  0xfc,  0xfe,  0x38,  0x8,  0x80,  0xe0,  0xf0,  0xe0,  0xe0,  0xe0,  0x80,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xf0,  0xf8,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x7f,  0x3c,  0x3c,  0x3e,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x7f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x7f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3e,  0x7e,  0x7e,  0xfe,  0xfe,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xf8,  0xf8,  0xfe,  0x7f,  0x7f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x7f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0x3f,  0xf,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x10,  0x7c,  0x7e,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xc3,  0x80,  0x0,  0x0,  0x0,  0x0,  0x86,  0xfe,  0xfe,  0x7e,  0x7c,  0x7c,  0x38,  0x0,  0x0,  0x0,  0x0,  0x3,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x1f,  0x7,  0x1,  0x0,  0x0,  0x0,  0x80,  0xf0,  0xf8,  0xfc,  0xfc,  0xfc,  0xf8,  0xf8,  0xf0,  0xc1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x3f,  0xf,  0x3,  0x1,  0x0,  0x0,  0x0,  0xe0,  0xf8,  0xfc,  0xfc,  0xfc,  0xfc,  0xfc,  0xc,  0x4,  0x0,  0x0,  0x0,  0x1,  0x87,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfe,  0xfe,  0xbf,  0x8c,  0xc0,  0xe0,  0x78,  0x3c,  0x18,  0x8,  0x0,  0x0,  0x0,  0x0,  0x1,  0x0,  0x0,  0x83,  0xf3,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xf,  0x7,  0x3,  0x3,  0x1,  0x1,  0x0,  0xe0,  0xf0,  0xf8,  0xf8,  0xfc,  0x7c,  0xc,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xf,  0xf,  0xf,  0xf,  0xff,  0xff,  0xff,  0xff,  0xff,  0xc0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x7,  0x3f,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x3f,  0xf,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xe0,  0x80,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x1e,  0x6,  0x6,  0x7,  0xc7,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x3f,  0x1f,  0x7,  0x3,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xe0,  0xf8,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfc,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe0,  0xe1,  0xf1,  0xf1,  0xf0,  0xf8,  0xfc,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe1,  0xf0,  0xf0,  0xf8,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfc,  0xf8,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe0,  0xe0,  0xf0,  0xf0,  0xf8,  0xfc,  0xf0,  0xf0,  0xf0,  0xf0,  0xf0,  0xf0,  0xf0,  0xf1,  0xf1,  0xf1,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfe,  0xfc,  0xf8,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe1,  0xe1,  0xe0,  0xf0,  0xf0,  0xf8,  0xf8,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x3f,  0xf,  0x3,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x8,  0xe,  0xf,  0x1f,  0x3f,  0x1f,  0xf,  0xcf,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x1f,  0xf,  0x3,  0x3,  0x3,  0x1f,  0x1f,  0x7f,  0x7f,  0x7f,  0x3f,  0x1f,  0x9f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x1f,  0xf,  0x3,  0x1,  0x0,  0x0,  0x3,  0x3,  0x7,  0xf,  0x1f,  0x1f,  0x3f,  0x3f,  0x7f,  0xff,  0xff,  0x7f,  0xff,  0x3f,  0xf,  0xf,  0x1f,  0x1f,  0x3f,  0x7f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x3f,  0x1f,  0x1f,  0x7f,  0x3f,  0x1f,  0x3f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x3f,  0xf,  0xf,  0xf,  0x3f,  0x3f,  0x3f,  0x7f,  0x3f,  0x3f,  0x7f,  0x7f,  0x7f,  0xff,  0xff,  0x1f,  0x7,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3,  0x1,  0x1,  0x1,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x2,  0x3,  0x3,  0xf,  0x1f,  0x7,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1,  0x0,  0x1,  0x1,  0x7,  0x7,  0xf,  0x1f,  0x1f,  0x7,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1,  0x1,  0x3,  0x3,  0x7,  0xf,  0xf,  0xf,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};


static esp_err_t i2c_init(void)
{
    int i2c_master_port = I2C_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = PIN_I2C_SDA;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = PIN_I2C_SCL;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_FREQ;
    i2c_param_config(i2c_master_port, &conf);
    return i2c_driver_install(i2c_master_port, conf.mode, I2C_RX_BUFFER, I2C_TX_BUFFER, 0);
}

static void display_command(uint8_t c) 
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, I2C_DISPLAY_ADDRESS << 1 | I2C_WRITE_BIT, I2C_ACK_CHECK_EN); 
    i2c_master_write_byte(cmd, 0x00, I2C_ACK_CHECK_EN);
    i2c_master_write_byte(cmd, c, I2C_ACK_CHECK_EN);
    i2c_master_stop(cmd);
    i2c_master_cmd_begin(I2C_NUM, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
}

void refresh_display(void)
{
    display_command(SH1106_SETLOWCOLUMN | 0x0);  // low col = 0
    display_command(SH1106_SETHIGHCOLUMN | 0x0);  // hi col = 0
    display_command(SH1106_SETSTARTLINE | 0x0); // line #0

    int height= 64;
	int width=132; //2 pixel overrun to either side 
	int m_row = 0;
	int m_col = 2;
	
	height >>= 3;
	width >>= 3;
	
	int p = 0;
	
	int i, j, k =0;
	

	for ( i = 0; i < height; i++) {
		
		// send a bunch of data in one xmission
        display_command(0xB0 + i + m_row);//set page address
        display_command(m_col & 0xf);//set lower column address
        display_command(0x10 | (m_col >> 4));//set higher column address
		
        for( j = 0; j < 8; j++){        
			i2c_cmd_handle_t cmd = i2c_cmd_link_create();
            i2c_master_start(cmd);
            i2c_master_write_byte(cmd, I2C_DISPLAY_ADDRESS << 1 | I2C_WRITE_BIT, I2C_ACK_CHECK_EN); 
            i2c_master_write_byte(cmd, 0x40, I2C_ACK_CHECK_EN);
            for ( k = 0; k < width; k++, p++) {
		        i2c_master_write_byte(cmd, buffer[p], I2C_ACK_CHECK_EN);
            }
            i2c_master_stop(cmd);
            i2c_master_cmd_begin(I2C_NUM, cmd, 1000 / portTICK_RATE_MS);
            i2c_cmd_link_delete(cmd);
        }
	}
}

void enable_display(void)
{
    ESP_ERROR_CHECK(i2c_init());
    
    //TODO: document this set of magic and tidy up 

    display_command(0xAE);

    display_command(0xD5);
    display_command(0x80);

    display_command(0xA8);
    display_command(0x3F);

    display_command(0xD3);
    display_command(0x00);

    display_command(0x40);

    display_command(0x8D);
    display_command(0x10);

    display_command(0xA4);
    display_command(0xAF);

    refresh_display();
}

void disable_display(void)
{
    display_command(0xAE);
}