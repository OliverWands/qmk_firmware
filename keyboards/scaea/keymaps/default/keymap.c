#include "scaea.h"
#include "eagle.h"
#include "jetbrains.h"
#include "timer.h"
#include "keymap_german.h"

uint8_t activeLayer = 0;
bool blink = false;
uint16_t blinkCount = 0;

const uint16_t PROGMEM
led[] =
LED_PINS;

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
[LYR1] =
KEYMAP(
        KC_ESC, DE_1, DE_2, DE_3, DE_4, DE_5,
        KC_TAB, DE_Q, DE_W, DE_E, DE_R, DE_T,
        KC_CAPS, DE_A, DE_S, DE_D, DE_F, DE_G,
        KC_LSFT, DE_LABK, DE_Y, DE_X, DE_C, DE_V,
        KC_LCTL, KC_LGUI, TO(HUB), KC_LALT, KC_SPC, MO(LYR11)
),
[LYR11] =
KEYMAP(
        KC_ESC, KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_DEL,
        KC_TAB, KC_TRNS, KC_UP, KC_TRNS, KC_VOLU, KC_BSPC,
        KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_MUTE, KC_ENT,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, DE_M,
        KC_LCTL, KC_LGUI, KC_TRNS, KC_LALT, KC_SPC, KC_TRNS
),
[LYR2] =
KEYMAP(
        RESET, KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_NLCK,
        KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PMNS,
        KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PPLS,
        KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_TRNS, KC_TRNS, TO(HUB), KC_P0, KC_PDOT, MO(LYR21)
),
[LYR21] =
KEYMAP(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
        KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LGUI, KC_TRNS, KC_LALT, KC_SPC, KC_TRNS
),
[JETBRAINS1] =
KEYMAP(
        KC_TRNS, JETBRAINS_LINECOMMENT, JETBRAINS_DOCCOMMENT, JETBRAINS_BLOCKCOMMENT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, JETBRAINS_LINUXC, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, TO(HUB), KC_TRNS, KC_TRNS, MO(JETBRAINS2)
),
[JETBRAINS2] =
KEYMAP(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
        KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LGUI, KC_TRNS, KC_LALT, KC_SPC, KC_TRNS
),
[LYR4] =
KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, TO(HUB), KC_TRNS, KC_TRNS, MO(LYR41)
),
[LYR41] =
KEYMAP(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
        KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LGUI, KC_TRNS, KC_LALT, KC_SPC, KC_TRNS
),
[LYR5] =
KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, TO(HUB), KC_TRNS, KC_TRNS, MO(LYR51)
),
[LYR51] =
KEYMAP(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
        KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LGUI, KC_TRNS, KC_LALT, KC_SPC, KC_TRNS
),
[LYR6] =
KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, TO(HUB), KC_TRNS, KC_TRNS, MO(LYR61)
),
[LYR61] =
KEYMAP(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,
        KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LGUI, KC_TRNS, KC_LALT, KC_SPC, KC_TRNS
),
[EAGLEBRD1] =
KEYMAP(
        KC_ESC, EAGLE_LAYER_TOP, EAGLE_LAYER_BOT, EAGLE_GRID_MM, EAGLE_GRID_MIL, KC_BSPC,
        KC_F3, EAGLE_DISPLAY_LAYER_TOP, EAGLE_UNDO, EAGLE_MOVE, EAGLE_RIPUP, EAGLE_HOLE,
        EAGLE_ZOOMFIT, EAGLE_DISPLAY_LAYER_STD, KC_S, EAGLE_POLYGON, EAGLE_VIA, EAGLE_ROUTEWIRE,
        KC_F4, EAGLE_DISPLAY_LAYER_BOT, EAGLE_REDO, EAGLE_LINE, KC_C, KC_V,
        KC_LCTL, KC_LGUI, TO(HUB), KC_LALT, KC_TRNS, MO(EAGLEBRD2)),
[EAGLEBRD2] =
KEYMAP(
        KC_ESC, EAGLE_DIMENSION, EAGLE_RATSNEST, EAGLE_GRID_MIC, EAGLE_GRID_INCH, KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EAGLE_RIPUP_GND, EAGLE_TEXT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[HUB] =
KEYMAP(
        RESET, TO(LYR1), TO(LYR2), TO(JETBRAINS1), TO(LYR4), TO(LYR5),
        KC_F11, TO(LYR6), TO(EAGLEBRD1), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return processEagleMacro(keycode, record) ||
           processJetbrainsMacro(keycode, record);
}

void matrix_init_user(void) {
    startSequence();
    layer_on(LYR1);
}

void matrix_scan_user(void) {
    if (((activeLayer % 2) == (HUB % 2)) || activeLayer == HUB) {
        blinkCount %= 1024;
        if (blinkCount == 1023) {
            blink = !blink;
        }
        if (blink) {
            setLayerIndication(activeLayer);
        } else {
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
