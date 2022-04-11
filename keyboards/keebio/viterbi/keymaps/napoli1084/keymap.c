#include QMK_KEYBOARD_H

#define NAPOLI1084_QWERTY_ENABLE
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
    TTWKNAP, KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
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
    _______, _______, _______, _______, _______, _______, _______,     _______, KC_0   , KC_0   , KC_DOT , KC_EQL , _______, _______
  ),

  [LYR_WORKNAP] = LAYOUT_ortho_5x14(
    _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_ESC , KC_NO  , KC_D   , KC_R   , KC_W   , KC_B   ,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    HOLDLYR, KC_TAB , KC_Q   , KC_S   , KC_H   , KC_T   , KC_G   ,     AG_SWAP, QWERTY,  _______, _______, _______, _______, _______,
    _______, _______, KC_A   , KC_X   , KC_M   , KC_C   , KC_V   ,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_Z   , _______, _______, _______,KC_SPACE,     _______, _______, _______, _______, _______, _______, _______
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
  )

};

const rgblight_segment_t PROGMEM my_capslock_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_WHITE}       // Light 3 LEDs, starting with LED 0
);
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
const rgblight_segment_t PROGMEM my_navnum_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_fn_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_MAGENTA}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_rgblayer,
    my_qwerty_rgblayer,    // Overrides caps lock layer
    my_navnum_rgblayer,    // Overrides qwerty layer
    my_fn_rgblayer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, LYR_QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, LYR_QNAVNUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, LYR_FN));
    return state;
}

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
