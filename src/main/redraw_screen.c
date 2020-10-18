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
SemaphoreHandle_t Screen_Selected_Value_Mutex = NULL;
int Screen_Selected_Value = 0;  
SemaphoreHandle_t Display_Active_Mutex = NULL;
int Display_Active = 1; 
SemaphoreHandle_t Menu_Locked_Mutex = NULL;
int Menu_Locked_Code = 0; 
unsigned long Display_Active_Timeout = 0;

//String buffer we can use for rendering data

char string_buffer[MAX_STRING_LENGTH];

//Scene names 

const char *scene_names[] = { "Daytime", "Evening 1", "Evening 2", "Party", "Show", "Special", "Off" }; 

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

static void draw_standard_value_screen(const char* title, const char* line1, const char* line2)
{
    draw_string(120,8,"{",NORMAL_SIZE, WHITE);
    draw_string(120,20,"|",NORMAL_SIZE, WHITE);
    draw_string(120,34,"+",NORMAL_SIZE, WHITE);
    draw_string(120,48,"-",NORMAL_SIZE, WHITE);

    draw_string(0,0,title,NORMAL_SIZE, WHITE);

    draw_string(8,12,line1,NORMAL_SIZE, WHITE);
    draw_string(8,20,line2,NORMAL_SIZE, WHITE);

    sprintf(string_buffer,"%u",get_screen_selected_value());
    draw_string(16,32,&string_buffer,DOUBLE_SIZE, BLACK);
}

void setup_menu_mutexs(void)
{
    Screen_No_Mutex = xSemaphoreCreateMutex();
    Display_Active_Mutex = xSemaphoreCreateMutex();
    Screen_Selected_Value_Mutex = xSemaphoreCreateMutex();
    Menu_Locked_Mutex = xSemaphoreCreateMutex();

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

//========================
//SCREEN SELECTED

//TODO: better exception handling here 
void set_screen(int new_screen_no, int new_screen_selected)
{
    if( Screen_No_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_No_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            set_screen_selected_value(new_screen_selected);
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

//========================
//SCREEN SELECTED VALUE 

void set_screen_selected_value(int new_screen_selected_value)
{
    if( Screen_Selected_Value_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_Selected_Value_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            Screen_Selected_Value = new_screen_selected_value;
            xSemaphoreGive( Screen_Selected_Value_Mutex );
        }
    }
}

void set_screen_selected_value_dec(int upper_bound, int lower_bound)
{
    if( Screen_Selected_Value_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_Selected_Value_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            if (Screen_Selected_Value<=lower_bound)
            {
                Screen_Selected_Value = upper_bound;
            }
            else
            {
                Screen_Selected_Value--;
            }
            xSemaphoreGive( Screen_Selected_Value_Mutex );
        }
    }
}

void set_screen_selected_value_inc(int upper_bound, int lower_bound)
{
    if( Screen_Selected_Value_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_Selected_Value_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            if (Screen_Selected_Value<upper_bound)
            {
                Screen_Selected_Value++;
            }
            else
            {
                Screen_Selected_Value = lower_bound;
            }
            xSemaphoreGive( Screen_Selected_Value_Mutex );
        }
    }
}

