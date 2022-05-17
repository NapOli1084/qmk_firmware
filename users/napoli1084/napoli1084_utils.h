
#pragma once

// Return values for key process functions like `process_record_user()`
#define PROCESS_CONTINUE true
#define PROCESS_STOP false


void napoli1084_unregister_mods(uint8_t mods);
void napoli1084_register_mods(uint8_t mods);
