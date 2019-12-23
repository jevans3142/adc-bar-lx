// Screen interface draw module
//-----------------------------------


#include "redraw_screen.h"
#include "screen_driver.h"

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
            draw_string(8,0,"Record Scene",NORMAL_SIZE, WHITE);
            draw_string(8,8,"Fade Time",NORMAL_SIZE, WHITE);
            draw_string(8,16,"S2L Mode",NORMAL_SIZE, WHITE);
            draw_string(8,24,"S2L High Ch",NORMAL_SIZE, WHITE);

            //Actually the menu icons
            draw_string(120,8,"{",NORMAL_SIZE, WHITE);
            draw_string(120,20,"|",NORMAL_SIZE, WHITE);
            draw_string(120,32,"}",NORMAL_SIZE, WHITE);
            draw_string(120,44,"~",NORMAL_SIZE, WHITE);

            //Actually the menu position cursor
            draw_string(0,0,"^",NORMAL_SIZE, WHITE);
            break;
    }
    disable_display();
    refresh_display();
    reenable_display();
}
