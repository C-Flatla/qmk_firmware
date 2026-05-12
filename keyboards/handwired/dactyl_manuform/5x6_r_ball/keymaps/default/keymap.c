// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_EQL,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,   KC_L,     KC_SLSH,
        KC_ENT,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,   KC_S,     KC_MINS,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,   KC_Z,     KC_BSLS,
        MO(2),   KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_SPC,  KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, DF(1),
        LM(1, MOD_LGUI), LM(1, MOD_LALT), KC_GRV,  LM(1, MOD_LCTL), KC_BSPC, KC_PGDN, KC_PGUP
    ),

    [1] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_RBRC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_LBRC,
        KC_ENT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_BSLS,
        MO(2),   KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_SPC,  KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, DF(0),
        KC_LGUI, KC_LALT, KC_GRV,  KC_LCTL, KC_BSPC, KC_PGDN, KC_PGUP
    ),

    [2] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_DEL,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_HOME, KC_END
    )
};
