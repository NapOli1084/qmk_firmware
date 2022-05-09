#include "napoli1084.h"

#define PROCESS_CONTINUE true
#define PROCESS_STOP false

#ifdef TAP_DANCE_ENABLE

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

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t reset_key_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

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

// The _reset function gets called when releasing the key after held
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


// Tap Dance definitions
// Limited to 256, see #define TD(n) (QK_TAP_DANCE | ((n)&0xFF))
qk_tap_dance_action_t tap_dance_actions[] = {
    [tap_dance_reset] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, napoli1084_reset_key_finished, napoli1084_reset_key_reset),
    [tap_dance_h_esc] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_ESC),
    [tap_dance_ctl_z_ctl_a] = ACTION_TAP_DANCE_DOUBLE(CTL_Z, CTL_A),
    [tap_dance_ctl_s_ctl_x] = ACTION_TAP_DANCE_DOUBLE(CTL_S, CTL_X),
    [tap_dance_ctl_c_F5] = ACTION_TAP_DANCE_DOUBLE(CTL_C, KC_F5),
    [tap_dance_F7_ctl_F7] = ACTION_TAP_DANCE_DOUBLE(CTL_F7, KC_F7),
    [tap_dance_ctl_f_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, CTL_F),
    [tap_dance_ctl_p_ctl_o] = ACTION_TAP_DANCE_DOUBLE(CTL_P, CTL_O),
};
#endif // TAP_DANCE_ENABLE

////////////////////////////////////////////////////////////////////////////////

#ifdef UNICODEMAP_ENABLE

const uint32_t PROGMEM unicode_map[] = {
    [uni_QUOTATION] = 0x0022, // "
    [uni_HASH] = 0x0023, // #
    [uni_APOSTROPHE] = 0x0027, // '
    [uni_COMMA] = 0x002C, // ,
    [uni_DOT] = 0x002E, // .
    [uni_SLASH] = 0x002F, // /
    [uni_LESSTHAN] = 0x003C, // <
    [uni_GREATERTHAN] = 0x003E, // >
    [uni_QUESTION] = 0x003F, // ?
    [uni_AT] = 0x0040, // @
    [uni_LEFTBRACKET] = 0x005B, // [
    [uni_BACKSLASH] = 0x005C, // `\`
    [uni_RIGHTBRACKET] = 0x005D, // ]
    [uni_CIRCUMFLEX] = 0x005E, // ^
    [uni_GRAVE] = 0x0060, // `
    [uni_LEFTCURLYBRACKET] = 0x007B, // {
    [uni_PIPE] = 0x007C, // |
    [uni_RIGHTCURLYBRACKET] = 0x007D, // }
    [uni_TILDE] = 0x007E, // ~
    [uni_a_CIRCUMFLEX] = 0x00E2, // â
    [uni_a_DIAERESIS] = 0x00E4, // ä
    [uni_a_GRAVE] = 0x00E0, // à
    [uni_c_CEDILLA] = 0x00E7, // ç
    [uni_e_ACUTE] = 0x00E9, // é
    [uni_e_CIRCUMFLEX] = 0x00EA, // ê
    [uni_e_DIAERESIS] = 0x00EB, // ë
    [uni_e_GRAVE] = 0x00E8, // è
    [uni_i_CIRCUMFLEX] = 0x00EE, // î
    [uni_i_DIAERESIS] = 0x00EF, // ï
    [uni_n_TILDE] = 0x00F1, // ñ
    [uni_o_CIRCUMFLEX] = 0x00F4, // ô
    [uni_o_DIAERESIS] = 0x00F6, // ö
    [uni_s_SHARP] = 0x00DF, // ß
    [uni_u_CIRCUMFLEX] = 0x00FB, // û
    [uni_u_DIAERESIS] = 0x00FC, // ü
    [uni_u_GRAVE] = 0x00F9, // ù
    [uni_y_DIAERESIS] = 0x00FF, // ÿ
    [uni_A_CIRCUMFLEX] = 0x00C2, // Â
    [uni_A_DIAERESIS] = 0x00C4, // Ä
    [uni_A_GRAVE] = 0x00C0, // À
    [uni_C_CEDILLA] = 0x00C7, // Ç
    [uni_E_ACUTE] = 0x00C9, // É
    [uni_E_CIRCUMFLEX] = 0x00CA, // Ê
    [uni_E_DIAERESIS] = 0x00CB, // Ë
    [uni_E_GRAVE] = 0x00C8, // È
    [uni_I_CIRCUMFLEX] = 0x00CE, // Î
    [uni_I_DIAERESIS] = 0x00CF, // Ï
    [uni_N_TILDE] = 0x00D1, // Ñ
    [uni_O_CIRCUMFLEX] = 0x00D4, // Ô
    [uni_O_DIAERESIS] = 0x00D6, // Ö
    [uni_S_SHARP] = 0x1E9E, // ẞ
    [uni_U_CIRCUMFLEX] = 0x00DB, // Û
    [uni_U_DIAERESIS] = 0x00DC, // Ü
    [uni_U_GRAVE] = 0x00D9, // Ù
    [uni_Y_DIAERESIS] = 0x0178, // Ÿ
};

