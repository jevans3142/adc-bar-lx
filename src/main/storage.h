// Storage module
//-----------------------------------

#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED

//Pin defs
#define PIN_SD_MISO 19
#define PIN_SD_MOSI 23 
#define PIN_SD_CLK  18
#define PIN_SD_CS   5 

void write_scene(int scene_number, uint8_t* scene_data);
int read_scene(int scene_number, uint8_t* scene_data);
void write_settings(struct Scene_Engine_Settings_Struct input);
struct Scene_Engine_Settings_Struct read_settings(void);

#endif  