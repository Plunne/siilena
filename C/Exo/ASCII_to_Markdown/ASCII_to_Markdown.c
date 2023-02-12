#include <stdio.h>
#include <stdlib.h>

#define HEIGHT  32
#define WIDTH   4

void fillTableASCII(unsigned char *ascii);
void getLineTableASCII(unsigned char *ascii, char line);
unsigned char getCellTableASCII(unsigned char *ascii, char line, char column);
void asciiToMarkdown(FILE *f, char *ascii);

int main(int argc, char const *argv[])
{
    /* Init ASCII Table */
    unsigned char tableASCII[HEIGHT][WIDTH];

    /* Fill ASCII Table */
    fillTableASCII(tableASCII);
    
    /* Init Output File */
    FILE *outfile = fopen("ASCII_Table.md", "w");

    /* If not output file, exit program */
    if (!outfile) exit(1);

    /* ASCII Table Markdown header */
    fputs("| Char | DEC | HEX | Char | DEC | HEX | Char | DEC | HEX | Char | DEC | HEX |\n", outfile);
    fputs("|:----:|----:|----:|:----:|----:|----:|:----:|----:|----:|:----:|----:|----:|\n", outfile);

    /* ASCII to Markdown Generator */
    asciiToMarkdown(outfile, tableASCII);

    fclose(outfile);

    return 0;
}

void fillTableASCII(unsigned char *ascii)
{
    for (char line=0; line < HEIGHT; line++) getLineTableASCII(ascii, line);
}

void getLineTableASCII(unsigned char *ascii, char line)
{
    for (char column=0; column < WIDTH; column++) ascii[HEIGHT * column + line] = HEIGHT * column + line;
}

unsigned char getCellTableASCII(unsigned char *ascii, char line, char column)
{
    return ascii[HEIGHT * column + line];
}

void asciiToMarkdown(FILE *f, char *ascii) {
       
    for (unsigned char i=0; i < HEIGHT; i++)
    {
        // New line
        fputc('|', f);
        // For each column       
        for (unsigned char j=0; j < WIDTH; j++)
        {
            fprintf(f, " `%c` |", getCellTableASCII(ascii, i, j));
            fprintf(f, " %d |", getCellTableASCII(ascii, i, j));
            fprintf(f, " 0x%X |", getCellTableASCII(ascii, i, j));
        }
        fputc('\n', f);
    }
}