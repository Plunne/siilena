#include "calcio.h"

void runCalculator() {

    char operator = '+';
    double (*result)(void);

    printf("\n***** CALCULATOR *****\n\n");
    printf("Select operator (default : +) :\n");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = &execAddition;
            break;
        case '-':
            result = &execSoustraction;
            break;
        case '*':
            result = &execMultiplication;
            break;
        case '/':
            result = &execDivision;
            break;

        default: break;
    }

    printf("%lf %c %lf = %lf\n", a, operator, b, result());

}