#include <stdio.h>
#include <stdlib.h>

#define HEIGHT  16
#define WIDTH   8

void fillTableASCII(unsigned char *ascii);
void getLineTableASCII(unsigned char *ascii, char line);
unsigned char getCellTableASCII(unsigned char *ascii, char line, char column);
void asciiTableHeader(FILE *f);
void asciiToMarkdown(FILE *f, char *ascii);

int main(int argc, char const *argv[])
{
    /* Init ASCII Table */
    unsigned char tableASCII[HEIGHT][WIDTH];

    /* Fill ASCII Table */
    fillTableASCII(tableASCII);
    
    /* Init Output File */
    FILE *outfile = fopen("ASCII_Table2.md", "w");

    /* If not output file, exit program */
    if (!outfile) exit(1);

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

void asciiTableHeader(FILE *f) {

    fputc('|', f);
    for (unsigned char i=0; i < WIDTH; i++) fputs(" Char | DEC | HEX |", f);
    fputc('\n', f);
    
    fputc('|', f);
    for (unsigned char i=0; i < WIDTH; i++) fputs(":----:|----:|----:|", f);
    fputc('\n', f);
}

void asciiToMarkdown(FILE *f, char *ascii) {

    // ASCII Table Markdown Header
    asciiTableHeader(f);

    // ASCII Table Generation
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