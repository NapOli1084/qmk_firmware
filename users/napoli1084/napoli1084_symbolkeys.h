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
