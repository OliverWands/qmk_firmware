#include "scaea.h"

void startSequence(void) {
    setPinOutput(L1);
    setPinOutput(L2);
    setPinOutput(L3);

    for (int inx = 0; inx < 7; inx++) {
        writePinHigh(L1);
        wait_us(50000);
        writePinLow(L1);
        writePinHigh(L2);
        wait_us(50000);
        writePinLow(L2);
        writePinHigh(L3);
        wait_us(50000);
        writePinLow(L3);
    }

    writePinLow(L1);
    writePinLow(L2);
    writePinLow(L3);
}

layer_state_t setLayerIndication(layer_state_t state, bool binaryOut) {
    uint8_t layer = get_highest_layer(state);
    if (binaryOut) {
        digitToBin(layer);
    } else {
        switch (layer) {
            case 0:
            case 1:
                digitToBin(1);
                break;
            case 2:
            case 3:
                digitToBin(2);
                break;
            case 4:
            case 5:
                digitToBin(3);
                break;
            case 6:
            case 7:
                digitToBin(4);
                break;
            case 8:
            case 9:
                digitToBin(5);
                break;
            case 10:
            case 11:
                digitToBin(6);
                break;
            case 12:
            case 13:
                digitToBin(7);
                break;
            case 14:
            default:
                digitToBin(0);
                break;
        }
    }
    return state;
}

void digitToBin(uint8_t digit) {
    bool vals[3];
    for (uint8_t jnx = 0; jnx < 3; jnx++) {
        uint8_t mask = 0b0001 << jnx;
        vals[jnx] = (digit & mask) != 0;
    }

    writePin(L1, vals[0]);
    writePin(L2, vals[1]);
    writePin(L3, vals[2]);
}