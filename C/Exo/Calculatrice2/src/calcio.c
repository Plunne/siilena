#include "calcio.h"

void runCalculator() {

    char operator = '+';
    double (*result)(void);

    printf("\n***** CALCULATOR *****\n\n");
    printf("Select operator (default : +) :\n");
    scanf(" %c", &operator);

    switch (operator) {
        
        // Quit if operator is 'q'
        case 'q': exit(0);
        
        case '+':
            result = &arithAddition;
            break;
        case '-':
            result = &arithSoustraction;
            break;
        case '*':
            result = &arithMultiplication;
            break;
        case '/':
            result = &arithDivision;
            break;
        case '>':
            result = &compSuperior;
            break;
        case '<':
            result = &compInferior;
            break;

        default: break;
    }

    printf("%lf %c %lf = %lf\n", a, operator, b, result());

}