static uint8_t symbol_mode = SYMD_UNICODE;
#else
static uint8_t symbol_mode = SYMD_KB_CAFR;
#endif // #ifdef UNICODEMAP_ENABLE


////////////////////////////////////////////////////////////////////////////////

#ifdef RGBLIGHT_LAYERS

const rgblight_segment_t PROGMEM my_capslock_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM / 4, HSV_WHITE}       // Light 3 LEDs, starting with LED 0
);

#ifdef NAPOLI1084_QWERTY_ENABLE
const rgblight_segment_t PROGMEM my_qwerty_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    // Left hand
    {0, 1, HSV_MAGENTA}, // 213
    {1, 1, 234, 255, 255}, //HSV_PINK},
    {2, 1, HSV_RED}, // 0
    {3, 1, 5, 255, 255}, //
    {4, 1, 10, 255, 255}, // Coral
    {5, 1, 15, 255, 255}, //
    {6, 1, 21, 255, 255}, // Orange
    // Right hand
    {7, 1, HSV_YELLOW}, // 43
    {8, 1, HSV_CHARTREUSE},
    {9, 1, HSV_GREEN},
    {10, 1, HSV_SPRINGGREEN},
    {11, 1, HSV_CYAN},
    {12, 1, HSV_BLUE},
    {13, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_qnavnum_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_BLUE}
);
#endif // NAPOLI1084_QWERTY_ENABLE

const rgblight_segment_t PROGMEM my_worknap_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_game_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_RED}
);
const rgblight_segment_t PROGMEM my_navnum_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {RGBLED_NUM / 4, RGBLED_NUM - 2*(RGBLED_NUM / 4), HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_frsymbol_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_frcaps_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 15, 255, 255} // orange
);
const rgblight_segment_t PROGMEM my_fn_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_f1f12_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 234, 255, 255} // pink
);
const rgblight_segment_t PROGMEM my_windows_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM / 4, HSV_BLUE},
    {RGBLED_NUM / 4, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_RED},
    {RGBLED_NUM / 2, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_YELLOW},
    {RGBLED_NUM - (RGBLED_NUM / 4), RGBLED_NUM / 4, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
#ifdef NAPOLI1084_QWERTY_ENABLE
    my_qwerty_rgblayer,    // Overrides caps lock layer
    my_qnavnum_rgblayer,    // Overrides qwerty layer
#endif
    my_worknap_rgblayer,
    my_game_rgblayer,
    my_capslock_rgblayer,
    my_navnum_rgblayer,
    my_frsymbol_rgblayer,
    my_frcaps_rgblayer,
    my_fn_rgblayer,    // Overrides other layers
    my_f1f12_rgblayer,
    my_windows_rgblayer
);

