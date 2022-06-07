#include "napoli1084_keycodes.h"
#include "napoli1084_rgblayers.h"
#include "napoli1084_symbolkeys.h"
#include "napoli1084_utils.h"


void keyboard_post_init_user(void) {
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

layer_state_t layer_state_set_user(layer_state_t state) {
    RGBLIGHT_LAYERS_ONLY(napoli1084_rgblayers_layer_state_set(state));
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
