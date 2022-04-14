#include QMK_KEYBOARD_H

#include "napoli1084.h" // users/napoli1084


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  Esc |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |  -   | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  \ | | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |  ]   |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  F1  | Caps |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  F2  | Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |  / ? | Shift|  =+  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |Qwerty| Ctrl |  \"" | GUI  | Alt  | Num  |Space |      |Space |  F5  | RAlt | RGui | App  | Ctl  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [LYR_QWERTY] = LAYOUT_ortho_5x14(
    KC_ESC,  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_BSPC,
    KC_BSLS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
    TTWRKNP, KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_F2  , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_EQL ,
    TOQWERT, KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT,OSQNVNUM, KC_SPC ,     KC_SPC , OSFN   , KC_RALT, KC_RGUI, KC_APP , KC_RCTL, KC_DEL
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |PrtScn|ScrlLk| Pause|Insert|      |   ^  |NumLk |   /  |   *  |   -  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      | WhL  | Home |   ^  | PgUp | WhR  |      |   %  |   7  |   8  |   9  |   +  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      | WhUp |  <-  |   v  |  ->  | WhUp |      |   $  |   4  |   5  |   6  |   +  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      | WhL  |  End | WhDn | PgDn | WhR  |      |   #  |   1  |   2  |   3  |   =  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   0  |   0  |   .  |   =  |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [LYR_QNAVNUM] = LAYOUT_ortho_5x14(
    _______, _______, KC_NO  , KC_PSCR, KC_SLCK, KC_PAUS, KC_INS ,     KC_CIRC, KC_NLCK, KC_PSLS, KC_ASTR,KC_MINUS, _______, _______,
    _______, _______, KC_WH_L, KC_HOME, KC_UP  , KC_PGUP, KC_WH_R,     KC_PERC, KC_7   , KC_8   , KC_9   , KC_PLUS, _______, _______,
    _______, _______, KC_WH_U, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_U,     KC_DLR , KC_4   , KC_5   , KC_6   , KC_PLUS, _______, _______,
    _______, _______, KC_WH_L, KC_END , KC_WH_D, KC_PGDN, KC_WH_R,     KC_HASH, KC_1   , KC_2   , KC_3   , KC_EQL , _______, _______,
    _______, _______, _______, _______, _______, HOLDLYR, _______,     _______, KC_0   , KC_0   , KC_DOT , KC_EQL , _______, _______
  ),

  [LYR_WORKNAP] = LAYOUT_ortho_5x14(
    _______, KC_NO  , KC_NO  , WN_2   , WN_3   , WN_4   , WN_5   ,     WN_6   , WN_7   , WN_8   , WN_9   , KC_NO  , WN_APP , _______,
    _______, WN_ESC , WN_1   , WN_D   , WN_R   , WN_W   , WN_B   ,     WN_J   , WN_F   , WN_U   , WN_P   , WN_0   , WN_DEL , _______,
    HOLDLYR, WN_TAB , WN_Q   , WN_S   , WN_H   , WN_T   , WN_G   ,     WN_Y   , WN_N   , WN_E   , WN_O   , WN_SCOL, WN_BSPC, _______,
    _______, WN_LSFT, WN_A   , WN_X   , WN_M   , WN_C   , WN_V   ,     WN_K   , WN_L   , WN_COMM, WN_DOT , WN_I   , WN_RSFT, _______,
    TOQWERT, WN_LCTL, WN_Z   , WN_LWIN, WN_LALT, WN_LTB1, WN_LTB2,     WN_RTB2, WN_RTB1, WN_RALT, WN_RWIN, WN_SLSH, WN_RCTL, _______
  ),
  [LYR_NAVNUM] = LAYOUT_ortho_5x14(
    _______, _______, KC_NO  , KC_PSCR, KC_SLCK, KC_PAUS, KC_INS ,     KC_CIRC, KC_NLCK, KC_PSLS, KC_ASTR,KC_MINUS, _______, _______,
    _______, _______, KC_NO  , KC_HOME, KC_UP  , KC_PGUP, KC_WH_R,     KC_PERC, KC_7   , KC_8   , KC_9   ,KC_MINUS, _______, _______,
    _______, _______, KC_WH_L, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_U,     KC_DLR , KC_4   , KC_5   , KC_6   ,KC_MINUS, _______, _______,
    _______, _______, KC_WH_U, KC_END , KC_WH_D, KC_PGDN, KC_WH_R,     KC_HASH, KC_1   , KC_2   , KC_3   , KC_PLUS, _______, _______,
    _______, _______, KC_WH_L, _______, _______, HOLDLYR, _______,     _______, _______, KC_0   , KC_DOT , KC_EQL , _______, _______
  ),
  [LYR_FRSYMBOL] = LAYOUT_ortho_5x14(
     RESET , _______, KC_NO  , KC_AT  , KC_HASH, KC_DLR , KC_PERC,     y_DIAER, u_DIAER, e_DIAER, o_DIAER, KC_NO  , _______,  RESET ,
    _______, n_TILDE, a_DIAER, KC_RCBR, KC_LCBR, KC_GRV , KC_CIRC,     KC_PERC, u_CIRCM, e_CIRCM, o_CIRCM, i_DIAER, _______, _______,
    _______, s_SHARP, a_CIRCM, KC_RPRN, KC_LPRN, KC_UNDS, KC_AMPR,     KC_DLR , u_GRAVE, e_ACUTE, KC_DQUO, i_CIRCM, _______, _______,
    _______, _______, a_GRAVE, KC_RBRC, KC_LBRC, c_CEDIL, KC_TILD,     KC_HASH, KC_ASTR, e_GRAVE, KC_BSLS, KC_QUOT, _______, _______,
    _______, _______, KC_EXLM, _______, _______,OSFRCAPS, _______,     _______, HOLDLYR, _______, _______, KC_PIPE, _______, _______
  ),
  [LYR_FRCAPS] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,     Y_DIAER, U_DIAER, E_DIAER, O_DIAER, _______, _______, _______,
    _______, N_TILDE, A_DIAER, _______, _______, _______, _______,     _______, U_CIRCM, E_CIRCM, O_CIRCM, I_DIAER, _______, _______,
    _______, S_SHARP, A_CIRCM, _______, _______, _______, _______,     _______, U_GRAVE, E_ACUTE, _______, I_CIRCM, _______, _______,
    _______, _______, A_GRAVE, _______, _______, C_CEDIL, _______,     _______, KC_ASTR, E_GRAVE, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, HOLDLYR, _______,     _______, _______, _______, _______, _______, _______, _______
  ),
