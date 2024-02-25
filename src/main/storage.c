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

#include "scene_engine.h"
#include "storage.h"

static const char *TAG = "storage";
sdmmc_card_t *card;

void init_sd_spi(void)
{

    spi_bus_config_t spi_bus_config = {
        .mosi_io_num = PIN_SD_MOSI,
        .miso_io_num = PIN_SD_MISO,
        .sclk_io_num = PIN_SD_CLK};

    spi_bus_initialize(VSPI_HOST, &spi_bus_config, 1);
}

static void init_sd_card()
{
    ESP_LOGI(TAG, "Initializing SD card");

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    host.slot = VSPI_HOST;
    slot_config.host_id = VSPI_HOST;
    slot_config.gpio_cs = PIN_SD_CS;

    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024};

    esp_err_t ret = esp_vfs_fat_sdspi_mount("/sdcard", &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
            ESP_LOGE(TAG, "Failed to mount filesystem. ");
        }
        else
        {
            ESP_LOGE(TAG, "Failed to initialize the card (%s). ", esp_err_to_name(ret));
        }
        return;
    }
}

static void deinit_sd_card(void)
{
    esp_err_t ret = esp_vfs_fat_sdcard_unmount("/sdcard", card);
    if (ret != ESP_OK)
    {
        if (ret == ESP_ERR_INVALID_ARG)
        {
            ESP_LOGE(TAG, "Failed to unmount SD card - Card unregistered.");
        }
        else
        {
            ESP_LOGE(TAG, "Failed to unmount SD card - Invalid state, no mount");
        }
        return;
    }

    ESP_LOGI(TAG, "Card unmounted");
}

void write_scene(uint8_t scene_number, uint8_t *scene_data)
{
    init_sd_card();

    ESP_LOGI(TAG, "Opening scene %i file for write", scene_number);
    char filename[sizeof "/sdcard/000.scn"];
    sprintf(filename, "/sdcard/%03u.scn", scene_number);
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Failed to open scene file for writing");
        return;
    }

    for (uint16_t i = 0; i < 513; i++)
    {
        fprintf(f, "%u\n", *scene_data);
        scene_data++;
    }

    fclose(f);
    ESP_LOGI(TAG, "File written");
    deinit_sd_card();
}

uint8_t read_scene(uint8_t scene_number, uint8_t *scene_data)
{
    init_sd_card();

    ESP_LOGI(TAG, "Opening scene %i file for read", scene_number);
    char filename[sizeof "/sdcard/000.scn"];
    sprintf(filename, "/sdcard/%03u.scn", scene_number);
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Failed to open scene file for reading");
        return 0;
    }

    for (uint16_t i = 0; i < 513; i++)
    {
        char line[5];
        fgets(line, sizeof(line), f);
        // strip newline
        char *pos = strchr(line, '\n');
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

void write_settings(struct Scene_Engine_Settings_Struct input)
{
    init_sd_card();

    ESP_LOGI(TAG, "Opening settings file for write");
    FILE *f = fopen("/sdcard/settings.stg", "w");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Failed to open settings file for writing");
        return;
    }

    fwrite(&input, sizeof(struct Scene_Engine_Settings_Struct), 1, f);

    fclose(f);
    ESP_LOGI(TAG, "Settings file written");
    deinit_sd_card();
}

struct Scene_Engine_Settings_Struct read_settings()
{
    init_sd_card();

    ESP_LOGI(TAG, "Opening settings file for read");
    FILE *f = fopen("/sdcard/settings.stg", "r");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Failed to open settings file for reading");

        // Return a 'default' settings file if SD card can't be read
        struct Scene_Engine_Settings_Struct temp;

        temp.fade_time = 5;
        temp.dmx_input_mode = 1;
        temp.s2l_mode = 0;
        temp.s2l_low_ch = 1;
        temp.s2l_midlow_ch = 2;
        temp.s2l_midhigh_ch = 3;
        temp.s2l_high_ch = 4;
        temp.colourfade_mode = 0;
        temp.colourfade_time = 10;
        temp.colourfade_r_ch = 1;
        temp.colourfade_g_ch = 2;
        temp.colourfade_b_ch = 3;

        return temp;
    }

    struct Scene_Engine_Settings_Struct temp;
    fread(&temp, sizeof(struct Scene_Engine_Settings_Struct), 1, f);

    fclose(f);
    ESP_LOGI(TAG, "File read");
    deinit_sd_card();
    return temp;
}