enum napoli1084_rgblayers {
#ifdef NAPOLI1084_QWERTY_ENABLE
    RGBLYR_QWERTY,
    RGBLYR_QNAVNUM,
#endif
    RGBLYR_WORKNAP,
    RGBLYR_GAME,
    RGBLYR_CAPSLOCK,
    RGBLYR_NAVNUM,
    RGBLYR_FRSYMBOL,
    RGBLYR_FRCAPS,
    RGBLYR_FN,
    RGBLYR_F1F12,
    RGBLYR_WINDOWS,
    RGBLYR_COUNT // not a layer, only serves to count number of layers
};

#endif // RGBLIGHT_LAYERS

////////////////////////////////////////////////////////////////////////////////

void napoli1084_cycle_symbol_mode(void) {
    symbol_mode = (symbol_mode + 1) % SYMD_COUNT;

    switch (symbol_mode)
    {
    case SYMD_KB_CAFR:
        SEND_STRING("CAFR");
        break;
    case SYMD_KB_CMS:
        SEND_STRING("CMS");
        break;
    case SYMD_KB_US:
        SEND_STRING("US");
        break;
#ifdef UNICODEMAP_ENABLE
    case SYMD_UNICODE:
        SEND_STRING("UNI");
        break;
#endif
    }
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_LAYERS
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
#endif
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(RGBLYR_CAPSLOCK, led_state.caps_lock);
#endif
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
  #ifdef NAPOLI1084_QWERTY_ENABLE
    rgblight_set_layer_state(RGBLYR_QWERTY, layer_state_cmp(state, LYR_QWERTY));
  #else
    rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
  #endif
#endif
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    _Static_assert(RGBLIGHT_MAX_LAYERS >= RGBLYR_COUNT, "Max RGB layers must be greater or equal to number of layers");
  #ifdef NAPOLI1084_QWERTY_ENABLE
    rgblight_set_layer_state(RGBLYR_QNAVNUM, layer_state_cmp(state, LYR_QNAVNUM));
    rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
  #endif
    rgblight_set_layer_state(RGBLYR_GAME, layer_state_cmp(state, LYR_GAME));
    rgblight_set_layer_state(RGBLYR_NAVNUM, layer_state_cmp(state, LYR_NAVNUM));
    rgblight_set_layer_state(RGBLYR_FRSYMBOL, layer_state_cmp(state, LYR_FRSYMBOL));
    rgblight_set_layer_state(RGBLYR_FRCAPS, layer_state_cmp(state, LYR_FRCAPS));
    rgblight_set_layer_state(RGBLYR_FN, layer_state_cmp(state, LYR_FN));
    rgblight_set_layer_state(RGBLYR_F1F12, layer_state_cmp(state, LYR_F1F12));
    rgblight_set_layer_state(RGBLYR_WINDOWS, layer_state_cmp(state, LYR_WINDOWS));
#endif // RGBLIGHT_LAYERS
    return state;
}

enum {
    SYMBOL_KEYS_MAX = 2
};
typedef struct {
    uint16_t keys[SYMBOL_KEYS_MAX];
} napoli1084_symbol_keys_t;

#define CAFR_CEDILLA_DEAD_KEY KC_RIGHT_BRACKET
#define CAFR_CIRCUMFLEX_DEAD_KEY KC_LEFT_BRACKET
#define CAFR_DIAERESIS_DEAD_KEY KC_RIGHT_CURLY_BRACE
#define CAFR_GRAVE_DEAD_KEY KC_QUOTE
#define CAFR_HASH KC_GRAVE
#define CAFR_QUOTE KC_LEFT_ANGLE_BRACKET
#define CAFR_DOUBLE_QUOTE KC_AT
#define CAFR_SLASH KC_HASH
#define CAFR_E_ACUTE KC_SLASH

