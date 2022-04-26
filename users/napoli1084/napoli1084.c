#include "napoli1084.h"

#include <assert.h> // static_assert

#ifdef TAP_DANCE_ENABLE
// Tap Dance definitions
// Limited to 256, see #define TD(n) (QK_TAP_DANCE | ((n)&0xFF))
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for H, twice for Escape
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
    [uni_SLASH] = 0x002F, // /
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

enum napoli1084_symbols_constants {
    // Combos like SS_LSFT("3") or SS_RALT("2") have a length of 7 + 1 terminating null
    SYMBOL_STRING_MAX_LENGTH = 8
};

typedef struct {
    const char string[SYMBOL_STRING_MAX_LENGTH];
} napoli1084_symbol_string_t;

static const napoli1084_symbol_string_t PROGMEM cafr_symbol_string_map[] = {
    [uni_QUOTATION] = {"@"}, // "
    [uni_HASH] = {"`"}, // #
    [uni_APOSTROPHE] = {"<"}, // '
    [uni_SLASH] = {SS_LSFT("3")}, // /
    [uni_QUESTION] = {SS_LSFT("6")}, // ?
    [uni_AT] = {SS_RALT("2")}, // @
    [uni_LEFTBRACKET] = {SS_RALT("[")}, // [
    [uni_BACKSLASH] = {SS_RALT("`")}, // `\`
    [uni_RIGHTBRACKET] = {SS_RALT("]")}, // ]
    [uni_CIRCUMFLEX] = {"[ "}, // ^ dead key
    [uni_GRAVE] = {"' "}, // ` dead key
    [uni_LEFTCURLYBRACKET] = {SS_RALT("'")}, // {
    [uni_PIPE] = {"~"}, // |
    [uni_RIGHTCURLYBRACKET] = {SS_RALT("\\")}, // }
    [uni_TILDE] = {SS_RALT(";")}, // ~
    [uni_a_CIRCUMFLEX] = {"[a"}, // â
    [uni_a_DIAERESIS] = {"}a"}, // ä
    [uni_a_GRAVE] = {"'a"}, // à
    [uni_c_CEDILLA] = {"]c"}, // ç
    [uni_e_ACUTE] = {"/"}, // é
    [uni_e_CIRCUMFLEX] = {"[e"}, // ê
    [uni_e_DIAERESIS] = {"}e"}, // ë
    [uni_e_GRAVE] = {"'e"}, // è
    [uni_i_CIRCUMFLEX] = {"[i"}, // î
    [uni_i_DIAERESIS] = {"}i"}, // ï
    [uni_n_TILDE] = {"n"}, // ñ
    [uni_o_CIRCUMFLEX] = {"[o"}, // ô
    [uni_o_DIAERESIS] = {"}o"}, // ö
    [uni_s_SHARP] = {"ss"}, // ß
    [uni_u_CIRCUMFLEX] = {"[u"}, // û
    [uni_u_DIAERESIS] = {"}u"}, // ü
    [uni_u_GRAVE] = {"'u"}, // ù
    [uni_y_DIAERESIS] = {"}y"}, // ÿ
    [uni_A_CIRCUMFLEX] = {"[A"}, // Â
    [uni_A_DIAERESIS] = {"}A"}, // Ä
    [uni_A_GRAVE] = {"'A"}, // À
    [uni_C_CEDILLA] = {"]C"}, // Ç
    [uni_E_ACUTE] = {"?"}, // É
    [uni_E_CIRCUMFLEX] = {"[E"}, // Ê
    [uni_E_DIAERESIS] = {"}E"}, // Ë
    [uni_E_GRAVE] = {"'E"}, // È
    [uni_I_CIRCUMFLEX] = {"[I"}, // Î
    [uni_I_DIAERESIS] = {"}I"}, // Ï
    [uni_N_TILDE] = {"N"}, // Ñ
    [uni_O_CIRCUMFLEX] = {"[O"}, // Ô
    [uni_O_DIAERESIS] = {"}O"}, // Ö
    [uni_S_SHARP] = {"SS"}, // ẞ
    [uni_U_CIRCUMFLEX] = {"[U"}, // Û
    [uni_U_DIAERESIS] = {"}U"}, // Ü
    [uni_U_GRAVE] = {"'U"}, // Ù
    [uni_Y_DIAERESIS] = {"}Y"}, // Ÿ
};

