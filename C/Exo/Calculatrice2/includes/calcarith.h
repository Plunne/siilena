#ifndef _CALCARITH_H
#define _CALCARITH_H

#include <stdio.h>

#include "calcope.h"

static double a = 0;
static double b = 0;

void insertNumbers(void);

double execAddition(void);
double execSoustraction(void);
double execMultiplication(void);
double execDivision(void);

double execSqr(void);

int compSuperior(int *a, int *b);
int compInferior(int *a, int *b);


#endif // _CALCARITH_H