/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

// how many taps before oneshot toggle is triggered
// https://docs.qmk.fm/#/one_shot_keys?id=one-shot-keys
#define ONESHOT_TAP_TOGGLE 2

// how many taps before triggering the toggle with layer Tap-Toggle function TT(layer)
// https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
#define TAPPING_TOGGLE 1

// how long before a tap becomes a hold in milliseconds
#define TAPPING_TERM 200

// https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

// Unicode mode WinCompose with KC_APP as trigger key
// https://docs.qmk.fm/#/feature_unicode?id=setting-the-input-mode
#define UNICODE_SELECTED_MODES UC_WINC
// https://docs.qmk.fm/#/feature_unicode?id=input-key-configuration
#define UNICODE_KEY_WINC KC_APPLICATION

#undef DEBOUNCE
#define DEBOUNCE 30

// Enables synchronization of the RGB light modes between controllers.
// https://docs.qmk.fm/#/feature_split_keyboard?id=hardware-configuration-options
#define RGBLED_SPLIT { 6, 6 }

// https://docs.qmk.fm/#/feature_rgblight?id=effects-and-animations
#define RGBLIGHT_ANIMATIONS
