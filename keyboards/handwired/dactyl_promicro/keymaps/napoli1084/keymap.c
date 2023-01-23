/*
Copyright 2021-2022 NapOli1084 (@napoli1084)

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

#include QMK_KEYBOARD_H
#include "napoli1084_keycodes.h" // users/napoli1084

#ifndef RGBLIGHT_SPLIT
#error RGBLIGHT_SPLIT not defined
#endif

#define NAPOLI1084_LAYOUT( \
    leftPinky3Row0, leftPinky2Row0, leftPinky1Row0, leftRingRow0, leftMiddleRow0, leftIndex1Row0, leftIndex2Row0, leftIndex3Row0, rightIndex3Row0, rightIndex2Row0, rightIndex1Row0, rightMiddleRow0, rightRingRow0, rightPinky1Row0, rightPinky2Row0, rightPinky3Row0, \
    leftPinky3Row1, leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1, leftIndex3Row1, rightIndex3Row1, rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, rightPinky3Row1, \
    leftPinky3Row2, leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2, leftIndex3Row2, rightIndex3Row2, rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, rightPinky3Row2, \
    leftPinky3Row3, leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3, leftIndex3Row3, rightIndex3Row3, rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, rightPinky3Row3, \
    leftPinky3Row4, leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4, leftIndex3Row4, rightIndex3Row4, rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, rightPinky3Row4, \
    leftPinky3Row5, leftPinky2Row5, leftPinky1Row5, leftRingRow5, leftMiddleRow5, leftIndex1Row5, leftIndex2Row5, leftIndex3Row5, rightIndex3Row5, rightIndex2Row5, rightIndex1Row5, rightMiddleRow5, rightRingRow5, rightPinky1Row5, rightPinky2Row5, rightPinky3Row5, \
    leftThumb0, leftThumb1, leftThumb2, leftThumb3, leftThumb4, leftThumb5, leftThumb6, leftThumb7, rightThumb7, rightThumb6, rightThumb5, rightThumb4, rightThumb3, rightThumb2, rightThumb1, rightThumb0 \
) \
    LAYOUT_6x6( \
        leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1,                rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, \
        leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2,                rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, \
        leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3,                rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, \
        leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4,                rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, \
        leftPinky2Row5, leftPinky1Row5, leftRingRow5, leftMiddleRow5, leftThumb1    , leftThumb2    ,                                 rightThumb2    , rightThumb1    , rightMiddleRow5, rightRingRow5, rightPinky1Row5, rightPinky2Row5, \
                                                                        leftThumb3, leftThumb4, leftThumb7,   rightThumb7, rightThumb4, rightThumb3, \
                                                                                                leftThumb6,   rightThumb6, \
                                                                                                leftThumb5,   rightThumb5 \
    )

#include "napoli1084_keymap.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ONE_GRV LT(1,KC_GRAVE)
//#define CTL_Z LCTL_T(KC_Z)
#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define LG_QUOT LGUI_T(KC_QUOT)
#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_SLS LCTL_T(KC_SLSH)
#define LT2_COL LT(_RAISE, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*[_QWERTY] = LAYOUT_6x6(
        KC_EQL , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_DEL ,RGB_EEP,RGB_HUI, RGB_SAI, RGB_VAI, RGB_LYR,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_BSPC,RGB_DBG,RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD,                                        KC_H   , KC_J  , KC_K  , KC_L  ,LT2_COL,LG_QUOT,
        KC_LSFT, KC_Z  ,DB_TOGG, UC_MOD , NC_SYMD, RGB_TOG,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,CTL_SLS,KC_RSFT,
        //KC_DEL , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        //KC_BSPC, KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,LT2_COL,LG_QUOT,
        //KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,CTL_SLS,KC_RSFT,
        KC_GRV ,KC_QUOT,KC_M   ,KC_LEFT,KC_RGHT,KC_SPC ,                                       KC_ENT , KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,KC_F1,
                                                KC_L    ,KC_Y   ,KC_N   ,       KC_RALT,CTL_ESC,KC_TAB ,
                                                                KC_O   ,        KC_PGUP,
                                                                KC_P   ,        KC_PGDN
    ),*/
    [LYR_WORKNAP] = NAPOLI1084_LAYOUT_LYR_WORKNAP,
    [LYR_GAME] = NAPOLI1084_LAYOUT_LYR_GAME,
    /*[_LOWER] = LAYOUT_6x6(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,KC_EXLM,KC_AT  ,KC_LBRC,KC_RBRC,KC_PIPE,                                       KC_UP  ,KC_P7  ,KC_P8  ,KC_P9  ,KC_PAST,KC_F12 ,
        _______,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                       KC_DOWN,KC_P4  ,KC_P5  ,KC_P6  ,KC_PPLS,_______,
        _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,                                       KC_AMPR,KC_P1  ,KC_P2  ,KC_P3  ,KC_PSLS,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_PDOT,KC_P0  ,KC_PEQL,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                                _______,       _______,
                                                                _______,       _______
    ),*/
    /*[_RAISE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_MS_U,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                                       _______,_______,_______,_______,_______,KC_MPLY,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,KC_MPRV,KC_MNXT,_______,_______,
        _______,_______,_______,KC_BTN1,KC_BTN2,_______,                                       KC_WBAK,KC_VOLU,KC_VOLD,KC_MUTE,_______,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                                _______,       _______,
                                                                _______,       _______
    )*/
    [LYR_NAVNUM] = NAPOLI1084_LAYOUT_LYR_NAVNUM,
    [LYR_FRSYMBOL] = NAPOLI1084_LAYOUT_LYR_FRSYMBOL,
    [LYR_FRCAPS] = NAPOLI1084_LAYOUT_LYR_FRCAPS,
    [LYR_FN] = NAPOLI1084_LAYOUT_LYR_FN,
    [LYR_F1F12] = NAPOLI1084_LAYOUT_LYR_F1F12,
    [LYR_WINDOWS] = NAPOLI1084_LAYOUT_LYR_WINDOWS
};
