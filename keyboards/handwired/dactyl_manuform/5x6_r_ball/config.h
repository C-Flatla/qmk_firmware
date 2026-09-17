#pragma once

#define EE_HANDS

/* Matrix */
#define MATRIX_ROW_PINS { GP2, GP3, GP4, GP5, GP6, GP7 }
#define MATRIX_COL_PINS { GP8, GP9, GP26, GP27, GP28, GP29 }

/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader

/* Trackball */
#define SPI_SCK_PIN GP18
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP19
#define PMW33XX_CS_PIN GP10

/* Sensor tuning (stock pmw3360 driver; set at init) */
// #define POINTING_DEVICE_DEBUG
#define PMW33XX_CPI 1600                  // 100-12000, increments of 100. Default 1600.
#define MOUSE_EXTENDED_REPORT             // Use -32767 to 32767, instead of just -127 to 127.
#define POINTING_DEVICE_INVERT_X          // Invert left/right movement
// #define PMW33XX_LIFTOFF_DISTANCE 0x02  // PixArt default; sensor sets is_lifted when ball is away from lens.
// #define PMW33XX_CLOCK_SPEED 2000000    // Default 2000000
// #define PMW33XX_SPI_DIVISOR 64         // Default varies by platform
// #define POINTING_DEVICE_TASK_THROTTLE_MS 10
