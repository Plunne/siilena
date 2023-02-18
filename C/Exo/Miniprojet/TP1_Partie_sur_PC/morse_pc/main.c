/* C library headers */
#include <stdio.h> // pour les entrées/sorties
#include <stdlib.h> // bibliotheque standard
#include <string.h> // pour les chaines de caracteres

#include "morselib.h"

int main(int argc, char **argv) {

    printf("%c\n", charToMorse('v')[3]);
    
    return 0;
}