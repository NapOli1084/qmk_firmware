#include "napoli1084_symbolkeys.h"
#include "napoli1084_symbolkeysdata.h"

#include "napoli1084.h"
#include "napoli1084_utils.h"

void napoli1084_cycle_symbol_mode(void) {
    symbol_mode = (symbol_mode + 1) % SYMD_COUNT;

    switch (symbol_mode)
    {
    case SYMD_KB_CAFR:
        SEND_STRING("CAFR");
        break;
    case SYMD_KB_CMS:
        SEND_STRING("CMS");
        break;
    case SYMD_KB_US:
        SEND_STRING("US");
        break;
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
static uint16_t symbol_press_repeat_timeout = 0;
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
        uint16_t timer = timer_read();
        if (timer >= symbol_press_repeat_timeout) {
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
        symbol_press_repeat_timeout = timer_read() + SYMBOL_HOLD_TIMEOUT_MS;
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