/* Fn
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |Swirl |HueInc|SatInc|ValInc|RModUp|      |BkLtUp|BritUp| VolUp| Stop | Prev |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |Plain |HueDec|SatDec|ValDec|RModDn|      |BkLtDn|BritDn| VolDn| Play | Next |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |RgbTst|      |      |      |RgbTog|      |BkLtOn|      | Mute |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [LYR_FN] = LAYOUT_ortho_5x14(
    _______, KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, _______,RGB_M_SW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,     BL_INC , KC_BRIU, KC_VOLU, KC_MSTP, KC_MPRV, _______, _______,
    _______, _______, RGB_M_P, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD,     BL_DEC , KC_BRID, KC_VOLD, KC_MPLY, KC_MNXT, _______, _______,
    _______, _______, RGB_M_T, KC_NO  , KC_NO  , KC_NO  , RGB_TOG,     BL_TOGG, KC_NO  , KC_MUTE, KC_NO  , KC_NO  , _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),
  [LYR_F1F12] = LAYOUT_ortho_5x14(
    _______, _______, KC_NO  , KC_F10 , KC_F11 , KC_F12 , KC_F22 ,     _______, KC_F10 , KC_F11 , KC_F12 , _______, _______, _______,
    _______, KC_F20 , KC_F21 , KC_F7  , KC_F8  , KC_F9  , KC_F19 ,     _______, KC_F7  , KC_F8  , KC_F9  , _______, _______, _______,
    _______, KC_F17 , KC_F18 , KC_F4  , KC_F5  , KC_F6  , KC_F16 ,     _______, HOLDLYR, KC_F5  , KC_F6  , _______, _______, _______,
    _______, _______, KC_F15 , KC_F1  , KC_F2  , KC_F3  , KC_F13 ,     _______, KC_F1  , KC_F2  , KC_F3  , _______, _______, _______,
    _______, _______, KC_F14 , _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),
  [LYR_WINDOWS] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MPRV, KC_VOLU, _______, _______,     KC_WAKE, WINLEFT, WINUP  , WINRGHT, _______, _______, _______,
    _______, _______, _______, KC_MNXT, KC_VOLD, HOLDLYR, _______,     KC_SLEP, WINSFTL, WINDOWN, WINSFTR, _______, _______, _______,
    _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______,     KC_PWR , WINCTLL, _______, WINCTLR, ALT_F4 , _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )
};

