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

#pragma once

#include "quantum/quantum_keycodes.h"

enum napoli1084_layers {
#ifdef NAPOLI1084_QWERTY_ENABLE
    LYR_QWERTY, // Default layer on keyboards I share with other people
    LYR_QNAVNUM, // Navigation/numpad layer for qwerty users
#endif
    LYR_WORKNAP, // My main default layer, based on Workman layout
    LYR_GAME, // Game layer
    LYR_NAVNUM, // Navigation (arrows, home/end, page up/down) / numpad layer
    LYR_FRSYMBOL, // French symbols layer
#ifdef NAPOLI1084_FRCAPS_ENABLE
    LYR_FRCAPS, // Capital french symbols layer
#endif
#ifdef NAPOLI1084_MOUSE_LAYER_ENABLE
    LYR_MOUSE, // Mouse layer
#endif
    LYR_FN, // Function keys layer
    LYR_F1F12, // F keys layer
    LYR_WINDOWS, // Windows combos layers
    LYR_COUNT, // Number of layers
#ifdef NAPOLI1084_QWERTY_ENABLE
    LYR_DEFAULT = LYR_QWERTY
#else
    LYR_DEFAULT = LYR_WORKNAP
#endif
};

enum napoli1084_keycodes {
    // NC = NapOli1084 Code
    NC_SYMD = SAFE_RANGE, // Symbol Mode cycle

    NAP_RGB_BEGIN,
    RGB_DBG = NAP_RGB_BEGIN, // RGB debug, prints RGB state to console
    RGB_EEP, // Save RGB settings to EEPROM
    RGB_LYR, // RGB layer mode
    NAP_RGB_END = RGB_LYR,
};

enum napoli1084_tap_dance_id {
    tap_dance_reset,
    tap_dance_h_esc,
    tap_dance_ctl_z_ctl_a,
    tap_dance_ctl_s_ctl_x,
    tap_dance_ctl_c_F5,
    tap_dance_F7_ctl_F7,
    tap_dance_ctl_f_F3,
    tap_dance_ctl_p_ctl_o,
    tap_dance_game_w,
    tap_dance_count
};

enum unicode_names {
    uni_QUOTATION,
    uni_HASH,
    uni_APOSTROPHE,
    uni_COMMA,
    uni_DOT,
    uni_SLASH,
    uni_LESSTHAN,
    uni_GREATERTHAN,
    uni_QUESTION,
    uni_AT,
    uni_LEFTBRACKET,
    uni_BACKSLASH,
    uni_RIGHTBRACKET,
    uni_CIRCUMFLEX,
    uni_GRAVE,
    uni_LEFTCURLYBRACKET,
    uni_PIPE,
    uni_RIGHTCURLYBRACKET,
    uni_TILDE,
    uni_a_CIRCUMFLEX,
    uni_a_DIAERESIS,
    uni_a_GRAVE,
    uni_c_CEDILLA,
    uni_e_ACUTE,
    uni_e_CIRCUMFLEX,
    uni_e_DIAERESIS,
    uni_e_GRAVE,
    uni_i_CIRCUMFLEX,
    uni_i_DIAERESIS,
    uni_n_TILDE,
    uni_o_CIRCUMFLEX,
    uni_o_DIAERESIS,
    uni_s_SHARP,
    uni_u_CIRCUMFLEX,
    uni_u_DIAERESIS,
    uni_u_GRAVE,
    uni_y_DIAERESIS,
    uni_A_CIRCUMFLEX,
    uni_A_DIAERESIS,
    uni_A_GRAVE,
    uni_C_CEDILLA,
    uni_E_ACUTE,
    uni_E_CIRCUMFLEX,
    uni_E_DIAERESIS,
    uni_E_GRAVE,
    uni_I_CIRCUMFLEX,
    uni_I_DIAERESIS,
    uni_N_TILDE,
    uni_O_CIRCUMFLEX,
    uni_O_DIAERESIS,
    uni_S_SHARP,
    uni_U_CIRCUMFLEX,
    uni_U_DIAERESIS,
    uni_U_GRAVE,
    uni_Y_DIAERESIS,
    uni_COUNT // not an ID, provides number of IDs
};
