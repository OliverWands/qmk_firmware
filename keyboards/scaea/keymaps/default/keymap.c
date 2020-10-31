#include "scaea.h"
#include "timer.h"

uint8_t activeLayer = 0;
bool blink = false;
uint16_t blinkCount = 0;

const uint16_t PROGMEM
led[] =
LED_PINS;

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
//
// Layer 0
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_BSLS, KC_Y, KC_X, KC_C, KC_V,
        KC_LCTL, KC_LGUI, MO(14), KC_LALT, KC_SPC, MO(1)
),

//
// Layer 1
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        RESET, KC_F2, KC_F4, KC_F5, KC_F11, KC_DEL,
        KC_TAB, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_BSPC,
        KC_CAPS, KC_MUTE, KC_UP, KC_MUTE, KC_VOLU, KC_ENT,
        KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_TRNS, KC_TRNS
),

//
// Layer 2
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_ESC, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        KC_TAB, KC_MPLY, KC_MSTP, KC_7, KC_8, KC_9,
        KC_CAPS, KC_MUTE, KC_UP, KC_4, KC_5, KC_6,
        KC_LSFT, KC_LEFT, KC_DOWN, KC_1, KC_2, KC_3,
        KC_LCTL, KC_LGUI, MO(14), KC_LALT, KC_SPC, MO(3)
),

//
// Layer 3
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

//
// Layer 4 | Eagle layer
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MO(14), KC_TRNS, KC_TRNS, MO(5)
),

//
// Layer 5
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

//
// Layer 6
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MO(14), KC_TRNS, KC_TRNS, MO(7)
),

//
// Layer 7
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

//
// Layer 8
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MO(14), KC_TRNS, KC_TRNS, MO(9)
),

//
// Layer 9
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

//
// Layer 10
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MO(14), KC_TRNS, KC_TRNS, MO(11)
),

//
// Layer 11
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

//
// Layer 12
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MO(14), KC_TRNS, KC_TRNS, MO(13)
),

//
// Layer 13
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

//
// Layer 14
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
//
KEYMAP(
        RESET, TO(0), TO(2), TO(4), TO(6), TO(8),
        KC_TRNS, TO(10), TO(12), KC_TRNS, KC_TRNS, KC_TRNS,
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
    if (((activeLayer % 2) != 0) || activeLayer == 14)
    {
        blinkCount %= 1024;
        if (blinkCount == 1023)
        {
            blink = !blink;
        }
        if (blink)
        {
            setLayerIndication(activeLayer);
        }
        else
        {
            digitToBin(0);
        }
        blinkCount++;
    }
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
    activeLayer = get_highest_layer(state);
    setLayerIndication(activeLayer);
    return state;
}