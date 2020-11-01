#include "scaea.h"
#include "timer.h"

uint8_t activeLayer = 0;
bool blink = false;
uint16_t blinkCount = 0;

const uint16_t PROGMEM
led[] =
LED_PINS;

enum eagle_keycodes {
    EAGLE_UNDO,
    EAGLE_REDO,
    EAGLE_ZOOMFIT,
    EAGLE_MOVE,
    EAGLE_RIPUP,
    EAGLE_ROUTEWIRE,
    EAGLE_TEXT,
    EAGLE_RATSNEST,
    EAGLE_DIMENSION,
    EAGLE_GRID_MM,
    EAGLE_GRID_MIL,
    EAGLE_GRID_INCH,
    EAGLE_GRID_MIC,
    EAGLE_LAYER_TOP,
    EAGLE_LAYER_BOT,
    EAGLE_DISPLAY_LAYER_TOP,
    EAGLE_DISPLAY_LAYER_STD,
    EAGLE_DISPLAY_LAYER_BOT,
    EAGLE_VIA,
    EAGLE_HOLE,
    EAGLE_LINE,
    EAGLE_POLYGON
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
//
// Layer 1
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
// Layer 1.1
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
        KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_M,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_TRNS
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
// Layer 2.1
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
// Layer 3 | Eagle Board layer
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_ESC        ,EAGLE_LAYER_TOP         ,EAGLE_DIMENSION ,EAGLE_LAYER_BOT ,EAGLE_RATSNEST          ,KC_BSPC    ,
        KC_F3         ,EAGLE_DISPLAY_LAYER_TOP ,EAGLE_MOVE      ,EAGLE_ROUTEWIRE ,EAGLE_RIPUP             ,EAGLE_TEXT ,
        EAGLE_ZOOMFIT ,KC_S                    ,EAGLE_POLYGON   ,EAGLE_VIA       ,EAGLE_HOLE              ,EAGLE_LINE ,
        KC_F4         ,EAGLE_DISPLAY_LAYER_BOT ,EAGLE_REDO      ,EAGLE_UNDO      ,KC_C                    ,KC_V       ,
        KC_LCTL       ,KC_LGUI                 ,MO(14)          ,KC_LALT         ,EAGLE_DISPLAY_LAYER_STD ,MO(5)
),
//
// Layer 3.1,
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
KEYMAP(
        KC_ESC, EAGLE_GRID_MM, EAGLE_GRID_MIL, EAGLE_GRID_INCH, EAGLE_GRID_MIC, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

//
// Layer 4
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
// Layer 4.1
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
// Layer 5
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
// Layer 5.1
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
        KC_TRNS, KC_TRNS, MO(14), KC_TRNS, KC_TRNS, MO(11)
),

//
// Layer 6.1
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
// Layer 7
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
// Layer 7.1
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EAGLE_UNDO:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_A);
                unregister_code(KC_A);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_REDO:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_B);
                unregister_code(KC_B);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_ZOOMFIT:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_F2);
                unregister_code(KC_F2);
                unregister_code(KC_LALT);
            }
            break;
        case EAGLE_MOVE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_M);
                unregister_code(KC_M);
                unregister_code(KC_LCTL);
            }
            break;
        case EAGLE_RIPUP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_R);
                unregister_code(KC_R);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_ROUTEWIRE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_1);
                unregister_code(KC_1);
                unregister_code(KC_LCTL);
            }
            break;
        case EAGLE_TEXT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_T);
                unregister_code(KC_T);
                unregister_code(KC_LCTL);
            }
            break;
        case EAGLE_GRID_MM:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F1);
                unregister_code(KC_F1);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_GRID_MIL:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F2);
                unregister_code(KC_F2);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_GRID_INCH:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F3);
                unregister_code(KC_F3);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_GRID_MIC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F4);
                unregister_code(KC_F4);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_DIMENSION:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F5);
                unregister_code(KC_F5);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_RATSNEST:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F6);
                unregister_code(KC_F6);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_DISPLAY_LAYER_TOP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F7);
                unregister_code(KC_F7);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_DISPLAY_LAYER_STD:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F8);
                unregister_code(KC_F8);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_DISPLAY_LAYER_BOT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F9);
                unregister_code(KC_F9);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_LAYER_TOP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F11);
                unregister_code(KC_F11);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_LAYER_BOT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_F12);
                unregister_code(KC_F12);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_VIA:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_V);
                unregister_code(KC_V);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_HOLE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_H);
                unregister_code(KC_H);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_LINE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_L);
                unregister_code(KC_L);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
        case EAGLE_POLYGON:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                register_code(KC_LALT);
                register_code(KC_P);
                unregister_code(KC_P);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
    }
    return true;
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