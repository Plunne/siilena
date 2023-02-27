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

    char test = 0xFF;
    printf("%x\n", test);

    test &= ~((1 << 4) | (1 << 0));
    printf("%x\n", test);

    return 0;
}
