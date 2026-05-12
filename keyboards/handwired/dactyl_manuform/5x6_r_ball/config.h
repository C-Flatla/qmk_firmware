#pragma once

#define EE_HANDS

#define MATRIX_ROW_PINS { GP2, GP3, GP4, GP5, GP6, GP7 }
#define MATRIX_COL_PINS { GP8, GP9, GP26, GP27, GP28, GP29 }

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

// TODO: Figure out what's needed to get trackball working
// #define POINTING_DEVICE_DEBUG
// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT
// #define SPI_DRIVER SPID0
// #define SPI_SCK_PIN GP18
// #define SPI_MISO_PIN GP20
// #define SPI_MOSI_PIN GP19
#define PMW33XX_CS_PIN GP10
// #define POINTING_DEVICE_SCLK_PIN GP18
// #define POINTING_DEVICE_SDIO_PIN GP20
// #define POINTING_DEVICE_CS_PIN GP10
