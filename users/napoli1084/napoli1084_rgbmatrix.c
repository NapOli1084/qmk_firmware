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

#include "napoli1084_keycodeenums.h"
#include "napoli1084_rgbmatrix_layers.h" // under keyboards/**/keymaps/napoli1084
#include "napoli1084_rgbmatrix.h"
#include "napoli1084_rgbmode.h"
#include "napoli1084_utils.h"

#include <stddef.h>
#include "quantum/rgb_matrix/rgb_matrix.h"


enum nap_rgb_matrix_layer_map_id {
    NAP_RGB_SINGLE_COLOR_LAYER_MAP = 0x40,
    NAP_RGB_MATRIX_LAYER_MAP = 0x00,
    NAP_RGB_LAYER_MAP_MASK = 0xC0,
    NAP_RGB_LAYER_INDEX_MASK = 0x3F,
};

enum nap_rgb_matrix_layer_id {
#ifdef NAPOLI1084_RGBMATRIX_LYR_WORKNAP
    NAP_RGB_MATRIX_LYR_WORKNAP,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_GAME
    NAP_RGB_MATRIX_LYR_GAME,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_NAVNUM
    NAP_RGB_MATRIX_LYR_NAVNUM,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_FRSYMBOL
    NAP_RGB_MATRIX_LYR_FRSYMBOL,
#endif
#ifdef NAPOLI1084_FRCAPS_ENABLE
#ifdef NAPOLI1084_RGBMATRIX_LYR_FRCAPS
    NAP_RGB_MATRIX_LYR_FRCAPS,
#endif
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_FN
    NAP_RGB_MATRIX_LYR_FN,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_F1F12
    NAP_RGB_MATRIX_LYR_F1F12,
#endif
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
#ifdef NAPOLI1084_RGBMATRIX_LYR_WINDOWS
    NAP_RGB_MATRIX_LYR_WINDOWS,
#endif
#endif
};

const uint8_t PROGMEM nap_rgb_matrix_layer_map[][RGB_MATRIX_LED_COUNT][3] = {
#ifdef NAPOLI1084_RGBMATRIX_LYR_WORKNAP
    [NAP_RGB_MATRIX_LYR_WORKNAP] = NAPOLI1084_RGBMATRIX_LYR_WORKNAP,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_GAME
    [NAP_RGB_MATRIX_LYR_GAME] = NAPOLI1084_RGBMATRIX_LYR_GAME,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_NAVNUM
    [NAP_RGB_MATRIX_LYR_NAVNUM] = NAPOLI1084_RGBMATRIX_LYR_NAVNUM,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_FRSYMBOL
    [NAP_RGB_MATRIX_LYR_FRSYMBOL] = NAPOLI1084_RGBMATRIX_LYR_FRSYMBOL,
#endif
#ifdef NAPOLI1084_FRCAPS_ENABLE
#ifdef NAPOLI1084_RGBMATRIX_LYR_FRCAPS
    [NAP_RGB_MATRIX_LYR_FRCAPS] = NAPOLI1084_RGBMATRIX_LYR_FRCAPS,
#endif
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_FN
    [NAP_RGB_MATRIX_LYR_FN] = NAPOLI1084_RGBMATRIX_LYR_FN,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_F1F12
    [NAP_RGB_MATRIX_LYR_F1F12] = NAPOLI1084_RGBMATRIX_LYR_F1F12,
#endif
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
#ifdef NAPOLI1084_RGBMATRIX_LYR_WINDOWS
    [NAP_RGB_MATRIX_LYR_WINDOWS] = NAPOLI1084_RGBMATRIX_LYR_WINDOWS,
#endif
#endif
};

const uint8_t PROGMEM nap_rgb_single_color_layer_map[][3] = {
    [LYR_WORKNAP] = { NAPOLI1084_HSV_LYR_WORKNAP },
    [LYR_GAME] = { NAPOLI1084_HSV_LYR_GAME },
    [LYR_NAVNUM] = { NAPOLI1084_HSV_LYR_NAVNUM },
    [LYR_FRSYMBOL] = { NAPOLI1084_HSV_LYR_FRSYMBOL },
#ifdef NAPOLI1084_FRCAPS_ENABLE
    [LYR_FRCAPS] = { NAPOLI1084_HSV_LYR_FRCAPS },
#endif
    [LYR_FN] = { NAPOLI1084_HSV_LYR_FN },
    [LYR_F1F12] = { NAPOLI1084_HSV_LYR_F1F12 },
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
    [LYR_WINDOWS] = { NAPOLI1084_HSV_LYR_WINDOWS },
#endif
};

const uint8_t PROGMEM nap_rgb_layer_index_map[] = {
#ifdef NAPOLI1084_RGBMATRIX_LYR_WORKNAP
    [LYR_WORKNAP] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_WORKNAP,
#else
    [LYR_WORKNAP] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_WORKNAP,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_GAME
    [LYR_GAME] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_GAME,
#else
    [LYR_GAME] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_GAME,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_NAVNUM
    [LYR_NAVNUM] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_NAVNUM,
#else
    [LYR_NAVNUM] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_NAVNUM,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_FRSYMBOL
    [LYR_FRSYMBOL] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_FRSYMBOL,
#else
    [LYR_FRSYMBOL] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_FRSYMBOL,
#endif
#ifdef NAPOLI1084_FRCAPS_ENABLE
#ifdef NAPOLI1084_RGBMATRIX_LYR_FRCAPS
    [LYR_FRCAPS] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_FRCAPS,
#else
    [LYR_FRCAPS] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_FRCAPS,
#endif
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_FN
    [LYR_FN] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_FN,
#else
    [LYR_FN] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_FN,
#endif
#ifdef NAPOLI1084_RGBMATRIX_LYR_F1F12
    [LYR_F1F12] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_F1F12,
#else
    [LYR_F1F12] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_F1F12,
#endif
#ifdef NAPOLI1084_LYR_WINDOWS_ENABLE
#ifdef NAPOLI1084_RGBMATRIX_LYR_WINDOWS
    [LYR_WINDOWS] = NAP_RGB_MATRIX_LAYER_MAP | NAP_RGB_MATRIX_LYR_WINDOWS,
#else
    [LYR_WINDOWS] = NAP_RGB_SINGLE_COLOR_LAYER_MAP | LYR_WINDOWS,
#endif
#endif
};

