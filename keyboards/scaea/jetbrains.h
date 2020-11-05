//
// Created by ow on 05.11.20.
//

#ifndef QMK_FIRMWARE_JETBRAINS_H
#define QMK_FIRMWARE_JETBRAINS_H

#include "send_string_keycodes.h"

enum jetbrains_keycodes {
    JETBRAINS_LINECOMMENT = SAFE_RANGE,
    JETBRAINS_BLOCKCOMMENT,
    JETBRAINS_DOCCOMMENT,
    JETBRAINS_LINUXC,
//    JETBRAINS_PRINT,
//    JETBRAINS_PRINTF,
//    JETBRAINS_PRINTLN
};

bool processJetbrainsMacro(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JETBRAINS_LINECOMMENT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_KP_SLASH);
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case JETBRAINS_BLOCKCOMMENT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_KP_SLASH);
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
        case JETBRAINS_DOCCOMMENT:
            if (record->event.pressed) {
                tap_code(KC_KP_SLASH);
                tap_code(KC_KP_SLASH);
                tap_code(KC_ENTER);
                tap_code(KC_KP_SLASH);
                tap_code(KC_KP_SLASH);
                tap_code(KC_ENTER);
                tap_code(KC_KP_SLASH);
                tap_code(KC_KP_SLASH);
                tap_code(KC_UP);
                tap_code(KC_SPC);
            }
            return false;
            break;
        case JETBRAINS_LINUXC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_F10);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
//        case JETBRAINS_PRINT:
//            if (record->event.pressed) {
//                SEND_STRING("System.out.print();");
//                tap_code(KC_LEFT);
//                tap_code(KC_LEFT);
//            }
//            return false;
//            break;
//        case JETBRAINS_PRINTF:
//            if (record->event.pressed) {
//                SEND_STRING('System.out.printf('');');
//                tap_code(KC_LEFT);
//                tap_code(KC_LEFT);
//                tap_code(KC_LEFT);
//            }
//            return false;
//            break;
//        case JETBRAINS_PRINTLN:
//            if (record->event.pressed) {
//                SEND_STRING("System.out.println();");
//                tap_code(KC_LEFT);
//                tap_code(KC_LEFT);
//            }
//            return false;
//            break;
        default:
            return true;
    }
}

#endif //QMK_FIRMWARE_JETBRAINS_H
