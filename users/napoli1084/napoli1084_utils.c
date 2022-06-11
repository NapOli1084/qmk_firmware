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

#ifdef CAPS_WORD_ENABLE
void napoli1084_shift_if_caps_word_on(void) {
    if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));
    }
}
#endif