static void set_layer_color(int layer) {
    HSV hsv;
    uint8_t map_layer_index = pgm_read_byte(&nap_rgb_layer_index_map[layer]);
    bool is_single_color_layer = (map_layer_index & NAP_RGB_LAYER_MAP_MASK) == NAP_RGB_SINGLE_COLOR_LAYER_MAP;
    uint8_t layer_index = map_layer_index & NAP_RGB_LAYER_INDEX_MASK;
    if (is_single_color_layer) {
        hsv.h = pgm_read_byte(&nap_rgb_single_color_layer_map[layer_index][0]);
        hsv.s = pgm_read_byte(&nap_rgb_single_color_layer_map[layer_index][1]);
        hsv.v = pgm_read_byte(&nap_rgb_single_color_layer_map[layer_index][2]);
    }

    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        if (!is_single_color_layer) {
            hsv.h = pgm_read_byte(&nap_rgb_matrix_layer_map[layer_index][i][0]);
            hsv.s = pgm_read_byte(&nap_rgb_matrix_layer_map[layer_index][i][1]);
            hsv.v = pgm_read_byte(&nap_rgb_matrix_layer_map[layer_index][i][2]);
        }
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rgb_matrix_get_suspend_state())
        return PROCESS_STOP;

#ifdef ORYX_CONFIGURATOR
    // ergodox_ez
    if (keyboard_config.disable_layer_led)
        return PROCESS_STOP;
#endif

    uint8_t nap_rgb_mode = napoli1084_rgb_mode_get();
    if (nap_rgb_mode >= NAP_RGB_MODE_EFFECT)
        return PROCESS_STOP;

    uint8_t layer = get_highest_layer(layer_state);

    if (nap_rgb_mode == NAP_RGB_MODE_LAYER_EFFECT_DEFAULT) {
        uint8_t default_layer = get_highest_layer(default_layer_state);
        if (layer <= default_layer) {
            return PROCESS_STOP;
        }
    }

    if (layer <= LYR_COUNT) {
        set_layer_color(layer);
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }

    return PROCESS_STOP;
}

// from rgb_matrix.c
void eeconfig_debug_rgb_matrix(void);

bool napoli1084_process_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    #ifndef RGB_MATRIX_DISABLE_KEYCODES
    #error RGB_MATRIX_DISABLE_KEYCODES is not defined, processing in this function supersedes the default
    #endif

    // need to trigger on key-up for edge-case issue (from quantum/process_keycode/process_rgb.c)
    if (record->event.pressed)
        return PROCESS_CONTINUE;

    switch (keycode) {
        case RGB_TOG:
            rgb_matrix_toggle_noeeprom();
            return PROCESS_STOP;
        case RGB_MODE_FORWARD:
            rgb_matrix_step_noeeprom();
            return PROCESS_STOP;
        case RGB_MODE_REVERSE:
            rgb_matrix_step_reverse_noeeprom();
            return PROCESS_STOP;
        case RGB_HUI:
            rgb_matrix_increase_hue_noeeprom();
            return PROCESS_STOP;
        case RGB_HUD:
            rgb_matrix_decrease_hue_noeeprom();
            return PROCESS_STOP;
        case RGB_SAI:
            rgb_matrix_increase_sat_noeeprom();
            return PROCESS_STOP;
        case RGB_SAD:
            rgb_matrix_decrease_sat_noeeprom();
            return PROCESS_STOP;
        case RGB_VAI:
            rgb_matrix_increase_val_noeeprom();
            return PROCESS_STOP;
        case RGB_VAD:
            rgb_matrix_decrease_val_noeeprom();
            return PROCESS_STOP;
        case RGB_SPI:
            rgb_matrix_increase_speed_noeeprom();
            return PROCESS_STOP;
        case RGB_SPD:
            rgb_matrix_decrease_speed_noeeprom();
            return PROCESS_STOP;
        case RGB_MODE_PLAIN:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            return PROCESS_STOP;
        case RGB_MODE_BREATHE:
            #if defined(ENABLE_RGB_MATRIX_BREATHING)
            rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_RAINBOW:
            #if defined(ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT)
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_SWIRL:
            #if defined(ENABLE_RGB_MATRIX_CYCLE_PINWHEEL)
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_PINWHEEL);
            #endif
            return PROCESS_STOP;
        case RGB_MODE_SNAKE:
            return PROCESS_STOP;
        case RGB_MODE_KNIGHT:
            return PROCESS_STOP;
        case RGB_MODE_XMAS:
            return PROCESS_STOP;
        case RGB_MODE_GRADIENT:
            return PROCESS_STOP;
        case RGB_MODE_RGBTEST:
            return PROCESS_STOP;
        case RGB_MODE_TWINKLE:
            return PROCESS_STOP;

        // Custom keycodes
        case RGB_DBG:
            eeconfig_debug_rgb_matrix();
            return PROCESS_STOP;
        case RGB_EEP:
            eeconfig_update_rgb_matrix();
            return PROCESS_STOP;
        case RGB_LYR:
            napoli1084_rgb_mode_forward();
            return PROCESS_STOP;
    }
    return PROCESS_CONTINUE;
}
