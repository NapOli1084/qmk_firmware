#include QMK_KEYBOARD_H
#include "napoli1084.h" // users/napoli1084


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LYR_WORKNAP] = LAYOUT_6x6(
        KC_NO  , KC_NO , KC_NO ,TTGAME ,KC_HYPR,TTF1F12,                        TTWIN  ,TTNVNUM,KC_MEH , KC_NO , KC_NO ,KC_APP ,
        KC_ESC ,TD_CTLZ,TD_CTLS,TD_CTLC, CTL_V , TD_F7 ,                        KC_TAB ,TD_CTLF,KC_SPC ,TD_CTLP, KC_0  ,KC_DELETE,
        KC_TAB ,LCTL_Q , KC_D  , KC_R  , KC_W  , KC_B  ,                         KC_J  , KC_F  , KC_U  , KC_P  ,RCTL_SC,KC_BSPC,
        KC_LSFT,LSFT_A , KC_S  ,TD_H_ESC,LTWIN_T,KC_G  ,                         KC_Y  ,LTF1_N , KC_E  , KC_O  ,RSFT_I ,KC_RSFT,
        KC_LCTL,LCTL_Z , KC_X  , KC_M  , KC_C  , KC_V  ,                         KC_K  , KC_L  ,KC_COMM,KC_DOT ,RCTL_SL,KC_RCTL,
                        KC_LCTL,KC_LALT,                                                        KC_LALT,KC_LWIN,
                                        OSL(LYR_NAVNUM),KC_SPACE,                KC_ENTER,OSL(LYR_FRSYMBOL),
                                                 TTGAME,KC_WH_U,        KC_PGUP,TTMOUSE,
                                             OSL(LYR_F1F12),KC_WH_D,        KC_PGDN,OSL(LYR_WINDOWS)
    ),
    [LYR_GAME] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,KC_T   ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,_______,_______,
        _______,KC_H   ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                        _______,_______,_______,_______,_______,_______,
         KC_K  ,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                        _______,_______,_______,_______,_______,_______,
         KC_P  ,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,                        _______,_______,_______,_______,_______,_______,
                        KC_M   ,KC_LALT,                                                        _______,_______,
                                            KC_SPACE,OSL(LYR_NAVNUM),            _______,_______,
                                                _______,KC_B   ,        _______,_______,
                                                _______,KC_G   ,        _______,_______
    ),
    [LYR_NAVNUM] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,KC_NO  ,KC_PSCR,KC_SLCK,KC_PAUS,KC_INS ,                        KC_CIRC,KC_NLCK,KC_SLSH,KC_ASTR,KC_MINUS,_______,
        _______,KC_WH_L,KC_HOME,KC_UP  ,KC_PGUP,KC_WH_R,                        KC_PERC, KC_7  , KC_8  , KC_9  ,KC_MINUS,_______,
        _______,KC_WH_U,KC_LEFT,KC_DOWN,KC_RGHT,KC_WH_U,                        KC_DLR , KC_4  , KC_5  , KC_6  ,KC_PLUS,_______,
        _______,KC_WH_L,KC_END ,KC_WH_D,KC_PGDN,KC_WH_R,                        KC_HASH, KC_1  , KC_2  , KC_3  ,KC_EQL ,_______,
                        _______,_______,                                                         KC_0  ,KC_DOT ,
                                            _______,_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
    [LYR_FRSYMBOL] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______, RESET ,
        n_TILDE,a_DIAER, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        y_DIAER,u_DIAER,e_DIAER,o_DIAER,i_DIAER,_______,
        s_SHARP,a_CIRCM,KC_RCBR,KC_LCBR,KC_GRV ,KC_CIRC,                        KC_PERC,u_CIRCM,e_CIRCM,o_CIRCM,i_CIRCM,_______,
        _______,a_GRAVE,KC_RPRN,KC_LPRN,KC_UNDS,KC_AMPR,                        KC_DLR ,u_GRAVE,e_ACUTE,KC_DQUO,KC_QUOT,_______,
        _______,KC_EXLM,KC_RBRC,KC_LBRC,c_CEDIL,KC_TILD,                        KC_HASH,KC_ASTR,e_GRAVE,KC_BSLS,KC_PIPE,_______,
                        _______,_______,                                                        _______,_______,
                                        OSL(LYR_FRCAPS),_______,                _______,HOLDLYR,
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
#ifdef MOUSEKEY_ENABLE
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
#endif // MOUSEKEY_ENABLE
    [LYR_F1F12] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        KC_F20 ,KC_F21 ,KC_F10 ,KC_F11 ,KC_F12 ,KC_F22 ,                        _______,KC_F10 ,KC_F11 ,KC_F12 ,_______,_______,
        KC_F17 ,KC_F18 ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F19 ,                        _______,KC_F7  ,KC_F8  ,KC_F9  ,_______,_______,
        KC_F14 ,KC_F15 ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F16 ,                        _______,HOLDLYR,KC_F5  ,KC_F6  ,_______,_______,
        KC_F23 ,KC_F24 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F13 ,                        _______,KC_F1  ,KC_F2  ,KC_F3  ,_______,_______,
                        _______,_______,                                                        _______,_______,
                                            _______,_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
    [LYR_WINDOWS] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
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

