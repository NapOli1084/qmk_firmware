
#define RGBLIGHT_MAX_LAYERS 12

// how many taps before oneshot toggle is triggered
// https://docs.qmk.fm/#/one_shot_keys?id=one-shot-keys
#define ONESHOT_TAP_TOGGLE 2

// how many taps before triggering the toggle with layer Tap-Toggle function TT(layer)
// https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
#define TAPPING_TOGGLE 1

// how long before a tap becomes a hold in milliseconds
#define TAPPING_TERM 225

// Waits milliseconds before calling unregister_code()
// Needed for my symbol keys with LSFT and 2 keys sequence, e.g. 'ë' on CAFR keyboard.
// Otherwise shift isn't applied to the right keystroke and doesn't give the desired result.
// 3 milliseconds seems enough (it worked well with 5 and 10 also).
// More than 3 milliseconds slows down repetition with WinCompose unicode keys
// since they end up tapping 7-11 keys and repetition is every 33ms.
#define TAP_CODE_DELAY 3

// https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
// https://docs.qmk.fm/#/mod_tap?id=changing-hold-function
// This makes it possible to do rolling combos (zx)
// with keys that convert to other keys on hold
// (z becomes ctrl when you hold it, and when this option isn't enabled,
// z rapidly followed by x actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT

// Unicode mode WinCompose with KC_APP as trigger key
// https://docs.qmk.fm/#/feature_unicode?id=setting-the-input-mode
#define UNICODE_SELECTED_MODES UC_WINC
// https://docs.qmk.fm/#/feature_unicode?id=input-key-configuration
#define UNICODE_KEY_WINC KC_APPLICATION

// Don't save Unicode mode to EEPROM
#define UNICODE_CYCLE_PERSIST 0

//#define UNICODE_TYPE_DELAY 0
