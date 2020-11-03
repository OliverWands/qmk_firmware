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
        case 1:
        case 2:
            digitToBin(1);
            break;
        case 3:
        case 4:
            digitToBin(2);
            break;
        case 5:
        case 6:
            digitToBin(3);
            break;
        case 7:
        case 8:
            digitToBin(4);
            break;
        case 9:
        case 10:
            digitToBin(5);
            break;
        case 11:
        case 12:
            digitToBin(6);
            break;
        case 13:
        case 14:
        case 0:
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