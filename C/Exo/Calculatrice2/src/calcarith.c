#include "calcarith.h"

extern double a;
extern double b;

double arithAddition(void) {

    puts("-- Addition --\n");
    insertNumbers();

    return addition(a, b);
}

double arithSoustraction(void) {
    
    puts("-- Soustraction --\n");
    insertNumbers();

    return soustraction(a, b);
}

double arithMultiplication(void) {

    puts("-- Multiplication --\n");
    insertNumbers();

    return multiplication(a, b);
}

double arithDivision(void) {

    puts("-- Division --\n");
    insertNumbers();

    return division(a, b);
}

double execSqr(void) {

    puts("-- Square --\n");
    insertNumbers();

    return sqr(a);
}
