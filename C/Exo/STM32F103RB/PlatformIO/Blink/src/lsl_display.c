#include "lsl_display.h"

unsigned char LSL_DISPLAY_Get7Seg(unsigned char number) {

    switch(number)
    {
        case 0: return 0b0111111;
        case 1: return 0b0000110;
        case 2: return 0b1011011;
        case 3: return 0b1001111;
        case 4: return 0b1100110;
        case 5: return 0b1101101;
        case 6: return 0b1111101;
        case 7: return 0b0000111;
        case 8: return 0b1111111;
        case 9: return 0b1101111;
        default: return 0b1000000;
    }
}

void LSL_DISPLAY_Display7Seg(LSL_Pinout *diode, unsigned char number, enum DiodeCOM common) {

    if (common == anode) LSL_DISPLAY_Display7SegAnodeCathode(diode, number, HIGH, LOW);
    else if (common == cathode) LSL_DISPLAY_Display7SegAnodeCathode(diode, number, LOW, HIGH);

}

void LSL_DISPLAY_Display7SegAnodeCathode(LSL_Pinout *diode, unsigned char number, enum PINOUT_STATE stateA, enum PINOUT_STATE stateB) {

    unsigned char segment = LSL_DISPLAY_Get7Seg(number);

    for (int i=0; i < DIODE_NB; i++) {

        LSL_PINOUTS_Write(&diode[i], stateA);
        if (segment & (1 << i)) {
            LSL_PINOUTS_Write(&diode[i], stateB);
        } else {
            LSL_PINOUTS_Write(&diode[i], stateA);
        }
    }
}