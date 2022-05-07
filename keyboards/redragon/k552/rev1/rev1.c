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
    {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12, NO_LED,     13,     14,     15 },
    { 16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     30,     31,     32 },
    { 33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44,     45,     46,     47,     48,     49 },
    { 50,     51,     52,     53,     54,     55,     56,     57,     58,     59,     60,     61,     62,     63, NO_LED, NO_LED, NO_LED },
    { 64,     65,     66,     67,     68,     69,     70,     71,     72,     73,     74,     75,     76,     77, NO_LED,     78, NO_LED },
    { 79,     80,     81,     82,     83,     84,     85, NO_LED,     86, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,     87,     88,     89 }
}, {
    {0  ,  0}, {26 ,  0}, {39 ,  0}, {52 ,  0}, {65 ,  0}, {84 ,  0}, {97 ,  0}, {110,  0}, {123,  0}, {143,  0}, {156,  0}, {169,  0}, {182,  0},            {198,  0}, {211,  0}, {224,  0},
    {0  , 15}, {13 , 15}, {26 , 15}, {39 , 15}, {52 , 15}, {65 , 15}, {78 , 15}, {91 , 15}, {104, 15}, {117, 15}, {130, 15}, {143, 15}, {156, 15}, {175, 15}, {198, 15}, {211, 15}, {224, 15},
    {3  , 27}, {19 , 27}, {32 , 27}, {45 , 27}, {58 , 27}, {71 , 27}, {84 , 27}, {97 , 27}, {110, 27}, {123, 27}, {136, 27}, {149, 27}, {162, 27}, {179, 27}, {198, 27}, {211, 27}, {224, 27},
    {5  , 40}, {23 , 40}, {36 , 40}, {49 , 40}, {62 , 40}, {75 , 40}, {88 , 40}, {101, 40}, {114, 40}, {127, 40}, {140, 40}, {153, 40}, {166, 40}, {180, 40},
    {2  , 52}, {16 , 52}, {29 , 52}, {42 , 52}, {55 , 52}, {68 , 52}, {81 , 52}, {94 , 52}, {107, 52}, {120, 52}, {133, 52}, {146, 52}, {159, 52}, {177, 52},            {211, 52},
    {2  , 64}, {18 , 64}, {34 , 64}, {83 , 64}, {131, 64}, {148, 64}, {164, 64},            {180, 64},                                                        {198, 64}, {211, 64}, {224, 64},
}, {
   1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4,
   1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
   8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
   1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    4,
   1, 1, 1, 4, 1, 1, 1,    1,                4, 4, 4,
} };
