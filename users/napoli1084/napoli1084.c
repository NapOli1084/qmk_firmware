/*
Copyright 2022 NapOli1084 (@napoli1084)

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
#include "napoli1084_keycodes.h"
#include "napoli1084_rgblayers.h"
#include "napoli1084_rgbmatrix.h"
#include "napoli1084_symbolkeys.h"
#include "napoli1084_utils.h"

#ifdef CONSOLE_ENABLE
    #ifdef NO_PRINT
        #error NO_PRINT defined with CONSOLE_ENABLE, nothing will be written to console
    #endif
    #ifdef NO_DEBUG
        #error NO_DEBUG defined with CONSOLE_ENABLE, no debugging will be available
    #endif
#else
    #ifndef NO_PRINT
        #error NO_PRINT not defined when CONSOLE_ENABLE not defined, printing not needed
    #endif
    #ifndef NO_DEBUG
        #error NO_DEBUG not defined when CONSOLE_ENABLE not defined, debugging not needed
    #endif
#endif

#ifdef LOCKING_SUPPORT_ENABLE
#error Locking support enabled, not needed
#endif

_Static_assert(LYR_COUNT <= MAX_LAYER, "Number of layers exceeds max");

void keyboard_post_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable_noeeprom();
    #endif
    RGBLIGHT_LAYERS_ONLY(napoli1084_rgblayers_keyboard_post_init());
}

bool led_update_user(led_t led_state) {
    RGBLIGHT_LAYERS_ONLY(napoli1084_rgblayers_led_update(led_state));
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    RGBLIGHT_LAYERS_ONLY(napoli1084_rgblayers_default_layer_state_set(state));
    return state;
}

#ifdef NAPOLI1084_ERGODOX
layer_state_t napoli1084_ergodox_layer_state_set(layer_state_t state);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    #ifdef NAPOLI1084_ERGODOX
    state = napoli1084_ergodox_layer_state_set(state);
    #endif
    RGBLIGHT_LAYERS_ONLY(state = napoli1084_rgblayers_layer_state_set(state));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, "
            "interrupt: %b, count: %u\n",
            keycode, record->event.key.col, record->event.key.row,
            record->event.pressed, record->event.time,
            record->tap.interrupted, record->tap.count);
#endif

    switch (keycode) {
    case NC_SYMD:
        return napoli1084_process_symbol_mode(keycode, record);
    case QK_UNICODEMAP ... QK_UNICODEMAP_PAIR_MAX:
        return napoli1084_process_symbol_key(keycode, record);
    case KC_LEFT_CTRL ... KC_RIGHT_GUI:
        return napoli1084_process_symbol_mod(keycode, record);
    case RGB_TOG ... RGB_MODE_RGBTEST:
    case NAP_RGB_BEGIN ... NAP_RGB_END:
        #ifdef RGB_MATRIX_ENABLE
        return napoli1084_process_rgb_matrix(keycode, record);
        #endif

        #ifdef RGBLIGHT_ENABLE
        //TODO
        //return napoli1084_process_rgblight(keycode, record);
        #endif
        break;
    }
    return PROCESS_CONTINUE;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:

        //{napoli1084
        case a_CIRCM ... y_DIAER:
        //}napoli1084

            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:

        //{napoli1084
        case TD_H_ESC:
        //case QK_UNICODEMAP_PAIR ... QK_UNICODEMAP_PAIR_MAX:
        case A_CIRCM ... Y_DIAER:
        //}napoli1084

            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

void matrix_scan_user(void) {
    napoli1084_update_symbol_key_press();
}
