#include "penduio.h"

/************************
 *     Input/Output     *
 ************************/

void displayPendu(PenduGame* Pendu) {
	
	printf("\n-- %s --\n", Pendu->word);
	printf("Letters already sent : %s\n", Pendu->try);
	printf("Number of try remaining : %d\n", Pendu->missedCpt);

}

void insertLetter(PenduGame* Pendu) {

	do {
		printf("Insert a letter : ");				// Insert a letter
		scanf(" %c", &Pendu->letter);				// Get letter input

	} while (checkUsed(Pendu));						// While letter was already sent

	Pendu->try[Pendu->nbTry] = Pendu->letter;	// Put Letter into try array
	Pendu->nbTry++;								// Increment try array indice
	Pendu->try[Pendu->nbTry] = '\0';			// Put last string char '\0' into try array
	
}
