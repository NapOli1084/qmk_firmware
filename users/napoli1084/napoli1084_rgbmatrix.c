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

#include <stddef.h>
#include "quantum/rgb_matrix/rgb_matrix.h"


#ifdef RGB_MATRIX_DISABLE_KEYCODES
    #error RGB_MATRIX_DISABLE_KEYCODES is defined
#endif

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

void rgb_matrix_indicators_user(void) {
    if (rgb_matrix_get_suspend_state())
        return;

#ifdef ORYX_CONFIGURATOR
    // ergodox_ez
    if (keyboard_config.disable_layer_led)
        return;
#endif

    uint8_t layer = get_highest_layer(layer_state);
    if (layer <= LYR_COUNT) {
        set_layer_color(layer);
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
}
