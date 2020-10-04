#include "scaea.h"
#include "timer.h"

const uint16_t PROGMEM
led[] =
LED_PINS;

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

KEYMAP(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_RABK, KC_Y, KC_X, KC_C, KC_M,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(
1), TG(2)),

KEYMAP(
        KC_ESC, KC_F2, KC_F4, KC_F5, KC_F11, KC_DEL,
        KC_TAB, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_BSPC,
        KC_CAPS, KC_MUTE, KC_UP, KC_MUTE, KC_VOLU, KC_ENT,
        KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_TRNS, KC_TRNS
),

KEYMAP(
        KC_ESC, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        KC_TAB, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_BSPC,
        KC_CAPS, KC_MUTE, KC_UP, KC_MUTE, KC_VOLU, KC_ENT,
        KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(
1), TG(2)),

KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    //keyevent_t event = record->event;

    switch (id) {

    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
    startSequence();
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_COMPOSE)) {
    } else {
    }

    if (usb_led & (1 << USB_LED_KANA)) {
    } else {
    }

}

layer_state_t layer_state_set_user(layer_state_t state) {
    return setLayerIndication(state, false);
};