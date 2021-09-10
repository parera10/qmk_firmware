#include QMK_KEYBOARD_H


#define _LAYER0 0
#define _LAYER1 1

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = LAYOUT(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,         KC_EQL,  KC_BSPC,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,         KC_RBRC,
     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,         KC_NUHS, KC_ENT,
     KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_UP,   MO(1),
     KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),
  
  [_LAYER1] = LAYOUT(
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,          KC_F12,  KC_DEL,
     RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_MPLY, KC_VOLD,         KC_VOLU,
     KC_TRNS, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_BRID,         KC_BRIU, KC_TRNS, 
     KC_TRNS, BL_TOGG, BL_STEP, BL_BRTG, BL_ON,   BL_OFF,  BL_INC,  BL_DEC,  KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,         KC_PGUP, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END) 
};

// Tap-hold 
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SLSH):
            return 150;
        default:
            return TAPPING_TERM;
    }
};

// RGB Layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {28, 1, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
};

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
};
