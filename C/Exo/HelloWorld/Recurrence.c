#include <stdio.h>

int factoriel(int n) {
	if (n == 0) return 1;			// Condition d'arret
	return n * factoriel(n - 1);
}

int main() {

	printf("%d", factoriel(4));

	return 0;
}