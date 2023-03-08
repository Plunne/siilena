#include "lsl_display.h"

/* 7 Segments */
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

    if (common == anode) LSL_DISPLAY_Display7SegAnodeCathode(diode, number, HIGH, LOW);         // If display has Common Anode
    else if (common == cathode) LSL_DISPLAY_Display7SegAnodeCathode(diode, number, LOW, HIGH);  // If display has Common Cathode

}

void LSL_DISPLAY_Display7SegAnodeCathode(LSL_Pinout *diode, unsigned char number, enum PINOUT_STATE stateA, enum PINOUT_STATE stateB) {

    unsigned char segment = LSL_DISPLAY_Get7Seg(number); // Translate number to bits pattern

    for (int i=0; i < DIODE_NB; i++) { // For each diode

        LSL_PINOUTS_Write(&diode[i], stateA);       // LED i OFF
        if (segment & (1 << i)) {                   // Check if at bit i, Pattern bit is HIGH
            LSL_PINOUTS_Write(&diode[i], stateB);   // If pattern bit is HIGH, LED i ON
        } else {                                    // Else pattern dosen't match HIGH for LED
            LSL_PINOUTS_Write(&diode[i], stateA);   // LED i OFF
        }
    }
}