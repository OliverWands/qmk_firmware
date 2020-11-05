#ifndef SCAEA_H
#define SCAEA_H

#include "quantum.h"

#define LYR1        1
#define LYR11       2
#define LYR2        3
#define LYR21       4
#define JETBRAINS1  5
#define JETBRAINS2  6
#define LYR4        7
#define LYR41       8
#define LYR5        9
#define LYR51       10
#define LYR6        11
#define LYR61       12
#define EAGLEBRD1   13
#define EAGLEBRD2   14
#define HUB         0

#define KEYMAP(\
    K00, K01, K02, K03, K04, K05, \
    K10, K11, K12, K13, K14, K15, \
    K20, K21, K22, K23, K24, K25, \
    K30, K31, K32, K33, K34, K35, \
    K40, K41, K42, K43, K44, K45  \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05 }, \
    { K10,   K11,   K12,   K13,   K14,   K15 }, \
    { K20,   K21,   K22,   K23,   K24,   K25 }, \
    { K30,   K31,   K32,   K33,   K34,   K35 }, \
    { K40,   K41,   K42,   K43,   K44,   K45 }  \
}

#endif

void startSequence(void);

void setLayerIndication(uint8_t layer);

void digitToBin(uint8_t digit);