#ifndef _MORSE_AUDIO_H
#define _MORSE_AUDIO_H

#define TIMER1  10
#define TIMER2  50
#define TIMER3  100

int timers[3] = { TIMER1, TIMER2, TIMER3 };

void beepAudio(int t);

#endif // _MORSE_AUDIO_H