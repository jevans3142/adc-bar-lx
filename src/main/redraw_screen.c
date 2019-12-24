// Screen interface draw module
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#include "redraw_screen.h"
#include "screen_driver.h"

static void draw_menu_symbols(void)
{
    //These strings have been remapped to the correct icons in the font data
    draw_string(120,8,"{",NORMAL_SIZE, WHITE);
    draw_string(120,20,"|",NORMAL_SIZE, WHITE);
    draw_string(120,34,"}",NORMAL_SIZE, WHITE);
    draw_string(120,48,"~",NORMAL_SIZE, WHITE);
}

//TODO: better exception handling here 
void set_screen(int new_screen_no)
{
    if( Screen_No_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_No_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            Screen_No = new_screen_no;
            redraw_screen(new_screen_no);
            xSemaphoreGive( Screen_No_Mutex );
        }
    }
}

//TODO: Is this overkill? Is the mutex required ie. are writes to int atomic on ESP32?
int get_screen(void)
{
    if( Screen_No_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_No_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            xSemaphoreGive( Screen_No_Mutex );
            return Screen_No;
        }
    }
    return NULL;
}

//TODO: Should in fact this function be static? Call only through set_screen?
void redraw_screen(int screen_no)
{
    clear_display();

    switch (screen_no)
    {
        case 0 : //Main status screen
            draw_line(0,28,128,28, WHITE);
            draw_line(64,28,64,64, WHITE);
            draw_string(8,12,"1",NORMAL_SIZE, WHITE);
            draw_rect(6,10,14,20, WHITE, LEAVE);
            draw_string(16,8,"Evening 1",DOUBLE_SIZE, WHITE);
            draw_string(70,30,"Audio in",NORMAL_SIZE, WHITE);
            draw_string(12,30,"DMX in",NORMAL_SIZE, WHITE);
            draw_string(12,40,"OFF",DOUBLE_SIZE, WHITE);
            break;  

        case 1 : //Main menu
            draw_menu_symbols();

            draw_string(0,0,"Main Menu",NORMAL_SIZE, WHITE);

            draw_string(8,12,"Record Scene",NORMAL_SIZE, WHITE);
            draw_string(8,20,"Fade Time",NORMAL_SIZE, WHITE);
            draw_string(8,28,"DMX Input Mode",NORMAL_SIZE, WHITE);
            draw_string(8,36,"Sound To Light...",NORMAL_SIZE, WHITE);
            draw_string(8,44,"Lock Controls",NORMAL_SIZE, WHITE);

            //Actually the menu position cursor
            draw_string(0,12,"^",NORMAL_SIZE, WHITE);
            break;

        case 2 : //S2L Settings
            draw_menu_symbols();

            draw_string(0,0,"Sound To Light Menu",NORMAL_SIZE, WHITE);

            draw_string(8,12,"Mode",NORMAL_SIZE, WHITE);
            draw_string(8,20,"High Channel",NORMAL_SIZE, WHITE);
            draw_string(8,28,"Mid-High Channel",NORMAL_SIZE, WHITE);
            draw_string(8,36,"Mid-Low Channel",NORMAL_SIZE, WHITE);
            draw_string(8,44,"Low Channel",NORMAL_SIZE, WHITE);

            //Actually the menu position cursor
            draw_string(0,12,"^",NORMAL_SIZE, WHITE);
            break;

        case 10 : // Record Scene
            break;
        case 11 : // Fade Time
            break;
        case 12 : // DMX Input Mode
            break;
        case 13 : // Lock Controls
            break;

        case 20 : // S2L Mode
            break;
        case 21 : // S2L High Ch
            break;
        case 22 : // S2L Mid High Ch 
            break;
        case 23 : // S2L Mid Low Ch
            break;
        case 24 : // S2L Low Ch
            break;

        
    }
    disable_display();
    refresh_display();
    reenable_display();
}
