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

#include "napoli1084_rgblayers.h"

#include "napoli1084_colors.h"
#include "napoli1084_keycodeenums.h"
#include "napoli1084_rgbmode.h"
#include "napoli1084_utils.h"

#ifndef RGBLIGHT_ENABLE
#error RGBLIGHT_ENABLE is not defined
#endif

#include <stddef.h>
#include "quantum/rgblight/rgblight.h"

#ifdef RGBLIGHT_LAYERS

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
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_NAVNUM}
);
#endif // NAPOLI1084_QWERTY_ENABLE

const rgblight_segment_t PROGMEM my_worknap_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_WORKNAP}
);
const rgblight_segment_t PROGMEM my_game_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_GAME}
);
const rgblight_segment_t PROGMEM my_navnum_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_NAVNUM}
);
const rgblight_segment_t PROGMEM my_frsymbol_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_FRSYMBOL}
);
#ifdef NAPOLI1084_FRCAPS_ENABLE
const rgblight_segment_t PROGMEM my_frcaps_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_FRCAPS}
);
#endif
const rgblight_segment_t PROGMEM my_fn_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_FN}
);
const rgblight_segment_t PROGMEM my_f1f12_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, NAPOLI1084_HSV_LYR_F1F12}
);
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
const rgblight_segment_t PROGMEM my_windows_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM / 4, HSV_BLUE},
    {RGBLED_NUM / 4, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_RED},
    {RGBLED_NUM / 2, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_YELLOW},
    {RGBLED_NUM - (RGBLED_NUM / 4), RGBLED_NUM / 4, HSV_GREEN}
);
#endif
const rgblight_segment_t PROGMEM my_test_rgblayer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM / 4, HSV_RED},
    {RGBLED_NUM / 4, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_GREEN},
    {RGBLED_NUM / 2, (RGBLED_NUM / 2) - (RGBLED_NUM / 4), HSV_BLUE},
    {RGBLED_NUM - (RGBLED_NUM / 4), RGBLED_NUM / 4, HSV_MAGENTA}
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
#ifdef NAPOLI1084_FRCAPS_ENABLE
    my_frcaps_rgblayer,
#endif
    my_fn_rgblayer,    // Overrides other layers
    my_f1f12_rgblayer,
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
    my_windows_rgblayer,
#endif
    my_test_rgblayer
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
#ifdef NAPOLI1084_FRCAPS_ENABLE
    RGBLYR_FRCAPS,
#endif
    RGBLYR_FN,
    RGBLYR_F1F12,
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
    RGBLYR_WINDOWS,
#endif
    RGBLYR_TEST,
    RGBLYR_COUNT // not a layer, only serves to count number of layers
};

static void napoli1084_rgblayers_set_rgblayers_state(layer_state_t state) {
    _Static_assert(RGBLIGHT_MAX_LAYERS >= RGBLYR_COUNT,
        "Max RGB layers must be greater or equal to number of layers");

  #ifdef NAPOLI1084_QWERTY_ENABLE
    rgblight_set_layer_state(RGBLYR_QWERTY, layer_state_cmp(state, LYR_QWERTY));
    rgblight_set_layer_state(RGBLYR_QNAVNUM, layer_state_cmp(state, LYR_QNAVNUM));
    rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
  #endif
    rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
    rgblight_set_layer_state(RGBLYR_GAME, layer_state_cmp(state, LYR_GAME));
    rgblight_set_layer_state(RGBLYR_NAVNUM, layer_state_cmp(state, LYR_NAVNUM));
    rgblight_set_layer_state(RGBLYR_FRSYMBOL, layer_state_cmp(state, LYR_FRSYMBOL));
  #ifdef NAPOLI1084_FRCAPS_ENABLE
    rgblight_set_layer_state(RGBLYR_FRCAPS, layer_state_cmp(state, LYR_FRCAPS));
  #endif
    rgblight_set_layer_state(RGBLYR_FN, layer_state_cmp(state, LYR_FN));
    rgblight_set_layer_state(RGBLYR_F1F12, layer_state_cmp(state, LYR_F1F12));
  #ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
    rgblight_set_layer_state(RGBLYR_WINDOWS, layer_state_cmp(state, LYR_WINDOWS));
  #endif

    led_t led_state = host_keyboard_led_state();
    rgblight_set_layer_state(RGBLYR_CAPSLOCK, led_state.caps_lock);
}

static bool napoli1084_rgblayers_enabled = false;

static void napoli1084_rgblayers_enable(layer_state_t state) {
    napoli1084_rgblayers_enabled = true;
    napoli1084_rgblayers_set_rgblayers_state(state);
}

static void napoli1084_rgblayers_disable(void) {
    napoli1084_rgblayers_enabled = false;

    for (uint8_t i = 0; i < RGBLYR_COUNT; ++i) {
        rgblight_set_layer_state(i, false);
    }
}

void napoli1084_rgblayers_keyboard_post_init(void) {
    rgblight_layers = my_rgb_layers;
    uint8_t nap_rgb_mode = napoli1084_rgb_mode_get();
    if (nap_rgb_mode <= NAP_RGB_MODE_LAYER_EFFECT_DEFAULT) {
        napoli1084_rgblayers_enable(layer_state);
    }
}

