// Low-level screen driver module
//-----------------------------------

#include <stdlib.h>
#include <string.h>
#include "driver/i2c.h"

#include "screen_driver.h"

SemaphoreHandle_t Display_Buffer_Mutex = NULL;
static uint8_t buffer[SH1106_LCDHEIGHT * SH1106_LCDWIDTH / 8] = { 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xe0,  0xf0,  0xf8,  0xf0,  0xf0,  0xf8,  0xfc,  0xfc,  0xfc,  0xfe,  0xfe,  0xfe,  0xfc,  0xf8,  0xf8,  0xf0,  0xe0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xc0,  0xc0,  0x40,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xf8,  0xfc,  0xfe,  0xe4,  0xf0,  0xe0,  0xc0,  0x80,  0x80,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xf0,  0xf8,  0xfc,  0xfe,  0xfc,  0xfc,  0xf8,  0x10,  0x80,  0x80,  0xc0,  0xc0,  0x80,  0x0,  0x80,  0xc0,  0xe0,  0xf8,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x1f,  0x3e,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfd,  0xf8,  0xfc,  0xff,  0xff,  0xff,  0xff,  0x3e,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xf8,  0xfc,  0xf0,  0xf0,  0xf8,  0xe0,  0x80,  0x0,  0x80,  0xc0,  0xc0,  0xe0,  0xf0,  0xfc,  0xfe,  0xff,  0xfc,  0xfe,  0x38,  0x8,  0x80,  0xe0,  0xf0,  0xe0,  0xe0,  0xe0,  0x80,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xc0,  0xe0,  0xf0,  0xf0,  0xf8,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x7f,  0x3c,  0x3c,  0x3e,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x7f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x7f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3e,  0x7e,  0x7e,  0xfe,  0xfe,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xf8,  0xf8,  0xfe,  0x7f,  0x7f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x3f,  0x7f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0x3f,  0xf,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x10,  0x7c,  0x7e,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xc3,  0x80,  0x0,  0x0,  0x0,  0x0,  0x86,  0xfe,  0xfe,  0x7e,  0x7c,  0x7c,  0x38,  0x0,  0x0,  0x0,  0x0,  0x3,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x1f,  0x7,  0x1,  0x0,  0x0,  0x0,  0x80,  0xf0,  0xf8,  0xfc,  0xfc,  0xfc,  0xf8,  0xf8,  0xf0,  0xc1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x3f,  0xf,  0x3,  0x1,  0x0,  0x0,  0x0,  0xe0,  0xf8,  0xfc,  0xfc,  0xfc,  0xfc,  0xfc,  0xc,  0x4,  0x0,  0x0,  0x0,  0x1,  0x87,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfe,  0xfe,  0xbf,  0x8c,  0xc0,  0xe0,  0x78,  0x3c,  0x18,  0x8,  0x0,  0x0,  0x0,  0x0,  0x1,  0x0,  0x0,  0x83,  0xf3,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xf,  0x7,  0x3,  0x3,  0x1,  0x1,  0x0,  0xe0,  0xf0,  0xf8,  0xf8,  0xfc,  0x7c,  0xc,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xf,  0xf,  0xf,  0xf,  0xff,  0xff,  0xff,  0xff,  0xff,  0xc0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x7,  0x3f,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x3f,  0xf,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xe0,  0x80,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x1e,  0x6,  0x6,  0x7,  0xc7,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x3f,  0x1f,  0x7,  0x3,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x80,  0xe0,  0xf8,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfc,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe0,  0xe1,  0xf1,  0xf1,  0xf0,  0xf8,  0xfc,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe1,  0xf0,  0xf0,  0xf8,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfc,  0xf8,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe0,  0xe0,  0xf0,  0xf0,  0xf8,  0xfc,  0xf0,  0xf0,  0xf0,  0xf0,  0xf0,  0xf0,  0xf0,  0xf1,  0xf1,  0xf1,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xfe,  0xfc,  0xf8,  0xf8,  0xf0,  0xf0,  0xe0,  0xe0,  0xe0,  0xe1,  0xe1,  0xe0,  0xf0,  0xf0,  0xf8,  0xf8,  0xfc,  0xfe,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x3f,  0xf,  0x3,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x8,  0xe,  0xf,  0x1f,  0x3f,  0x1f,  0xf,  0xcf,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x1f,  0xf,  0x3,  0x3,  0x3,  0x1f,  0x1f,  0x7f,  0x7f,  0x7f,  0x3f,  0x1f,  0x9f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x7f,  0x1f,  0xf,  0x3,  0x1,  0x0,  0x0,  0x3,  0x3,  0x7,  0xf,  0x1f,  0x1f,  0x3f,  0x3f,  0x7f,  0xff,  0xff,  0x7f,  0xff,  0x3f,  0xf,  0xf,  0x1f,  0x1f,  0x3f,  0x7f,  0x7f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x3f,  0x1f,  0x1f,  0x7f,  0x3f,  0x1f,  0x3f,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x3f,  0xf,  0xf,  0xf,  0x3f,  0x3f,  0x3f,  0x7f,  0x3f,  0x3f,  0x7f,  0x7f,  0x7f,  0xff,  0xff,  0x1f,  0x7,  0x1,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x3,  0x1,  0x1,  0x1,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x2,  0x3,  0x3,  0xf,  0x1f,  0x7,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1,  0x0,  0x1,  0x1,  0x7,  0x7,  0xf,  0x1f,  0x1f,  0x7,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1,  0x1,  0x3,  0x3,  0x7,  0xf,  0xf,  0xf,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};

