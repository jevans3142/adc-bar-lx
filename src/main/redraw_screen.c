// Screen interface draw module
//-----------------------------------

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"

#include "redraw_screen.h"
#include "screen_driver.h"
#include "scene_engine.h"

//Define states and mutexs
SemaphoreHandle_t Screen_No_Mutex = NULL;
int Screen_No = 0; 
SemaphoreHandle_t Menu_Selected_Mutex = NULL;
int Menu_Selected = 10; 
SemaphoreHandle_t Display_Active_Mutex = NULL;
int Display_Active = 1; 
unsigned long Display_Active_Timeout = 0;

char c; 


static unsigned long IRAM_ATTR millis()
{
    return (unsigned long) (esp_timer_get_time() / 1000ULL);
}

static void draw_menu_symbols(void)
{
    //These strings have been remapped to the correct icons in the font data
    draw_string(120,8,"{",NORMAL_SIZE, WHITE);
    draw_string(120,20,"|",NORMAL_SIZE, WHITE);
    draw_string(120,34,"}",NORMAL_SIZE, WHITE);
    draw_string(120,48,"~",NORMAL_SIZE, WHITE);
}

void setup_menu_mutexs(void)
{
    Screen_No_Mutex = xSemaphoreCreateMutex();
    Menu_Selected_Mutex = xSemaphoreCreateMutex();
    Display_Active_Mutex = xSemaphoreCreateMutex();

    reset_display_active_status();
}

void display_timeout_task(void)
{
    while (1)
    {
        if (((millis()-Display_Active_Timeout) >= 60000ULL) && Display_Active)
        {
            if( Display_Active_Mutex != NULL )
            {
                if( xSemaphoreTake( Display_Active_Mutex, ( TickType_t ) 10 ) == pdTRUE )
                {
                    //Turn off screen
                    Display_Active = 0;
                    disable_display();
                    xSemaphoreGive(Display_Active_Mutex);
                }
            }
        }
        vTaskDelay(DISPLAY_ACTIVE_INTERVAL_MS);
    } 
}

int get_display_active_status(void)
{
    if( Display_Active_Mutex != NULL )
    {
        if( xSemaphoreTake( Display_Active_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            int returnval = Display_Active;
            xSemaphoreGive(Display_Active_Mutex);
            return returnval;
        }
    }
    return NULL;
}

int reset_display_active_status(void)
{
    int returnval = 0;
    if( Display_Active_Mutex != NULL )
    {
        if( xSemaphoreTake( Display_Active_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            Display_Active_Timeout = millis();
            if (Display_Active == 0)
            {
                reenable_display();
                Display_Active = 1;
                returnval = 1; 
            }
            xSemaphoreGive(Display_Active_Mutex);  
        }
    }
    return returnval;
}

//TODO: better exception handling here 
void set_screen(int new_screen_no, int new_menu_selected)
{
    if( Screen_No_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_No_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            set_menu_selected(new_menu_selected);
            Screen_No = new_screen_no;
            redraw_screen(new_screen_no);
            xSemaphoreGive( Screen_No_Mutex );
        }
    }
}

int get_screen(void)
{
    if( Screen_No_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_No_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            int returnval = Screen_No;
            xSemaphoreGive( Screen_No_Mutex );
            return returnval;
        }
    }
    return NULL;
}

void set_menu_selected(int new_menu_selected)
{
    if( Menu_Selected_Mutex != NULL )
    {
        if( xSemaphoreTake( Menu_Selected_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            Menu_Selected = new_menu_selected;
            xSemaphoreGive( Menu_Selected_Mutex );
        }
    }
}

int get_menu_selected(void)
{
    if( Menu_Selected_Mutex != NULL )
    {
        if( xSemaphoreTake( Menu_Selected_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            int returnval = Menu_Selected;
            xSemaphoreGive( Menu_Selected_Mutex );
            return returnval;
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
        case SCREEN_MAIN_STATUS :
            draw_line(0,28,128,28, WHITE);
            draw_line(64,28,64,64, WHITE);
            draw_string(8,12,"1",NORMAL_SIZE, WHITE);
            draw_rect(6,10,14,20, WHITE, LEAVE);
            draw_string(16,8,"Evening 1",DOUBLE_SIZE, WHITE);
            draw_string(70,30,"Audio in",NORMAL_SIZE, WHITE);
            draw_string(12,30,"DMX in",NORMAL_SIZE, WHITE);
            draw_string(12,40,"OFF",DOUBLE_SIZE, WHITE);
            break;  

        case SCREEN_MAIN_MENU :
            draw_menu_symbols();

            draw_string(0,0,"Main Menu",NORMAL_SIZE, WHITE);

            draw_string(8,12,"Record Scene",NORMAL_SIZE, WHITE);
            draw_string(8,20,"Fade Time",NORMAL_SIZE, WHITE);
            draw_string(8,28,"DMX Input Mode",NORMAL_SIZE, WHITE);
            draw_string(8,36,"Sound To Light...",NORMAL_SIZE, WHITE);
            draw_string(8,44,"Lock Controls",NORMAL_SIZE, WHITE);

            //Actually the menu position cursor
            draw_string(0,(12+8*get_menu_selected()),"^",NORMAL_SIZE, WHITE);
            break;

        case SCREEN_S2L_MENU :
            draw_menu_symbols();

            draw_string(0,0,"Sound To Light Menu",NORMAL_SIZE, WHITE);

            draw_string(8,12,"Mode",NORMAL_SIZE, WHITE);
            draw_string(8,20,"High Channel",NORMAL_SIZE, WHITE);
            draw_string(8,28,"Mid-High Channel",NORMAL_SIZE, WHITE);
            draw_string(8,36,"Mid-Low Channel",NORMAL_SIZE, WHITE);
            draw_string(8,44,"Low Channel",NORMAL_SIZE, WHITE);

            //Actually the menu position cursor
            draw_string(0,(12+8*get_menu_selected()),"^",NORMAL_SIZE, WHITE);
            break;

        case SCREEN_RECORD_SCENE :
            draw_menu_symbols();

            draw_string(0,0,"Record Scene",NORMAL_SIZE, WHITE);

            if (get_menu_selected() == 0)
            {
                draw_string(8,12,"Select scene to",NORMAL_SIZE, WHITE);
                draw_string(8,20,"overwrite:",NORMAL_SIZE, WHITE);
                
            }
            else
            {

            }

            break;
        case SCREEN_FADE_TIME : 
            break;
        case SCREEN_DMX_MODE : 
            break;
        case SCREEN_LOCK_CTRLS : 
            break;

        case SCREEN_S2L_MODE : 
            break;
        case SCREEN_S2L_H_CH :
            break;
        case SCREEN_S2L_MH_CH : 
            break;
        case SCREEN_S2L_ML_CH : 
            break;
        case SCREEN_S2L_L_CH : 
            break;

        
    }
    refresh_display();
}
