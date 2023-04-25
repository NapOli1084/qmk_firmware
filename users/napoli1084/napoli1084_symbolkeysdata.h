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
#include "napoli1084_symbolkeys.h"

#include "napoli1084_keycodeenums.h"

#ifdef UNICODEMAP_ENABLE

// See:
// #define XP(i, j) (QK_UNICODEMAP_PAIR | ((i)&0x7F) | (((j)&0x7F) << 7)) // 127 max i and j
_Static_assert(uni_COUNT <= 0x7F+1, "Number of unicode map indexes cannot exceed 128, see XP()");

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

#endif // #ifdef UNICODEMAP_ENABLE

////////////////////////////////////////////////////////////////////////////////

#ifndef NAPOLI1084_SYMD_KB_CAFR_DISABLE

#define CAFR_CEDILLA_DEAD_KEY KC_RIGHT_BRACKET
#define CAFR_CIRCUMFLEX_DEAD_KEY KC_LEFT_BRACKET
#define CAFR_DIAERESIS_DEAD_KEY LSFT(KC_RIGHT_BRACKET)
#define CAFR_GRAVE_DEAD_KEY KC_QUOTE
#define CAFR_HASH KC_GRAVE
#define CAFR_QUOTE LSFT(KC_COMMA)
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
    [uni_GREATERTHAN] = {{LSFT(KC_BACKSLASH), KC_NO}}, // >
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
#endif // #ifndef NAPOLI1084_SYMD_KB_CAFR_DISABLE

#ifndef NAPOLI1084_SYMD_KB_CMS_DISABLE

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
#endif // #ifndef NAPOLI1084_SYMD_KB_CMS_DISABLE

#ifndef NAPOLI1084_SYMD_KB_US_DISABLE
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
#endif // #ifndef NAPOLI1084_SYMD_KB_US_DISABLE

static const napoli1084_symbol_keys_t* const PROGMEM nap_symbol_keys_maps[] = {
    #ifndef NAPOLI1084_SYMD_KB_CAFR_DISABLE
    cafr_symbol_keys_map,
    #endif
    #ifndef NAPOLI1084_SYMD_KB_CMS_DISABLE
    cms_symbol_keys_map,
    #endif
    #ifndef NAPOLI1084_SYMD_KB_US_DISABLE
    us_symbol_keys_map,
    #endif
};

