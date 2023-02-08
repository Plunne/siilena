#include <stdio.h>

int main() {

	int longueur = 4;
	int largeur = 12;

	for (int y=0; y < longueur; y++) {
		for (int x = 0; x < largeur; x++) printf("*");
		printf("\n");
	}

	return 0;
}