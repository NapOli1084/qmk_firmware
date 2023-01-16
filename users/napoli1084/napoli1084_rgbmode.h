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

#pragma once

#include "quantum/led.h"
#include "quantum/action_layer.h"

enum napoli1084_rgb_layer_modes {
#if defined(RGBLIGHT_LAYERS) || defined(RGB_MATRIX_ENABLE)
    NAP_RGB_MODE_LAYER, // Use layer colors
    NAP_RGB_MODE_LAYER_EFFECT_DEFAULT, // Use layer colors except on default layer, play effect
    NAP_RGB_MODE_LAYER_TEST, // Test layer
#endif
    NAP_RGB_MODE_EFFECT, // Use QMK's RGB effects
    NAP_RGB_MODE_COUNT
};

uint8_t napoli1084_rgb_mode_get(void);
void napoli1084_rgb_mode_forward(void);
