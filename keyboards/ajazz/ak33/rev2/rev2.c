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

#include "rev2.h"

led_config_t g_led_config = { {
    {   0, NO_LED,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13,     14  },
    {  15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28, NO_LED,     29  },
    {  30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43, NO_LED,     44  },
    {  45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56, NO_LED,     57, NO_LED,     58  },
    {  59, NO_LED,     60,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     71, NO_LED,     72  },
    {  73,     74,     75, NO_LED, NO_LED, NO_LED,     76, NO_LED, NO_LED, NO_LED,     77,     78,     79,     80, NO_LED,     81  }
}, {
    {3  ,  0},            {21 ,  0}, {36 ,  0}, {51 ,  0}, {66 ,  0}, {81 ,  0}, {96 ,  0}, {111,  0}, {126,  0}, {141,  0}, {156,  0}, {171,  0}, {186,  0}, {201,  0}, {221,  0},
    {0  , 17}, {15 , 17}, {30 , 17}, {45 , 17}, {60 , 17}, {75 , 17}, {90 , 17}, {105, 17}, {120, 17}, {135, 17}, {150, 17}, {165, 17}, {180, 17}, {202, 17},            {224, 17},
    {3  , 29}, {21 , 29}, {36 , 29}, {51 , 29}, {66 , 29}, {81 , 29}, {96 , 29}, {111, 29}, {126, 29}, {141, 29}, {156, 29}, {171, 29}, {186, 29}, {205, 29},            {224, 29},
    {5  , 41}, {25 , 41}, {40 , 41}, {55 , 41}, {70 , 41}, {85 , 41}, {100, 41}, {115, 41}, {130, 41}, {145, 41}, {160, 41}, {175, 41},            {200, 41},            {224, 41},
    {8  , 52},            {31 , 52}, {46 , 52}, {61 , 52}, {76 , 52}, {91 , 52}, {106, 52}, {121, 52}, {136, 52}, {151, 52}, {166, 52}, {188, 52}, {205, 52},            {222, 52},
    {2  , 64}, {19 , 64}, {36 , 64},                                  {96 , 64},                                  {149, 64}, {166, 64}, {188, 64}, {205, 64},            {222, 64},
}, {
   1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
   4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    4,
   1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4,
   8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,    4,
   1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4,    4,
   1, 1, 1,          4,          1, 1, 4, 4,    4,
} };
