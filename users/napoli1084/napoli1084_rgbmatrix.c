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
#include "napoli1084_utils.h"

#include <stddef.h>
#include "quantum/rgb_matrix/rgb_matrix.h"

#ifndef NAPOLI1084_RGBMATRIX_LYR
    #error NAPOLI1084_RGBMATRIX_LYR must be defined in napoli1084_rgbmatrix_layers.h
#endif

#ifndef NAPOLI1084_RGBMATRIX_LYR_WORKNAP
    #define NAPOLI1084_RGBMATRIX_LYR_WORKNAP NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_WORKNAP)
#endif
#ifndef NAPOLI1084_RGBMATRIX_LYR_GAME
    #define NAPOLI1084_RGBMATRIX_LYR_GAME NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_GAME)
#endif
#ifndef NAPOLI1084_RGBMATRIX_LYR_NAVNUM
    #define NAPOLI1084_RGBMATRIX_LYR_NAVNUM NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_NAVNUM)
#endif
#ifndef NAPOLI1084_RGBMATRIX_LYR_FRSYMBOL
    #define NAPOLI1084_RGBMATRIX_LYR_FRSYMBOL NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_FRSYMBOL)
#endif
#ifndef NAPOLI1084_RGBMATRIX_LYR_FRCAPS
    #define NAPOLI1084_RGBMATRIX_LYR_FRCAPS NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_FRCAPS)
#endif
#ifndef NAPOLI1084_RGBMATRIX_LYR_FN
    #define NAPOLI1084_RGBMATRIX_LYR_FN NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_FN)
#endif
#ifndef NAPOLI1084_RGBMATRIX_LYR_F1F12
    #define NAPOLI1084_RGBMATRIX_LYR_F1F12 NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_F1F12)
#endif
#ifndef NAPOLI1084_RGBMATRIX_LYR_WINDOWS
    #define NAPOLI1084_RGBMATRIX_LYR_WINDOWS NAPOLI1084_RGBMATRIX_LYR(NAPOLI1084_HSV_LYR_WINDOWS)
#endif

const uint8_t PROGMEM nap_rgb_matrix_layer_map[][DRIVER_LED_TOTAL][3] = {
    [LYR_WORKNAP] = { NAPOLI1084_RGBMATRIX_LYR_WORKNAP },
    [LYR_GAME] = { NAPOLI1084_RGBMATRIX_LYR_GAME },
    [LYR_NAVNUM] = { NAPOLI1084_RGBMATRIX_LYR_NAVNUM },
    [LYR_FRSYMBOL] = { NAPOLI1084_RGBMATRIX_LYR_FRSYMBOL },
    [LYR_FRCAPS] = { NAPOLI1084_RGBMATRIX_LYR_FRCAPS },
    [LYR_FN] = { NAPOLI1084_RGBMATRIX_LYR_FN },
    [LYR_F1F12] = { NAPOLI1084_RGBMATRIX_LYR_F1F12 },
    [LYR_WINDOWS] = { NAPOLI1084_RGBMATRIX_LYR_WINDOWS },
};

static void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&nap_rgb_matrix_layer_map[layer][i][0]),
            .s = pgm_read_byte(&nap_rgb_matrix_layer_map[layer][i][1]),
            .v = pgm_read_byte(&nap_rgb_matrix_layer_map[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

enum napoli1084_rgb_layer_modes {
    NAP_RGB_MODE_LAYER, // Use layer colors
    NAP_RGB_MODE_LAYER_EFFECT_DEFAULT, // Use layer colors except on default layer, play effect
    NAP_RGB_MODE_EFFECT, // Use QMK's RGB matrix effects
    NAP_RGB_MODE_COUNT
};

static uint8_t nap_rgb_mode = NAP_RGB_MODE_LAYER;

void rgb_matrix_indicators_user(void) {
    if (rgb_matrix_get_suspend_state())
        return;

#ifdef ORYX_CONFIGURATOR
    // ergodox_ez
    if (keyboard_config.disable_layer_led)
        return;
#endif

    if (nap_rgb_mode >= NAP_RGB_MODE_EFFECT)
        return;

    uint8_t layer = get_highest_layer(layer_state);

    if (nap_rgb_mode == NAP_RGB_MODE_LAYER_EFFECT_DEFAULT) {
        uint8_t default_layer = get_highest_layer(default_layer_state);
        if (layer <= default_layer) {
            return;
        }
    }

    if (layer <= LYR_COUNT) {
        set_layer_color(layer);
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
}

static void napoli1084_rgb_mode_forward(void) {
    ++nap_rgb_mode;
    nap_rgb_mode %= NAP_RGB_MODE_COUNT;
    dprintf("nap rgb layer mode: %u\n", nap_rgb_mode);
    dprintf("nap rgb layer highest layer: %u\n", get_highest_layer(layer_state));
    dprintf("nap rgb layer default layer: %u\n", get_highest_layer(default_layer_state));
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
