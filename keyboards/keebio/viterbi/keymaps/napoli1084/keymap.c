#include QMK_KEYBOARD_H

#include "napoli1084.h" // users/napoli1084


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


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

#if 0
#ifdef RGBLIGHT_LAYERS

const rgblight_segment_t PROGMEM my_capslock_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_WHITE}       // Light 3 LEDs, starting with LED 0
);

#ifdef NAPOLI1084_QWERTY_ENABLE
const rgblight_segment_t PROGMEM my_qwerty_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    // Left hand
    {0, 1, HSV_MAGENTA}, // 213
    {1, 1, 234, 255, 255}, //HSV_PINK},
    {2, 1, HSV_RED}, // 0
    {3, 1, 5, 255, 255}, //
    {4, 1, 10, 255, 255}, // Coral
    {5, 1, 15, 255, 255}, //
    {6, 1, 21, 255, 255}, // Orange
    // Right hand
    {7, 1, HSV_YELLOW}, // 43
    {8, 1, HSV_CHARTREUSE},
    {9, 1, HSV_GREEN},
    {10, 1, HSV_SPRINGGREEN},
    {11, 1, HSV_CYAN},
    {12, 1, HSV_BLUE},
    {13, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_qnavnum_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_CYAN}
);
#endif // NAPOLI1084_QWERTY_ENABLE

const rgblight_segment_t PROGMEM my_worknap_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_SPRINGGREEN}
);
const rgblight_segment_t PROGMEM my_game_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_RED}
);
const rgblight_segment_t PROGMEM my_navnum_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 10, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_frsymbol_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_frcaps_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, 21, 255, 255} // orange
);
const rgblight_segment_t PROGMEM my_fn_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_f1f12_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, 234, 255, 255} // pink
);
const rgblight_segment_t PROGMEM my_windows_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_BLUE},
    {3, 4, HSV_RED},
    {7, 4, HSV_YELLOW},
    {13,3, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
#ifdef NAPOLI1084_QWERTY_ENABLE
    my_qwerty_rgblayer,    // Overrides caps lock layer
    my_qnavnum_rgblayer,    // Overrides qwerty layer
#endif
    my_worknap_rgblayer,
    my_game_rgblayer,
    my_capslock_rgblayer,
    my_navnum_rgblayer,
    my_frsymbol_rgblayer,
    my_frcaps_rgblayer,
    my_fn_rgblayer,    // Overrides other layers
    my_f1f12_rgblayer,
    my_windows_rgblayer
);

enum napoli1084_rgblayers {
#ifdef NAPOLI1084_QWERTY_ENABLE
    RGBLYR_QWERTY,
    RGBLYR_QNAVNUM,
#endif
    RGBLYR_WORKNAP,
    RGBLYR_GAME,
    RGBLYR_CAPSLOCK,
    RGBLYR_NAVNUM,
    RGBLYR_FRSYMBOL,
    RGBLYR_FRCAPS,
    RGBLYR_FN,
    RGBLYR_F1F12,
    RGBLYR_WINDOWS,
};

#endif // RGBLIGHT_LAYERS

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_LAYERS
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
#endif
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(RGBLYR_CAPSLOCK, led_state.caps_lock);
#endif
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
  #ifdef NAPOLI1084_QWERTY_ENABLE
    rgblight_set_layer_state(RGBLYR_QWERTY, layer_state_cmp(state, LYR_QWERTY));
  #else
    rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
  #endif
#endif
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
  #ifdef NAPOLI1084_QWERTY_ENABLE
    rgblight_set_layer_state(RGBLYR_QNAVNUM, layer_state_cmp(state, LYR_QNAVNUM));
    rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
  #endif
    rgblight_set_layer_state(RGBLYR_GAME, layer_state_cmp(state, LYR_GAME));
    rgblight_set_layer_state(RGBLYR_NAVNUM, layer_state_cmp(state, LYR_NAVNUM));
    rgblight_set_layer_state(RGBLYR_FRSYMBOL, layer_state_cmp(state, LYR_FRSYMBOL));
    rgblight_set_layer_state(RGBLYR_FRCAPS, layer_state_cmp(state, LYR_FRCAPS));
    rgblight_set_layer_state(RGBLYR_FN, layer_state_cmp(state, LYR_FN));
    rgblight_set_layer_state(RGBLYR_F1F12, layer_state_cmp(state, LYR_F1F12));
    rgblight_set_layer_state(RGBLYR_WINDOWS, layer_state_cmp(state, LYR_WINDOWS));
#endif // RGBLIGHT_LAYERS
    return state;
}
#endif

#if 0
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(LYR_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(LYR_QNAVNUM);
        update_tri_layer(LYR_QNAVNUM, LYR_FN, LYR_WORKNAP);
      } else {
        layer_off(LYR_QNAVNUM);
        update_tri_layer(LYR_QNAVNUM, LYR_FN, LYR_WORKNAP);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(LYR_FN);
        update_tri_layer(LYR_QNAVNUM, LYR_FN, LYR_WORKNAP);
      } else {
        layer_off(LYR_FN);
        update_tri_layer(LYR_QNAVNUM, LYR_FN, LYR_WORKNAP);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(LYR_WORKNAP);
      } else {
        layer_off(LYR_WORKNAP);
      }
      return false;
      break;
  }
  return true;
}
#endif // trilayer
