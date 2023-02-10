#include <stdio.h>

#define PATTERN	2
#define HEIGHT	5
#define WIDTH	3

#define CHAR0	'_'
#define CHAR1	'*'

char data2D[HEIGHT][WIDTH] = {
	{ 0, 0, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 1 }
};
char data2DTmp[HEIGHT][WIDTH] = {
	{ 1, 0, 0 },
	{ 1, 0, 0 },
	{ 1, 0, 1 },
	{ 0, 0, 1 },
	{ 0, 0, 1 }
};

char data3D[PATTERN][HEIGHT][WIDTH] = {
	{
		{ 0, 0, 1 },
		{ 0, 0, 1 },
		{ 0, 0, 1 },
		{ 0, 0, 1 },
		{ 0, 0, 1 }
	},
	{
		{ 1, 0, 0 },
		{ 1, 0, 0 },
		{ 1, 0, 1 },
		{ 0, 0, 1 },
		{ 0, 0, 1 }
	}
};
char bus[WIDTH + 1] = { '*', '*', '*','\0' };

void dataToBus(char* data);
char* getAdresseRowFromData2D(int row);
char* getAdresseRowFromPatternAdresse(int row, char* pattern);
char* getAdresseRowFromPatternAdresse3D(int row, int idx_pattern);
void displayData2D();
void displayPattern2D(char* pattern);
void displayPattern3D(int idx_pattern);

int main() {
	//displayData2D();
	//displayPattern2D(data2DTmp);
	displayPattern3D(1);
	return 0;
}

void displayData2D() {
	for (int i = 0; i < HEIGHT; i++)
	{
		dataToBus(getAdresseRowFromData2D(i));
		puts(bus);
	}
}

void displayPattern2D(char *pattern) {
	for (int i = 0; i < HEIGHT; i++)
	{
		dataToBus(getAdresseRowFromPatternAdresse(i, pattern));
		puts(bus);
	}
}

void displayPattern3D(int idx_pattern) {
	for (int i = 0; i < HEIGHT; i++)
	{
		dataToBus(getAdresseRowFromPatternAdresse3D(i, idx_pattern));
		puts(bus);
	}
}

void dataToBus(char* data) {
	for (int i = 0; i < WIDTH; i++) {
		bus[i] = (!data[i]) ? CHAR0 : CHAR1;
	}
}

char* getAdresseRowFromData2D(int row) {
	return &data2D[row];
}

char* getAdresseRowFromPatternAdresse(int row, char* pattern) {
	return &pattern[row * WIDTH];
}

char* getAdresseRowFromPatternAdresse3D(int row, int idx_pattern) {
	return &data3D[row * WIDTH * (HEIGHT * idx_pattern)];
}
