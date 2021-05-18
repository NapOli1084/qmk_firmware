#include QMK_KEYBOARD_H


#define WORKMAN 0
#define NAVNUM 1
#define FRSYMBOL 2

#define TTNVNUM TT(NAVNUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WORKMAN] = LAYOUT_6x6(
        KC_NO  , KC_NO , KC_F3 , KC_F4 ,TTNVNUM, KC_F6 ,                         KC_F7 ,TTNVNUM, KC_F9 ,KC_F10 , KC_NO ,KC_APP ,
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_TAB, KC_DEL,KC_SPC ,KC_BSPC, KC_0  ,KC_DELETE,
        KC_TAB , KC_Q  , KC_D  , KC_R  , KC_W  , KC_B  ,                         KC_J  , KC_F  , KC_U  , KC_P  ,KC_SCLN,KC_BSPC,
        KC_LSFT, KC_A  , KC_S  , KC_H  , KC_T  , KC_G  ,                         KC_Y  , KC_N  , KC_E  , KC_O  ,KC_I   ,KC_RSFT,
        KC_LCTL, KC_Z  , KC_X  , KC_M  , KC_C  , KC_V  ,                         KC_K  , KC_L  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RCTL,
                        KC_LCTL,KC_LSFT,                                                        KC_LALT,KC_LWIN,
                                        OSL(NAVNUM),KC_SPACE,                KC_ENTER,OSL(FRSYMBOL),
                                                KC_TAB ,KC_WH_U,        KC_PGUP, KC_DEL,
                                                KC_BSPC,KC_WH_D,        KC_PGDN,KC_LALT
    ),
    [NAVNUM] = LAYOUT_6x6(
        KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,                         KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,
        _______,KC_NO,KC_SYSREQ,KC_SLCK,KC_PAUS,KC_INS ,                        KC_CIRC,KC_NLCK,KC_SLSH,KC_ASTR,KC_MINUS,_______,
        _______,KC_NO  ,KC_HOME,KC_UP  ,KC_PGUP,KC_WH_U,                        KC_PERC, KC_7  , KC_8  , KC_9  ,KC_MINUS,_______,
        _______,KC_WH_L,KC_LEFT,KC_DOWN,KC_RGHT,KC_WH_R,                        KC_DLR , KC_4  , KC_5  , KC_6  ,KC_PLUS,_______,
        _______,_______,KC_END ,KC_NO  ,KC_PGDN,KC_WH_D,                        KC_HASH, KC_1  , KC_2  , KC_3  ,KC_EQL ,_______,
                        _______,_______,                                                         KC_0  ,KC_DOT ,
                                            _______,_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
    [FRSYMBOL] = LAYOUT_6x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_N   , KC_A  , KC_P  , KC_F9 ,KC_F10 ,RESET ,
        _______, KC_NO , KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,_______,_______,_______,_______,_______,
        _______,KC_NO  ,KC_RCBR,KC_LCBR,KC_GRV ,KC_CIRC,                        KC_PERC,_______,_______,_______,_______,_______,
        _______,_______,KC_RPRN,KC_LPRN,KC_UNDS,KC_AMPR,                        KC_DLR ,_______,_______,KC_DQUO,_______,_______,
        _______,KC_EXLM,KC_RBRC,KC_LBRC,_______,KC_TILD,                        KC_HASH,KC_ASTR,_______,KC_BSLS,KC_QUOT,_______,
                        _______,_______,                                                        _______,_______,
                                            _______,_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
};

