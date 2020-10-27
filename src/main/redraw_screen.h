// Screen interface draw module
//-----------------------------------

#ifndef SCREEN_REDRAW_H_INCLUDED
#define SCREEN_REDRAW_H_INCLUDED

#define DISPLAY_ACTIVE_INTERVAL_MS ( 1000 / portTICK_PERIOD_MS)

#define S2L_REFRESH_INTERVAL_MS ( 100 / portTICK_PERIOD_MS)

#define MAX_STRING_LENGTH 20

//Define screen IDs 

#define SCREEN_MAIN_STATUS 0
#define SCREEN_MAIN_MENU 1

#define SCREEN_RECALL_SCENE 10
#define SCREEN_RECORD_SCENE 11
#define SCREEN_FADE_TIME 12
#define SCREEN_S2L_MENU 13
#define SCREEN_DMX_MODE 14
#define SCREEN_LOCK_CTRLS 15
#define SCREEN_ABOUT 16

#define SCREEN_S2L_MODE 20
#define SCREEN_S2L_ENABLE 21
#define SCREEN_S2L_H_CH 22
#define SCREEN_S2L_MH_CH 23
#define SCREEN_S2L_ML_CH 24
#define SCREEN_S2L_L_CH 25

#define SCREEN_RECORD_CONFIRM 98
#define SCREEN_UNLOCK_CTRLS 99

//-------

void setup_menu_mutexs(void);

void display_timeout_task(void);
int get_display_active_status(void);
int reset_display_active_status(void);

void set_screen(int screen_no, int new_menu_selected);
int get_screen(void);

void set_screen_selected_value(int new_screen_selected_value);
void set_screen_selected_value_dec(int upper_bound, int lower_bound);
void set_screen_selected_value_inc(int upper_bound, int lower_bound);
int get_screen_selected_value(void);

void set_lock_code(int new_lock_code);
int get_lock_code(void);

void s2l_meter_refresh_task(void);

void redraw_screen(int screen_no);



#endif  