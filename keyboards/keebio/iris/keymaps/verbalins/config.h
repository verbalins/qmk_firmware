/*
Copyright 2019 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#endif

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCB10
#define PRODUCT_ID      0x1256
#define DEVICE_VER      0x0400
#define MANUFACTURER    Keebio
#define PRODUCT         Iris Keyboard
#define DESCRIPTION     Split 50 percent ergonomic keyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { B1, F0, F5, F6, F7 }
#define MATRIX_COL_PINS { F1, F4, D3, D2, B7, D4 }
#define MATRIX_ROW_PINS_RIGHT { B1, B2, D2, F1, F4 }
#define MATRIX_COL_PINS_RIGHT { D4, D7, D3, B7, F0, B3 }
#define SPLIT_HAND_PIN D5
#define QMK_ESC_OUTPUT F1
#define QMK_ESC_INPUT B1
#define QMK_LED B0
#define QMK_SPEAKER C6

#define ENCODER_RESOLUTION 4
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B3 }
#define ENCODERS_PAD_A_RIGHT { F7 }
#define ENCODERS_PAD_B_RIGHT { F6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5 

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

#define BACKLIGHT_PIN B5
#define BACKLIGHT_LEVELS 5

/* ws2812 RGB LED */
#define RGB_DI_PIN D6
#define RGBLED_NUM 12    // Number of LEDs
#define RGBLED_SPLIT { 6, 6 }

#define LAYOUT( \
    LA1, LA2, LA3, LA4, LA5, LA6,           RA6, RA5, RA4, RA3, RA2, RA1, \
    LB1, LB2, LB3, LB4, LB5, LB6,           RB6, RB5, RB4, RB3, RB2, RB1, \
    LC1, LC2, LC3, LC4, LC5, LC6,           RC6, RC5, RC4, RC3, RC2, RC1, \
    LD1, LD2, LD3, LD4, LD5, LD6, LE6, RE6, RD6, RD5, RD4, RD3, RD2, RD1, \
                        LE3, LE4, LE5, RE5, RE4, RE3 \
    ) \
    { \
        { LA1, LA2, LA3, LA4, LA5, LA6 }, \
        { LB1, LB2, LB3, LB4, LB5, LB6 }, \
        { LC1, LC2, LC3, LC4, LC5, LC6 }, \
        { LD1, LD2, LD3, LD4, LD5, LD6 }, \
        { KC_NO, KC_NO, LE3, LE4, LE5, LE6 }, \
        { RA1, RA2, RA3, RA4, RA5, RA6 }, \
        { RB1, RB2, RB3, RB4, RB5, RB6 }, \
        { RC1, RC2, RC3, RC4, RC5, RC6 }, \
        { RD1, RD2, RD3, RD4, RD5, RD6 }, \
        { KC_NO, KC_NO, RE3, RE4, RE5, RE6 } \
    }
