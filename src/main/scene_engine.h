// Scene engine module
//-----------------------------------

#ifndef SCENE_ENGINE_H_INCLUDED
#define SCENE_ENGINE_H_INCLUDED

#define PIN_SCENE_LEDS_BIT_1 33
#define PIN_SCENE_LEDS_BIT_2 25
#define PIN_SCENE_LEDS_BIT_4 26

#define PIN_SCENE_LEDS_MASK  ((1ULL<<PIN_SCENE_LEDS_BIT_1) | (1ULL<<PIN_SCENE_LEDS_BIT_2) | (1ULL<<PIN_SCENE_LEDS_BIT_4) )

#define SCENE_STATE_STATIC 0
#define SCENE_STATE_FADING 1

#define SCENE_CALC_INTERVAL_MS ( 500 / portTICK_PERIOD_MS)

void setup_scene_mutexs(void);
void set_scene(int new_scene_no);
int get_scene(void);
void transfer_scene_data(uint8_t* output);
void scene_calc_task(void);

#endif  