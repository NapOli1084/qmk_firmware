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

#include "napoli1084_keycodeenums.h"
#include "quantum.h"


// One-shot layer keys
#define OSL_QNAV OSL(LYR_QNAVNUM)
#define OSL_NAV OSL(LYR_NAVNUM)
#define OSL_FN OSL(LYR_FN)
#define OSL_F12 OSL(LYR_F1F12)
#define OSL_FRS OSL(LYR_FRSYMBOL)
#ifdef NAPOLI1084_FRCAPS_ENABLE
    #define OSL_FRC OSL(LYR_FRCAPS)
#else
    #define OSL_FRC OSM(MOD_LSFT)
#endif
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
    #define OSL_WIN OSL(LYR_WINDOWS)
#else
    #define OSL_WIN OSL(LYR_F1F12)
#endif

// Layer TO keys
#define TODEFLT TO(LYR_DEFAULT)

// Layer Tap-Toggle keys
#define TTGAME TT(LYR_GAME)
#define TTNVNUM TT(LYR_NAVNUM)
#define TTWRKNP TT(LYR_WORKNAP)

#ifdef NAPOLI1084_MOUSE_LAYER_ENABLE
    #define TTMOUSE TT(LYR_MOUSE)
#else
    #define TTMOUSE KC_NO
#endif

// Layer-tap (layer when held, key code when tapped)
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
    #define LTWIN_T LT(LYR_WINDOWS,KC_T)
    #define LTF1_N LT(LYR_F1F12,KC_N)
#else
    #define LTWIN_T KC_T
    #define LTF1_N KC_N
#endif

// Placeholder for key being held to toggle current layer.
#define HOLDLYR KC_TRANSPARENT

// One shot mods
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)

#define CTL_A LCTL(KC_A)
#define CTL_S LCTL(KC_S)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define CTL_F LCTL(KC_F)
#define CTL_P LCTL(KC_P)
#define CTL_O LCTL(KC_O)
#define CTL_F7 LCTL(KC_F7)

// Hold for CTL/SFT, tap for char
#define LCTL_Q LCTL_T(KC_Q)
#define LSFT_A LSFT_T(KC_A)
#define LCTL_Z LCTL_T(KC_Z)
#define RCTL_SC RCTL_T(KC_SEMICOLON)
#define RSFT_I RSFT_T(KC_I)
#define RCTL_SL RCTL_T(KC_SLASH)

#define WINSFTL LGUI(LSFT(KC_LEFT))
#define WINSFTR LGUI(LSFT(KC_RIGHT))
#define WINDOWN LGUI(KC_DOWN)
#define ALT_F4  LALT(KC_F4)
#define WINLEFT LGUI(KC_LEFT)
#define WINUP LGUI(KC_UP)
#define WINRGHT LGUI(KC_RIGHT)
#define WINCTLL LCTL(LGUI(KC_LEFT))
#define WINCTLR LCTL(LGUI(KC_RIGHT))

////////////////////////////////////////////////////////////////////////////////////////////////////
// Tap Dance declarations

#ifdef TAP_DANCE_ENABLE

#define TD_H_ESC TD(tap_dance_h_esc)
#define TD_CTLZ TD(tap_dance_ctl_z_ctl_a)
#define TD_CTLS TD(tap_dance_ctl_s_ctl_x)
#define TD_CTLC TD(tap_dance_ctl_c_F5)
#define TD_CTLF TD(tap_dance_ctl_f_F3)
#define TD_F7 TD(tap_dance_F7_ctl_F7)
#define TD_CTLP TD(tap_dance_ctl_p_ctl_o)
#define TD_GAMW TD(tap_dance_game_w)

#define NC_RSET TD(tap_dance_reset)

#endif // #ifdef TAP_DANCE_ENABLE
////////////////////////////////////////////////////////////////////////////////

