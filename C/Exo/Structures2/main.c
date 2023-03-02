#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

int main(void) {
		
	/* Personne1 */
	
	Personne Personne1;
	InitPersonne(&Personne1);
	
	char* prenom1	= "Prenom1";
	char* nom1		= "NOM1";
	int age1		= 18;

	setPersonne(&Personne1, nom1, prenom1, age1);
	displayPersonne(&Personne1);
	
	/* Personne2 */

	Personne Personne2;
	InitPersonne(&Personne2);

	char* prenom2	= "Pren2";
	char* nom2		= "NM2";
	int age2		= 20;
	
	setPersonne(&Personne2, nom2, prenom2, age2);
	displayPersonne(&Personne2);
	
	/* age Difference */

	displayDiffAge(diffAge(&Personne1, &Personne2));

	/* Verify anti-overlap */

	setPersonne(&Personne1, "NN", "ppp", 2);
	displayPersonne(&Personne1);

	/* copy Personne */

	copyPersonne(&Personne1, &Personne2);
	displayPersonne(&Personne1);

	return 0;
}