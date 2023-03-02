#include <stdio.h>
#include <stdlib.h>

#include "varArgs.h"

int main(void) {

    CalcStruct op1 = {'+', 135.5 };
    CalcStruct op2 = {'-', 20.3 };
    CalcStruct op3 = {'-', 15.2 };
    CalcStruct op4 = {'/', 2 };
    CalcStruct op5 = {'*', 4 };

    printf("Result : %lf\n", evaluate_expression(4, '+', 3.5, '/', 2));
    printf("Result struct : %lf\n", evaluate_struct(5, op1, op2, op3, op4, op5));

	return 0;
}
