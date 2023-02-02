// Algorithmie Avancee
// 3 - For_Each Valeur Non Commune (Version plus poussee par Lena avec Tableau a taille dynamique)
// Pre-requis
// Algorithmie1_Bases.c
// Algorithmie3_ForEach1_ValeurCommune.c
// Algorithmie3_ForEach2_ValeurNonCommune.c
// Et un peu d'anglais lol

#include <stdio.h>

int main()
{
    int tab1[] = {11, 22, 33, 44, 76};	// 4BYTES cells array
    int tab2[] = {33, 44, 55, 56};		// 4BYTES cells array
    
    int TAB1_SIZE = sizeof(tab1)/sizeof(tab1[0]);	// SIZE OF tab1
    int TAB2_SIZE = sizeof(tab2)/sizeof(tab2[0]);	// SIZE OF tab2
    
    int tab_dynsize = 0;	// Init a dynamic size for an incoming array

	/* START OF FRAME */
    printf("--------\n");

	/**********
	 * Part 1 *
	 **********/
	
	/* Tab 1 uncommon with Tab 2 */
	// Watch 1st array uncommon values with 2nd one (tab1 VS tab2)
    for (int i=0; i < TAB1_SIZE; i++) {
		// Create a flag variable
        char found = 0;
		// Look for a common value in the 2nd array
        for (int j=0; j < TAB2_SIZE; j++) {
            if (tab1[i] == tab2[j]) {	// If there is a common value
                found = 1;				// Set flag to 1
                break;					// Then leave the loop
            }
        }
		// If there isn't a common value
        if (!found) {
            printf("tab1 vs tab2 : %d\n", tab1[i]);	// Display the uncommon value
            tab_dynsize++;							// Increase the size of the incoming array
        }
    }
    
	/**********
	 * Part 2 *
	 **********/

	/* Tab 2 uncommon with Tab 1 */
	// Watch 2nd array uncommon values with 1st one (tab1 VS tab2)
    for (int i=0; i < TAB2_SIZE; i++) {
		// Create a flag variable
        char found = 0;
		// Look for a common value in the 1st array
        for (int j=0; j < TAB1_SIZE; j++) {
            if (tab2[i] == tab1[j]) {	// If there is a common value
                found = 1;				// Set flag to 1
                break;					// Then leave the loop
            }
        }
		// If there isn't a common value
        if (!found) {
            printf("tab2 vs tab1 : %d\n", tab2[i]);	// Display the uncommon value
            tab_dynsize++;							// Increase the size of the incoming array
        }
    }

	/**********
	 * Part 3 *
	 **********/

	/* Fill the uncommon array (Previously incoming one) */
    printf("---\n");				// Draw a separator
    printf("%d\n", tab_dynsize);	// Display the size of the uncommon array
    
    int tabDynamic[tab_dynsize];	// Setup the uncommon array with the dynamic size
	
	/* Tab 1 uncommon with Tab 2 */
	// Watch 1st array uncommon values with 2nd one (tab1 VS tab2)
    for (int i=0; i < TAB1_SIZE; i++) {
		// Create a flag variable
        char found = 0;
		// Look for a common value in the 2nd array
        for (int j=0; j < TAB2_SIZE; j++) {
            if (tab1[i] == tab2[j]) {	// If there is a common value
                found = 1;				// Set flag to 1
                break;					// Then leave the loop
            }
        }
		// If there isn't a common value
        if (!found) {
            tabDynamic[i] = tab1[i];	// Fill the uncommon array with the 1st array
        }
    }
    
	/* Tab 2 uncommon with Tab 1 */
	// Watch 2nd array uncommon values with 1st one (tab1 VS tab2)
    for (int i=0; i < TAB2_SIZE; i++) {
		// Create a flag variable
        char found = 0;
		// Look for a common value in the 1st array
        for (int j=0; j < TAB1_SIZE; j++) {
            if (tab2[i] == tab1[j]) {	// If there is a common value
                found = 1;				// Set flag to 1
                break;					// Then leave the loop
            }
        }
		// If there isn't a common value
        if (!found) {
            tabDynamic[i] = tab2[i];	// Fill the uncommon array with the 2nd array
        }
    }

	/* Display the uncommon array content */
    for (int i=0; i < tab_dynsize; i++) printf("Different numbers %d : %d\n", i, tabDynamic[i]);

	/* END OF FRAME */
	
	return 0;
}
