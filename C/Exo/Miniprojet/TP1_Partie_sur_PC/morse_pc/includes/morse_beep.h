#ifndef _MORSE_BEEP_H
#define _MORSE_BEEP_H

#include "morse_audio.h"

#define MORSE_DOT   '.'
#define MORSE_LONG  '_'
#define MORSE_DEAD  '/'

void morseToBeep(char beep);
void beepMorse(char * m);

#endif // _MORSE_BEEP_H