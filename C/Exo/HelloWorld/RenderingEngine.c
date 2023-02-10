#include <stdio.h>

#define WIDTH 3
#define HEIGHT 5
char patternOne[HEIGHT][WIDTH] = { { 0, 0, 1 }, { 0, 1, 1 }, { 1, 0, 1 } ,{ 0, 0, 1 }, { 0, 0, 1 }};
char patternTwo[HEIGHT][WIDTH] = { { 1, 1, 1 }, { 0, 0, 1 }, { 0, 1, 0 } ,{ 1, 0, 0 }, { 1, 1, 1 } };

char bus[WIDTH + 1] = { '*', '*', '*','\0' };
char* ptr_r1data2d = &patternOne[1]; // for debug
char* ptr_r2data2d = &patternOne[2]; //for debug

void dataToBus(char* data);
char* getAdresseRowFomData2D(int row); //deprecated
char* getAdresseRowFromData2DAdresse(int row, char* data2d);
void displayData2D(char* ptr_data2d);
void display(int entier);
char* choosePattern(int entier);

int main(){
	display(2);
	display(1);
	return 0;
}

void display(int entier) {
	char* tmp = choosePattern(entier);
	displayData2D(tmp);
}

char* choosePattern(int entier) {
	if (entier == 1) {
		return patternOne;
	}
	else {
		return patternTwo;
	}
}

void displayData2D(char* ptr_data2D) {
	for (int i = 0; i < HEIGHT; i++)
	{
		dataToBus(getAdresseRowFromData2DAdresse(i, ptr_data2D));
		puts(bus);
	}
	puts("");
}

char* getAdresseRowFomData2D(int row) {
	return &patternOne[row];
}
char* getAdresseRowFromData2DAdresse(int row, char* data2d) {
	return &data2d[row*WIDTH];
}

void dataToBus(char* data) {
	for (int i = 0; i < WIDTH; i++) {
		bus[i] = (!data[i]) ? '_' : '*';
	}
}