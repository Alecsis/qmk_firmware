// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_pad_4x3(
        KC_1,   KC_2,   KC_3,   KC_4,
        KC_5,   KC_6,   KC_7,   KC_8,
        LCTL(KC_C),   LCTL(KC_V),   KC_F13,   TG(1)
      
    ),
    [1] = LAYOUT_pad_4x3(
        KC_6,   KC_2,   KC_3,   KC_4,
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_A,   MO(3),   TG(2)
      
    ), 
    [2] = LAYOUT_pad_4x3(
        KC_9,   KC_2,   KC_3,   KC_4,
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_A,   KC_B,   TO(0)
      
    ),
    [3] = LAYOUT_pad_4x3(
        QK_BOOT,   KC_2,   KC_3,   KC_4,
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_A,   KC_B,   KC_C
      
    )              
};

enum layer_names {
    _MAC_DEFAULT,
    _MAC_UTILITY,
    _MAC_MOMENTARY


};


#ifdef OLED_ENABLE



// Draw to OLED
bool oled_task_user() {
    //128x32 
        // Default OLED code
    led_t led_state = host_keyboard_led_state();
    oled_set_cursor(2,10);
    oled_write_P(led_state.caps_lock ? PSTR(" Caps Lock "): PSTR(" Macropad "), false);
    oled_set_cursor(0,1);
    // Switch on current active layer
    switch (get_highest_layer(layer_state)) {
        case _MAC_DEFAULT :
            oled_write("Main Layer", false);
            break;
        case _MAC_UTILITY :
            oled_write("Util Layer", false);
            break;
        case _MAC_MOMENTARY : 
            oled_write("AUX Layer", false);
            break;

    }

    return false;
}

#endif