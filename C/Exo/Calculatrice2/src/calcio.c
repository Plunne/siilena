#include "calcio.h"

void printResult(double x) {
    printf("\nResultat : %lf\n", x);
}


void runCalculator() {

    char operator = '+';

    printf("\n***** CALCULATOR *****\n\n");
    printf("Select operator (default : +) :\n");
    scanf("%c", &operator);

    switch (operator) {
        case '+':
            printResult(addition(x, y));
            break;
        case '-':
            printResult(soustraction(x, y));
            break;
        case '*':
            printResult(multiplication(x, y));
            break;
        case '/':
            printResult(division(x, y));
            break;

        default: break;
    }

    printf("%lf %c %lf\n", x, operator, y);

}