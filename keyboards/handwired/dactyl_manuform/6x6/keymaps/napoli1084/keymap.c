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

#define NAPOLI1084_LAYOUT( \
    leftPinky3Row0, leftPinky2Row0, leftPinky1Row0, leftRingRow0, leftMiddleRow0, leftIndex1Row0, leftIndex2Row0, leftIndex3Row0, rightIndex3Row0, rightIndex2Row0, rightIndex1Row0, rightMiddleRow0, rightRingRow0, rightPinky1Row0, rightPinky2Row0, rightPinky3Row0, \
    leftPinky3Row1, leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1, leftIndex3Row1, rightIndex3Row1, rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, rightPinky3Row1, \
    leftPinky3Row2, leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2, leftIndex3Row2, rightIndex3Row2, rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, rightPinky3Row2, \
    leftPinky3Row3, leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3, leftIndex3Row3, rightIndex3Row3, rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, rightPinky3Row3, \
    leftPinky3Row4, leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4, leftIndex3Row4, rightIndex3Row4, rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, rightPinky3Row4, \
    leftPinky3Row5, leftPinky2Row5, leftPinky1Row5, leftRingRow5, leftMiddleRow5, leftIndex1Row5, leftIndex2Row5, leftIndex3Row5, rightIndex3Row5, rightIndex2Row5, rightIndex1Row5, rightMiddleRow5, rightRingRow5, rightPinky1Row5, rightPinky2Row5, rightPinky3Row5, \
    leftThumb0, leftThumb2, leftThumb3, leftThumb4, leftThumb5, leftThumb6, leftThumb7, rightThumb7, rightThumb6, rightThumb5, rightThumb4, rightThumb3, rightThumb2, rightThumb1, rightThumb0 \
) \
    LAYOUT_6X6( \
        leftPinky2Row0, leftPinky1Row0, leftRingRow0, leftMiddleRow0, leftIndex1Row0, leftIndex2Row0,                rightIndex2Row0, rightIndex1Row0, rightMiddleRow0, rightRingRow0, rightPinky1Row0, rightPinky2Row0, \
        leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1,                rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, \
        leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2,                rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, \
        leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3,                rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, \
        leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4,                rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, \
                                        leftRingRow5, leftMiddleRow5,                                                                                  rightMiddleRow5, rightRingRow5, \
                                                                      leftThumb1, leftThumb2,                                rightThumb2, rightThumb1, \
                                                                                     leftThumb4, leftThumb6,  rightThumb6, rightThumb4, \
                                                                                    leftThumb3, leftThumb5,    rightThumb5, rightThumb3 \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LYR_WORKNAP] = LAYOUT_6x6(
        TODEFLT , KC_NO  , KC_NO  , TTGAME , KC_HYPR, TODEFLT,                TODEFLT, TTNVNUM, KC_MEH , KC_NO  , KC_NO  , WN_APP ,
        WN_ESC  , WN_1   , WN_2   , WN_3   , WN_4   , WN_5   ,                WN_6   , WN_7   , WN_8   , WN_9   , WN_0   , WN_DEL ,
        WN_TAB  , WN_Q   , WN_D   , WN_R   , WN_W   , WN_B   ,                WN_J   , WN_F   , WN_U   , WN_P   , WN_SCOL, WN_BSPC,
        WN_LSFT , WN_A   , WN_S   , WN_H   , WN_T   , WN_G   ,                WN_Y   , WN_N   , WN_E   , WN_O   , WN_I   , WN_RSFT,
        WN_LCTL , WN_Z   , WN_X   , WN_M   , WN_C   , WN_V   ,                WN_K   , WN_L   , WN_COMM, WN_DOT , WN_SLSH, WN_RCTL,
                           WN_LWIN, WN_LALT,                                                    WN_RALT, WN_RWIN,
                                             WN_LTB1, WN_LTB2,                WN_RTB2, WN_RTB1,
                                                    WN_LTB4, KC_WH_U,  KC_PGUP, WN_RTB4,
                                                 WN_LTB3, KC_WH_D,        KC_PGDN, WN_RTB3
    ),
    [LYR_GAME] = LAYOUT_6x6(
        _______,_______,_______,_______,KC_T   ,_______,                        _______,_______,_______,_______,_______,_______,
        _______,KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,_______,_______,
        _______,KC_H   ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                        _______,_______,_______,_______,_______,_______,
         KC_K  ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                        _______,_______,_______,_______,_______,_______,
         KC_P  ,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,                        _______,_______,_______,_______,_______,_______,
                        KC_M   ,KC_LALT,                                                        _______,_______,
                                            KC_SPACE,OSL(LYR_NAVNUM),            _______,_______,
                                                _______,KC_B   ,        _______,_______,
                                                _______,KC_G   ,        _______,_______
    ),
    [LYR_NAVNUM] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,NNRMDR5,NNRRGR5,_______,_______,
        _______,KC_NO  ,KC_PSCR,KC_SCRL,KC_PAUS,KC_INS ,                        UN_CIRC,KC_NUM ,NNRMDR4,NNRRGR4,KC_MINUS,_______,
        _______,KC_WH_L,KC_HOME,KC_UP  ,KC_PGUP,KC_WH_R,                        KC_PERC, KC_7  ,NNRMDR3,NNRRGR3,KC_MINUS,_______,
        _______,KC_WH_U,KC_LEFT,KC_DOWN,KC_RGHT,KC_WH_U,                        KC_DLR , KC_4  ,NNRMDR2,NNRRGR2,KC_PLUS,_______,
        _______,KC_WH_L,KC_END ,KC_WH_D,KC_PGDN,KC_WH_R,                        UN_HASH, KC_1  ,NNRMDR1,NNRRGR1,KC_EQL ,_______,
                        _______,_______,                                                        NNRMDR0,NNRRGR0,
                                            _______,_______,                _______, OSFN   ,
                                                 _______,_______,    _______,_______,
                                                _______,_______,        _______,_______
    ),
    [LYR_FRSYMBOL] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,NC_RSET,
        n_TILDE,a_DIAER, UN_AT ,UN_HASH,KC_DLR ,KC_PERC,                        y_DIAER,u_DIAER,e_DIAER,o_DIAER,i_DIAER,_______,
        s_SHARP,a_CIRCM,UN_RCBR,UN_LCBR,UN_GRAV,UN_CIRC,                        KC_PERC,u_CIRCM,e_CIRCM,o_CIRCM,i_CIRCM,_______,
        _______,a_GRAVE,KC_RPRN,KC_LPRN,KC_UNDS,KC_AMPR,                        KC_DLR ,u_GRAVE,e_ACUTE,UN_DQUO,UN_APOS,_______,
        _______,KC_EXLM,UN_RBRC,UN_LBRC,c_CEDIL,UN_TILD,                        UN_HASH,KC_ASTR,e_GRAVE,UN_BSLS,UN_PIPE,_______,
                        _______,_______,                                                        _______,_______,
                                        OSFRCAPS,_______,                       _______,HOLDLYR,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
    [LYR_FRCAPS] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        N_TILDE,A_DIAER,_______,_______,_______,_______,                        Y_DIAER,U_DIAER,E_DIAER,O_DIAER,I_DIAER,_______,
        S_SHARP,A_CIRCM,_______,_______,_______,_______,                        _______,U_CIRCM,E_CIRCM,O_CIRCM,I_CIRCM,_______,
        _______,A_GRAVE,_______,_______,_______,_______,                        _______,U_GRAVE,E_ACUTE,_______,_______,_______,
        _______,_______,_______,_______,C_CEDIL,_______,                        _______,_______,E_GRAVE,_______,_______,_______,
                        _______,_______,                                                        _______,_______,
                                            _______,_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
