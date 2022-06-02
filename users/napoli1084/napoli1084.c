#include "napoli1084.h"
#include "napoli1084_rgblayers.h"
#include "napoli1084_symbolkeys.h"
#include "napoli1084_utils.h"

//#ifdef TAP_DANCE_ENABLE

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

bool is_tap_dance_double(td_state_t state) {
    switch (state) {
    case TD_DOUBLE_TAP:
    case TD_DOUBLE_HOLD:
        return true;
    case TD_DOUBLE_SINGLE_TAP: // not considered double since it just applies twice the single tap
    default:
        return false;
    }
}

// See https://docs.qmk.fm/#/feature_tap_dance
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

#ifndef NAPOLI1084_TD_DEBUG_STRING_ENABLE
    #define NAPOLI1084_TD_DEBUG_STRING_ENABLE 0
#endif

#if NAPOLI1084_TD_DEBUG_STRING_ENABLE
    #define TD_DEBUG_ONLY(...) __VA_ARGS__
    #define TD_DEBUG_STRING(str) SEND_STRING(str)
#else
    #define TD_DEBUG_ONLY(...)
    #define TD_DEBUG_STRING(str)
#endif

#if NAPOLI1084_TD_DEBUG_STRING_ENABLE
void napoli1084_send_tp_debug_string(td_state_t state) {
    switch (state) {
        case TD_NONE: SEND_STRING("TD_NONE\n"); break;
        case TD_UNKNOWN: SEND_STRING("TD_UNKNOWN\n"); break;
        case TD_SINGLE_TAP: SEND_STRING("TD_SINGLE_TAP\n"); break;
        case TD_SINGLE_HOLD: SEND_STRING("TD_SINGLE_HOLD\n"); break;
        case TD_DOUBLE_TAP: SEND_STRING("TD_DOUBLE_TAP\n"); break;
        case TD_DOUBLE_HOLD: SEND_STRING("TD_DOUBLE_HOLD\n"); break;
        case TD_DOUBLE_SINGLE_TAP: SEND_STRING("TD_DOUBLE_SINGLE_TAP\n"); break;
        case TD_TRIPLE_TAP: SEND_STRING("TD_TRIPLE_TAP\n"); break;
        case TD_TRIPLE_HOLD: SEND_STRING("TD_TRIPLE_HOLD\n"); break;
    }
}
#endif

// Create an instance of 'td_tap_t' for the 'RESET' tap dance.
static td_tap_t reset_key_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void napoli1084_reset_key_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_DEBUG_STRING("napoli1084_reset_key_finished: ");
    reset_key_tap_state.state = cur_dance(state);
    TD_DEBUG_ONLY(napoli1084_send_tp_debug_string(reset_key_tap_state.state));
    switch (reset_key_tap_state.state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_TAP: layer_move(LYR_DEFAULT); break;
        case TD_DOUBLE_HOLD: reset_keyboard(); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
        default: break;
    }
}

// The _reset function gets called when releasing the key after held,
// or right after finished when tapped.
void napoli1084_reset_key_reset(qk_tap_dance_state_t *state, void *user_data) {
    TD_DEBUG_STRING("napoli1084_reset_key_reset: ");
    TD_DEBUG_ONLY(napoli1084_send_tp_debug_string(reset_key_tap_state.state));
    switch (reset_key_tap_state.state) {
        case TD_SINGLE_TAP: break;//unregister_code(KC_X); break;
        case TD_SINGLE_HOLD: break;// unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;//unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: break;//unregister_code(KC_LALT);
        //case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X);
        default: break;
    }
    reset_key_tap_state.state = TD_NONE;
}

static td_tap_t h_esc_key_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void napoli1084_h_esc_key_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_DEBUG_STRING("napoli1084_h_key_finished: ");
    h_esc_key_tap_state.state = cur_dance(state);
    TD_DEBUG_ONLY(napoli1084_send_tp_debug_string(h_esc_key_tap_state.state));

    if (is_tap_dance_double(h_esc_key_tap_state.state)) {
        caps_word_off();
    } else {
        if (is_caps_word_on()) {
            add_weak_mods(MOD_BIT(KC_LSFT));
        }
    }

    switch (h_esc_key_tap_state.state) {
        case TD_SINGLE_HOLD: register_code(KC_H); break;
        case TD_DOUBLE_TAP: tap_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: register_code(KC_ESC); break;
        //case TD_TRIPLE_TAP: tap_code(KC_H); // fallthrough
        //case TD_DOUBLE_SINGLE_TAP: tap_code(KC_H); // fallthrough
        //case TD_SINGLE_TAP: tap_code(KC_H); break;
        default:
            for (uint8_t i = 0; i < state->count; ++i) {
                tap_code(KC_H);
            }
            break;
    }
}

void napoli1084_h_esc_key_reset(qk_tap_dance_state_t *state, void *user_data) {
    TD_DEBUG_STRING("napoli1084_h_esc_key_reset: ");
    TD_DEBUG_ONLY(napoli1084_send_tp_debug_string(h_esc_key_tap_state.state));
    switch (h_esc_key_tap_state.state) {
        case TD_SINGLE_TAP: break;//unregister_code(KC_H); break;
        case TD_SINGLE_HOLD: unregister_code(KC_H); break;
        case TD_DOUBLE_TAP: break;//unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_ESC);
        //case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_H);
        default: break;
    }
    h_esc_key_tap_state.state = TD_NONE;
}

// Tap Dance definitions
// Limited to 256, see #define TD(n) (QK_TAP_DANCE | ((n)&0xFF))
qk_tap_dance_action_t tap_dance_actions[] = {
    [tap_dance_reset] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, napoli1084_reset_key_finished, napoli1084_reset_key_reset),
    [tap_dance_h_esc] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, napoli1084_h_esc_key_finished, napoli1084_h_esc_key_reset),
    [tap_dance_ctl_z_ctl_a] = ACTION_TAP_DANCE_DOUBLE(CTL_Z, CTL_A),
    [tap_dance_ctl_s_ctl_x] = ACTION_TAP_DANCE_DOUBLE(CTL_S, CTL_X),
    [tap_dance_ctl_c_F5] = ACTION_TAP_DANCE_DOUBLE(CTL_C, KC_F5),
    [tap_dance_F7_ctl_F7] = ACTION_TAP_DANCE_DOUBLE(CTL_F7, KC_F7),
    [tap_dance_ctl_f_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, CTL_F),
    [tap_dance_ctl_p_ctl_o] = ACTION_TAP_DANCE_DOUBLE(CTL_P, CTL_O),
};
//#endif // TAP_DANCE_ENABLE

////////////////////////////////////////////////////////////////////////////////

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
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        // napoli1084 specific keycodes
        case TD_H_ESC:
        case QK_UNICODE ... QK_UNICODE_MAX:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

void matrix_scan_user(void) {
    napoli1084_update_symbol_key_press();
}
