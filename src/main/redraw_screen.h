// Screen interface draw module
//-----------------------------------

#ifndef SCREEN_REDRAW_H_INCLUDED
#define SCREEN_REDRAW_H_INCLUDED

#define DISPLAY_ACTIVE_INTERVAL_MS ( 1000 / portTICK_PERIOD_MS)

//Define screen IDs 

#define SCREEN_MAIN_STATUS 0
#define SCREEN_MAIN_MENU 1

#define SCREEN_RECORD_SCENE 10
#define SCREEN_FADE_TIME 11
#define SCREEN_DMX_MODE 12
#define SCREEN_S2L_MENU 13
#define SCREEN_LOCK_CTRLS 14

#define SCREEN_S2L_MODE 20
#define SCREEN_S2L_H_CH 21
#define SCREEN_S2L_MH_CH 22
#define SCREEN_S2L_ML_CH 23
#define SCREEN_S2L_L_CH 24

//-------

void setup_menu_mutexs(void);
void display_timeout_task(void);
int get_display_active_status(void);
int reset_display_active_status(void);
void set_screen(int screen_no, int new_menu_selected);
int get_screen(void);
void set_menu_selected(int new_menu_selected);
int get_menu_selected(void);
void redraw_screen(int screen_no);

#endif  