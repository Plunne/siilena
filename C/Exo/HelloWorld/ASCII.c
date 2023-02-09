#include <stdio.h>

int main() {

	for (int i = 0; i < 256; i++) printf("ASCII caractere %c\t DEC: %d\t HEX: 0x%X\n", i, i, i);
	
	while (1) {
		char caractere = '0';
		printf("\n\nRechercher un caractere : ");
		scanf(" %c", &caractere);
		printf("ASCII: %c\t DEC: %d\t HEX: 0x%X\n", caractere, caractere, caractere);
	}

	return 0;
}