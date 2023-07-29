/*
Copyright 2019 Stephen Peery

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
#define MOUSEKEY_INTERVAL 0
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 0
#define MOUSEKEY_MAX_SPEED 30
#define MOUSEKEY_WHEEL_DELAY 0

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FN,
    _FN2,
    _FN3,
    _FN5,
    _FN6,
    _GAME,
    _COLE,
    _STOCK,
};
enum my_keycodes {
    RESET_KB = SAFE_RANGE,
    KC_FNX,
//    KC_FNX2,
//    KC_FNX3,
    KC_FNX4,
//    KC_12,
    KC_NUMFN,
    BAR
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Row:        0           1           2           3        4           5        6        7           8           9           10          11          12          13          14          15          16          17          18          19          20     */
    [_BASE] = { {   KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_PSCR,    KC_PAUS,    KC_SLCK,    KC_NO,      KC_NO,      KC_NO,      KC_NO   },
                {   KC_GRV,     KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_MINS, KC_EQL,     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       TG(_GAME),  TO(_STOCK), KC_HOME,    KC_PGUP,    LT(_FN3,KC_NLCK),    KC_PSLS,    KC_PAST,    KC_PMNS },
                {   KC_TAB,     KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_LBRC, KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS },
                {   KC_BSPC,    KC_Z,       KC_X,       KC_C,    KC_V,       KC_B,    KC_RBRC, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NUHS,    KC_ENT,     KC_NO,      KC_NO,      KC_NO,      KC_P4,      KC_P5,      KC_P6,      KC_NO   },
                {   KC_LSFT,    KC_UP,      SGUI(KC_N), MO(_FN3), KC_RSFT,   KC_SPC,  TG(_FN2), MO(_FN),   KC_RSFT,    KC_RALT,    KC_INT2,    KC_CAPS,    KC_NO,      KC_RSFT,    KC_NO,      KC_UP,      KC_NO,      KC_P1,      KC_P2,      KC_P3,      KC_PENT },
                {   KC_LCTL,    KC_LGUI,    KC_LALT,    LT(_FN5,KC_ENT), KC_INT4,    KC_FNX,  KC_APP,  KC_NO,      KC_RCTL,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO,      KC_P0,      KC_PDOT,    KC_NO   }
              },
    [_FN]   = { {   RESET,      KC_F13,     KC_F14,     KC_F15,  KC_F16,     KC_F17,  KC_F18,  KC_F19,     KC_F20,     KC_F21,     KC_F22,     KC_F23,     KC_F24,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   RESET_KB,   KC_TILD,    KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_EXLM,    KC_QUES,    KC_9,       KC_0,       _______,    KC_COLN,    _______,    RGB_M_P,    RGB_M_B,    RGB_M_R,    _______,    _______,    _______,    _______ },
                {   _______,    KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    _______, KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,    _______,    RGB_M_SW,   RGB_MOD,    RGB_RMOD,   _______,    _______,    _______,    _______ },
                {   _______,    KC_EXLM,    KC_AT,      KC_HASH, KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR,    KC_LPRN,    KC_RPRN,    KC_ASTR,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_VAI,    _______,    KC_BRIU,    KC_BRID,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_HUD,    RGB_VAD,    RGB_HUI,    _______,    _______,    _______,    _______ }
             },
    [_FN2]  = { {   _______,    KC_MSEL,    KC_VOLD,    KC_VOLU, KC_MUTE,    KC_MSTP, KC_MPRV, KC_MPLY,    KC_MNXT,    KC_MAIL,    KC_WHOM,    KC_CALC,    RGB_TOG,    _______,    KC_PAUS,    _______,    KC_SLEP,    _______,    _______,    _______,    _______ },
                {   _______,    KC_P5,      _______,    KC_UP,   _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_SAI,    RGB_HUI,    RGB_SAI,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    KC_LEFT,    KC_DOWN, KC_RIGHT,   _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_SAD,    RGB_HUD,    RGB_SAD,    _______,    _______,    _______,    _______ },
                {   _______,    KC_MSTP,    KC_MPRV,    KC_MPLY, KC_MNXT,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_SPI,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RGB_SPD,    _______,    _______,    _______,    _______,    _______ }
             },
    [_FN3]  = { {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    KC_P,       KC_O,       KC_I,    KC_U,       KC_Y,    _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    KC_SCLN,    KC_L,       KC_K,    KC_J,       KC_H,    _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_7,       KC_8,       KC_9,    _______ },
                {   _______,    KC_SLSH,    KC_DOT,     KC_COMM, KC_M,       KC_N,    _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_4,       KC_5,       KC_6,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,    _______,    _______ }
             },
    [_FN5]  = { {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    KC_MINS,    KC_PLUS,    KC_ASTR, KC_SLSH,    KC_EQL,  _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_LPRN, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_7,       KC_8,       KC_9,    _______ },
                {   _______,    KC_6,       KC_7,       KC_8,    KC_9,       KC_0,    KC_RPRN, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_4,       KC_5,       KC_6,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,    _______ },
                {   MO(_FN6),   _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,    _______,    _______ }
             },
    [_FN6]  = { {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,  LSFT(KC_DEL), _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    _______, LSFT(KC_F14), LSFT(KC_F15), LSFT(KC_F16),        _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_7,       KC_8,       KC_9,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_4,       KC_5,       KC_6,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,    _______,    _______ }
             },
    [_GAME]=  { {   KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_NO,      KC_NO,      KC_NO,      KC_NO   },
                {   KC_2,       KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_MINS, KC_EQL,     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       TG(_GAME),  TO(_BASE),  KC_HOME,    KC_PGUP,    KC_NLCK, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_PMNS },
                {   KC_TAB,     KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_LBRC, KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,    KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, KC_PPLS },
                {   KC_BSPC,    KC_Z,       KC_X,       KC_C,    KC_V,       KC_B,    KC_RBRC, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NUHS,    KC_ENT,     KC_NO,      KC_NO,      KC_NO,      KC_MS_LEFT, KC_MS_BTN1, KC_MS_RIGHT, KC_NO   },
                {   KC_LSFT,    KC_NUBS,    KC_MS_WH_UP, KC_MS_WH_DOWN, KC_LSFT,    KC_SPC,  KC_1,   MO(_COLE),  KC_7,       KC_8,       KC_9,       KC_0,       KC_NO,      KC_RSFT,    KC_NO,      KC_UP,      KC_NO,      KC_MS_BTN2, KC_MS_DOWN, KC_MS_BTN3, KC_PENT },
                {   KC_LCTL,    KC_LGUI,    KC_LALT,    KC_ENT,  KC_RALT,    KC_FNX,  KC_APP,  KC_NO,      KC_RCTL,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO,    KC_MS_ACCEL0, KC_MS_ACCEL2, KC_NO   }
              },
    [_COLE] = { {   _______,    KC_1,       KC_2,       KC_3,    KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    KC_Q,       KC_W,       KC_F,    KC_P,       KC_G,    _______, _______,    KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ },
                {   _______,    KC_A,       KC_R,       KC_S,    KC_T,       KC_D,    _______, KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       _______,    _______,    _______,    _______,    _______,    KC_7,       KC_8,       KC_9,    _______ },
                {   _______,    KC_Z,       KC_X,       KC_C,    KC_V,       KC_B,    _______, KC_K,       KC_M,       _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_4,       KC_5,       KC_6,    _______ },
                {   _______,    _______,    _______,    KC_LCTL, KC_LSFT,    KC_SPC,  _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,    _______ },
                {   _______,    _______,    _______,    _______, _______,    _______, _______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,    _______,    _______ }
             },
    [_STOCK]= { {   KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_NO,      KC_PSCR,    KC_SLCK,    KC_PAUS,    KC_NO,      KC_NO,      KC_NO,      KC_NO   },
                {   KC_AT,      KC_Q,       KC_W,       KC_E,    KC_R,       KC_T,    KC_MINS, KC_EQL,     KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,    TO(_BASE),  KC_HOME,    KC_PGUP,    KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS },
                {   KC_TAB,     KC_A,       KC_S,       KC_D,    KC_F,       KC_G,    KC_LBRC, KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,    KC_P7,      KC_P8,      KC_P9,      KC_PPLS },
                {   KC_BSPC,    KC_Z,       KC_X,       KC_C,    KC_V,       KC_B,    KC_RBRC, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_NUHS,    KC_ENT,     KC_NO,      KC_NO,      KC_NO,      KC_P4,      KC_P5,      KC_P6,      KC_NO   },
                {   KC_LSFT,    KC_NUBS,    KC_1,       KC_2,    KC_3,       KC_4,    KC_5,    KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_NO,      KC_RSFT,    KC_NO,      KC_UP,      KC_NO,      KC_P1,      KC_P2,      KC_P3,      KC_PENT },
                {   KC_LCTL,    KC_LGUI,    KC_LALT,    KC_SPC,  KC_RALT,    KC_FNX,  KC_APP,  KC_NO,      KC_RCTL,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO,      KC_P0,      KC_PDOT,    KC_NO   }
              },
};
/*
//colours      hsv
#define Red    {0,255,255}
#define Orange {28,255,255}
#define Yellow {43,255,255}
#define Green  {85,255,255}
#define Blue   {170,255,255}
#define Violet {193,255,255}
#define Sakura {242,171,255}
#define White  {0,0,255}
#define ______ {,,}
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
*/    /*  Row:    0        1        2        3        4        5        6        7        8        9        10       11       12       13       14       15        16       17       18        19        20     */
/*    [_FN]   = { Red,              ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  Red,     ______,  ______,  ______,  ______,   ______, \
                ______,  Yellow,  Yellow,  Yellow,  Yellow,  Yellow,  ______,  ______,  ______,  ______,  ______,  Sakura,  Sakura,  ______,  ______,  ______,   ______,  ______,  ______,   Sakura,   Sakura, \
                Red,     Violet,  Green,   Violet,  Violet,  ______,  ______,  ______,  ______,  ______,  Sakura,  Sakura,  Sakura,  ______,  ______,  ______,   ______,  ______,  ______,   Sakura,   ______, \
                ______,  Green,   Green,   Green,   Violet,  Violet,  ______,  ______,  Violet,  ______,  ______,  ______,  ______,  ______,                              ______,  ______,   Sakura, \
                Orange,           Blue,    Blue,    Blue,    Blue,    Violet,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           ______,            ______,  ______,   Sakura,   ______, \
                Orange,  ______,  ______,                             ______,                             ______,  White,   ______,  ______,  ______,  ______,   ______,           ______,   Sakura, },
    [_FN2]  = { White,            Green,   Green,   Green,   Green,   Green,   Green,   Green,   Green,   Green,   Green,   Green,   Green,   Orange,  Orange,   Orange, \
                White,   ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  Orange,  Orange,  ______,  Sakura,  Sakura,   Sakura,  ______,  ______,   ______,   ______, \
                ______,  Yellow,  Yellow,  Yellow,  Yellow,  Yellow,  Yellow,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  Sakura,  Sakura,   Sakura,  ______,  ______,   ______,   ______, \
                ______,  Yellow,  Yellow,  Yellow,  Yellow,  Yellow,  Yellow,  ______,  ______,  ______,  ______,  ______,  ______,  ______,                              ______,  ______,   ______, \
                ______,           Yellow,  Yellow,  Yellow,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           Orange,            ______,  ______,   ______,   ______, \
                ______,  White,   ______,                             ______,                             ______,  White,   ______,  ______,  Orange,  Orange,   Orange,           ______,   ______, },
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
};
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t fnx_layer_timer;
    switch (keycode){
        case KC_FNX:                                    
            if(record->event.pressed){
                fnx_layer_timer = timer_read();
                layer_on(_FN);
            } else {
                layer_off(_FN);
                if (timer_elapsed(fnx_layer_timer) < 100) {  
                    layer_invert(_FN2);
                }
            }
        return true;
/*       case KC_FNX2:
            if(record->event.pressed) {
                fnx_layer_timer = timer_read();
                register_code(KC_LSFT); // Change the key to be held here
            } else {
                unregister_code(KC_LSFT); // Change the key that was held here, too!
                if (timer_elapsed(fnx_layer_timer) < 50) {
                     layer_invert(_FN4); // Change the character(s) to be sent on tap here
                }
            }
        return false; // We handled this keypress
       case KC_FNX3:
            if(record->event.pressed) {
                fnx_layer_timer = timer_read();
                layer_on(_FN3); // Change the key to be held here
            } else {
                layer_off(_FN3); // Change the key that was held here, too!
                if (timer_elapsed(fnx_layer_timer) < 50) {
                     register_code(KC_X); // Change the character(s) to be sent on tap here
                }
            }
        return false; // We handled this keypress
       case KC_FNX4:
            if(record->event.pressed) {
                fnx_layer_timer = timer_read();
                layer_on(_FN5); // Change the key to be held here
            } else {
                layer_off(_FN5); // Change the key that was held here, too!
                layer_off(_FN3); // Change the key that was held here, too!
                if (timer_elapsed(fnx_layer_timer) < 50) {
                     register_code(KC_X); // Change the character(s) to be sent on tap here
                }
            }
        return false; // We handled this keypress
       case KC_FNX4:
            if(record->event.pressed) {
                fnx_layer_timer = timer_read();
                layer_on(_FN5); // Change the key to be held here
            } else {
                layer_off(_FN5); // Change the key that was held here, too!
                if (timer_elapsed(fnx_layer_timer) < 150) {
                     register_code(KC_ENT); // Change the character(s) to be sent on tap here
                }
            }
        return true; // We handled this keypress
       case KC_12:
            if(record->event.pressed) {
                fnx_layer_timer = timer_read();
                register_code(KC_1); // Change the key to be held here
            } else {
                unregister_code(KC_1); // Change the key that was held here, too!
                if (timer_elapsed(fnx_layer_timer) < 150) {
                     register_code(KC_2); // Change the character(s) to be sent on tap here
                }
            }
        return false; // We handled this keypress
*/        case KC_NUMFN:                                    
            if(record->event.pressed){
                fnx_layer_timer = timer_read();
                layer_on(_FN);
            } else {
                layer_off(_FN);
                if (timer_elapsed(fnx_layer_timer) < 150) {  
                    layer_invert(_FN3);
                }
            }
        return true;
          case RESET_KB:
            NVIC_SystemReset();
    }
    return true;
};
/*
void rgb_matrix_indicators_user(void) {
  switch (biton32(layer_state)) {
    case _FN:
      set_layer_color(_FN);
      break;
    case _FN2:
      set_layer_color(_FN2);
      break;
  }
}
*/
uint8_t prev = _BASE;
uint32_t desired = 1;
void matrix_init_user() {
    rgblight_mode(desired);
}
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_STOCK) {
      switch (layer) {
        case _BASE:
          rgblight_mode(1);
          break;
        case _FN2:
          rgblight_mode(3);
          rgblight_sethsv(100,255,255);
          break;
        case _FN3:
          rgblight_mode(3);
          rgblight_sethsv(26,255,255);
          break;
        case _FN5:
          rgblight_mode(3);
          rgblight_sethsv(80,255,255);
          break;
        case _FN6:
          rgblight_mode(3);
          rgblight_sethsv(159,255,255);
          break;
        case _GAME:
          rgblight_mode(2);
          rgblight_sethsv(205,255,255);
          break;
        case _COLE:
          rgblight_mode(2);
          rgblight_sethsv(100,255,255);
          break;
        case _STOCK:
          rgblight_mode(2);
          rgblight_sethsv(159,255,255);
          break;
        case _FN:
          rgblight_mode(3);
          rgblight_sethsv(242,171,255);
          break;
      }
  } else {
      desired = rgblight_get_mode();
  }
  prev = layer;
  return state;
}
