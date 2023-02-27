#include <stdio.h>
#include "modify.h"

int x = 1;
int y = 2;

int main()
{
    printf("x = %d | y = %d\n", x, y);
    
    modifX();
    printf("x = %d | y = %d\n", x, y);
    
    modifY();
    printf("x = %d | y = %d\n", x, y);

    return 0;
}


