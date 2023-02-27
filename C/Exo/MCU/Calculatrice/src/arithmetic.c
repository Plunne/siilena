#include "arithmetic.h"

double addition(double x, double y) {
    return x + y;
}

double soustraction(double x, double y) {
    return x - y;
}

double multiplication(double x, double y) {
    return x * y;
}

double division(double x, double y) {
    if(y) return x / y;
}

double sqr(double x) {
    return (double) x * x;
}