static void napoli1084_rgblayers_effect_default(layer_state_t state) {
    // Must check if we're on default layer,
    // if so we disable RGB layers to let effect set RGB values.
    uint8_t layer = get_highest_layer(state);
    uint8_t default_layer = get_highest_layer(default_layer_state);
    if (layer == default_layer) {
        // Disable RGB layers to let effect set RGB values.
        napoli1084_rgblayers_disable();
    } else {
        napoli1084_rgblayers_enable(state);
    }
}

void napoli1084_rgb_mode_on_set(uint8_t rgb_mode) {
    bool is_test = rgb_mode == NAP_RGB_MODE_LAYER_TEST;
    rgblight_set_layer_state(RGBLYR_TEST, is_test);

    switch (rgb_mode) {
        case NAP_RGB_MODE_LAYER:
        case NAP_RGB_MODE_LAYER_TEST:
            napoli1084_rgblayers_enable(layer_state);
            break;
        case NAP_RGB_MODE_LAYER_EFFECT_DEFAULT:
            napoli1084_rgblayers_effect_default(layer_state);
            break;
        case NAP_RGB_MODE_EFFECT:
            napoli1084_rgblayers_disable();
            break;
    }
}

bool napoli1084_rgblayers_led_update(led_t led_state) {
    if (napoli1084_rgblayers_enabled) {
        rgblight_set_layer_state(RGBLYR_CAPSLOCK, led_state.caps_lock);
    }
    return true;
}

// Called when setting default (base) layer
layer_state_t napoli1084_rgblayers_default_layer_state_set(layer_state_t state) {
   #ifdef NAPOLI1084_QWERTY_ENABLE
     //rgblight_set_layer_state(RGBLYR_QWERTY, layer_state_cmp(state, LYR_QWERTY));
   #else
     //rgblight_set_layer_state(RGBLYR_WORKNAP, layer_state_cmp(state, LYR_WORKNAP));
   #endif
    return state;
}

// Called when changing layer
layer_state_t napoli1084_rgblayers_layer_state_set(layer_state_t state) {

    uint8_t nap_rgb_mode = napoli1084_rgb_mode_get();
    if (nap_rgb_mode == NAP_RGB_MODE_LAYER_EFFECT_DEFAULT) {
        napoli1084_rgblayers_effect_default(state);
    } else if (napoli1084_rgblayers_enabled) {
        napoli1084_rgblayers_set_rgblayers_state(state);
    }

    return state;
}

#endif // RGBLIGHT_LAYERS

//#ifdef RGBLIGHT_ENABLE
bool napoli1084_process_rgblight(uint16_t keycode, keyrecord_t *record) {
    #ifndef RGBLIGHT_DISABLE_KEYCODES
    #error RGBLIGHT_DISABLE_KEYCODES is not defined, processing in this function supersedes the default
    #endif

    // need to trigger on key-up for edge-case issue (from quantum/process_keycode/process_rgb.c)
    if (record->event.pressed)
        return PROCESS_CONTINUE;

    switch (keycode) {
        case RGB_TOG:
            rgblight_toggle_noeeprom();
            return PROCESS_STOP;
        case RGB_MODE_FORWARD:
            rgblight_step_noeeprom();
            return PROCESS_STOP;
        case RGB_MODE_REVERSE:
            rgblight_step_reverse_noeeprom();
            return PROCESS_STOP;
        case RGB_HUI:
            rgblight_increase_hue_noeeprom();
            return PROCESS_STOP;
        case RGB_HUD:
            rgblight_decrease_hue_noeeprom();
            return PROCESS_STOP;
        case RGB_SAI:
            rgblight_increase_sat_noeeprom();
            return PROCESS_STOP;
        case RGB_SAD:
            rgblight_decrease_sat_noeeprom();
            return PROCESS_STOP;
        case RGB_VAI:
            rgblight_increase_val_noeeprom();
            return PROCESS_STOP;
        case RGB_VAD:
            rgblight_decrease_val_noeeprom();
            return PROCESS_STOP;
        case RGB_SPI:
            rgblight_increase_speed_noeeprom();
            return PROCESS_STOP;
        case RGB_SPD:
            rgblight_decrease_speed_noeeprom();
            return PROCESS_STOP;
        case RGB_MODE_PLAIN:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            return PROCESS_STOP;
        case RGB_MODE_BREATHE:
            #if defined(RGBLIGHT_EFFECT_BREATHING)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_RAINBOW:
            #if defined(RGBLIGHT_EFFECT_RAINBOW_MOOD)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_SWIRL:
            #if defined(RGBLIGHT_EFFECT_RAINBOW_SWIRL)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_SNAKE:
            #if defined(RGBLIGHT_EFFECT_SNAKE)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_KNIGHT:
            #if defined(RGBLIGHT_EFFECT_KNIGHT)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_XMAS:
            #if defined(RGBLIGHT_EFFECT_CHRISTMAS)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_GRADIENT:
            #if defined(RGBLIGHT_EFFECT_STATIC_GRADIENT)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_RGBTEST:
            #if defined(RGBLIGHT_EFFECT_RGB_TEST)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_TWINKLE:
            #if defined(RGBLIGHT_EFFECT_TWINKLE)
            rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE);
            #endif
            return PROCESS_STOP;

        // Custom keycodes
        case RGB_DBG:
            eeconfig_debug_rgblight();
            return PROCESS_STOP;
        case RGB_EEP:
            eeconfig_update_rgblight_current();
            return PROCESS_STOP;
        case RGB_LYR:
            napoli1084_rgb_mode_forward();
            return PROCESS_STOP;
    }
    return PROCESS_CONTINUE;
}
//#endif RGBLIGHT_ENABLE