static const uint8_t oled_font6x8[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
    0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, // !
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, // "
    0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14, // #
    0x78, 0x7E, 0x49, 0x49, 0x7E, 0x78, // $ - Altered to padlock icon
    0x00, 0x62, 0x64, 0x08, 0x13, 0x23, // %
    0x00, 0x36, 0x49, 0x55, 0x22, 0x50, // &
    0x00, 0x00, 0x05, 0x03, 0x00, 0x00, // '
    0x00, 0x00, 0x1c, 0x22, 0x41, 0x00, // (
    0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, // )
    0x00, 0x14, 0x08, 0x3E, 0x08, 0x14, // *
    0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, // +
    0x00, 0x00, 0x00, 0xA0, 0x60, 0x00, // ,
    0x00, 0x08, 0x08, 0x08, 0x08, 0x08, // -
    0x00, 0x00, 0x60, 0x60, 0x00, 0x00, // .
    0x00, 0x20, 0x10, 0x08, 0x04, 0x02, // /
    0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
    0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, // 1
    0x00, 0x42, 0x61, 0x51, 0x49, 0x46, // 2
    0x00, 0x21, 0x41, 0x45, 0x4B, 0x31, // 3
    0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, // 4
    0x00, 0x27, 0x45, 0x45, 0x45, 0x39, // 5
    0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
    0x00, 0x01, 0x71, 0x09, 0x05, 0x03, // 7
    0x00, 0x36, 0x49, 0x49, 0x49, 0x36, // 8
    0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, // 9
    0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // :
    0x00, 0x00, 0x56, 0x36, 0x00, 0x00, // ;
    0x00, 0x08, 0x14, 0x22, 0x41, 0x00, // <
    0x00, 0x14, 0x14, 0x14, 0x14, 0x14, // =
    0x00, 0x00, 0x41, 0x22, 0x14, 0x08, // >
    0x00, 0x02, 0x01, 0x51, 0x09, 0x06, // ?
    0x00, 0x32, 0x49, 0x59, 0x51, 0x3E, // @
    0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, // A
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, // B
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, // C
    0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, // D
    0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, // E
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, // F
    0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A, // G
    0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, // H
    0x00, 0x00, 0x41, 0x7F, 0x41, 0x00, // I
    0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, // J
    0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, // K
    0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, // L
    0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
    0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, // N
    0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, // O
    0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, // P
    0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
    0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, // R
    0x00, 0x46, 0x49, 0x49, 0x49, 0x31, // S
    0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, // T
    0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, // U
    0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, // V
    0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, // W
    0x00, 0x63, 0x14, 0x08, 0x14, 0x63, // X
    0x00, 0x07, 0x08, 0x70, 0x08, 0x07, // Y
    0x00, 0x61, 0x51, 0x49, 0x45, 0x43, // Z
    0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, // [
    0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55, // backslash
    0x00, 0x00, 0x41, 0x41, 0x7F, 0x00, // ]
    0x00, 0x7F, 0x3E, 0x1C, 0x08, 0x00, // ^ - Altered to side arrow
    0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // _
    0x00, 0x00, 0x01, 0x02, 0x04, 0x00, // '
    0x00, 0x20, 0x54, 0x54, 0x54, 0x78, // a
    0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, // b
    0x00, 0x38, 0x44, 0x44, 0x44, 0x20, // c
    0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, // d
    0x00, 0x38, 0x54, 0x54, 0x54, 0x18, // e
    0x00, 0x08, 0x7E, 0x09, 0x01, 0x02, // f
    0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
    0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, // h
    0x00, 0x00, 0x44, 0x7D, 0x40, 0x00, // i
    0x00, 0x40, 0x80, 0x84, 0x7D, 0x00, // j
    0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, // k
    0x00, 0x00, 0x41, 0x7F, 0x40, 0x00, // l
    0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, // m
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x78, // n
    0x00, 0x38, 0x44, 0x44, 0x44, 0x38, // o
    0x00, 0xFC, 0x24, 0x24, 0x24, 0x18, // p
    0x00, 0x18, 0x24, 0x24, 0x18, 0xFC, // q
    0x00, 0x7C, 0x08, 0x04, 0x04, 0x08, // r
    0x00, 0x48, 0x54, 0x54, 0x54, 0x20, // s
    0x00, 0x04, 0x3F, 0x44, 0x40, 0x20, // t
    0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C, // u
    0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, // v
    0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, // w
    0x00, 0x44, 0x28, 0x10, 0x28, 0x44, // x
    0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // y
    0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, // z
    0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, // { - Altered to 'hamburger' menu 
    0x60, 0xC0, 0xE0, 0x78, 0x1E, 0x06, // ¦ - Altered to tick icon 
    0x08, 0x0C, 0x7E, 0x7E, 0x0C, 0x08, // } - Altered to up arrow
    0x10, 0x30, 0x7E, 0x7E, 0x30, 0x10, // ~ - Altered to down arrow
    0x38, 0x3E, 0x49, 0x49, 0x3E, 0x38, // ü - Altered to padlock icon
    0x00, 0x3D, 0x40, 0x40, 0x40, 0x3D, // Ü
    0x00, 0x21, 0x54, 0x54, 0x54, 0x79, // ä
    0x00, 0x7D, 0x12, 0x11, 0x12, 0x7D, // Ä
    0x00, 0x39, 0x44, 0x44, 0x44, 0x39, // ö
    0x00, 0x3D, 0x42, 0x42, 0x42, 0x3D, // Ö
    0x00, 0x02, 0x05, 0x02, 0x00, 0x00, // °
    0x00, 0x7E, 0x01, 0x49, 0x55, 0x73, // ß
};