static const napoli1084_symbol_keys_t PROGMEM cafr_symbol_keys_map[uni_COUNT] = {
    [uni_QUOTATION] = {{CAFR_DOUBLE_QUOTE, KC_NO}}, // "
    [uni_HASH] = {{CAFR_HASH, KC_NO}}, // #
    [uni_APOSTROPHE] = {{CAFR_QUOTE, KC_NO}}, // '
    [uni_COMMA] = {{KC_COMMA, KC_NO}}, // ,
    [uni_DOT] = {{KC_DOT, KC_NO}}, // ,
    [uni_SLASH] = {{CAFR_SLASH, KC_NO}}, // /
    [uni_LESSTHAN] = {{KC_BACKSLASH, KC_NO}}, // <
    [uni_GREATERTHAN] = {{KC_PIPE, KC_NO}}, // >
    [uni_QUESTION] = {{KC_CIRCUMFLEX, KC_NO}}, // ?
    [uni_AT] = {{RALT(KC_2), KC_NO}}, // @
    [uni_LEFTBRACKET] = {{RALT(KC_LEFT_BRACKET), KC_NO}}, // [
    [uni_BACKSLASH] = {{RALT(KC_GRAVE), KC_NO}}, // '\'
    [uni_RIGHTBRACKET] = {{RALT(KC_RIGHT_BRACKET), KC_NO}}, // ]
    [uni_CIRCUMFLEX] = {{KC_LEFT_BRACKET, KC_SPACE}}, // ^
    [uni_GRAVE] = {{KC_QUOTE, KC_SPACE}}, // `
    [uni_LEFTCURLYBRACKET] = {{RALT(KC_QUOTE), KC_NO}}, // {
    [uni_PIPE] = {{KC_TILDE, KC_NO}}, // |
    [uni_RIGHTCURLYBRACKET] = {{RALT(KC_BACKSLASH), KC_NO}}, // }
    [uni_TILDE] = {{RALT(KC_SEMICOLON), KC_NO}}, // ~
    [uni_a_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, KC_A}},
    [uni_a_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, KC_A}},
    [uni_a_GRAVE] = {{CAFR_GRAVE_DEAD_KEY, KC_A}},
    [uni_c_CEDILLA] = {{CAFR_CEDILLA_DEAD_KEY, KC_C}},
    [uni_e_ACUTE] = {{CAFR_E_ACUTE, KC_NO}},
    [uni_e_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, KC_E}},
    [uni_e_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, KC_E}},
    [uni_e_GRAVE] = {{CAFR_GRAVE_DEAD_KEY, KC_E}},
    [uni_i_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, KC_I}},
    [uni_i_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, KC_I}},
    // Can't be emitted on CAFR keyboard, use default unicode processing
    [uni_n_TILDE] = {{KC_NO, KC_NO}},
    [uni_o_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, KC_O}},
    [uni_o_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, KC_O}},
    // Can't be emitted on CAFR keyboard, use default unicode processing
    [uni_s_SHARP] = {{KC_NO, KC_NO}},
    [uni_u_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, KC_U}},
    [uni_u_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, KC_U}},
    [uni_u_GRAVE] = {{CAFR_GRAVE_DEAD_KEY, KC_U}},
    [uni_y_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, KC_Y}},
    [uni_A_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, LSFT(KC_A)}},
    [uni_A_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, LSFT(KC_A)}},
    [uni_A_GRAVE] = {{CAFR_GRAVE_DEAD_KEY, LSFT(KC_A)}},
    [uni_C_CEDILLA] = {{CAFR_CEDILLA_DEAD_KEY, LSFT(KC_C)}},
    [uni_E_ACUTE] = {{LSFT(CAFR_E_ACUTE), KC_NO}},
    [uni_E_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, LSFT(KC_E)}},
    [uni_E_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, LSFT(KC_E)}},
    [uni_E_GRAVE] = {{CAFR_GRAVE_DEAD_KEY, LSFT(KC_E)}},
    [uni_I_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, LSFT(KC_I)}},
    [uni_I_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, LSFT(KC_I)}},
    // Can't be emitted on CAFR keyboard, use default unicode processing
    [uni_N_TILDE] = {{KC_NO, KC_NO}},
    [uni_O_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, LSFT(KC_O)}},
    [uni_O_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, LSFT(KC_O)}},
    // Can't be emitted on CAFR keyboard, use default unicode processing
    [uni_S_SHARP] = {{KC_NO, KC_NO}},
    [uni_U_CIRCUMFLEX] = {{CAFR_CIRCUMFLEX_DEAD_KEY, LSFT(KC_U)}},
    [uni_U_DIAERESIS] = {{CAFR_DIAERESIS_DEAD_KEY, LSFT(KC_U)}},
    [uni_U_GRAVE] = {{CAFR_GRAVE_DEAD_KEY, LSFT(KC_U)}},
    // Strangely, lower case ÿ works on CAFR keyboard, but upper case Ÿ doesn't.
    // Use default unicode processing.
    [uni_Y_DIAERESIS] = {{KC_NO, KC_NO}}, // Ÿ
};


