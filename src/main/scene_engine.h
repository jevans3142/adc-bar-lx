// Scene engine module
//-----------------------------------

#ifndef SCENE_ENGINE_H_INCLUDED
#define SCENE_ENGINE_H_INCLUDED

#define PIN_SCENE_LEDS_BIT_1 33
#define PIN_SCENE_LEDS_BIT_2 25
#define PIN_SCENE_LEDS_BIT_4 26

#define PIN_SCENE_LEDS_MASK  ((1ULL<<PIN_SCENE_LEDS_BIT_1) | (1ULL<<PIN_SCENE_LEDS_BIT_2) | (1ULL<<PIN_SCENE_LEDS_BIT_4) )

void setup_scene_mutexs(void);
void set_scene(int new_scene_no);
int get_scene(void);
void scene_calc_task(void);

#endif  