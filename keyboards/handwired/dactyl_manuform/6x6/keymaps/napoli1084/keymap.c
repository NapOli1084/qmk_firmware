#include QMK_KEYBOARD_H

enum layer_names {
    WORKMAN,
    GAME,
    NAVNUM,
    FRSYMBOL,
    FRCAPS,
    MOUSE,
    F1F12,
    WINDOWS
};

#define HOLDLYR _______
#define TTGAME TT(GAME)
#define TTMOUSE TT(MOUSE)
#define TTNVNUM TT(NAVNUM)
#define TTF1F12 TT(F1F12)
#define LTWIN_T LT(WINDOWS,KC_T)
#define LTF1_N LT(F1F12,KC_N)
#define WINSFTL LGUI(LSFT(KC_LEFT))
#define WINSFTR LGUI(LSFT(KC_RIGHT))
#define WINDOWN LGUI(KC_DOWN)
#define ALT_F4  LALT(KC_F4)
#define WINLEFT LGUI(KC_LEFT)
#define WINUP LGUI(KC_UP)
#define WINRGHT LGUI(KC_RIGHT)
#define WINCTLL LCTL(LGUI(KC_LEFT))
#define WINCTLR LCTL(LGUI(KC_RIGHT))

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
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
    uni_Y_DIAERESIS
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
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

#define a_CIRCM XP(uni_a_CIRCUMFLEX, uni_A_CIRCUMFLEX)
#define a_DIAER XP(uni_a_DIAERESIS, uni_A_DIAERESIS)
#define a_GRAVE XP(uni_a_GRAVE, uni_A_GRAVE)
#define c_CEDIL XP(uni_c_CEDILLA, uni_C_CEDILLA)
#define e_ACUTE XP(uni_e_ACUTE, uni_E_ACUTE)
#define e_CIRCM XP(uni_e_CIRCUMFLEX, uni_E_CIRCUMFLEX)
//#define e_CIRCM X(uni_e_CIRCUMFLEX)
#define e_GRAVE XP(uni_e_GRAVE, uni_E_GRAVE)
#define e_DIAER XP(uni_e_DIAERESIS, uni_E_DIAERESIS)
#define i_CIRCM XP(uni_i_CIRCUMFLEX, uni_I_CIRCUMFLEX)
#define i_DIAER XP(uni_i_DIAERESIS, uni_I_DIAERESIS)
#define n_TILDE XP(uni_n_TILDE, uni_N_TILDE)
#define o_CIRCM XP(uni_o_CIRCUMFLEX, uni_O_CIRCUMFLEX)
#define o_DIAER XP(uni_o_DIAERESIS, uni_O_DIAERESIS)
#define s_SHARP XP(uni_s_SHARP, uni_S_SHARP)
#define u_CIRCM XP(uni_u_CIRCUMFLEX, uni_U_CIRCUMFLEX)
#define u_DIAER XP(uni_u_DIAERESIS, uni_U_DIAERESIS)
#define u_GRAVE XP(uni_u_GRAVE, uni_U_GRAVE)
#define y_DIAER XP(uni_y_DIAERESIS, uni_Y_DIAERESIS)

