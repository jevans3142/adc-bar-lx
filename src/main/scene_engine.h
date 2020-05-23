// Scene engine module
//-----------------------------------

#ifndef SCENE_ENGINE_H_INCLUDED
#define SCENE_ENGINE_H_INCLUDED

#define PIN_SCENE_LEDS_BIT_1 33
#define PIN_SCENE_LEDS_BIT_2 25
#define PIN_SCENE_LEDS_BIT_4 26

#define PIN_SCENE_LEDS_MASK  ((1ULL<<PIN_SCENE_LEDS_BIT_1) | (1ULL<<PIN_SCENE_LEDS_BIT_2) | (1ULL<<PIN_SCENE_LEDS_BIT_4) )

#define PIN_S2L_ADCS_MASK ((1ULL<<PIN_S2L_ADC_1) | (1ULL<<PIN_S2L_ADC_2) | (1ULL<<PIN_S2L_ADC_3) | (1ULL<<PIN_S2L_ADC_4))

#define SCENE_STATE_STATIC 0
#define SCENE_STATE_FADING 1

#define S2L_MODE_OFF 0
#define S2L_MODE_PULSE 1

#define NUMBER_OF_SCENES 7

#define SCENE_CALC_INTERVAL_MS ( 500 / portTICK_PERIOD_MS)

struct Scene_Engine_Settings_Struct {
    bool s2l_enable[NUMBER_OF_SCENES];
    uint8_t s2l_mode;
    uint16_t sel_low_ch;
    uint16_t sel_midlow_ch ;
    uint16_t sel_midhigh_ch;
    uint16_t sel_high_ch;
}; 

void setup_scene_mutexs(void);

void set_scene(int new_scene_no);
int get_scene(void);

//void set_scene_engine_settings(struct Scene_Engine_Settings_Struct new_Scene_Engine_Settings);
//struct Scene_Engine_Settings_Struct get_scene_engine_settings(void);

void scene_calc_task(uint8_t* output);
void record_scene(uint8_t scene_no);

#endif  