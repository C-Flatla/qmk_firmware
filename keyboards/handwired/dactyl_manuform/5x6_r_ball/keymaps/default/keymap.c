// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    PTR_DIS = SAFE_RANGE,
    PTR_EN,
    PTR_CPII,
    PTR_CPID,
    DRAG_SCROLL,
};

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 100.0
#define SCROLL_DIVISOR_V 100.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_EQL,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,   KC_L,     KC_SLSH,
        KC_ENT,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,   KC_S,     KC_MINS,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,   KC_Z,     KC_BSLS,
        MO(2),   KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_SPC,  KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, DF(1),
        LM(1, MOD_LGUI), LM(1, MOD_LALT), KC_GRV,  LM(1, MOD_LCTL), KC_BSPC, KC_PGDN, KC_BSPC
    ),

    [1] = LAYOUT(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_MINS,
        KC_ENT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_BSLS,
        MO(2),   KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_SPC,  KC_PGUP, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, DF(0),
        KC_LGUI, KC_LALT, KC_GRV,  KC_LCTL, KC_BSPC, KC_PGDN, KC_BSPC
    ),

    [2] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12,
        _______, _______, _______, _______, _______, _______, _______, QK_MOUSE_BUTTON_1, QK_MOUSE_BUTTON_2, DRAG_SCROLL, _______, _______,
        _______, PTR_DIS, PTR_EN, PTR_CPID, PTR_CPII, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_HOME,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_END, KC_DEL
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef POINTING_DEVICE_ENABLE
    switch (keycode) {
        case PTR_DIS: /* Disable trackball */
            if (record->event.pressed) {
                pointing_device_set_status(POINTING_DEVICE_STATUS_FAILED);
            }
            return false;
        case PTR_EN: /* Enable trackball */
            if (record->event.pressed) {
                pointing_device_set_status(POINTING_DEVICE_STATUS_SUCCESS);
            }
            return false;
        case PTR_CPII: /* Increase trackball CPI */
            if (record->event.pressed) {
                pointing_device_set_cpi(pointing_device_get_cpi()+100);
                dprintf("CPI: %u\n", pointing_device_get_cpi());
            }
            return false;
        case PTR_CPID: /* Decrease trackball CPI */
            if (record->event.pressed) {
                pointing_device_set_cpi(pointing_device_get_cpi()-100);
                dprintf("CPI: %u\n", pointing_device_get_cpi());
            }
            return false;
        case DRAG_SCROLL: /* Toggle drag scrolling */
            if (record->event.pressed) {
                set_scrolling = !set_scrolling;
            }
            return false;
    }
#endif
    return true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v -= (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

void keyboard_post_init_user(void) {
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    debug_mouse  = true;
}
