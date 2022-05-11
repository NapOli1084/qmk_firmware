#pragma once

#include <quantum/action.h>

#include <stdint.h>

enum {
    // Max number of keys to tap in sequence to produce a symbol
    SYMBOL_KEYS_MAX = 2,
    // Duration that the key must be held before it starts repeating
    SYMBOL_HOLD_TIMEOUT_MS = 500,
    // Duration between each repetition when key is held
    SYMBOL_REPEAT_TIMEOUT_MS = 33,
};

typedef struct {
    uint16_t keys[SYMBOL_KEYS_MAX];
} napoli1084_symbol_keys_t;

bool napoli1084_process_symbol_mode(uint16_t keycode, keyrecord_t *record);
bool napoli1084_process_symbol_key(uint16_t keycode, keyrecord_t* record);
bool napoli1084_process_symbol_mod(uint16_t keycode, keyrecord_t* record);
void napoli1084_update_symbol_key_press(void);
bool napoli1084_symbol_key_press(uint16_t keycode);
