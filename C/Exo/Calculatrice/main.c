#include <stdio.h>
#include <stdlib.h>

#include "calcio.h"
#include "arithmetic.h"

int main(int argc, char const *argv[])
{

    if (argc == 4) {

        double x = atof(argv[1]);
        double y = atof(argv[3]);

        char operator = argv[2][0];
        printf("%lf %c %lf\n", x, operator, y);
        
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
    }
    
    return 0;
}