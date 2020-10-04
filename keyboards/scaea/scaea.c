#include "scaea.h"

void startSequence(void) {
    setPinOutput(L1);
	setPinOutput(L2);
	setPinOutput(L3);

    for (int inx = 0; inx < 7; inx++)
	{
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

	// writePinHigh(L1);
	// wait_us(150000);
	// writePinLow(L1);
	// writePinHigh(L2);
	// wait_us(150000);
	// writePinLow(L2);
	// writePinHigh(L3);
	// wait_us(150000);
	// writePinLow(L3);

	// writePinHigh(L1);
	// wait_us(125000);
	// writePinLow(L1);
	// writePinHigh(L2);
	// wait_us(125000);
	// writePinLow(L2);
	// writePinHigh(L3);
	// wait_us(125000);
	// writePinLow(L3);

	// writePinHigh(L1);
	// wait_us(100000);
	// writePinLow(L1);
	// writePinHigh(L2);
	// wait_us(100000);
	// writePinLow(L2);
	// writePinHigh(L3);
	// wait_us(100000);
	// writePinLow(L3);

	// writePinHigh(L1);
	// wait_us(75000);
	// writePinLow(L1);
	// writePinHigh(L2);
	// wait_us(75000);
	// writePinLow(L2);
	// writePinHigh(L3);
	// wait_us(75000);
	// writePinLow(L3);

	// for (int inx = 0; inx < 5; inx++)
	// {
	// 	writePinHigh(L1);
	// 	wait_us(50000);
	// 	writePinLow(L1);
	// 	writePinHigh(L2);
	// 	wait_us(50000);
	// 	writePinLow(L2);
	// 	writePinHigh(L3);
	// 	wait_us(50000);
	// 	writePinLow(L3);
	// }

	// for (int inx = 0; inx < 10; inx++)
	// {
	// 	writePinHigh(L1);
	// 	wait_us(25000);
	// 	writePinLow(L1);
	// 	writePinHigh(L2);
	// 	wait_us(25000);
	// 	writePinLow(L2);
	// 	writePinHigh(L3);
	// 	wait_us(25000);
	// 	writePinLow(L3);
	// }

	// for (int inx = 0; inx < 15; inx++)
	// {
	// 	writePinHigh(L1);
	// 	wait_us(12500);
	// 	writePinLow(L1);
	// 	writePinHigh(L2);
	// 	wait_us(12500);
	// 	writePinLow(L2);
	// 	writePinHigh(L3);
	// 	wait_us(12500);
	// 	writePinLow(L3);
	// }

	// for (int inx = 0; inx < 20; inx++)
	// {
	// 	writePinHigh(L1);
	// 	wait_us(6250);
	// 	writePinLow(L1);
	// 	writePinHigh(L2);
	// 	wait_us(6250);
	// 	writePinLow(L2);
	// 	writePinHigh(L3);
	// 	wait_us(6250);
	// 	writePinLow(L3);
	// }

	writePinLow(L1);
  	writePinLow(L2);
  	writePinLow(L3);
}

layer_state_t setLayerIndication(layer_state_t state, bool binaryOut) {
    uint8_t layer = get_highest_layer(state);
    if (binaryOut) {
        switch (layer) {
            case 0:
                writePinLow(L1);
                writePinLow(L2);
                writePinLow(L3);
                break;
            case 1:
                writePinHigh(L1);
                writePinLow(L2);
                writePinLow(L3);
                break;
            case 2:
                writePinLow(L1);
                writePinHigh(L2);
                writePinLow(L3);
                break;
            case 3:
                writePinHigh(L1);
                writePinHigh(L2);
                writePinLow(L3);
                break;
            case 4:
                writePinHigh(L1);
                writePinHigh(L2);
                writePinLow(L3);
                break;
            case 5:
                writePinLow(L1);
                writePinLow(L2);
                writePinHigh(L3);
                break;
            case 6:
                writePinHigh(L1);
                writePinLow(L2);
                writePinHigh(L3);
                break;
            case 7:
                writePinLow(L1);
                writePinHigh(L2);
                writePinHigh(L3);
                break;
            case 8:
                writePinHigh(L1);
                writePinHigh(L2);
                writePinHigh(L3);
                break;
            default:
                writePinLow(L1);
                writePinLow(L2);
                writePinLow(L3);
                break;
        }
    } else {
        switch (layer) {
            case 0:
                writePinHigh(L1);
                writePinLow(L2);
                writePinLow(L3);
                break;
            case 1:
                writePinLow(L1);
                writePinHigh(L2);
                writePinLow(L3);
                break;
            case 2:
                writePinLow(L1);
                writePinLow(L2);
                writePinHigh(L3);
                break;
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            default:
                writePinLow(L1);
                writePinLow(L2);
                writePinLow(L3);
                break;
        }
    }
    return state;
}