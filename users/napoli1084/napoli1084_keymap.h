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

#define NAPOLI1084_LAYOUT_LYR_WORKNAP NAPOLI1084_LAYOUT( \
  //lPinky3, lPinky2, lPinky1, lRing  , lMiddle, lIndex1, lIndex2, lIndex3,    rIndex3, rIndex2, rIndex1, rMiddle, rRing  , rPinky1, rPinky2, rPinky3,
    KC_NO  , TODEFLT, KC_NO  , KC_NO  , TTGAME , KC_HYPR, TODEFLT, KC_NO  ,    KC_NO  , TODEFLT, TTNVNUM, KC_MEH , KC_NO  , KC_NO  , WN_APP , KC_NO  , \
    KC_NO  , WN_ESC , WN_1   , WN_2   , WN_3   , WN_4   , WN_5   , KC_NO  ,    KC_NO  , WN_6   , WN_7   , WN_8   , WN_9   , WN_0   , WN_DEL , KC_NO  , \
    KC_NO  , WN_TAB , WN_Q   , WN_D   , WN_R   , WN_W   , WN_B   , KC_NO  ,    KC_NO  , WN_J   , WN_F   , WN_U   , WN_P   , WN_SCOL, WN_BSPC, KC_NO  , \
    KC_NO  , WN_LSFT, WN_A   , WN_S   , WN_H   , WN_T   , WN_G   , KC_NO  ,    KC_NO  , WN_Y   , WN_N   , WN_E   , WN_O   , WN_I   , WN_RSFT, KC_NO  , \
    KC_NO  , WN_LCTL, WN_Z   , WN_X   , WN_M   , WN_C   , WN_V   , KC_NO  ,    KC_NO  , WN_K   , WN_L   , WN_COMM, WN_DOT , WN_SLSH, WN_RCTL, KC_NO  , \
    KC_NO  , KC_NO  , KC_NO  , WN_LWIN, WN_LALT, KC_NO  , KC_NO  , KC_NO  ,    KC_NO  , KC_NO  , KC_NO  , WN_RALT, WN_RWIN, KC_NO  , KC_NO  , KC_NO  , \
  //leftThumb1, leftThumb2, leftThumb3, leftThumb4, leftThumb5, leftThumb6, leftThumb7, leftThumb8, rightThumb8, rightThumb7, rightThumb6, rightThumb5, rightThumb4, rightThumb3, rightThumb2, rightThumb1
    WN_LTB1, WN_LTB2, WN_LTB3, WN_LTB4, KC_WH_D, KC_WH_U, WL_LTB4, KC_NO  , rightThumb8, rightThumb7, rightThumb6, rightThumb5, rightThumb4, rightThumb3, rightThumb2, rightThumb1 \
)
