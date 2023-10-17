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

#include "napoli1084_keycodes.h"
#include "napoli1084_symbolkeys.h"
#include "napoli1084_symbolkeysdata.h"
#include "napoli1084_utils.h"

#include "quantum/quantum.h"
#include "quantum/process_keycode/process_unicodemap.h"

enum napoli1084_symbol_mode {
    #ifndef NAPOLI1084_SYMD_KB_CAFR_DISABLE
    SYMD_KB_CAFR, // Canadian French
    #endif
    #ifndef NAPOLI1084_SYMD_KB_CMS_DISABLE
    SYMD_KB_CMS, // Canadian Multilingual Standard
    #endif
    #ifndef NAPOLI1084_SYMD_KB_US_DISABLE
    SYMD_KB_US, // US QWERTY
    #endif
    SYMD_KB_COUNT, // Number of keyboard symbol modes (not a mode)
    SYMD_UNICODE = SYMD_KB_COUNT, // Default, uses currently selected Unicode mode as per get_unicode_input_mode()
    #ifdef UNICODEMAP_ENABLE
    SYMD_COUNT // Number of symbol modes (not a mode)
    #else
    SYMD_COUNT = SYMD_KB_COUNT
    #endif
};

#ifdef UNICODEMAP_ENABLE
static uint8_t symbol_mode = SYMD_UNICODE;
#else
static uint8_t symbol_mode = SYMD_KB_CAFR;
#endif

void napoli1084_cycle_symbol_mode(void) {
    symbol_mode = (symbol_mode + 1) % SYMD_COUNT;

    switch (symbol_mode)
    {
    #ifndef NAPOLI1084_SYMD_KB_CAFR_DISABLE
    case SYMD_KB_CAFR:
        SEND_STRING("CAFR");
        break;
    #endif
    #ifndef NAPOLI1084_SYMD_KB_CMS_DISABLE
    case SYMD_KB_CMS:
        SEND_STRING("CMS");
        break;
    #endif
    #ifndef NAPOLI1084_SYMD_KB_US_DISABLE
    case SYMD_KB_US:
        SEND_STRING("US");
        break;
    #endif
    #ifdef UNICODEMAP_ENABLE
    case SYMD_UNICODE:
        SEND_STRING("UNI");
        break;
    #endif
    }
}

bool napoli1084_process_symbol_mode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        napoli1084_cycle_symbol_mode();
    }
    return PROCESS_STOP;
}

static void napoli1084_get_symbol_keys(uint16_t                  keycode,
                                       napoli1084_symbol_keys_t *entry) {
    uint16_t map_index = unicodemap_index(keycode);

    const napoli1084_symbol_keys_t *const *map_ptr =
        nap_symbol_keys_maps + symbol_mode;
    const napoli1084_symbol_keys_t *entry_ptr = pgm_read_ptr(map_ptr);
    entry_ptr += map_index;
    memcpy_P(entry, entry_ptr, sizeof(napoli1084_symbol_keys_t));
}

static uint8_t symbol_saved_mods = 0;
static uint32_t symbol_press_repeat_timeout = 0;
static uint16_t symbol_press_keycode = 0;

bool napoli1084_symbol_key_press(uint16_t keycode) {
    napoli1084_symbol_keys_t entry;
    napoli1084_get_symbol_keys(keycode, &entry);

    uint16_t key1 = entry.keys[0];
    if (key1 == KC_NO) {
        // rely on default `process_unicodemap()`
        return PROCESS_CONTINUE;
    }

    // Clear mods
    symbol_saved_mods = get_mods(); // Save current mods
    napoli1084_unregister_mods(symbol_saved_mods);

    // Tap keys
    tap_code16(key1);
    uint16_t key2 = entry.keys[1];
    if (key2 != KC_NO) {
        tap_code16(key2);
    }

    // Re-register mods
    napoli1084_register_mods(symbol_saved_mods);

    return PROCESS_STOP;
}

void napoli1084_update_symbol_key_press(void) {
    if (symbol_press_repeat_timeout > 0) {
        uint32_t timer = timer_read32();
        if (timer >= symbol_press_repeat_timeout) {

            #ifdef CONSOLE_ENABLE
            xprintf("SYMBOL REPEAT: keycode: 0x%04X, timer: %lu, timeout: %lu\n",
                symbol_press_keycode, timer, symbol_press_repeat_timeout);
            #endif

            bool process_state = PROCESS_CONTINUE;
            if (symbol_mode < SYMD_KB_COUNT) {
                process_state = napoli1084_symbol_key_press(symbol_press_keycode);
            }
            #if UNICODEMAP_ENABLE
            if (process_state == PROCESS_CONTINUE) {
                keyrecord_t record = {.event = {.pressed = true}};
                process_unicodemap(symbol_press_keycode, &record);
            }
            #endif
            symbol_press_repeat_timeout += SYMBOL_REPEAT_TIMEOUT_MS;
        }
    }
}

bool napoli1084_process_symbol_key(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        symbol_press_keycode = keycode;
        symbol_press_repeat_timeout = timer_read32() + SYMBOL_HOLD_TIMEOUT_MS;
    } else if (symbol_press_keycode == keycode) {
        symbol_press_keycode        = 0;
        symbol_press_repeat_timeout = 0;
    }

    if (symbol_mode < SYMD_KB_COUNT) {
        if (record->event.pressed) {
            return napoli1084_symbol_key_press(keycode);
        }
        return PROCESS_STOP;
    }
    else { //if (symbol_mode == SYMD_UNICODE) {
        // Let default `process_unicodemap()` take place
        return PROCESS_CONTINUE;
    }
}

bool napoli1084_process_symbol_mod(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        napoli1084_unregister_mods(symbol_saved_mods);
        symbol_saved_mods = 0;
    }
    return PROCESS_CONTINUE;
}
