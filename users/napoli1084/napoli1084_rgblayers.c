/*
Copyright 2022 NapOli1084 (@napoli1084)

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

#ifdef RGBLIGHT_LAYERS
#include "napoli1084_rgblayers.h"

#include "napoli1084_keycodeenums.h"

#include <stddef.h>
#include "quantum/rgblight/rgblight.h"

const rgblight_segment_t PROGMEM my_capslock_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM / 4, HSV_WHITE}       // Light 3 LEDs, starting with LED 0
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
    {0, RGBLED_NUM, HSV_BLUE}
);
#endif // NAPOLI1084_QWERTY_ENABLE

const rgblight_segment_t PROGMEM my_worknap_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_game_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_RED}
);
const rgblight_segment_t PROGMEM my_navnum_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {RGBLED_NUM / 4, RGBLED_NUM - 2*(RGBLED_NUM / 4), HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_frsymbol_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_frcaps_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 15, 255, 255} // orange
);
const rgblight_segment_t PROGMEM my_fn_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_f1f12_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, 234, 255, 255} // pink
);
const rgblight_segment_t PROGMEM my_windows_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM / 4, HSV_BLUE},
    {RGBLED_NUM / 4, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_RED},
    {RGBLED_NUM / 2, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_YELLOW},
    {RGBLED_NUM - (RGBLED_NUM / 4), RGBLED_NUM / 4, HSV_GREEN}
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
    RGBLYR_COUNT // not a layer, only serves to count number of layers
};

void napoli1084_rgblayers_keyboard_post_init(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool napoli1084_rgblayers_led_update(led_t led_state) {
    rgblight_set_layer_state(RGBLYR_CAPSLOCK, led_state.caps_lock);
    return true;
}

layer_state_t napoli1084_rgblayers_default_layer_state_set(layer_state_t state) {
  #ifdef NAPOLI1084_QWERTY_ENABLE
    rgblight_set_layer_state(RGBLYR_QWERTY, layer_state_cmp(state, LYR_QWERTY));
  #else
    rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
  #endif
    return state;
}

layer_state_t napoli1084_rgblayers_layer_state_set(layer_state_t state) {
    _Static_assert(RGBLIGHT_MAX_LAYERS >= RGBLYR_COUNT,
        "Max RGB layers must be greater or equal to number of layers");
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
    return state;
}

#endif // RGBLIGHT_LAYERS
