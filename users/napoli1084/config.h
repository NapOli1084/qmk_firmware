
#define RGBLIGHT_MAX_LAYERS 12

// how many taps before oneshot toggle is triggered
// https://docs.qmk.fm/#/one_shot_keys?id=one-shot-keys
#define ONESHOT_TAP_TOGGLE 2

// how many taps before triggering the toggle with layer Tap-Toggle function TT(layer)
// https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
#define TAPPING_TOGGLE 1

// how long before a tap becomes a hold in milliseconds
#define TAPPING_TERM 225

// https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

// Unicode mode WinCompose with KC_APP as trigger key
// https://docs.qmk.fm/#/feature_unicode?id=setting-the-input-mode
#define UNICODE_SELECTED_MODES UC_WINC
// https://docs.qmk.fm/#/feature_unicode?id=input-key-configuration
#define UNICODE_KEY_WINC KC_APPLICATION

// Don't save Unicode mode to EEPROM
#define UNICODE_CYCLE_PERSIST 0

//#define UNICODE_TYPE_DELAY 0
