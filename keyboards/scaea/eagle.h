//
// Created by ow on 03.11.20.
//

#ifndef QMK_FIRMWARE_EAGLEMACROS_H
#define QMK_FIRMWARE_EAGLEMACROS_H

enum eagle_keycodes {
    EAGLE_UNDO = SAFE_RANGE,
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

bool processEagleMacro(uint16_t keycode, keyrecord_t *record)
{
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
            return false;
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
            return false;
            break;
        case EAGLE_ZOOMFIT:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_F2);
                unregister_code(KC_F2);
                unregister_code(KC_LALT);
            }
            return false;
            break;
        case EAGLE_MOVE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_M);
                unregister_code(KC_M);
                unregister_code(KC_LCTL);
            }
            return false;
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
            return false;
            break;
        case EAGLE_ROUTEWIRE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_1);
                unregister_code(KC_1);
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case EAGLE_TEXT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_T);
                unregister_code(KC_T);
                unregister_code(KC_LCTL);
            }
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
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
            return false;
            break;
        default:
            return true;
    }
}

#endif //QMK_FIRMWARE_EAGLEMACROS_H
