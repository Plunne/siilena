#include <stdio.h>
#include <stdlib.h>

#include "io.h"

void printResult(long x) {

    FILE *f = fopen("output.txt", "w");

    fprintf(f, "\nLe carre de %d est %ld .\n", x, sqr(x));

    fclose(f);

}