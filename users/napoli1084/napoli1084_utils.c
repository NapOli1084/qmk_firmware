#include "napoli1084_utils.h"
#include "quantum.h"

void napoli1084_unregister_mods(uint8_t mods) {
    if (mods & MOD_BIT(KC_LEFT_SHIFT)) {
        unregister_code(KC_LSFT);
        // tap twice to clear sticky key
        tap_code(KC_LSFT);
        tap_code(KC_LSFT);
    }
    if (mods & MOD_BIT(KC_RIGHT_SHIFT)) {
        unregister_code(KC_RSFT);
        // tap twice to clear sticky key
        tap_code(KC_RSFT);
        tap_code(KC_RSFT);
    }
    clear_mods(); // Clear internal mods state
}

void napoli1084_register_mods(uint8_t mods) {
    if (mods & MOD_BIT(KC_LEFT_SHIFT)) {
        register_code(KC_LSFT);
    }
    if (mods & MOD_BIT(KC_RIGHT_SHIFT)) {
        register_code(KC_RSFT);
    }
    set_mods(mods); // Re-set internal mods state
}