static const napoli1084_symbol_string_t PROGMEM cms_symbol_string_map[] = {
    [uni_QUOTATION] = {""}, // "
    [uni_HASH] = {""}, //
    [uni_APOSTROPHE] = {""}, // '
    [uni_SLASH] = {""}, // /
    [uni_QUESTION] = {""}, // ?
    [uni_AT] = {SS_LSFT("2")}, // @
    [uni_LEFTBRACKET] = {""}, // [
    [uni_BACKSLASH] = {""}, // `\`
    [uni_RIGHTBRACKET] = {""}, // ]
    [uni_CIRCUMFLEX] = {""}, // ^
    [uni_GRAVE] = {""}, // `
    [uni_LEFTCURLYBRACKET] = {""}, // {
    [uni_PIPE] = {""}, // |
    [uni_RIGHTCURLYBRACKET] = {""}, // }
    [uni_TILDE] = {""}, // ~
    [uni_a_CIRCUMFLEX] = {""}, // â
    [uni_a_DIAERESIS] = {""}, // ä
    [uni_a_GRAVE] = {""}, // à
    [uni_c_CEDILLA] = {""}, // ç
    [uni_e_ACUTE] = {""}, // é
    [uni_e_CIRCUMFLEX] = {""}, // ê
    [uni_e_DIAERESIS] = {""}, // ë
    [uni_e_GRAVE] = {""}, // è
    [uni_i_CIRCUMFLEX] = {""}, // î
    [uni_i_DIAERESIS] = {""}, // ï
    [uni_n_TILDE] = {""}, // ñ
    [uni_o_CIRCUMFLEX] = {""}, // ô
    [uni_o_DIAERESIS] = {""}, // ö
    [uni_s_SHARP] = {""}, // ß
    [uni_u_CIRCUMFLEX] = {""}, // û
    [uni_u_DIAERESIS] = {""}, // ü
    [uni_u_GRAVE] = {""}, // ù
    [uni_y_DIAERESIS] = {""}, // ÿ
    [uni_A_CIRCUMFLEX] = {""}, // Â
    [uni_A_DIAERESIS] = {""}, // Ä
    [uni_A_GRAVE] = {""}, // À
    [uni_C_CEDILLA] = {""}, // Ç
    [uni_E_ACUTE] = {""}, // É
    [uni_E_CIRCUMFLEX] = {""}, // Ê
    [uni_E_DIAERESIS] = {""}, // Ë
    [uni_E_GRAVE] = {""}, // È
    [uni_I_CIRCUMFLEX] = {""}, // Î
    [uni_I_DIAERESIS] = {""}, // Ï
    [uni_N_TILDE] = {""}, // Ñ
    [uni_O_CIRCUMFLEX] = {""}, // Ô
    [uni_O_DIAERESIS] = {""}, // Ö
    [uni_S_SHARP] = {""}, // ẞ
    [uni_U_CIRCUMFLEX] = {""}, // Û
    [uni_U_DIAERESIS] = {""}, // Ü
    [uni_U_GRAVE] = {""}, // Ù
    [uni_Y_DIAERESIS] = {""}, // Ÿ
};

static const napoli1084_symbol_string_t PROGMEM us_symbol_string_map[] = {
    [uni_QUOTATION] = {""}, // "
    [uni_HASH] = {""}, //
    [uni_APOSTROPHE] = {""}, // '
    [uni_SLASH] = {""}, // /
    [uni_QUESTION] = {""}, // ?
    [uni_AT] = {SS_LSFT("2")}, // @
    [uni_LEFTBRACKET] = {""}, // [
    [uni_BACKSLASH] = {""}, // `\`
    [uni_RIGHTBRACKET] = {""}, // ]
    [uni_CIRCUMFLEX] = {""}, // ^
    [uni_GRAVE] = {""}, // `
    [uni_LEFTCURLYBRACKET] = {""}, // {
    [uni_PIPE] = {""}, // |
    [uni_RIGHTCURLYBRACKET] = {""}, // }
    [uni_TILDE] = {""}, // ~
    [uni_a_CIRCUMFLEX] = {""}, // â
    [uni_a_DIAERESIS] = {""}, // ä
    [uni_a_GRAVE] = {""}, // à
    [uni_c_CEDILLA] = {""}, // ç
    [uni_e_ACUTE] = {""}, // é
    [uni_e_CIRCUMFLEX] = {""}, // ê
    [uni_e_DIAERESIS] = {""}, // ë
    [uni_e_GRAVE] = {""}, // è
    [uni_i_CIRCUMFLEX] = {""}, // î
    [uni_i_DIAERESIS] = {""}, // ï
    [uni_n_TILDE] = {""}, // ñ
    [uni_o_CIRCUMFLEX] = {""}, // ô
    [uni_o_DIAERESIS] = {""}, // ö
    [uni_s_SHARP] = {""}, // ß
    [uni_u_CIRCUMFLEX] = {""}, // û
    [uni_u_DIAERESIS] = {""}, // ü
    [uni_u_GRAVE] = {""}, // ù
    [uni_y_DIAERESIS] = {""}, // ÿ
    [uni_A_CIRCUMFLEX] = {""}, // Â
    [uni_A_DIAERESIS] = {""}, // Ä
    [uni_A_GRAVE] = {""}, // À
    [uni_C_CEDILLA] = {""}, // Ç
    [uni_E_ACUTE] = {""}, // É
    [uni_E_CIRCUMFLEX] = {""}, // Ê
    [uni_E_DIAERESIS] = {""}, // Ë
    [uni_E_GRAVE] = {""}, // È
    [uni_I_CIRCUMFLEX] = {""}, // Î
    [uni_I_DIAERESIS] = {""}, // Ï
    [uni_N_TILDE] = {""}, // Ñ
    [uni_O_CIRCUMFLEX] = {""}, // Ô
    [uni_O_DIAERESIS] = {""}, // Ö
    [uni_S_SHARP] = {""}, // ẞ
    [uni_U_CIRCUMFLEX] = {""}, // Û
    [uni_U_DIAERESIS] = {""}, // Ü
    [uni_U_GRAVE] = {""}, // Ù
    [uni_Y_DIAERESIS] = {""}, // Ÿ
};

