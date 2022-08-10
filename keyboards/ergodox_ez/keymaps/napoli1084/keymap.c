#include QMK_KEYBOARD_H
#include "version.h"
#include "napoli1084_keycodes.h" // users/napoli1084

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: WorkNap Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |ToDefault|      |Ctrl+S|Ctrl+C|Ctrl+V|  F7  |Defalt|           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   Esc   |Ctrl+Z|   D  |   R  |   W  |   B  |Hyper |           |      |   J  |   F  |   U  |   P  |   0  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Tab   |   Q  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   ;  | Backspc|
 * |---------+------+------+------+------+------| Game |           |      |------+------+------+------+------+--------|
 * | LShift  |   A  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   I  | RShift |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl |   Z  |      | LAlt |NavNum|                                       |      |    . |   0  |   /  | RCtl |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|  F5  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |F1-F12|------|       |------|WinLyr|Enter |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LYR_WORKNAP] = LAYOUT_ergodox_pretty(
  TODEFLT, KC_NO  , WN_2   , WN_3   , WN_4   , WN_5   , TODEFLT,     TODEFLT, WN_6   , WN_7   , WN_8   , WN_9   , KC_NO  , WN_APP ,
  WN_ESC , WN_1   , WN_D   , WN_R   , WN_W   , WN_B   , KC_HYPR,     KC_MEH , WN_J   , WN_F   , WN_U   , WN_P   , WN_0   , WN_DEL ,
  WN_TAB , WN_Q   , WN_S   , WN_H   , WN_T   , WN_G   ,                       WN_Y   , WN_N   , WN_E   , WN_O   , WN_SCOL, WN_BSPC,
  WN_LSFT, WN_A   , WN_X   , WN_M   , WN_C   , WN_V   , WN_LTB4,     WN_RTB4, WN_K   , WN_L   , WN_COMM, WN_DOT , WN_I   , WN_RSFT,
  WN_LCTL, WN_Z   , WN_LWIN, WN_LALT, WN_LTB1,                                         WN_RTB1, WN_RALT, WN_RWIN, WN_SLSH, WN_RCTL,
                                               RGB_MOD, _______,     RGB_TOG, KC_F5  ,
                                                        KC_WH_U,     KC_PGUP,
                                      WN_LTB2, WN_LTB3, KC_WH_D,     KC_PGDN, WN_RTB3, WN_RTB2
),
[LYR_GAME] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[LYR_NAVNUM] = LAYOUT_ergodox_pretty(
  _______, KC_NO  , KC_PSCR, KC_SLCK, KC_PAUS, KC_INS , _______,     _______, KC_CIRC, KC_NLCK, KC_PSLS, KC_ASTR,KC_MINUS, _______,
  _______, KC_NO  , KC_HOME, KC_UP  , KC_PGUP, KC_WH_R, _______,     _______, KC_PERC, KC_7   , KC_8   , KC_9   ,KC_MINUS, _______,
  _______, KC_WH_L, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_U,                       KC_DLR , KC_4   , KC_5   , KC_6   ,KC_MINUS, _______,
  _______, KC_WH_U, KC_END , KC_WH_D, KC_PGDN, KC_WH_R, _______,     _______, KC_HASH, KC_1   , KC_2   , KC_3   , KC_PLUS, _______,
  _______, KC_WH_L, _______, _______, HOLDLYR,                                         OSFN   , KC_0   , KC_DOT , KC_EQL , _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[LYR_FRSYMBOL] = LAYOUT_ergodox_pretty(
  _______, KC_NO  , UN_AT  , UN_HASH, KC_DLR , KC_PERC, _______,     _______, y_DIAER, u_DIAER, e_DIAER, o_DIAER, KC_NO  , NC_RSET,
  n_TILDE, a_DIAER, UN_RCBR, UN_LCBR, UN_GRAV, UN_CIRC, _______,     _______, KC_PERC, u_CIRCM, e_CIRCM, o_CIRCM, i_DIAER, _______,
  s_SHARP, a_CIRCM, KC_RPRN, KC_LPRN, KC_UNDS, KC_AMPR,                       KC_DLR , u_GRAVE, e_ACUTE, UN_DQUO, i_CIRCM, _______,
  _______, a_GRAVE, UN_RBRC, UN_LBRC, c_CEDIL, UN_TILD, _______,     _______, UN_HASH, KC_ASTR, e_GRAVE, UN_BSLS, UN_APOS, _______,
  _______, KC_EXLM, _______, _______,OSFRCAPS,                                         HOLDLYR, _______, _______, UN_PIPE, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[LYR_FRCAPS] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, Y_DIAER, U_DIAER, E_DIAER, O_DIAER, _______, _______,
  N_TILDE, A_DIAER, _______, _______, _______, _______, _______,     _______, _______, U_CIRCM, E_CIRCM, O_CIRCM, I_DIAER, _______,
  S_SHARP, A_CIRCM, _______, _______, _______, _______,                       _______, U_GRAVE, E_ACUTE, _______, I_CIRCM, _______,
  _______, A_GRAVE, _______, _______, C_CEDIL, _______, _______,     _______, _______, _______, E_GRAVE, _______, _______, _______,
  _______, _______, _______, _______, HOLDLYR,                                         _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[LYR_FN] = LAYOUT_ergodox_pretty(
  NC_RSET, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,     _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , NC_RSET,
  _______, KC_F1  , RGB_HUI, RGB_SAI, RGB_VAI, RGB_LYR, _______,     _______, BL_INC , KC_BRIU, KC_VOLU, KC_MSTP, KC_F10 , _______,
  _______,RGB_M_SW, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD,                       BL_DEC , KC_BRID, KC_VOLD, KC_MPLY, KC_MPRV, _______,
  _______, RGB_M_P, DB_TOGG, UC_MOD , NC_SYMD, RGB_TOG, _______,     _______, BL_TOGG, KC_NO  , KC_MUTE, KC_NO  , KC_MNXT, _______,
  _______, RGB_M_T, _______, _______, HOLDLYR,                                         HOLDLYR, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
[LYR_F1F12] = LAYOUT_ergodox_pretty(
  NC_RSET, KC_NO  , KC_F10 , KC_F11 , KC_F12 , KC_F22 , _______,     _______, _______, KC_F10 , KC_F11 , KC_F12 , _______, _______,
  KC_F20 , KC_F21 , KC_F7  , KC_F8  , KC_F9  , KC_F19 , _______,     _______, _______, KC_F7  , KC_F8  , KC_F9  , _______, _______,
  KC_F17 , KC_F18 , KC_F4  , KC_F5  , KC_F6  , KC_F16 ,                       _______, HOLDLYR, KC_F5  , KC_F6  , _______, _______,
  _______, KC_F15 , KC_F1  , KC_F2  , KC_F3  , KC_F13 , _______,     _______, _______, KC_F1  , KC_F2  , KC_F3  , _______, _______,
  _______, KC_F14 , _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, HOLDLYR, _______,     _______, _______, _______
),
[LYR_WINDOWS] = LAYOUT_ergodox_pretty(
  NC_RSET, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, NC_RSET,
  _______, _______, KC_MPRV, KC_VOLU, _______, _______, _______,     _______, KC_WAKE, WINLEFT, WINUP  , WINRGHT, _______, _______,
  _______, _______, KC_MNXT, KC_VOLD, HOLDLYR, _______,                       KC_SLEP, WINSFTL, WINDOWN, WINSFTR, _______, _______,
  _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______,     _______, KC_PWR , WINCTLL, _______, WINCTLR, ALT_F4 , _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, HOLDLYR, _______
),
/*
[LYR_] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
*/
};
// clang-format on


// Runs whenever there is a layer state change.
layer_state_t napoli1084_ergodox_layer_state_set(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