#define CMS_CIRCUMFLEX_DEAD_KEY KC_LEFT_BRACKET
#define CMS_DIAERESIS_DEAD_KEY LSFT(KC_LEFT_BRACKET)
#define CMS_GRAVE_DEAD_KEY RALT(KC_LEFT_BRACKET)
#define CMS_TILDE_DEAD_KEY RALT(KC_RIGHT_BRACKET)
#define CMS_A_GRAVE KC_BACKSLASH
#define CMS_C_CEDILLA KC_RIGHT_BRACKET
#define CMS_E_ACUTE KC_SLASH
#define CMS_E_GRAVE KC_QUOTE
#define CMS_U_GRAVE KC_NONUS_BACKSLASH

static const napoli1084_symbol_keys_t PROGMEM cms_symbol_keys_map[uni_COUNT] = {
    [uni_QUOTATION] = {{LSFT(KC_DOT), KC_NO}}, // "
    [uni_HASH] = {{KC_HASH, KC_NO}}, // #
    [uni_APOSTROPHE] = {{LSFT(KC_COMMA), KC_NO}}, // '
    [uni_COMMA] = {{KC_COMMA, KC_NO}}, // ,
    [uni_DOT] = {{KC_DOT, KC_NO}}, // ,
    [uni_SLASH] = {{KC_GRAVE, KC_NO}}, // /
    [uni_LESSTHAN] = {{RALT(KC_COMMA), KC_NO}}, // <
    [uni_GREATERTHAN] = {{RALT(KC_DOT), KC_NO}}, // >
    [uni_QUESTION] = {{LSFT(KC_6), KC_NO}}, // ?
    [uni_AT] = {{KC_AT, KC_NO}}, // @
    [uni_LEFTBRACKET] = {{RALT(KC_9), KC_NO}}, // [
    [uni_BACKSLASH] = {{LSFT(KC_GRAVE), KC_NO}}, // '\'
    [uni_RIGHTBRACKET] = {{RALT(KC_0), KC_NO}}, // ]
    [uni_CIRCUMFLEX] = {{KC_LEFT_BRACKET, KC_SPACE}}, // ^
    [uni_GRAVE] = {{RALT(KC_LEFT_BRACKET), KC_SPACE}}, // `
    [uni_LEFTCURLYBRACKET] = {{RALT(KC_7), KC_NO}}, // {
    [uni_PIPE] = {{RALT(KC_GRAVE), KC_NO}}, // |
    [uni_RIGHTCURLYBRACKET] = {{RALT(KC_8), KC_NO}}, // }
    [uni_TILDE] = {{CMS_TILDE_DEAD_KEY, KC_SPACE}}, // ~
    [uni_a_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, KC_A}},
    [uni_a_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, KC_A}},
    [uni_a_GRAVE] = {{CMS_A_GRAVE, KC_NO}},
    [uni_c_CEDILLA] = {{CMS_C_CEDILLA, KC_NO}},
    [uni_e_ACUTE] = {{CMS_E_ACUTE, KC_NO}},
    [uni_e_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, KC_E}},
    [uni_e_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, KC_E}},
    [uni_e_GRAVE] = {{CMS_E_GRAVE, KC_NO}},
    [uni_i_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, KC_I}},
    [uni_i_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, KC_I}},
    [uni_n_TILDE] = {{CMS_TILDE_DEAD_KEY, KC_N}},
    [uni_o_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, KC_O}},
    [uni_o_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, KC_O}},
    // Can't be emitted on CMS keyboard, use default unicode processing
    [uni_s_SHARP] = {{KC_NO, KC_NO}},
    [uni_u_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, KC_U}},
    [uni_u_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, KC_U}},
    [uni_u_GRAVE] = {{CMS_U_GRAVE, KC_NO}},
    [uni_y_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, KC_Y}},
    [uni_A_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, LSFT(KC_A)}},
    [uni_A_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, LSFT(KC_A)}},
    [uni_A_GRAVE] = {{LSFT(CMS_A_GRAVE), KC_NO}},
    [uni_C_CEDILLA] = {{LSFT(CMS_C_CEDILLA), KC_NO}},
    [uni_E_ACUTE] = {{LSFT(CMS_E_ACUTE), KC_NO}},
    [uni_E_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, LSFT(KC_E)}},
    [uni_E_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, LSFT(KC_E)}},
    [uni_E_GRAVE] = {{LSFT(CMS_E_GRAVE), KC_NO}},
    [uni_I_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, LSFT(KC_I)}},
    [uni_I_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, LSFT(KC_I)}},
    [uni_N_TILDE] = {{CMS_TILDE_DEAD_KEY, LSFT(KC_N)}},
    [uni_O_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, LSFT(KC_O)}},
    [uni_O_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, LSFT(KC_O)}},
    // Can't be emitted on CMS keyboard, use default unicode processing
    [uni_S_SHARP] = {{KC_NO, KC_NO}},
    [uni_U_CIRCUMFLEX] = {{CMS_CIRCUMFLEX_DEAD_KEY, LSFT(KC_U)}},
    [uni_U_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, LSFT(KC_U)}},
    [uni_U_GRAVE] = {{LSFT(CMS_U_GRAVE), KC_NO}},
    [uni_Y_DIAERESIS] = {{CMS_DIAERESIS_DEAD_KEY, LSFT(KC_Y)}}, // Ÿ
};

