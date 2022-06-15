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

#include <stddef.h>
#include "quantum/rgb_matrix/rgb_matrix.h"

#define NAP_HSV_FRCAPS 15, 255, 255 // orange
#define NAP_HSV_F1F12 234, 255, 255 // pink

const uint8_t PROGMEM nap_rgb_matrix_layer_map[][DRIVER_LED_TOTAL][3] = {
    [LYR_WORKNAP] = { {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN} },
    [LYR_GAME] = { {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED} },
    [LYR_NAVNUM] = { {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE} },
    [LYR_FRSYMBOL] = { {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_YELLOW} },
    [LYR_FRCAPS] = { {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS}, {NAP_HSV_FRCAPS} },
    [LYR_FN] = { {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA}, {HSV_MAGENTA} },
    [LYR_F1F12] = { {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12}, {NAP_HSV_F1F12} },
    [LYR_WINDOWS] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },
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

    uint8_t layer = biton32(layer_state);
    if (layer <= LYR_COUNT) {
        set_layer_color(layer);
    } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0, 0, 0);
    }
}
