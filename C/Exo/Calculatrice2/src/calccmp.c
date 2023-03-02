#include "calccmp.h"

double compSuperior(void) {
    
    puts("-- Superior --\n");
    insertNumbers();
    
    if (a > b) return 1;
    else return 0;
}

double compInferior(void) {

    puts("-- Inferior --\n");
    insertNumbers();
    
    if (a < b) return (double)1;
    else return (double)0;
}