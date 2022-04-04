#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

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
 * | Nap  | Ctrl |  \"" | GUI  | Alt  | Num  |Space |      |Space |  F5  | RAlt | RGui | App  | Ctl  | Del  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_ESC,  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_BSPC,
    KC_BSLS, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
    KC_F1  , KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_F2  , KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_EQL ,
    LOWER  , KC_LCTL, KC_NUBS, KC_LGUI, KC_LALT, LOWER  , KC_SPC ,     KC_SPC , RAISE  , KC_RALT, KC_RGUI, KC_APP , KC_RCTL, KC_DEL
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_TILD, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    KC_UNDS, _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LCBR, KC_RCBR,
    KC_PLUS, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______, _______,
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,     KC_F12 , KC_NUHS, KC_NUBS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE
  ),

  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  _______,
    _______, _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,     AG_SWAP, QWERTY,  _______, _______, _______, _______, _______,
    _______, _______, _______, BL_TOGG, BL_STEP, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

};

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_WHITE},       // Light 3 LEDs, starting with LED 0
    {11, 3, HSV_WHITE}       // Light 3 LEDs, starting with LED 11
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
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
const rgblight_segment_t PROGMEM my_numnav_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_fkeys_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_MAGENTA}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_rgblayer,
    my_qwerty_rgblayer,    // Overrides caps lock layer
    my_numnav_rgblayer,    // Overrides other layers
    my_fkeys_rgblayer     // Overrides other layers
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
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