#ifdef NAPOLI1084_MOUSE_LAYER_ENABLE
    [LYR_MOUSE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,KC_BTN3,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,KC_BTN1,KC_MS_U,KC_BTN2,_______,                        _______,KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,
        _______,LCTL(KC_A),KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_U,                     KC_WH_U,KC_MS_L,KC_MS_D,KC_MS_R,LCTL(KC_A),_______,
        _______,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_WH_D,            KC_WH_D,LCTL(KC_V),LCTL(KC_C),LCTL(KC_X),LCTL(KC_Z),_______,
                        KC_BTN1,KC_BTN2,                                                        KC_BTN1,KC_BTN2,
                                            _______,_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
#endif // NAPOLI1084_MOUSE_LAYER_ENABLE
    [LYR_FN] = LAYOUT_6x6(
         NC_RSET, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, NC_RSET,
         _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
         _______,RGB_M_SW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,                BL_INC , KC_BRIU, KC_VOLU, KC_MSTP, KC_MPRV, _______,
         _______, RGB_M_P, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD,                BL_DEC , KC_BRID, KC_VOLD, KC_MPLY, KC_MNXT, _______,
         _______, RGB_M_T, DB_TOGG, UC_MOD , NC_SYMD, RGB_TOG,                BL_TOGG, KC_NO  , KC_MUTE, KC_NO  , KC_MNXT, _______,
                           _______, _______,                                                    _______, _______,
                                             HOLDLYR, _______,                _______, HOLDLYR,
                                                    _______, _______,  _______, _______,
                                                 _______, _______,        _______, _______
    ),
    [LYR_F1F12] = LAYOUT_6x6(
        NC_RSET, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, NC_RSET,
        KC_F20 , KC_F21 , KC_F10 , KC_F11 , KC_F12 , KC_F22 ,                         _______, KC_F10 , KC_F11 , KC_F12 , _______, _______,
        KC_F17 , KC_F18 , KC_F7  , KC_F8  , KC_F9  , KC_F19 ,                         _______, KC_F7  , KC_F8  , KC_F9  , _______, _______,
        _______, KC_F15 , KC_F4  , KC_F5  , KC_F6  , KC_F16 ,                         _______, HOLDLYR, KC_F5  , KC_F6  , _______, _______,
        _______, KC_F14 , KC_F1  , KC_F2  , KC_F3  , KC_F13 ,                         _______, KC_F1  , KC_F2  , KC_F3  , _______, _______,
                        _______, _______,                                                         _______, _______,
                                            _______, _______,                 _______, _______,
                                                _______, _______,         _______, _______,
                                                HOLDLYR, _______,         _______, _______
    ),
    [LYR_WINDOWS] = LAYOUT_6x6(
        NC_RSET,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,NC_RSET,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,KC_MPRV,KC_VOLU,_______,_______,                        KC_WAKE,WINLEFT,WINUP  ,WINRGHT,_______,_______,
        _______,_______,KC_MNXT,KC_VOLD,HOLDLYR,_______,                        KC_SLEP,WINSFTL,WINDOWN,WINSFTR,ALT_F4 ,_______,
        _______,_______,KC_MPLY,KC_MUTE,_______,_______,                        KC_PWR ,WINCTLL,_______,WINCTLR,_______,_______,
                        _______,_______,                                                        _______,_______,
                                            _______,_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
    // [EMPTY] = LAYOUT_6x6(
    //     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
    //     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
    //                     _______,_______,                                                        _______,_______,
    //                                         _______,_______,                _______,_______,
    //                                             _______,_______,        _______,_______,
    //                                             _______,_______,        _______,_______
    // ),
};

