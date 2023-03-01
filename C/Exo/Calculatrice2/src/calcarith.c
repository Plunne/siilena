#include "calcarith.h"

void insertNumbers(void) {
    
    /* A */
    puts("Saisir a : \n");
    scanf("%lf", &a);

    /* B */
    puts("Saisir b : \n");
    scanf("%lf", &b);

}

double execAddition(void) {

    puts("-- Addition --\n");
    insertNumbers();

    return addition(a, b);
}

double execSoustraction(void) {
    
    puts("-- Soustraction --\n");
    insertNumbers();

    return soustraction(a, b);
}

double execMultiplication(void) {

    puts("-- Multiplication --\n");
    insertNumbers();

    return multiplication(a, b);
}

double execDivision(void) {

    puts("-- Division --\n");
    insertNumbers();

    return division(a, b);
}

double execSqr(void) {

    puts("-- Square --\n");
    insertNumbers();

    return sqr(a);
}


int compSuperior(int *a, int *b) {
    if (*a == *b) return 0;
    if (*a > *b) return *a;
    else return *b;
}

int compInferior(int *a, int *b) {
    if (*a == *b) return 0;
    if (*a < *b) return *a;
    else return *b;
}