static const napoli1084_symbol_keys_t PROGMEM us_symbol_keys_map[uni_COUNT] = {
    [uni_QUOTATION] = {{KC_DOUBLE_QUOTE, KC_NO}}, // "
    [uni_HASH] = {{KC_HASH, KC_NO}}, // #
    [uni_APOSTROPHE] = {{KC_QUOTE, KC_NO}}, // '
    [uni_COMMA] = {{KC_COMMA, KC_NO}}, // ,
    [uni_DOT] = {{KC_DOT, KC_NO}}, // ,
    [uni_SLASH] = {{KC_SLASH, KC_NO}}, // /
    [uni_LESSTHAN] = {{KC_LEFT_ANGLE_BRACKET, KC_NO}}, // <
    [uni_GREATERTHAN] = {{KC_RIGHT_ANGLE_BRACKET, KC_NO}}, // >
    [uni_QUESTION] = {{KC_QUESTION, KC_NO}}, // ?
    [uni_AT] = {{KC_AT, KC_NO}}, // @
    [uni_LEFTBRACKET] = {{KC_LEFT_BRACKET, KC_NO}}, // [
    [uni_BACKSLASH] = {{KC_BACKSLASH, KC_NO}}, // '\'
    [uni_RIGHTBRACKET] = {{KC_RIGHT_BRACKET, KC_NO}}, // ]
    [uni_CIRCUMFLEX] = {{KC_CIRCUMFLEX, KC_NO}}, // ^
    [uni_GRAVE] = {{KC_GRAVE, KC_NO}}, // `
    [uni_LEFTCURLYBRACKET] = {{KC_LEFT_CURLY_BRACE, KC_NO}}, // {
    [uni_PIPE] = {{KC_PIPE, KC_NO}}, // |
    [uni_RIGHTCURLYBRACKET] = {{KC_RIGHT_CURLY_BRACE, KC_NO}}, // }
    [uni_TILDE] = {{KC_TILDE, KC_NO}}, // ~
    [uni_a_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_a_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_a_GRAVE] = {{KC_NO, KC_NO}},
    [uni_c_CEDILLA] = {{KC_NO, KC_NO}},
    [uni_e_ACUTE] = {{KC_NO, KC_NO}},
    [uni_e_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_e_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_e_GRAVE] = {{KC_NO, KC_NO}},
    [uni_i_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_i_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_n_TILDE] = {{KC_NO, KC_NO}},
    [uni_o_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_o_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_s_SHARP] = {{KC_NO, KC_NO}},
    [uni_u_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_u_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_u_GRAVE] = {{KC_NO, KC_NO}},
    [uni_y_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_A_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_A_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_A_GRAVE] = {{KC_NO, KC_NO}},
    [uni_C_CEDILLA] = {{KC_NO, KC_NO}},
    [uni_E_ACUTE] = {{KC_NO, KC_NO}},
    [uni_E_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_E_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_E_GRAVE] = {{KC_NO, KC_NO}},
    [uni_I_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_I_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_N_TILDE] = {{KC_NO, KC_NO}},
    [uni_O_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_O_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_S_SHARP] = {{KC_NO, KC_NO}},
    [uni_U_CIRCUMFLEX] = {{KC_NO, KC_NO}},
    [uni_U_DIAERESIS] = {{KC_NO, KC_NO}},
    [uni_U_GRAVE] = {{KC_NO, KC_NO}},
    [uni_Y_DIAERESIS] = {{KC_NO, KC_NO}}, // Ÿ
};

