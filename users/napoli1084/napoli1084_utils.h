
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

#include <stdint.h>

// Return values for key process functions like `process_record_user()`
#define PROCESS_CONTINUE true
#define PROCESS_STOP false


void napoli1084_unregister_mods(uint8_t mods);
void napoli1084_register_mods(uint8_t mods);

#ifdef CAPS_WORD_ENABLE
void napoli1084_shift_if_caps_word_on(void);
#endif

#ifdef CONSOLE_ENABLE
#define nap_dprintf(fmt, ...) dprintf(fmt, ##__VA_ARGS__)
#else
#define nap_dprintf(fmt, ...)
#endif

