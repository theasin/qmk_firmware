/*
Copyright 2021 Coccolith

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

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE = 0,
    _1KEY = 1,
    _FN = 2
};

enum layer_keycodes {
    RGB_S_C = SAFE_RANGE,   //Change effect to Sakura solid color
    RGB_S_R                 //Change effect to Sakura solid reactive
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
       ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
       │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
       │ Tab │ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │ [ │ ] │  \  │PgU│
       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
       │ Caps │ a │ s │ d │ f │ g │ h │ j │ k │ l │ ; │ ' │  Enter │PgD│
       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
       │ LShift │ z │ x │ c │ v │ b │ n │ m │ , │ . │ / │ RSht │ ↑ │End│
       ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
       │LCrl│GUI │LAlt│         Space          │RAlt│ Fn │ │ ← │ ↓ │ → │
       └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
       ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
       │ ~ │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ _ │ + │       │   │
       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
       │     │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ { │ } │  |  │   │
       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
       │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ : │ " │        │   │
       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
       │ LShift │ Z │ X │ C │ V │ B │ N │ M │ < │ > │ ? │ RSht │   │   │
       ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
       │    │    │    │                        │    │    │ │   │   │   │
       └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
       ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
       │ ` │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
       │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
       │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
       │        │   │   │   │   │   │   │   │   │   │   │      │   │   │
       ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
       │    │GUI │    │                        │    │    │ │   │   │   │
       └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
*/
    /*  Row:    0        1        2        3     4     5       6     7     8        9       10       11       12       13       14     */
    [_BASE] = LAYOUT_65_ansi_blocker(
                KC_GESC, KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
                KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
                KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
                KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
                KC_LCTL, KC_LGUI, KC_LALT,             KC_SPC,             KC_RALT,         MO(_FN), KC_LEFT,          KC_DOWN, KC_RIGHT
             ),

    [_1KEY] = LAYOUT_65_ansi_blocker(
                KC_GESC, KC_1,    KC_2,    KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
                KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
                KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
                KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
                KC_LCTL, KC_LGUI, KC_LALT,             KC_SPC,             KC_RALT,         MO(_FN), KC_LEFT,          KC_DOWN, KC_RIGHT
             ),

/*
       ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
       │Rst│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Delete│   │
       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
       │E_Rst│Tog│Mod│Hui│Hud│Sai│Sad│Vai│Vad│   │PSc│Scr│Pse│     │   │
       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
       │ NKRO │Spi│Spd│   │   │   │   │   │   │   │   │   │        │   │
       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
       │        │   │   │   │   │   │   │   │S_C│S_R│1Ky│      │VoU│Mut│
       ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
       │    │    │    │                        │    │ Fn │ │Prv│VoD│Nxt│
       └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
*/
    /*  Row:    0        1        2        3        4        5        6        7        8        9        10         11       12       13       14     */
    [_FN] = LAYOUT_65_ansi_blocker( 
                RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,  KC_F12,  KC_DEL,  KC_TRNS,
                EEP_RST, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR,   KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS,
                NK_TOGG, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_S_C, RGB_S_R, TG(_1KEY), KC_TRNS,          KC_VOLU, KC_MUTE,
                KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                   KC_TRNS,          KC_TRNS,   KC_MPRV,          KC_VOLD, KC_MNXT
           ),
};

//colours      hsv
#define Orange {28,255,255}
#define Yellow {43,255,255}
#define Green  {85,255,255}
#define Sakura {242,171,255}
#define White  {0,0,255}
#define ______ {0,0,0}       //no colour

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    /*  Row:    0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      */
    [_1KEY] = { ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, Sakura,  \
                ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
                ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______,  \
                ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______,  \
                ______, ______, ______,                 ______,                 ______,         ______, ______,         ______, ______, },
    [_FN]   = { White,  Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, Orange, ______,  \
                White,  Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, ______, Orange, Orange, Orange, ______, ______,  \
                White,  Yellow, Yellow, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______,  \
                ______, ______, ______, ______, ______, ______, ______, ______, Sakura, Sakura, Sakura, ______,         Green,  Green,   \
                ______, ______, ______,                 ______,                 ______,         White,  Green,          Green,  Green,  },
};

void set_layer_color(int layer) {

  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
    switch (biton32(layer_state)) {
        case _FN:
            set_layer_color(_FN);
            break;
        case _1KEY:
            set_layer_color(_1KEY);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	    case RGB_S_C:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv(242, 171, 255);
            return false;
            break;
	    case RGB_S_R:
            rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            rgb_matrix_sethsv(242, 171, 255);
            return false;
            break;
    }

    return true;
}