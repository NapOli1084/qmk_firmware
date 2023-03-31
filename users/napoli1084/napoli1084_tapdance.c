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
#include "napoli1084_utils.h"
#include "quantum.h"

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

// Create an instance of 'td_tap_t' for all tap dances.
// No need to have one per tap dance, there can't be multiple tap dances in progress at same time.
static td_tap_t key_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

#if 0
static bool napoli1084_is_tap_dance_double(td_state_t state) {
    switch (state) {
    case TD_DOUBLE_TAP:
    case TD_DOUBLE_HOLD:
        return true;
    case TD_DOUBLE_SINGLE_TAP: // not considered double since it just applies twice the single tap
    default:
        return false;
    }
}
#endif

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
td_state_t cur_dance(tap_dance_state_t *state) {
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

#if defined(NAPOLI1084_TD_DEBUG_ENABLE) && defined(CONSOLE_ENABLE)
    #define NAPOLI1084_TD_DEBUG_ENABLED 1
#else
    #define NAPOLI1084_TD_DEBUG_ENABLED 0
#endif

#if NAPOLI1084_TD_DEBUG_ENABLED
    #define TD_DEBUG_STATE(state) dprintf("%s: %s\n", __FUNCTION__, napoli1084_get_td_state_str(state))
#else
    #define TD_DEBUG_STATE(state)
#endif

#if NAPOLI1084_TD_DEBUG_ENABLED
static const char* napoli1084_get_td_state_str(td_state_t state) {
    switch (state) {
        case TD_NONE: return "TD_NONE";
        case TD_UNKNOWN: return "TD_UNKNOWN";
        case TD_SINGLE_TAP: return "TD_SINGLE_TAP";
        case TD_SINGLE_HOLD: return "TD_SINGLE_HOLD";
        case TD_DOUBLE_TAP: return "TD_DOUBLE_TAP";
        case TD_DOUBLE_HOLD: return "TD_DOUBLE_HOLD";
        case TD_DOUBLE_SINGLE_TAP: return "TD_DOUBLE_SINGLE_TAP";
        case TD_TRIPLE_TAP: return "TD_TRIPLE_TAP";
        case TD_TRIPLE_HOLD: return "TD_TRIPLE_HOLD";
    }
    return "<TD_INVALID>";
}
#endif

//#define NAPOLI1084_TAP_HOLD_DANCE
#ifdef NAPOLI1084_TAP_HOLD_DANCE
typedef struct {
    uint16_t kc1tap;
    uint16_t kc1hold;
    uint16_t kc2tap;
    uint16_t kc2hold;
    uint16_t kc3tap;
    uint16_t kc3hold;
} nap_tap_hold_dance_data_t;

static void napoli1084_register_code(uint16_t code) {
    //extract_mod_bits(code);
    //tap_code16
}

void napoli1084_tap_hold_dance_finished(tap_dance_state_t *state, void *user_data) {
    key_tap_state.state = cur_dance(state);
    TD_DEBUG_STATE(key_tap_state.state);
    nap_tap_hold_dance_data_t* data = (nap_tap_hold_dance_data_t*)user_data;

    switch (key_tap_state.state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP: break;
        case TD_DOUBLE_HOLD: break;
        // This case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
        case TD_TRIPLE_TAP: break;
        case TD_TRIPLE_HOLD: break;
        default: break;
    }
}

// The _reset function gets called when releasing the key after held,
// or right after finished when tapped.
void napoli1084_tap_hold_dance_reset(tap_dance_state_t *state, void *user_data) {
}
#endif

////////////////////////////////////////////////////////////////////////////////
enum napoli1084_game_w_state {
    GAME_W_HOLD_DISABLED,
    GAME_W_HOLD_INACTIVE,
    GAME_W_HOLD_ACTIVE,
};

uint8_t game_w_state = GAME_W_HOLD_INACTIVE;
bool game_w_registered = false;

void napoli1084_game_w_each_tap(tap_dance_state_t *state, void *user_data) {
    nap_dprintf("TD GAME W each tap count=%u game_w_state=%u\n", state->count, game_w_state);

    switch (state->count) {
        case 1:
            register_code(KC_W);
            game_w_registered = true;

            if (game_w_state == GAME_W_HOLD_ACTIVE) {
                // if held and press again, deactivate hold
                game_w_state = GAME_W_HOLD_INACTIVE;
            }
            break;
        case 2: // activate hold unless disabled
            if (game_w_state != GAME_W_HOLD_DISABLED) {
                game_w_state = GAME_W_HOLD_ACTIVE;
            } else {
                if (game_w_registered)
                    unregister_code(KC_W);
                register_code(KC_W);
                game_w_registered = true;
            }
            break;
        case 3: // toggle disable
            if (game_w_state != GAME_W_HOLD_DISABLED) {
                game_w_state = GAME_W_HOLD_DISABLED;
            } else {
                game_w_state = GAME_W_HOLD_ACTIVE;
            }
            break;
    }
}

void napoli1084_game_w_finished(tap_dance_state_t *state, void *user_data) {
}

void napoli1084_game_w_reset(tap_dance_state_t *state, void *user_data) {
    if (game_w_registered) {
        switch (game_w_state) {
            case GAME_W_HOLD_DISABLED:
            case GAME_W_HOLD_INACTIVE:
                unregister_code(KC_W);
                game_w_registered = false;
                break;
        }
    }
}

bool napoli1084_game_w_process(uint16_t keycode, keyrecord_t *record) {
    nap_dprintf("TD GAME W process keycode=%u pressed=%u registered=%u game_w_state=%u\n",
        keycode, record->event.pressed, game_w_registered, game_w_state);

    switch (keycode) {
    case KC_S: // move back cancels move forward hold
        if (record->event.pressed && game_w_registered) {
            unregister_code(KC_W);
            game_w_registered = false;
            switch (game_w_state) {
                case GAME_W_HOLD_ACTIVE: game_w_state = GAME_W_HOLD_INACTIVE; break;
                case GAME_W_HOLD_DISABLED: break;
                case GAME_W_HOLD_INACTIVE: break;
            }
        }
        break;
    case TD_GAMW:
        if (!record->event.pressed && game_w_registered) {
            switch (game_w_state) {
                case GAME_W_HOLD_DISABLED:
                    unregister_code(KC_W);
                    game_w_registered = false;
                    break;
            }
        }
        break;
    }
    return PROCESS_CONTINUE;
}

////////////////////////////////////////////////////////////////////////////////

void napoli1084_reset_key_finished(tap_dance_state_t *state, void *user_data) {
    key_tap_state.state = cur_dance(state);
    TD_DEBUG_STATE(key_tap_state.state);

    switch (key_tap_state.state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_TAP:
            clear_keyboard();
            layer_move(LYR_DEFAULT);
            napoli1084_game_w_reset(NULL, NULL);
            break;
        case TD_DOUBLE_HOLD:
            // enter keyboard flash state
            reset_keyboard();
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
        default: break;
    }
}

// The _reset function gets called when releasing the key after held,
// or right after finished when tapped.
void napoli1084_reset_key_reset(tap_dance_state_t *state, void *user_data) {
    TD_DEBUG_STATE(key_tap_state.state);

    switch (key_tap_state.state) {
        case TD_SINGLE_TAP: break;//unregister_code(KC_X); break;
        case TD_SINGLE_HOLD: break;// unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: break;//unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: break;//unregister_code(KC_LALT);
        //case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X);
        default: break;
    }
    key_tap_state.state = TD_NONE;
}

void napoli1084_h_esc_key_finished(tap_dance_state_t *state, void *user_data) {
    key_tap_state.state = cur_dance(state);
    TD_DEBUG_STATE(key_tap_state.state);

    #if 0 //def CAPS_WORD_ENABLE
    if (napoli1084_is_tap_dance_double(key_tap_state.state)) {
        caps_word_off();
    } else {
        napoli1084_shift_if_caps_word_on();
    }
    #endif

    switch (key_tap_state.state) {
        case TD_SINGLE_HOLD:
            caps_word_off();
            register_code(KC_LCTL);
            tap_code(KC_ESC);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            // Since I often double-tap H for ESC and then type another key rapidly,
            // I'll tap ESC even for double-single tap.
            // This is what I want most of the time, I rarely want to type 2 H in a row.
        case TD_DOUBLE_TAP:
            caps_word_off();
            tap_code(KC_ESC);
            break;
        case TD_DOUBLE_HOLD:
            caps_word_off();
            register_code(KC_ESC);
            break;
        //case TD_TRIPLE_TAP: tap_code(KC_H); // fallthrough
        //case TD_SINGLE_TAP: tap_code(KC_H); break;
        default:
            napoli1084_shift_if_caps_word_on();
            for (uint8_t i = 0; i < state->count; ++i) {
                tap_code(KC_H);
            }
            break;
    }
}

void napoli1084_h_esc_key_reset(tap_dance_state_t *state, void *user_data) {
    TD_DEBUG_STATE(key_tap_state.state);

    switch (key_tap_state.state) {
        case TD_SINGLE_TAP: break;//unregister_code(KC_H); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;//unregister_code(KC_H); break;
        case TD_DOUBLE_TAP: break;//unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_ESC);
        //case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_H);
        default: break;
    }
    key_tap_state.state = TD_NONE;
}



// Tap Dance definitions
// Limited to 256, see #define TD(n) (QK_TAP_DANCE | ((n)&0xFF))
_Static_assert(tap_dance_count <= 0x00FF+1, "Number of tap dances cannot exceed 256, see TD()");
tap_dance_action_t tap_dance_actions[] = {
    [tap_dance_reset] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, napoli1084_reset_key_finished, napoli1084_reset_key_reset),
    [tap_dance_h_esc] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, napoli1084_h_esc_key_finished, napoli1084_h_esc_key_reset),
    [tap_dance_ctl_z_ctl_a] = ACTION_TAP_DANCE_DOUBLE(CTL_Z, CTL_A),
    [tap_dance_ctl_s_ctl_x] = ACTION_TAP_DANCE_DOUBLE(CTL_S, CTL_X),
    [tap_dance_ctl_c_F5] = ACTION_TAP_DANCE_DOUBLE(CTL_C, KC_F5),
    [tap_dance_F7_ctl_F7] = ACTION_TAP_DANCE_DOUBLE(CTL_F7, KC_F7),
    [tap_dance_ctl_f_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, CTL_F),
    [tap_dance_ctl_p_ctl_o] = ACTION_TAP_DANCE_DOUBLE(CTL_P, CTL_O),
    [tap_dance_game_w] = ACTION_TAP_DANCE_FN_ADVANCED(napoli1084_game_w_each_tap, napoli1084_game_w_finished, napoli1084_game_w_reset),
};
//#endif // TAP_DANCE_ENABLE