static esp_err_t i2c_init(void)
{
    int i2c_master_port = I2C_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = PIN_I2C_SDA;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = PIN_I2C_SCL;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_FREQ;
    i2c_param_config(i2c_master_port, &conf);
    return i2c_driver_install(i2c_master_port, conf.mode, I2C_RX_BUFFER, I2C_TX_BUFFER, 0);
}

static void display_command(uint8_t c) 
{
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, I2C_DISPLAY_ADDRESS << 1 | I2C_WRITE_BIT, I2C_ACK_CHECK_EN); 
    i2c_master_write_byte(cmd, 0x00, I2C_ACK_CHECK_EN);
    i2c_master_write_byte(cmd, c, I2C_ACK_CHECK_EN);
    i2c_master_stop(cmd);
    i2c_master_cmd_begin(I2C_NUM, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
}

void setup_display_mutexs(void)
{
    Display_Buffer_Mutex = xSemaphoreCreateMutex();
}

void refresh_display(void)
{
    display_command(SH1106_SETLOWCOLUMN | 0x0);  // low col = 0
    display_command(SH1106_SETHIGHCOLUMN | 0x0);  // hi col = 0
    display_command(SH1106_SETSTARTLINE | 0x0); // line #0

    int height= 64;
	int width=132; //2 pixel overrun to either side 
	int m_row = 0;
	int m_col = 2;
	
	height >>= 3;
	width >>= 3;
	
	int p = 0;
	
	int i, j, k =0;

    if( Display_Buffer_Mutex != NULL )
    {
        if( xSemaphoreTake( Display_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {
            
	        for ( i = 0; i < height; i++)
            {
		
		        // send a bunch of data in one xmission
                display_command(0xB0 + i + m_row);//set page address
                display_command(m_col & 0xf);//set lower column address
                display_command(0x10 | (m_col >> 4));//set higher column address
		
                for( j = 0; j < 8; j++)
                {        
			        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
                    i2c_master_start(cmd);
                    i2c_master_write_byte(cmd, I2C_DISPLAY_ADDRESS << 1 | I2C_WRITE_BIT, I2C_ACK_CHECK_EN); 
                    i2c_master_write_byte(cmd, 0x40, I2C_ACK_CHECK_EN);
                    for ( k = 0; k < width; k++, p++) 
                    {
		                i2c_master_write_byte(cmd, buffer[p], I2C_ACK_CHECK_EN);
                    }
                    i2c_master_stop(cmd);
                    i2c_master_cmd_begin(I2C_NUM, cmd, 1000 / portTICK_RATE_MS);
                    i2c_cmd_link_delete(cmd);
                }
	        }

           xSemaphoreGive( Display_Buffer_Mutex );
        }
    }
}

void enable_display(void)
{
    ESP_ERROR_CHECK(i2c_init());
    
    //TODO: document this set of magic and tidy up 

    display_command(0xAE);

    display_command(0xD5);
    display_command(0x80);

    display_command(0xA8);
    display_command(0x3F);

    display_command(0xD3);
    display_command(0x00);

    display_command(0x40);

    display_command(0x8D);
    display_command(0x10);

    display_command(0xA4);
    display_command(0xAF);

    refresh_display();
}

void reenable_display(void)
{
    display_command(0xAF);
}

void disable_display(void)
{
    display_command(0xAE);
}

void clear_display(void)
{
    if( Display_Buffer_Mutex != NULL )
    {
        if( xSemaphoreTake( Display_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {      
            memset(buffer, 0, (SH1106_LCDWIDTH*SH1106_LCDHEIGHT/8));
            xSemaphoreGive( Display_Buffer_Mutex );
        }
    }
}

void draw_pixel(int16_t x, int16_t y, uint16_t type)
{
    if( Display_Buffer_Mutex != NULL )
    {
        if( xSemaphoreTake( Display_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {      
            if ((x < 0) || (x >= SH1106_LCDWIDTH ) || (y < 0) || (y >= SH1106_LCDHEIGHT)) 
            { 
                xSemaphoreGive( Display_Buffer_Mutex );
                return; 
            }
            
            switch (type) 
            {
            case WHITE:   
                buffer[x+ (y/8)*SH1106_LCDWIDTH] |=  (1 << (y&7)); 
                break;
            case BLACK:   
                buffer[x+ (y/8)*SH1106_LCDWIDTH] &= ~(1 << (y&7)); 
                break; 
            case INVERT:  
                buffer[x+ (y/8)*SH1106_LCDWIDTH] ^=  (1 << (y&7)); 
                break; 
            }

            xSemaphoreGive( Display_Buffer_Mutex );
        }
    }

}

void draw_line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t type)
{  
    int16_t dx, dy, sx, sy, err, e2;

    dx = abs(x2-x1);
    if (x1<x2) { sx = 1; } else { sx = -1; }
    dy = -abs(y2-y1);
    if (y1<y2) { sy = 1; } else { sy = -1; }
    err = dx+dy;  /* error value e_xy */
    while (true)
    {
        if (x1==x2 && y1==y2) { break; }
        e2 = 2*err;
        if (e2 >= dy)
        { 
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y1 += sy;
        }
        draw_pixel(x1,y1,type);
    }
}

void draw_rect(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t outline, uint16_t fill)
{
    int16_t sx, sy, x, y;

    if (x1<x2) { sx = 1; } else { sx = -1; }
    if (y1<y2) { sy = 1; } else { sy = -1; }
    
    draw_line(x1,y1,x1,y2,outline);
    draw_line(x1,y1,x2,y1,outline);
    draw_line(x2,y2,x1,y2,outline);
    draw_line(x2,y2,x2,y1,outline);

    if (fill != LEAVE)
    {
        for ( x = x1 + sx; x != x2; x=x+sx) 
        {
            for ( y = y1 + sy; y != y2; y=y+sy) 
            {
                draw_pixel(x,y,fill);
            }
        }
    }

}

void static draw_byte(uint_fast8_t x, uint_fast8_t y, uint8_t b, uint8_t type)
{
    if( Display_Buffer_Mutex != NULL )
    {
        if( xSemaphoreTake( Display_Buffer_Mutex, ( TickType_t ) 10 ) == pdTRUE )
        {  

            if ((x < 0) || (x >= SH1106_LCDWIDTH ) || (y < 0) || (y >= SH1106_LCDHEIGHT)) 
            { 
                xSemaphoreGive( Display_Buffer_Mutex );
                return; 
            }

            uint_fast16_t buffer_index = y / 8 * SH1106_LCDWIDTH + x;

            //TODO - handle different draw types - assumes white only for now
        
            // If the y position matches a page, then easy mode:
            if (y % 8 == 0)
            {
                if (buffer_index < (SH1106_LCDHEIGHT * SH1106_LCDWIDTH / 8))
                {
                    buffer[buffer_index] |= b;
                }
            }
            else
            {
                uint16_t w = (uint16_t) b << (y % 8);
                if (buffer_index < (SH1106_LCDHEIGHT * SH1106_LCDWIDTH / 8))
                {
                    buffer[buffer_index] |= (w & 0xFF);
                }
                uint16_t buffer_index2 = buffer_index + SH1106_LCDWIDTH;
                if (buffer_index2 < (SH1106_LCDHEIGHT * SH1106_LCDWIDTH / 8))
                {
                    buffer[buffer_index2] |= (w >> 8);
                }
            }
            xSemaphoreGive( Display_Buffer_Mutex );
        }
    }
}

void static draw_bytes(uint_fast8_t x, uint_fast8_t y, const uint8_t* data, uint_fast8_t size, uint_fast8_t scaling, uint_fast8_t type)
{
    for (uint_fast8_t column = 0; column < size; column++)
    {
        uint8_t b;
        
        b = *data;
        
        data++;
        if (scaling == DOUBLE_SIZE)
        {
            // Stretch vertically
            uint16_t w = 0;
            for (uint_fast8_t bit = 0; bit < 8; bit++)
            {
                if (b & (1 << bit))
                {
                    uint_fast8_t pos = bit << 1;
                    w |= ((1 << pos) | (1 << (pos + 1)));
                }
            }

            // Output 2 times to stretch horizontally            
            draw_byte(x, y, w & 0xFF, type);
            draw_byte(x, y + 8, (w >> 8), type);
            x++;
            draw_byte(x, y, w & 0xFF, type);
            draw_byte(x, y + 8, (w >> 8), type);
            x++;
        }
        else // NORMAL_SIZE
        {
            draw_byte(x++, y, b, type);
        }
    }
}

void static draw_character(uint_fast8_t x, uint_fast8_t y, char c, uint_fast8_t scaling, uint_fast8_t type)
{
    // Invalid position
    if (x >= SH1106_LCDWIDTH || y >= SH1106_LCDHEIGHT || c < 32)
    {
        return;
    }
    uint16_t font_index = (c - 32)*6;

    // Invalid character code/font index
    if (font_index >= sizeof (oled_font6x8))
    {
        return;
    }

    draw_bytes(x, y, &oled_font6x8[font_index], 6, scaling, type);
}

void draw_string(uint_fast8_t x, uint_fast8_t y, const char* s, uint_fast8_t scaling, uint_fast8_t type)
{
    while (*s)
    {
        draw_character(x, y, *s, scaling, type);
        if (scaling == DOUBLE_SIZE)
        {
            x += 11;
        }
        else // NORMAL_SIZE
        {
            x += 6;
        }
        s++;
    }
}
