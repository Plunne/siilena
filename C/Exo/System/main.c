#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char * cmd = "";
	char* prompt = "lena@sii $ ";

	while (1) {
		printf(prompt);
		scanf("%s", cmd);

		system(cmd);
	}

	return 0;
}