static const napoli1084_symbol_keys_t* const PROGMEM nap_symbol_keys_maps[] = {
    cafr_symbol_keys_map,
    cms_symbol_keys_map,
    us_symbol_keys_map,
};


//#define NAPOLI1084_UNICODE_PRESS_TIMER

#ifdef NAPOLI1084_UNICODE_PRESS_TIMER
static uint16_t unicode_press_timer = 0;
enum {UNICODE_PRESS_BUFFER_SIZE=4};
static uint16_t unicode_press_buffer[UNICODE_PRESS_BUFFER_SIZE] = {0};
static uint16_t unicode_press_count = 0;
#endif

void napoli1084_unregister_mods(uint8_t mods) {
    if (mods & MOD_BIT(KC_LEFT_SHIFT)) {
        unregister_code(KC_LSFT);
        // tap twice to clear sticky key
        tap_code(KC_LSFT);
        tap_code(KC_LSFT);
    }
    if (mods & MOD_BIT(KC_RIGHT_SHIFT)) {
        unregister_code(KC_RSFT);
        // tap twice to clear sticky key
        tap_code(KC_RSFT);
        tap_code(KC_RSFT);
    }
    clear_mods(); // Clear internal mods state
}

void napoli1084_register_mods(uint8_t mods) {
    if (mods & MOD_BIT(KC_LEFT_SHIFT)) {
        register_code(KC_LSFT);
    }
    if (mods & MOD_BIT(KC_RIGHT_SHIFT)) {
        register_code(KC_RSFT);
    }
    set_mods(mods); // Re-set internal mods state
}

