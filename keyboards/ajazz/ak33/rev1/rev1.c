/* Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

#include "rev1.h"

led_config_t g_led_config = { {
    {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12, NO_LED, NO_LED,  NO_LED,  NO_LED },
    { 15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28, NO_LED,      29,      44 },
    { 30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     14,      72,      58 },
    { 45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56, NO_LED,     57, NO_LED,  NO_LED,  NO_LED },
    { 59, NO_LED,     60,     61,     62,     63,     64,     65,     66,     67,     68,     69, NO_LED,     70, NO_LED,      71,  NO_LED },
    { 73,     74,     75,     76,     77,     13, NO_LED, NO_LED,     78, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,     79,      80,      81 }
}, {
    {4  ,  0}, {22 ,  0}, {37 ,  0}, {52 ,  0}, {67 ,  0}, {82 ,  0}, {97 ,  0}, {112,  0}, {127,  0}, {142,  0}, {157,  0}, {172,  0}, {187,  0},
    {202,  0}, {220,  0}, {0  , 13}, {15 , 13}, {30 , 13}, {45 , 13}, {60 , 13}, {75 , 13}, {90 , 13}, {105, 13}, {119, 13}, {134, 13}, {149, 13}, {164, 13},            {179, 13}, {202, 13},
    {224, 13}, {4  , 26}, {22 , 26}, {37 , 26}, {52 , 26}, {67 , 26}, {82 , 26}, {97 , 26}, {112, 26}, {127, 26}, {142, 26}, {157, 26}, {172, 26}, {187, 26}, {205, 26}, {224, 26}, {6  , 38},
	{26 , 38}, {41 , 38}, {56 , 38}, {71 , 38}, {86 , 38}, {101, 38}, {116, 38}, {131, 38}, {146, 38}, {161, 38}, {175, 38}, {200, 38},            {224, 38},
	{9  , 51},            {34 , 51}, {49 , 51}, {63 , 51}, {78 , 51}, {93 , 51}, {108, 51}, {123, 51}, {138, 51}, {153, 51}, {168, 51},            {185, 51},            {203, 51},
	{222, 51}, {2  , 64}, {21 , 64}, {39 , 64}, {95 , 64}, {151, 64},                       {168, 64},                                                        {185, 64}, {203, 64}, {222, 64},
}, {
   1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 1,
   4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    4,
   1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,    4,
   4, 1, 1, 1, 4, 1,       1,                4, 4, 4,
} };
