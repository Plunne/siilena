#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fichier = fopen("ASCII_Table.md", "w");

    if (!fichier) exit(1);

    fprintf(fichier, "| Char | DEC | HEX | Char | DEC | HEX | Char | DEC | HEX | Char | DEC | HEX |\n");
    fprintf(fichier, "|:----:|----:|-----:|:----:|----:|-----:|:----:|----:|-----:|:----:|----:|-----:|\n");
    
    for (unsigned int i=0; i < 32; i++) {
        fprintf(fichier, "| `%c` | %d  | 0x%X | `%c` | %d  | 0x%X | `%c` | %d  | 0x%X | `%c` | %d  | 0x%X |\n", i, i, i, i+32, i+32, i+32, i+64, i+64, i+64, i+96, i+96, i+96);
    }

    fclose(fichier);

    return 0;
}
