/*
Copyright 2021-2022 NapOli1084 (@napoli1084)

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

// Use serial communication for split keyboard (left <=> right communication)
#define USE_SERIAL

// Indicates handedness flashed in EEPROM
// https://docs.qmk.fm/#/config_options?id=setting-handedness
// https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom
#define EE_HANDS

#undef DEBOUNCE
#define DEBOUNCE 30

// Enables synchronization of the RGB light modes between controllers.
// https://docs.qmk.fm/#/feature_split_keyboard?id=hardware-configuration-options
#define RGBLED_SPLIT { 6, 6 }

// https://docs.qmk.fm/#/feature_rgblight?id=effects-and-animations
// RGBLIGHT_ANIMATIONS is deprecated and animation modes should be explicitly defined.
//#define RGBLIGHT_ANIMATIONS

#define LAYER_STATE_8BIT
