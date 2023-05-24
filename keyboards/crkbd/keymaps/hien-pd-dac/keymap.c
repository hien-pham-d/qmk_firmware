/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

// Define layer name.
#define _BASE_L   0
#define _LOWER_L  1
#define _RAISE_L  2
#define _ADJUST_L 3
#define _GAME_L 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_L] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, LALT_T(KC_A), LSFT_T(KC_S), LGUI_T(KC_D), LCTL_T(KC_F), KC_G,    KC_H, RCTL_T(KC_J), RGUI_T(KC_K), RSFT_T(KC_L), RALT_T(KC_QUOT), KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BTN1,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LCTL,   MO(_LOWER_L),  KC_LSFT,    KC_SPC,  MO(_RAISE_L),   KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER_L] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_TRNS,   KC_TRNS,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_ENT, KC_SPC, KC_BSPC, KC_BTN1,  KC_BTN2,                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_TRNS,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, TG(_GAME_L),               KC_TRNS, KC_TRNS,   KC_LT,   KC_GT, KC_QUES,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   MO(_ADJUST_L),   KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE_L] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TILD, KC_EQL, KC_DQUO, KC_UNDS,                      KC_PIPE, KC_MINS, KC_COLN, KC_LCBR, KC_RCBR,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS,  KC_GRV, KC_LPRN, KC_RPRN, KC_QUES,                      KC_BSLS, KC_PLUS, KC_SCLN, KC_LBRC, KC_RBRC,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   MO(_ADJUST_L), KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST_L] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_F11,  KC_F12,  KC_DEL, KC_PSCR,   RESET,                      RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_INS, KC_PGUP, KC_PGDN, KC_HOME,  KC_END,                      KC_TRNS, RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,   KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
  [_GAME_L] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_Q,   KC_W, KC_E,  KC_R, KC_T,                                  KC_CIRC, KC_AMPR, KC_ASTR, KC_TRNS, KC_BSPC,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_A, KC_S, KC_D, KC_F,  KC_G,                                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_Z, KC_X, KC_C, KC_V, TG(_GAME_L),                            KC_TRNS, KC_TRNS,   KC_LT,   KC_GT, KC_QUES,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, KC_TRNS, KC_LALT,    KC_TRNS,   MO(3),   KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE   0
#define L_LOWER  2
#define L_RAISE  4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    /* default logo */
    /* static const char PROGMEM qmk_logo[] = { */
        /* 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, */
        /* 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, */
        /* 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00 */
    /* }; */

    /* oled_write_P(qmk_logo, false); */

    /* // my customized logo: `hienpd` */
    /* static const char PROGMEM raw_logo[] = { */
        /* 0,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,248,248,252,252,254,254,254,254,254,126, 62, 62,126,252,252,252,248,248,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,240,240,240,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,240,240,240,224,  0,224,224,224,224,224,224,224,224,224,224,224,224,224,224,192,  0,224,240,240,240,240,240,248,248,248,248,248,248,248,248,240,240, 96,  0,224,240,240,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,240,240,224,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
        /* 0,  0,  0,  0,  0,  0,248,254,255,255,255,255,255,127,255,223,143,  7,  7,143,222,252,248,248,252,222,143,  7,  7, 15,159,255,255,255,254,240,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,143,128,192,192,192,192,192,192,224,224,224,255,255,255,255,  0,  0,  1,  1,  1,  1,255,255,255,255,255,  1,  1,  3,  3,  1,  1,  0,253,255,255,255,255,224,224,224,224,224,224,224,240,240,224,192,  0,  0,255,255,255,255,255, 31,127,254,252,240,224,192,128,  0,  0,  0,  0,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0, */
        /* 0,  0,  0,  0,  0,  0, 15,127,255,255,255,249,240,224,240,249, 63, 31, 15, 31, 59,113,224,192,225,243,255,255,254,255,255,255,255,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  7,  7,  7,  7,  3,  3,  3,  3,  3,  3,  3,255,255,255,255,  0,  0,128,128,192,192,255,255,255,255,255,192,192,192,192,192,  0,  0,255,255,255,255,255,131,131,129,129,129,129,129,129,129,129,  0,  0,  0,255,255,255,255,255,  0,  0,  0,  1,  3, 15, 31, 63,127,254,252,248,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0, */
        /* 0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  7,  7, 15, 31, 63, 63, 63,126,124,124,126,127,127,127,127, 63, 63, 31, 31, 15,  7,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  7,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  7,  7,  3,  0,  0,  3,  7,  7,  7,  7,  7,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  0,  3,  7,  7,  7, 15, 15, 15, 15, 15, 15, 15, 15,  7,  7,  2,  0,  0,  3,  7,  7,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
    /* }; */
    /* oled_write_raw_P(raw_logo, sizeof(raw_logo)); */

    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,248,248,252,254,254,255,255,255,255,223,143, 15,159,255,255,254,252,252,240,224,192,  0,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,248,248,248,248,  0,  0,248,248,248,248,248, 56, 56, 56, 56, 56, 56, 56, 56, 56,  0,  0,248,248,248,248,248,240,192,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 60,255,255,255,255,207,135,143,253,248,120,249,223,143,143,159,253,248,240,249,255,255,255,255, 28,  0,  0,  0,  0,255,255,255,255, 28, 28, 28, 28, 28, 28,255,255,255,255,  0,  0,  0,255,255,255,255,  0,  0,255,255,255,255,255, 28, 28, 28, 28, 28, 28, 28, 28,  0,  0,  0,255,255,255,255,  3,  7, 31,127,252,240,192,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 15, 31, 63,127,127,127,252,248,248,255,255,255,255,127,127, 63, 63, 31, 15,  7,  1,  0,  0,  0,  0,  0, 15, 15, 15, 15,  0,  0,  0,  0,  0,  0, 15, 15, 15, 15,  0,  0,  0, 15, 15, 15, 15,  0,  0, 15, 15, 15, 15, 15, 14, 14, 14, 14, 14, 14, 14, 14, 14,  0,  0, 15, 15, 15, 15,  0,  0,  0,  0,  1,  7, 15, 15, 15, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
