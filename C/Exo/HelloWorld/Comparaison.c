#include <stdio.h>

int main() {

    int a = 3;
    int b = 2;
    int c = 4;
    int d = 6;

    if ((c < d) && ((a < b) || (a < c))) printf("VRAI\n");
    else printf("FAUX\n");

    return 0;
}