#define A_CIRCM X(uni_A_CIRCUMFLEX)
#define A_DIAER X(uni_A_DIAERESIS)
#define A_GRAVE X(uni_A_GRAVE)
#define C_CEDIL X(uni_C_CEDILLA)
#define E_ACUTE X(uni_E_ACUTE)
#define E_CIRCM X(uni_E_CIRCUMFLEX)
#define E_GRAVE X(uni_E_GRAVE)
#define E_DIAER X(uni_E_DIAERESIS)
#define I_CIRCM X(uni_I_CIRCUMFLEX)
#define I_DIAER X(uni_I_DIAERESIS)
#define N_TILDE X(uni_N_TILDE)
#define O_CIRCM X(uni_O_CIRCUMFLEX)
#define O_DIAER X(uni_O_DIAERESIS)
#define S_SHARP X(uni_S_SHARP)
#define U_CIRCM X(uni_U_CIRCUMFLEX)
#define U_DIAER X(uni_U_DIAERESIS)
#define U_GRAVE X(uni_U_GRAVE)
#define Y_DIAER X(uni_Y_DIAERESIS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WORKMAN] = LAYOUT_6x6(
        KC_NO  , KC_NO , KC_NO ,TTGAME ,KC_HYPR,TT(WINDOWS),                    TTF1F12,TTNVNUM,KC_MEH , KC_NO , KC_NO ,KC_APP ,
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_TAB ,KC_DEL ,KC_SPC ,KC_BSPC, KC_0  ,KC_DELETE,
        KC_TAB , KC_Q  , KC_D  , KC_R  , KC_W  , KC_B  ,                         KC_J  , KC_F  , KC_U  , KC_P  ,KC_SCLN,KC_BSPC,
        KC_LSFT, KC_A  , KC_S  , KC_H  ,LTWIN_T, KC_G  ,                         KC_Y  ,LTF1_N , KC_E  , KC_O  ,KC_I   ,KC_RSFT,
        KC_LCTL, KC_Z  , KC_X  , KC_M  , KC_C  , KC_V  ,                         KC_K  , KC_L  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RCTL,
                        KC_LCTL,KC_LSFT,                                                        KC_LALT,KC_LWIN,
                                        OSL(NAVNUM),KC_SPACE,                KC_ENTER,OSL(FRSYMBOL),
                                                TTMOUSE,KC_WH_U,        KC_PGUP,TTMOUSE,
                                                KC_BSPC,KC_WH_D,        KC_PGDN,KC_LALT
    ),
    [GAME] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,KC_T   ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,_______,_______,
        _______,KC_LCTL,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,                        _______,KC_H   ,_______,_______,_______,_______,
        _______,KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,                        _______,_______,KC_M   ,_______,_______,_______,
        _______,KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,                        _______,_______,_______,_______,_______,_______,
                        _______,KC_LALT,                                                        _______,_______,
                                            KC_SPACE,OSL(F1F12),            _______,_______,
                                                KC_G   ,KC_B   ,        _______,_______,
                                                _______,_______,        _______,_______
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
        n_TILDE,a_DIAER, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        y_DIAER,u_DIAER,e_DIAER,o_DIAER,i_DIAER,_______,
        s_SHARP,a_CIRCM,KC_RCBR,KC_LCBR,KC_GRV ,KC_CIRC,                        KC_PERC,u_CIRCM,e_CIRCM,o_CIRCM,i_CIRCM,_______,
        _______,a_GRAVE,KC_RPRN,KC_LPRN,KC_UNDS,KC_AMPR,                        KC_DLR ,u_GRAVE,e_ACUTE,KC_DQUO,KC_QUOT,_______,
        _______,KC_EXLM,KC_RBRC,KC_LBRC,c_CEDIL,KC_TILD,                        KC_HASH,KC_ASTR,e_GRAVE,KC_BSLS,KC_PIPE,_______,
                        _______,_______,                                                        _______,_______,
                                        OSL(FRCAPS),_______,                _______,_______,
                                                _______,_______,        _______,_______,
                                                _______,_______,        _______,_______
    ),
    [FRCAPS] = LAYOUT_6x6(
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
    [MOUSE] = LAYOUT_6x6(
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
    [F1F12] = LAYOUT_6x6(
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
    [WINDOWS] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
        _______,_______,KC_MPRV,KC_VOLU,_______,_______,                        _______,WINLEFT,WINUP  ,WINRGHT,_______,_______,
        _______,_______,KC_MNXT,KC_VOLD,HOLDLYR,_______,                        _______,WINSFTL,WINDOWN,WINSFTR,ALT_F4 ,_______,
        _______,_______,KC_MPLY,KC_MUTE,_______,_______,                        _______,WINCTLL,_______,WINCTLR,_______,_______,
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

