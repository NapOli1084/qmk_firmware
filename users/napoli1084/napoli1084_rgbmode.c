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

#include "napoli1084_rgbmode.h"

#include "quantum/bitwise.h"
#include "quantum/action_layer.h"
#include "quantum/logging/debug.h"

static uint8_t nap_rgb_mode = 0;

uint8_t napoli1084_rgb_mode_get(void) {
    return nap_rgb_mode;
}

__attribute__((weak)) void napoli1084_rgb_mode_on_set(uint8_t rgb_mode) {
}

void napoli1084_rgb_mode_set(uint8_t rgb_mode) {
    napoli1084_rgb_mode_on_set(rgb_mode);
    nap_rgb_mode = rgb_mode;
    dprintf("nap rgb layer mode: %u\n", nap_rgb_mode);
    dprintf("nap rgb layer highest layer: %u\n", get_highest_layer(layer_state));
    dprintf("nap rgb layer default layer: %u\n", get_highest_layer(default_layer_state));
}

void napoli1084_rgb_mode_forward(void) {
    uint8_t rgb_mode = nap_rgb_mode;
    ++rgb_mode;
    rgb_mode %= NAP_RGB_MODE_COUNT;
    napoli1084_rgb_mode_set(rgb_mode);
}