void napoli1084_get_symbol_keys(uint16_t                  keycode,
                                napoli1084_symbol_keys_t *entry) {
    uint16_t map_index = unicodemap_index(keycode);

    const napoli1084_symbol_keys_t *const *map_ptr =
        nap_symbol_keys_maps + symbol_mode;
    const napoli1084_symbol_keys_t *entry_ptr = pgm_read_ptr(map_ptr);
    entry_ptr += map_index;
    memcpy_P(entry, entry_ptr, sizeof(napoli1084_symbol_keys_t));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t symbol_saved_mods = 0;

#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, "
            "interrupt: %b, count: %u\n",
            keycode, record->event.key.col, record->event.key.row,
            record->event.pressed, record->event.time,
            record->tap.interrupted, record->tap.count);
#endif

    switch (keycode) {
    case NC_SYMD:
        if (record->event.pressed) {
            napoli1084_cycle_symbol_mode();
        }
        return PROCESS_STOP;
        break;
    case QK_UNICODEMAP ... QK_UNICODEMAP_PAIR_MAX:
        if (symbol_mode < SYMD_KB_COUNT) {
            if (record->event.pressed) {
                napoli1084_symbol_keys_t entry;
                napoli1084_get_symbol_keys(keycode, &entry);

                uint16_t key1 = entry.keys[0];
                if (key1 == KC_NO) {
                    // rely on default `process_unicodemap()`
                    return PROCESS_CONTINUE;
                }

                // Clear mods
                symbol_saved_mods = get_mods(); // Save current mods
                napoli1084_unregister_mods(symbol_saved_mods);

                // Tap keys
                tap_code16(key1);
                uint16_t key2 = entry.keys[1];
                if (key2 != KC_NO) {
                    tap_code16(key2);
                }

                // Re-register mods
                napoli1084_register_mods(symbol_saved_mods);
            }
            return PROCESS_STOP;
        }
#ifdef UNICODEMAP_ENABLE
        else if (symbol_mode == SYMD_UNICODE) {

            #ifdef NAPOLI1084_UNICODE_PRESS_TIMER
            if(record->event.pressed) {
                if (unicode_press_timer == 0) {
                    unicode_press_timer = timer_read();
                    return PROCESS_CONTINUE;
                }
                else {
                    if (unicode_press_count < UNICODE_PRESS_BUFFER_SIZE) {
                        unicode_press_buffer[unicode_press_count] = keycode;
                        ++unicode_press_count;
                    }
                    return PROCESS_STOP;
                }
            }
            #endif

            // Let default `process_unicodemap()` take place
            return PROCESS_CONTINUE;
        }
#endif // UNICODEMAP_ENABLE
        return PROCESS_CONTINUE;
        break;
    case KC_LEFT_CTRL ... KC_RIGHT_GUI:
        if (!record->event.pressed) {
            napoli1084_unregister_mods(symbol_saved_mods);
            symbol_saved_mods = 0;
        }
        break;
    }
    return PROCESS_CONTINUE;
}

void matrix_scan_user(void) {

#ifdef NAPOLI1084_UNICODE_PRESS_TIMER
    if (unicode_press_timer > 0) {
        if (timer_elapsed(unicode_press_timer) > 300) {
            tap_code16(KC_A + unicode_press_count);

            if (unicode_press_count > 0) {
                keyrecord_t record   = {};
                record.event.pressed = true;
                process_unicodemap(unicode_press_buffer[0], &record);
                for (uint16_t i = 0; i < unicode_press_count - 1; ++i) {
                    unicode_press_buffer[i] = unicode_press_buffer[i + 1];
                }
                --unicode_press_count;
                if (unicode_press_count == 0) {
                    unicode_press_timer = 0;
                } else {
                    unicode_press_timer = timer_read();
                }
            } else {
                unicode_press_timer = 0;
            }
        }
    }
#endif

}
