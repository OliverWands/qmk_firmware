#include "scaea.h"
#include "eagle.h"

#include "timer.h"
#include "keymap_german.h"

#define LYR1 0
#define LYR11 1
#define LYR2 2
#define LYR21 3
#define LYR3 4
#define LYR31 5
#define LYR4 6
#define LYR41 7
#define LYR5 8
#define LYR51 9
#define LYR6 10
#define LYR61 11
#define EAGLE1 12
#define EAGLE2 13
#define HUB 14

uint8_t activeLayer = 0;
bool blink = false;
uint16_t blinkCount = 0;

const uint16_t PROGMEM
led[] =
LED_PINS;

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
[LYR1] = KEYMAP(
        KC_ESC  ,KC_1    ,KC_2     ,KC_3    ,KC_4   ,KC_5      ,
        KC_TAB  ,KC_Q    ,KC_W     ,KC_E    ,KC_R   ,KC_T      ,
        KC_CAPS ,KC_A    ,KC_S     ,KC_D    ,KC_F   ,KC_G      ,
        KC_LSFT ,DE_LABK ,DE_Y     ,KC_X    ,KC_C   ,KC_V      ,
        KC_LCTL ,KC_LGUI ,OSL(HUB) ,KC_LALT ,KC_SPC , MO(LYR11)
),

//
// Layer 1.1
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR11] = KEYMAP(
        RESET   ,KC_F2   ,KC_F4   ,KC_F5   ,KC_F11  ,KC_DEL  ,
        KC_TAB  ,KC_MPLY ,KC_MSTP ,KC_MPRV ,KC_MNXT ,KC_BSPC ,
        KC_CAPS ,KC_MUTE ,KC_UP   ,KC_MUTE ,KC_VOLU ,KC_ENT  ,
        KC_LSFT ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_VOLD ,KC_M    ,
        KC_LCTL ,KC_LGUI ,KC_LALT ,KC_SPC  ,KC_SPC  ,KC_TRNS
),

//
// Layer 2
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR2] = KEYMAP(
        KC_ESC  ,KC_F9   ,KC_F10   ,KC_F11  ,KC_F12 ,KC_DEL    ,
        KC_TAB  ,KC_MPLY ,KC_MSTP  ,KC_7    ,KC_8   ,KC_9      ,
        KC_CAPS ,KC_MUTE ,KC_UP    ,KC_4    ,KC_5   ,KC_6      ,
        KC_LSFT ,KC_LEFT ,KC_DOWN  ,KC_1    ,KC_2   ,KC_3      ,
        KC_LCTL ,KC_LGUI ,OSL(HUB) ,KC_LALT ,KC_SPC ,MO(LYR21)
),

//
// Layer 2.1
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR21] = KEYMAP(
        RESET   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
),



//
// Layer 4
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR3] = KEYMAP(
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,OSL(HUB) ,KC_TRNS ,KC_TRNS ,MO(LYR31)
),

//
// Layer 4.1
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR31] = KEYMAP(
        RESET   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
),

//
// Layer 5
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR4] = KEYMAP(
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,OSL(HUB) ,KC_TRNS ,KC_TRNS ,MO(LYR41)
),

//
// Layer 5.1
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR41] = KEYMAP(
        RESET   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
),

//
// Layer 6
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR5] = KEYMAP(
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,OSL(HUB) ,KC_TRNS ,KC_TRNS ,MO(LYR51)
),

//
// Layer 6.1
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR51] = KEYMAP(
        RESET   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
),

//
// Layer 7
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR6] = KEYMAP(
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,KC_TRNS  ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,
        KC_TRNS ,KC_TRNS ,OSL(HUB) ,KC_TRNS ,KC_TRNS ,MO(LYR61)
),

//
// Layer 7.1
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[LYR61] = KEYMAP(
        RESET   ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,
        KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
),

//
// Layer 3 | Eagle Board layer
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[EAGLE1] = KEYMAP(
        KC_ESC        ,EAGLE_LAYER_TOP         ,EAGLE_LAYER_BOT ,EAGLE_DIMENSION ,EAGLE_RATSNEST ,KC_BSPC         ,
        KC_F3         ,EAGLE_DISPLAY_LAYER_TOP ,EAGLE_UNDO      ,EAGLE_MOVE      ,EAGLE_HOLE     ,EAGLE_RIPUP     ,
        EAGLE_ZOOMFIT ,EAGLE_DISPLAY_LAYER_STD ,KC_S            ,EAGLE_POLYGON   ,EAGLE_VIA      ,EAGLE_ROUTEWIRE ,
        KC_F4         ,EAGLE_DISPLAY_LAYER_BOT ,EAGLE_REDO      ,EAGLE_LINE      ,KC_C           ,KC_V            ,
        KC_LCTL       ,KC_LGUI                 ,OSL(HUB)          ,KC_LALT       ,EAGLE_TEXT     ,MO(EAGLE2)
),
//
// Layer 3.1,
// | ESC   | 1   | 2   | 3     | 4   | 5   |
// | TAB   | Q   | W   | E     | R   | T   |
// | CAPS  | A   | S   | D     | F   | G   |
// | SHIFT | <   | Y   | X     | C   | V   |
// | CTRL  | WIN | ALT | SPACE | FN1 | FN2 |
//
[EAGLE2] = KEYMAP(
        KC_ESC  ,EAGLE_GRID_MM ,EAGLE_GRID_MIL ,EAGLE_GRID_INCH ,EAGLE_GRID_MIC ,KC_DEL  ,
        KC_TRNS ,KC_TRNS       ,KC_TRNS        ,KC_TRNS         ,KC_TRNS        ,KC_TRNS ,
        KC_TRNS ,KC_TRNS       ,KC_TRNS        ,KC_TRNS         ,KC_TRNS        ,KC_TRNS ,
        KC_TRNS ,KC_TRNS       ,KC_TRNS        ,KC_TRNS         ,KC_TRNS        ,KC_TRNS ,
        KC_TRNS ,KC_TRNS       ,KC_TRNS        ,KC_TRNS         ,KC_TRNS        ,KC_TRNS
),

[HUB] = KEYMAP(
        RESET ,TO(LYR1) ,TO(LYR2)   ,TO(LYR3) ,TO(LYR4) ,TO(LYR5) ,
        KC_NO ,TO(LYR6) ,TO(EAGLE1) ,KC_NO    ,KC_NO    ,KC_NO    ,
        KC_NO ,KC_NO    ,KC_NO      ,KC_NO    ,KC_NO    ,KC_NO    ,
        KC_NO ,KC_TRNS  ,KC_TRNS    ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
        KC_NO ,KC_NO    ,KC_NO      ,KC_NO    ,KC_NO    ,KC_NO
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    processEagleMacro(keycode, record);
    return true;
}

void matrix_init_user(void) {
    startSequence();
}

void matrix_scan_user(void) {
    if (((activeLayer % 2) != 0) || activeLayer == HUB)
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
