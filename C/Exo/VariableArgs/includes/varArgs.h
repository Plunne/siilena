#ifndef __VARARGS_H
#define __VARARGS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    char operator;
    double value;
}CalcStruct;

double evaluate_expression(int nb_args, ...);
double evaluate_struct(int nb_args, ...);

#endif // __VARARGS_H

