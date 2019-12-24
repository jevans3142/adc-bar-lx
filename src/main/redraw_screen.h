// Screen interface draw module
//-----------------------------------

#ifndef SCREEN_REDRAW_H_INCLUDED
#define SCREEN_REDRAW_H_INCLUDED

void setup_menu_mutexs(void);
void set_screen(int screen_no);
int get_screen(void);
void redraw_screen(int screen_no);

#endif  