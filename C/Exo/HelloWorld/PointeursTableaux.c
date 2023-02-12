#include <stdio.h>

int main() {

	int tableau_int[5][2] = {0, 1, 2, 3, 4};
	int *int_ptr = tableau_int;

	int premier_element = *int_ptr;
	int *troisieme_element = tableau_int + 3;
	int difference = troisieme_element - int_ptr;

	return 0;
}