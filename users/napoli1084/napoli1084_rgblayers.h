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

#ifdef RGBLIGHT_LAYERS
    void napoli1084_rgblayers_keyboard_post_init(void);
    bool napoli1084_rgblayers_led_update(led_t led_state);
    layer_state_t napoli1084_rgblayers_default_layer_state_set(layer_state_t state);
    layer_state_t napoli1084_rgblayers_layer_state_set(layer_state_t state);

    #define RGBLIGHT_LAYERS_ONLY(...) __VA_ARGS__
#else
    #define RGBLIGHT_LAYERS_ONLY(...)
#endif

