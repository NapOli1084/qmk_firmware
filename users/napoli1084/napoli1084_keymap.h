/*
Copyright 2023 NapOli1084 (@napoli1084)

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

#ifndef NAPOLI1084_LAYOUT
#error NAPOLI1084_LAYOUT() not defined
#endif

#ifndef NAPOLI1084_LAYOUT_STD
#define NAPOLI1084_LAYOUT_STD NAPOLI1084_LAYOUT
#endif

  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_QWERTY NAPOLI1084_LAYOUT_STD( \
    KC_NO  , NC_RSET, KC_NO  , KC_NO  , TTGAME , KC_HYPR, NC_RSET, KC_NO  ,    KC_NO  , NC_RSET, TTNVNUM, KC_MEH , KC_NO  , KC_NO  , NC_RSET, KC_NO  , \
    KC_ESC , KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , NC_RSET,    NC_RSET, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_BSPC, \
    KC_BSLS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_NO  ,    KC_NO  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, \
    TTWRKNP, KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_NO  ,    KC_NO  , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , \
    KC_F2  , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , TTGAME ,    KC_NO  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_EQL , \
    NC_RSET, KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, KC_NO  , KC_NO  , KC_NO  ,    KC_NO  , KC_NO  , KC_NO  , KC_RALT, KC_RGUI, KC_APP , KC_RCTL, KC_DEL , \
    KC_NO  ,OSL_QNAV,KC_SPACE, KC_NO  , KC_NO  , KC_WH_D, KC_WH_U, NC_RSET,    NC_RSET, KC_PGUP, KC_PGDN, KC_NO  , KC_NO  , KC_SPC , OSL_FN , KC_NO \
)


  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_QNAVNUM NAPOLI1084_LAYOUT_STD( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_NO  , KC_PSCR, KC_SCRL, KC_PAUS, KC_INS , _______,    _______, KC_CIRC, KC_NUM , KC_PSLS, KC_ASTR,KC_MINUS, _______, _______, \
    _______, _______, KC_WH_L, KC_HOME, KC_UP  , KC_PGUP, KC_WH_R, _______,    _______, KC_PERC, KC_7   , KC_8   , KC_9   , KC_PLUS, _______, _______, \
    _______, _______, KC_WH_U, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_U, _______,    _______, KC_DLR , KC_4   , KC_5   , KC_6   , KC_PLUS, _______, _______, \
    _______, _______, KC_WH_L, KC_END , KC_WH_D, KC_PGDN, KC_WH_R, _______,    _______, KC_HASH, KC_1   , KC_2   , KC_3   , KC_EQL , _______, _______, \
    _______, _______, KC_NUBS, KC_LGUI, KC_LALT, KC_NO  , KC_NO  , _______,    _______, KC_NO  , KC_NO  , KC_0   , KC_DOT , KC_EQL , _______, _______, \
    _______, HOLDLYR, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, KC_0   , _______ \
)

  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_WORKNAP NAPOLI1084_LAYOUT( \
    _______, NC_RSET, KC_NO  , KC_NO  , TTGAME , KC_HYPR, NC_RSET, KC_NO  ,    KC_NO  , NC_RSET, TTNVNUM, KC_MEH , KC_NO  , KC_NO  , NC_RSET, _______, \
    TTGAME , KC_ESC , TD_CTLZ, TD_CTLS, TD_CTLC, CTL_V  , TD_F7  , NC_RSET,    NC_RSET, KC_TAB , TD_CTLF, KC_SPC , TD_CTLP, KC_0   , KC_DEL , TTMOUSE, \
    HOLDLYR, KC_TAB , LCTL_Q , KC_D   , KC_R   , KC_W   , KC_B   , KC_NO  ,    KC_NO  , KC_J   , KC_F   , KC_U   , KC_P   , RCTL_SC, KC_BSPC, _______, \
    OSL_F12, WN_LSFT, LSFT_A , KC_S   ,TD_H_ESC, LTWIN_T, KC_G   , KC_NO  ,    KC_NO  , KC_Y   , LTF1_N , KC_E   , KC_O   , RSFT_I , WN_RSFT, OSL_WIN, \
    NC_RSET, WN_LCTL, LCTL_Z , KC_X   , KC_M   , KC_C   , KC_V   , TTGAME ,    KC_NO  , KC_K   , KC_L   , UN_COMM, UN_DOT , UN_SLSH, WN_RCTL, _______, \
    KC_NO  , KC_NO  , KC_NO  , KC_LGUI, KC_LALT, KC_NO  , KC_NO  , KC_NO  ,    KC_NO  , KC_NO  , KC_NO  , KC_APP , KC_LGUI, KC_NO  , KC_NO  , KC_NO  , \
    KC_NO  , OSL_NAV,KC_SPACE, OSL_F12, TTGAME , KC_WH_D, KC_WH_U, NC_RSET,    NC_RSET, KC_PGUP, KC_PGDN, TTMOUSE, OSL_WIN,KC_ENTER, OSL_FRS, KC_NO \
)

  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_GAME NAPOLI1084_LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_ESC , KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,    _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, \
    _______, KC_TAB , KC_T   , KC_Q   , TD_GAMW, KC_E   , KC_R   , KC_T   ,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_G   , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_B   , KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_M   , KC_LALT, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______,KC_SPACE, SH_OS  , _______, _______, KC_H   , KC_5   , _______,    _______, _______, _______, _______, _______, _______, _______, _______ \
)

  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_NAVNUM NAPOLI1084_LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_NO  , KC_PSCR, KC_SCRL, KC_PAUS, KC_INS , _______,    _______, UN_CIRC, KC_NUM , KC_PSLS, KC_PAST, KC_MINUS,_______, _______, \
    _______, _______, KC_WH_L, KC_HOME, KC_UP  , KC_PGUP, KC_WH_R, _______,    _______, KC_PERC, KC_7   , KC_8   , KC_9   , KC_MINUS,_______, _______, \
    _______, _______, KC_WH_U, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_U, _______,    _______, KC_DLR , KC_4   , KC_5   , KC_6   , KC_PLUS, _______, _______, \
    _______, _______, KC_WH_L, KC_END , KC_WH_D, KC_PGDN, KC_WH_R, _______,    _______, UN_HASH, KC_1   , KC_2   , KC_3   , KC_EQL , _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_0   , KC_DOT , _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, OSL_FN , _______ \
)

  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_FRSYMBOL NAPOLI1084_LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, NC_RSET, _______, \
    _______, n_TILDE, a_DIAER, UN_AT  , UN_HASH, KC_DLR , KC_PERC, _______,    _______, y_DIAER, u_DIAER, e_DIAER, o_DIAER, i_DIAER, _______, _______, \
    _______, s_SHARP, a_CIRCM, UN_RCBR, UN_LCBR, UN_GRAV, UN_CIRC, _______,    _______, KC_PERC, u_CIRCM, e_CIRCM, o_CIRCM, i_CIRCM, _______, _______, \
    _______,OSM_LSFT, a_GRAVE, KC_RPRN, KC_LPRN, KC_UNDS, KC_AMPR, _______,    _______, KC_DLR , u_GRAVE, e_ACUTE, UN_DQUO, UN_APOS,OSM_RSFT, _______, \
    _______, _______, KC_EXLM, UN_RBRC, UN_LBRC, c_CEDIL, UN_TILD, _______,    _______, UN_HASH, KC_ASTR, e_GRAVE, UN_BSLS, UN_PIPE, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, OSL_FRC, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, HOLDLYR, _______ \
)

#ifdef NAPOLI1084_FRCAPS_ENABLE
  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_FRCAPS NAPOLI1084_LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, NC_RSET, _______, \
    _______, N_TILDE, A_DIAER, _______, _______, _______, _______, _______,    _______, Y_DIAER, U_DIAER, E_DIAER, O_DIAER, I_DIAER, _______, _______, \
    _______, S_SHARP, A_CIRCM, _______, _______, _______, _______, _______,    _______, _______, U_CIRCM, E_CIRCM, O_CIRCM, I_CIRCM, _______, _______, \
    _______, _______, A_GRAVE, _______, _______, _______, _______, _______,    _______, _______, U_GRAVE, E_ACUTE, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, C_CEDIL, _______, _______,    _______, _______, _______, E_GRAVE, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, HOLDLYR, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______ \
)
#endif

  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_FN NAPOLI1084_LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, NC_RSET, _______, \
    _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,    _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______, \
    _______, _______, RGB_EEP, RGB_HUI, RGB_SAI, RGB_VAI, RGB_LYR, _______,    _______, BL_UP  , KC_BRIU, KC_VOLU, KC_MSTP, KC_MPRV, _______, _______, \
    _______, _______, RGB_DBG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD, _______,    _______, BL_DOWN, KC_BRID, KC_VOLD, KC_MPLY, KC_MNXT, _______, _______, \
    _______, _______, OS_TOGG, DB_TOGG, UC_NEXT, NC_SYMD, RGB_TOG, _______,    _______, BL_TOGG, KC_NO  , KC_MUTE, KC_NO  , KC_NO  , _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, HOLDLYR, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, HOLDLYR, _______ \
)

  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_F1F12 NAPOLI1084_LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, NC_RSET, _______, \
    _______, _______, KC_F21 , KC_F10 , KC_F11 , KC_F12 , KC_F22 , _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_F18 , KC_F7  , KC_F8  , KC_F9  , KC_F19 , _______,    _______, KC_WAKE, WINLEFT, WINUP  , WINRGHT, _______, _______, _______, \
    _______, _______, KC_F15 , KC_F4  , KC_F5  , KC_F6  , KC_F16 , _______,    _______, KC_SLEP, WINSFTL, WINDOWN, WINSFTR, ALT_F4 , _______, _______, \
    _______, _______, KC_F14 , KC_F1  , KC_F2  , KC_F3  , KC_F13 , _______,    _______, KC_PWR , WINCTLL, _______, WINCTLR, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, HOLDLYR, _______, _______, _______, _______,    _______, _______, _______, _______, HOLDLYR, _______, _______, _______ \
)

#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
  //lThumb0, lThumb1, lThumb2, lThumb3, lThumb4, lThumb5, lThumb6, lThumb7,    rThumb7, rThumb6, rThumb5, rThumb4, rThumb3, rThumb2, rThumb1, rThumb0
#define NAPOLI1084_LAYOUT_LYR_WINDOWS NAPOLI1084_LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, NC_RSET, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_MPRV, KC_VOLU, _______, _______, _______,    _______, KC_WAKE, WINLEFT, WINUP  , WINRGHT, _______, _______, _______, \
    _______, _______, _______, KC_MNXT, KC_VOLD, HOLDLYR, _______, _______,    _______, KC_SLEP, WINSFTL, WINDOWN, WINSFTR, ALT_F4 , _______, _______, \
    _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______,    _______, KC_PWR , WINCTLL, _______, WINCTLR, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, HOLDLYR, _______, _______, _______ \
)
#endif

#ifndef NAPOLI1084_KEYMAPS_DISABLE
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef NAPOLI1084_QWERTY_ENABLE
    [LYR_QWERTY] = NAPOLI1084_LAYOUT_LYR_QWERTY,
    [LYR_QNAVNUM] = NAPOLI1084_LAYOUT_LYR_QNAVNUM,
#endif
    [LYR_WORKNAP] = NAPOLI1084_LAYOUT_LYR_WORKNAP,
    [LYR_GAME] = NAPOLI1084_LAYOUT_LYR_GAME,
    [LYR_NAVNUM] = NAPOLI1084_LAYOUT_LYR_NAVNUM,
    [LYR_FRSYMBOL] = NAPOLI1084_LAYOUT_LYR_FRSYMBOL,
#ifdef NAPOLI1084_FRCAPS_ENABLE
    [LYR_FRCAPS] = NAPOLI1084_LAYOUT_LYR_FRCAPS,
#endif
    [LYR_FN] = NAPOLI1084_LAYOUT_LYR_FN,
    [LYR_F1F12] = NAPOLI1084_LAYOUT_LYR_F1F12,
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
    [LYR_WINDOWS] = NAPOLI1084_LAYOUT_LYR_WINDOWS
#endif
};
#endif