static const napoli1084_symbol_string_t* const PROGMEM nap_symbol_string_maps[] = {
    cafr_symbol_string_map,
    cms_symbol_string_map,
    us_symbol_string_map,
};

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

// static_assert available in C11
#ifndef static_assert
#define static_assert(constant_expression, string_literal)
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    static_assert(RGBLIGHT_MAX_LAYERS >= RGBLYR_COUNT, "Max RGB layers must be greater or equal to number of layers");
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
/*
static bool is_shift_pressed(void)
{
    return get_mods() & MOD_MASK_SHIFT;
}


static bool napoli1084_process_slash(keyrecord_t *record)
{
    switch (symbol_mode)
    {
    case SYMD_KB_CAFR:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                tap_code16(LSFT(KC_6)); // ?
            }
            else {
                tap_code16(LSFT(KC_3)); // '\'
            }
        }
        return false;
        break;
    case SYMD_KB_CMS:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                tap_code16(LSFT(KC_6)); // ?
            }
            else {
                tap_code16(KC_GRAVE); // '\'
            }
        }
        return false;
        break;
#ifdef UNICODEMAP_ENABLE
    case SYMD_UNICODE:
        return false;
        break;
#endif
    }
    return true; // let default processing occur
}*/


//#define NAPOLI1084_UNICODE_PRESS_TIMER

#ifdef NAPOLI1084_UNICODE_PRESS_TIMER
static uint16_t unicode_press_timer = 0;
enum {UNICODE_PRESS_BUFFER_SIZE=4};
static uint16_t unicode_press_buffer[UNICODE_PRESS_BUFFER_SIZE] = {0};
static uint16_t unicode_press_count = 0;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    //case KC_SLASH:
        //return napoli1084_process_slash(record);
        //break;
    case NC_SYMD:
        if (record->event.pressed) {
            napoli1084_cycle_symbol_mode();
        }
        return false;
        break;
    case QK_UNICODEMAP ... QK_UNICODEMAP_PAIR_MAX:
        if (symbol_mode < SYMD_KB_COUNT) {
            if (record->event.pressed) {
                const napoli1084_symbol_string_t *const *map_ptr = nap_symbol_string_maps + symbol_mode;
                uint16_t map_index = unicodemap_index(keycode);
                const napoli1084_symbol_string_t *entry_ptr = pgm_read_ptr(map_ptr);
                entry_ptr += map_index;
                send_string_P(entry_ptr->string);

                #if 0
                size_t len = strlen_P(entry_ptr->string);
                tap_code16(KC_A + (uint16_t)len);
                #endif
            }
            return false;
        }
#ifdef UNICODEMAP_ENABLE
        else if (symbol_mode == SYMD_UNICODE) {

            #ifdef NAPOLI1084_UNICODE_PRESS_TIMER
            if(record->event.pressed) {
                if (unicode_press_timer == 0) {
                    unicode_press_timer = timer_read();
                    return true;
                }
                else {
                    if (unicode_press_count < UNICODE_PRESS_BUFFER_SIZE) {
                        unicode_press_buffer[unicode_press_count] = keycode;
                        ++unicode_press_count;
                    }
                    return false;
                }
            }
            #endif
            #if 0
            if(record->event.pressed) {
                static uint16_t press_count = 0;
                ++press_count;
                press_count = press_count % 2;
                tap_code16(KC_A + press_count);
            //wait_ms(100);
            //tap_code16(KC_A + (uint16_t)record->tap.count);
            }
            #endif

            // Let default unicode map processing take place
            return true;

            //process_unicodemap(keycode, record);
        }
#endif // UNICODEMAP_ENABLE
        return true;
        break;
    }
    return true;
}

void matrix_scan_user(void) {

#ifdef NAPOLI1084_UNICODE_PRESS_TIMER
  if (unicode_press_timer > 0) {
    if (timer_elapsed(unicode_press_timer) > 300) {
        tap_code16(KC_A + unicode_press_count);

        if (unicode_press_count > 0) {
            keyrecord_t record = {};
            record.event.pressed = true;
            process_unicodemap(unicode_press_buffer[0], &record);
            for (uint16_t i = 0; i<unicode_press_count-1; ++i)
            {
                unicode_press_buffer[i] = unicode_press_buffer[i+1];
            }
            --unicode_press_count;
            if (unicode_press_count == 0) {
                unicode_press_timer = 0;
            }
            else {
                unicode_press_timer = timer_read();
            }
        }
        else {
            unicode_press_timer = 0;
        }
    }
  }
#endif
}
