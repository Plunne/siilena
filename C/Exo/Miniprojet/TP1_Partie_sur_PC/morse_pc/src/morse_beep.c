#include "morse_beep.h"

void morseToBeep(char beep) {

    switch (beep)
    {
    case '.':
        beepAudio(timers[0]);
        break;
    
    default:
        break;
    }

}


void beepMorse(char * m) {

}