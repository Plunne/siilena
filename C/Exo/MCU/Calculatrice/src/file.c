#include <stdio.h>
#include <stdlib.h>

#include "io.h"

void printResult(long x) {

    FILE *f = fopen("output.txt", "w");

    if(!f) return;

    fprintf(f, "\nResultat : %d .\n", x);

    fclose(f);

}