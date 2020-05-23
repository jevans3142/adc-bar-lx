// Storage module
//-----------------------------------

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdspi_host.h"
#include "sdmmc_cmd.h"

#include "storage.h"

static const char *TAG = "storage";

static void init_sd_card()
{
    //ESP_LOGI(TAG, "Initializing SD card");

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    sdspi_slot_config_t slot_config = SDSPI_SLOT_CONFIG_DEFAULT();
    host.slot = VSPI_HOST;
    slot_config.gpio_miso = PIN_SD_MISO;
    slot_config.gpio_mosi = PIN_SD_MOSI;
    slot_config.gpio_sck  = PIN_SD_CLK;
    slot_config.gpio_cs   = PIN_SD_CS;

    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024
    };

    sdmmc_card_t* card;
    esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount filesystem. "
                "If you want the card to be formatted, set format_if_mount_failed = true.");
        } else {
            ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
        }
        return;
    }

    sdmmc_card_print_info(stdout, card);
}

static void deinit_sd_card(void)
{
    esp_vfs_fat_sdmmc_unmount();
    ESP_LOGI(TAG, "Card unmounted");
}

void write_scene(int scene_number, uint8_t* scene_data)
{
    init_sd_card();

    ESP_LOGI(TAG, "Opening file");
    char filename[sizeof "/sdcard/000.scn"];
    sprintf(filename, "/sdcard/%03u.scn",scene_number); 
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }

    for(int i=0; i<513;i++)
    {
        fprintf(f, "%u\n", *scene_data);
        scene_data++;
    }
    
    fclose(f);
    ESP_LOGI(TAG, "File written");
    deinit_sd_card();

}

int read_scene(int scene_number, uint8_t* scene_data)
{
    init_sd_card();

    ESP_LOGI(TAG, "Opening file");
    char filename[sizeof "/sdcard/000.scn"];
    sprintf(filename, "/sdcard/%03u.scn",scene_number); 
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return 0;
    }

    for(int i=0; i<513;i++)
    {
        char line[5];
        fgets(line, sizeof(line), f);
        // strip newline
        char* pos = strchr(line, '\n');
        if (pos) 
        {
            *pos = '\0';
        }
        *scene_data = (uint8_t)atoi(line);
        scene_data++;
    }
    
    fclose(f);
    ESP_LOGI(TAG, "File read");
    deinit_sd_card();
    return 1;
}