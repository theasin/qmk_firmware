/* Copyright 2021 Adam Honse <https://gitlab.com/CalcProgrammer1>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID      0x5002

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

/* Key matrix pin           0    1,   2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14, 15 */
#define MATRIX_ROW_PINS { C15, D11, D10, D9, D8, D7 }
#define MATRIX_COL_PINS {  A0,  A1,  A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, B0 }

/* Direction of diode (COL2ROW or ROW2COL) */
#define DIODE_DIRECTION COL2ROW

/* LED Indicator */
#define LED_CAPS_LOCK_PIN B14
#define LED_PIN_ON_STATE 0

/* RGB matrix size */
#define LED_MATRIX_COLS MATRIX_COLS
#define LED_MATRIX_ROWS MATRIX_ROWS
#define LED_MATRIX_ROW_CHANNELS 3
#define LED_MATRIX_ROWS_HW (LED_MATRIX_ROWS * LED_MATRIX_ROW_CHANNELS)

/* RGB matrix pin              0   1,  2,  3,  4,  5,  6,  7,  8,   9,  10,  11, 12, 13  14  15   16   17 */
#define LED_MATRIX_ROW_PINS { C0, C1, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, B6, B7, B8, B9, B10, B11 }
#define LED_MATRIX_COL_PINS MATRIX_COL_PINS

/* RGB led number */
#define DRIVER_LED_TOTAL 82
