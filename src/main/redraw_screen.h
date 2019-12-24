// Screen interface draw module
//-----------------------------------

#ifndef SCREEN_REDRAW_H_INCLUDED
#define SCREEN_REDRAW_H_INCLUDED

void set_screen(int screen_no);
int get_screen(void);
void redraw_screen(int screen_no);

extern SemaphoreHandle_t Screen_No_Mutex;
extern int Screen_No;

#endif  