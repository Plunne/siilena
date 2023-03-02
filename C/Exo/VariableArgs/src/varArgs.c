#include "varArgs.h"

double evaluate_expression(int nb_args, ...) {
    
    va_list arg_ptr;

    va_start(arg_ptr, nb_args);

    double result = 0.0;
    double divCtrl = 1;

    for (int i = 0; i < nb_args/2; i++) {
        
        switch (va_arg(arg_ptr, char)) {

            case '+':
                    result += va_arg(arg_ptr, double);
                    break;
            case '-':
                    result -= va_arg(arg_ptr, double);
                    break;
            case '*':
                    result *= va_arg(arg_ptr, double);
                    break;
            case '/':
                    divCtrl = va_arg(arg_ptr, double);
                    if(divCtrl) result /= divCtrl;
                    else {
                        puts("NULL DIV ERROR!");
                        return 0;
                    }
                    break;
            default:
                    puts("ERROR");
                    return 0;
                    break;
        }
    }
    va_end(arg_ptr);

    return result;
}

double evaluate_struct(int nb_args, ...) {
    
    va_list arg_ptr;

    va_start(arg_ptr, nb_args);

    double result = 0.0;

    for (int i = 0; i < nb_args; i++) {
        
        CalcStruct calcOp = va_arg(arg_ptr, CalcStruct);

        switch (calcOp.operator) {
            case '+':
                    result += calcOp.value;
                    break;
            case '-':
                    result -= calcOp.value;
                    break;
            case '*':
                    result *= calcOp.value;
                    break;
            case '/':
                    if (calcOp.value) result /= calcOp.value;
                    else {
                        puts("NULL DIV ERROR!");
                        return 0;
                    }
                    break;

            default:
                puts("OPERATOR ERROR!");
                return 0;
                break;
        }
    }
    va_end(arg_ptr);

    return result;
}