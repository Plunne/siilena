#include <stdio.h>


#define HEIGHT	5
#define WIDTH	3

#define CHAR0	'_'
#define CHAR1	'*'


void displayRow(unsigned char *row);
unsigned char* switchChar(unsigned char *row);
void displayAllRows(unsigned char *row);

/* Initialisations */
unsigned char matriceLED[HEIGHT][WIDTH + 1] = {
	{ '0', '0', '1', '\0' },
	{ '0', '1', '1', '\0' },
	{ '1', '0', '1', '\0' },
	{ '0', '0', '1', '\0' },
	{ '0', '0', '1', '\0' }
};

int main() {

	

	/* Process */
	//displayRow(rangeeLED);
	displayAllRows(matriceLED);

	return 0;
}


/***************
 * Display Row *
 ***************/
void displayRow(unsigned char *row) {
	puts(switchChar(row));
}

/***************
 * Switch Char *
 ***************/
unsigned char* switchChar(unsigned char* row) {
	for (int i = 0; i < WIDTH; i++) {
		switch (row[i]) {
			case '0': 
				row[i] = CHAR0;
				break;
			case '1': 
				row[i] = CHAR1;
				break;

			default:
				break;
		}
	}

	return row;
}

/***************
 * Display All *
 ***************/
void displayAllRows(unsigned char* row) {
	for (int i=0; i < HEIGHT; i++) {
		displayRow(&row[i * WIDTH]);
	}
}