#define UN_HASH UM(uni_HASH)
#define UN_APOS UM(uni_APOSTROPHE)
#define UN_COMM UP(uni_COMMA, uni_LESSTHAN)
#define UN_DOT UP(uni_DOT, uni_GREATERTHAN)
#define UN_SLSH UP(uni_SLASH, uni_QUESTION)
#define UN_DQUO UM(uni_QUOTATION)
#define UN_AT UM(uni_AT)
#define UN_LBRC UM(uni_LEFTBRACKET)
#define UN_RBRC UM(uni_RIGHTBRACKET)
#define UN_BSLS UM(uni_BACKSLASH)
#define UN_CIRC UM(uni_CIRCUMFLEX)
#define UN_GRAV UM(uni_GRAVE)
#define UN_LCBR UM(uni_LEFTCURLYBRACKET)
#define UN_RCBR UM(uni_RIGHTCURLYBRACKET)
#define UN_PIPE UM(uni_PIPE)
#define UN_TILD UM(uni_TILDE)

#define a_CIRCM UP(uni_a_CIRCUMFLEX, uni_A_CIRCUMFLEX)
#define a_DIAER UP(uni_a_DIAERESIS, uni_A_DIAERESIS)
#define a_GRAVE UP(uni_a_GRAVE, uni_A_GRAVE)
#define c_CEDIL UP(uni_c_CEDILLA, uni_C_CEDILLA)
#define e_ACUTE UP(uni_e_ACUTE, uni_E_ACUTE)
#define e_CIRCM UP(uni_e_CIRCUMFLEX, uni_E_CIRCUMFLEX)
#define e_GRAVE UP(uni_e_GRAVE, uni_E_GRAVE)
#define e_DIAER UP(uni_e_DIAERESIS, uni_E_DIAERESIS)
#define i_CIRCM UP(uni_i_CIRCUMFLEX, uni_I_CIRCUMFLEX)
#define i_DIAER UP(uni_i_DIAERESIS, uni_I_DIAERESIS)
#define n_TILDE UP(uni_n_TILDE, uni_N_TILDE)
#define o_CIRCM UP(uni_o_CIRCUMFLEX, uni_O_CIRCUMFLEX)
#define o_DIAER UP(uni_o_DIAERESIS, uni_O_DIAERESIS)
#define s_SHARP UP(uni_s_SHARP, uni_S_SHARP)
#define u_CIRCM UP(uni_u_CIRCUMFLEX, uni_U_CIRCUMFLEX)
#define u_DIAER UP(uni_u_DIAERESIS, uni_U_DIAERESIS)
#define u_GRAVE UP(uni_u_GRAVE, uni_U_GRAVE)
#define y_DIAER UP(uni_y_DIAERESIS, uni_Y_DIAERESIS)

#define A_CIRCM UM(uni_A_CIRCUMFLEX)
#define A_DIAER UM(uni_A_DIAERESIS)
#define A_GRAVE UM(uni_A_GRAVE)
#define C_CEDIL UM(uni_C_CEDILLA)
#define E_ACUTE UM(uni_E_ACUTE)
#define E_CIRCM UM(uni_E_CIRCUMFLEX)
#define E_GRAVE UM(uni_E_GRAVE)
#define E_DIAER UM(uni_E_DIAERESIS)
#define I_CIRCM UM(uni_I_CIRCUMFLEX)
#define I_DIAER UM(uni_I_DIAERESIS)
#define N_TILDE UM(uni_N_TILDE)
#define O_CIRCM UM(uni_O_CIRCUMFLEX)
#define O_DIAER UM(uni_O_DIAERESIS)
#define S_SHARP UM(uni_S_SHARP)
#define U_CIRCM UM(uni_U_CIRCUMFLEX)
#define U_DIAER UM(uni_U_DIAERESIS)
#define U_GRAVE UM(uni_U_GRAVE)
#define Y_DIAER UM(uni_Y_DIAERESIS)

////////////////////////////////////////////////////////////////////////////////

// Worknap Keys
#ifdef NAPOLI1084_ONE_SHOT_MODS
    #define WN_LSFT OSM(MOD_LSFT)
    #define WN_RSFT OSM(MOD_RSFT)
    #define WN_LCTL OSM(MOD_LCTL)
    #define WN_RCTL OSM(MOD_RCTL)
    #define WN_RWIN OSM(MOD_LGUI)
#else
    #define WN_LSFT KC_LSFT
    #define WN_RSFT KC_RSFT
    #define WN_LCTL KC_LCTL
    #define WN_RCTL KC_RCTL
    #define WN_RWIN KC_LGUI
#endif

