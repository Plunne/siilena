#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char * cmd = "";
	const char* default_prompt = "lena@sii $ ";
	char* prompt = default_prompt;

	while (1) {
		printf(prompt);
		scanf("%s", cmd);

		if (*cmd == "cprompt") {
			printf("Change prompt : ");
			scanf("%s", prompt);
			if (prompt == "") prompt = default_prompt;
		}
		else {
			system(cmd);
		}

	}

	return 0;
}