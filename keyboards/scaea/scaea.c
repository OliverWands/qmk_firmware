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

void setLayerIndication(uint8_t layer) {
    switch (layer) {
        case LYR1:
        case LYR11:
            digitToBin(1);
            break;
        case LYR2:
        case LYR21:
            digitToBin(2);
            break;
        case LYR3:
        case LYR31:
            digitToBin(3);
            break;
        case LYR4:
        case LYR41:
            digitToBin(4);
            break;
        case LYR5:
        case LYR51:
            digitToBin(5);
            break;
        case LYR6:
        case LYR61:
            digitToBin(6);
            break;
        case EAGLE1:
        case EAGLE2:
        case HUB:
            digitToBin(7);
            break;
    }
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