int get_screen_selected_value(void)
{
    if( Screen_Selected_Value_Mutex != NULL )
    {
        if( xSemaphoreTake( Screen_Selected_Value_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            int returnval = Screen_Selected_Value;
            xSemaphoreGive( Screen_Selected_Value_Mutex );
            return returnval;
        }
    }
    return NULL;
}

//========================
// Screen lock code

void set_lock_code(int new_lock_code)
{
    if( Menu_Locked_Mutex != NULL )
    {
        if( xSemaphoreTake( Menu_Locked_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            Menu_Locked_Code = new_lock_code;
            xSemaphoreGive( Menu_Locked_Mutex );
        }
    }
}

int get_lock_code(void)
{
    if( Menu_Locked_Mutex != NULL )
    {
        if( xSemaphoreTake( Menu_Locked_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            int returnval = Menu_Locked_Code;
            xSemaphoreGive( Menu_Locked_Mutex );
            return returnval;
        }
    }
    return NULL;
}

//========================

void redraw_screen(int screen_no)
{
    clear_display();

    switch (screen_no)
    {
        case SCREEN_MAIN_STATUS :
            draw_line(0,28,128,28, WHITE);
            draw_line(64,28,64,64, WHITE);
            sprintf(string_buffer,"%u",get_scene());
            draw_string(8,12,&string_buffer,NORMAL_SIZE, WHITE);
            draw_rect(6,10,14,20, WHITE, LEAVE);
            draw_string(16,8,scene_names[get_scene()-1],DOUBLE_SIZE, WHITE);
            
            draw_string(70,30,"Audio in",NORMAL_SIZE, WHITE);
            draw_string(12,30,"DMX in",NORMAL_SIZE, WHITE);
            switch (get_scene_engine_settings().dmx_input_mode)
            {
                case DMX_MODE_OFF :
                    draw_string(12,40,"OFF",DOUBLE_SIZE, WHITE);
                    break;
                case DMX_MODE_HTP :
                    draw_string(12,40,"HTP",DOUBLE_SIZE, WHITE);
                    break;
            }
            
            if (get_lock_code()!=0)
            {
                draw_string(120,8,"$",NORMAL_SIZE, WHITE); // Actually the padlock icon
            }
            else 
            {
                draw_string(120,8,"{",NORMAL_SIZE, WHITE); // Actually the menu icon
            }
            break;  

        case SCREEN_MAIN_MENU :
            draw_menu_symbols();

            if (get_screen_selected_value()<5) 
            {
                draw_string(0,0,"Main Menu 1/2",NORMAL_SIZE, WHITE);
                draw_string(8,16,"Recall Scene",NORMAL_SIZE, WHITE);
                draw_string(8,24,"Record Scene",NORMAL_SIZE, WHITE);
                draw_string(8,32,"Fade Time",NORMAL_SIZE, WHITE);
                draw_string(8,40,"Sound To Light...",NORMAL_SIZE, WHITE);
                draw_string(8,48,"DMX Input Mode",NORMAL_SIZE, WHITE);
                draw_string(8,56,"~",NORMAL_SIZE, WHITE); //Down arrow
                
                draw_string(0,(16+8*get_screen_selected_value()),"^",NORMAL_SIZE, WHITE); //Menu cursor
            }
            else
            {
                draw_string(0,0,"Main Menu 2/2",NORMAL_SIZE, WHITE);
                draw_string(8,16,"Lock Controls",NORMAL_SIZE, WHITE);
                draw_string(8,8,"}",NORMAL_SIZE, WHITE); //Up arrow 
  
                draw_string(0,(16+8*(get_screen_selected_value()-5)),"^",NORMAL_SIZE, WHITE); //Menu cursor
            }

            break;

        case SCREEN_S2L_MENU :
            draw_menu_symbols();

            draw_string(0,0,"Sound To Light Menu",NORMAL_SIZE, WHITE);

            draw_string(8,16,"Mode",NORMAL_SIZE, WHITE);
            draw_string(8,24,"High Channel",NORMAL_SIZE, WHITE);
            draw_string(8,32,"Mid-High Channel",NORMAL_SIZE, WHITE);
            draw_string(8,40,"Mid-Low Channel",NORMAL_SIZE, WHITE);
            draw_string(8,48,"Low Channel",NORMAL_SIZE, WHITE);

            //Actually the menu position cursor
            draw_string(0,(16+8*get_screen_selected_value()),"^",NORMAL_SIZE, WHITE);
            break;


        case SCREEN_RECALL_SCENE :
            draw_standard_value_screen("Recall Scene", "Select scene to", "recall:"); 
            draw_string(42,36,scene_names[get_screen_selected_value()-1],NORMAL_SIZE, WHITE);
            break;
        case SCREEN_RECORD_SCENE :
            draw_standard_value_screen("Record Scene", "Select scene to", "overwrite:"); 
            draw_string(42,36,scene_names[get_screen_selected_value()-1],NORMAL_SIZE, WHITE);  
            break;        
        case SCREEN_RECORD_CONFIRM :
            draw_string(0,0,"Record Scene",NORMAL_SIZE, WHITE);
            draw_string(120,8,"{",NORMAL_SIZE, WHITE);
            draw_string(120,20,"|",NORMAL_SIZE, WHITE);

            draw_string(8,12,"Are you sure?",NORMAL_SIZE, WHITE);
            draw_string(8,28,"This scene will",NORMAL_SIZE, WHITE);
            draw_string(8,36,"be written when |",NORMAL_SIZE, WHITE);
            draw_string(8,44,"is pressed.",NORMAL_SIZE, WHITE);
            break;
        case SCREEN_FADE_TIME : 
            draw_standard_value_screen("Fade time", "Select new", "fade time:");
            draw_string(42,38,"seconds",NORMAL_SIZE, WHITE);
            break;
        case SCREEN_DMX_MODE :
            draw_menu_symbols();

            draw_string(0,0,"DMX Mode",NORMAL_SIZE, WHITE);

            draw_string(8,12,"Select new",NORMAL_SIZE, WHITE);
            draw_string(8,20,"DMX input mode:",NORMAL_SIZE, WHITE);

            switch (get_screen_selected_value())
            {
                case DMX_MODE_OFF :
                    draw_string(16,32,"Off",DOUBLE_SIZE, BLACK); 
                    break;
                case DMX_MODE_HTP : 
                    draw_string(16,32,"HTP",DOUBLE_SIZE, BLACK); 
                    break;
            }
            break;
        case SCREEN_LOCK_CTRLS : 
            draw_standard_value_screen("Lock Controls", "Select a lock", "code:");
            break;

        case SCREEN_S2L_MODE : 
            draw_menu_symbols();

            draw_string(0,0,"S2L Mode",NORMAL_SIZE, WHITE);

            draw_string(8,12,"Select new",NORMAL_SIZE, WHITE);
            draw_string(8,20,"Sound-to-light mode:",NORMAL_SIZE, WHITE);

            switch (get_screen_selected_value())
            {
                case S2L_MODE_OFF :
                    draw_string(16,32,"Off",DOUBLE_SIZE, BLACK); 
                    break;
                case S2L_MODE_PULSE : 
                    draw_string(16,32,"Pulse",DOUBLE_SIZE, BLACK); 
                    break;
            }
            break;
        case SCREEN_S2L_H_CH :
            draw_standard_value_screen("S2L High Ch", "Select new", "DMX channel:");
            break;
        case SCREEN_S2L_MH_CH : 
            draw_standard_value_screen("S2L Mid-High Ch", "Select new", "DMX channel:");
            break;
        case SCREEN_S2L_ML_CH : 
            draw_standard_value_screen("S2L Mid-Low Ch", "Select new", "DMX channel:");
            break;
        case SCREEN_S2L_L_CH : 
            draw_standard_value_screen("S2L Low Ch", "Select new", "DMX channel:");
            break;

        case SCREEN_UNLOCK_CTRLS : 
            draw_standard_value_screen("Unlock Controls", "Enter the lock", "code:");
            break;
        
    }
    refresh_display();
}