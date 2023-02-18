#include "morse_code.h"

char * charToMorse(char c) {

    switch (c)
    {
        case 'a': return MORSE_A;
        case 'b': return MORSE_B;
        case 'c': return MORSE_C;
        case 'd': return MORSE_D;
        case 'e': return MORSE_E;
        case 'f': return MORSE_F;
        case 'g': return MORSE_G;
        case 'h': return MORSE_H;
        case 'i': return MORSE_I;
        case 'j': return MORSE_J;
        case 'k': return MORSE_K;
        case 'l': return MORSE_L;
        case 'm': return MORSE_M;
        case 'n': return MORSE_N;
        case 'o': return MORSE_O;
        case 'p': return MORSE_P;
        case 'q': return MORSE_Q;
        case 'r': return MORSE_R;
        case 's': return MORSE_S;
        case 't': return MORSE_T;
        case 'u': return MORSE_U;
        case 'v': return MORSE_V;
        case 'w': return MORSE_W;
        case 'x': return MORSE_X;
        case 'y': return MORSE_Y;
        case 'z': return MORSE_Z;
    
        default: return "";
    }
}