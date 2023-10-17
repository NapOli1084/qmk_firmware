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

///////////////////////////////////////////////////////////////////////////
// Caps Word
///////////////////////////////////////////////////////////////////////////
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD


///////////////////////////////////////////////////////////////////////////
// Layers
///////////////////////////////////////////////////////////////////////////
// I don't expect using more than 16 layers, so using 16 bits saves some space.
// Moved to keyboard
//#define LAYER_STATE_16BIT

///////////////////////////////////////////////////////////////////////////
// Locking
///////////////////////////////////////////////////////////////////////////
// This is for mechanically locking keys.
// https://docs.qmk.fm/#/squeezing_avr?id=configh-settings
// https://docs.qmk.fm/#/faq_keymap?id=mechanical-lock-switch-support
//
// Supports KC_LOCKING_CAPS_LOCK, KC_LOCKING_NUM_LOCK, KC_LOCKING_SCROLL_LOCK.
// ergodox_ez enables it (?!), keebio/viterbi and dactyl_manuform also,
// let's disable it.
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

///////////////////////////////////////////////////////////////////////////
// RGB backlight/underglow
///////////////////////////////////////////////////////////////////////////
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LAYERS
#endif
#define RGBLIGHT_MAX_LAYERS 12
#undef RGBLIGHT_SLEEP
#define RGBLIGHT_SLEEP

// Using my own processing for rgb keycodes
#define RGBLIGHT_DISABLE_KEYCODES

#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 8
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 8
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 8


///////////////////////////////////////////////////////////////////////////
// RGB Matrix
///////////////////////////////////////////////////////////////////////////
#undef RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#undef RGB_MATRIX_TIMEOUT
// Turn off after 10 minutes
#define RGB_MATRIX_TIMEOUT 600000

// Startup animation speed
//#define RGB_MATRIX_STARTUP_SPD 60

// Using my own processing for rgb keycodes
#define RGB_MATRIX_DISABLE_KEYCODES

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN

//#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINDROPS // few bright red/blue/green/yellow colors
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // many pastel colors, pink/purple/turquoise/etc.

#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

#undef RGB_MATRIX_KEYPRESSES
#undef RGB_MATRIX_KEYRELEASES
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

///////////////////////////////////////////////////////////////////////////
// Tapping
///////////////////////////////////////////////////////////////////////////

// how many taps before oneshot toggle is triggered
// https://docs.qmk.fm/#/one_shot_keys?id=one-shot-keys
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 5000

// how many taps before triggering the toggle with layer Tap-Toggle function TT(layer)
// https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
#define TAPPING_TOGGLE 1

// how long before a tap becomes a hold in milliseconds
#undef TAPPING_TERM
#define TAPPING_TERM 225

// Waits milliseconds before calling unregister_code() when tap_code() is called.
// Needed for my symbol keys with LSFT and 2 keys sequence, e.g. 'ë' on CAFR keyboard.
// Otherwise shift isn't applied to the right keystroke and doesn't give the desired result.
// 3 milliseconds seems enough (it worked well with 5 and 10 also).
// More than 3 milliseconds slows down repetition with WinCompose unicode keys
// since they end up tapping 7-11 keys and repetition is every 33ms.
#define TAP_CODE_DELAY 6

///////////////////////////////////////////////////////////////////////////
// Unicode
///////////////////////////////////////////////////////////////////////////

// Unicode mode WinCompose with KC_APP as trigger key
// https://docs.qmk.fm/#/feature_unicode?id=setting-the-input-mode
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
// https://docs.qmk.fm/#/feature_unicode?id=input-key-configuration
#define UNICODE_KEY_WINC KC_APPLICATION

// Don't save Unicode mode to EEPROM
#define UNICODE_CYCLE_PERSIST 0

//#define UNICODE_TYPE_DELAY 0


