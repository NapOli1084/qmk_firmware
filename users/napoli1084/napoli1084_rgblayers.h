#pragma once

#include "quantum/led.h"
#include "quantum/action_layer.h"

#ifdef RGBLIGHT_LAYERS
    void napoli1084_rgblayers_keyboard_post_init(void);
    bool napoli1084_rgblayers_led_update(led_t led_state);
    layer_state_t napoli1084_rgblayers_default_layer_state_set(layer_state_t state);
    layer_state_t napoli1084_rgblayers_layer_state_set(layer_state_t state);

    #define RGBLIGHT_LAYERS_ONLY(...) __VA_ARGS__
#else
    #define RGBLIGHT_LAYERS_ONLY(...)
#endif

