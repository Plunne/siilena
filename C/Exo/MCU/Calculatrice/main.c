#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "io.h"

int main()
{
    int x;

    printf("Tapez un nombre entier :\n");
    scanf("%d", &x);

    printResult(x);    

    exit(EXIT_SUCCESS);
}
