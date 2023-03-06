#include "pendufile.h"

#include <errno.h>
#include <time.h>

void getFileWord(PenduGame* Pendu) {

	/* File Open */
	Pendu->file = fopen("PenduList.txt", "r"); // Open the PenduLIst.txt file containing all words

	/* File check */
	if (!Pendu->file) { // If file doesn't exists

		perror("Error opening file");
		printf("errno = %d\n", errno);

		if (errno == ENOENT) {
			perror("File not found\n");
		}
		else if (errno == EACCES) {
			perror("Permission denied\n");
		}
		else {
			perror("Unknown error\n");
		}
        
		exit(EXIT_FAILURE);	// Exit program as failure state
	}


	/* Line/Words number */
	char wordTmp[PENDU_MAX_WORD];	// Buffer that'll store the line content (word)
	unsigned short nb_lines = 0;	// Line Counter

	while (fgets(wordTmp, 30, Pendu->file) != NULL) {	// While not at the end
		nb_lines++;										// Increment lines counter
	}

	/* Random */
	srand(time(NULL));						// Start random
	int randomNumber = rand() %nb_lines;	// Get a random number (0 -> max line number)

	/* Rewind */
	rewind(Pendu->file); // Set file pointer back to SOF

	/* Init PENDU */
	*Pendu->PENDU = ""; // Init PENDU word to find (allow assignments)
	
	/* Get random word */
	for (int randomCpt = 0; randomCpt < randomNumber; randomCpt++) { // WHile not at the random line
		fscanf(Pendu->file, "%s", Pendu->PENDU); // Assign the word into the PENDU word to find
	}

	// At this moment, the loop stopped at the random word
	// The word is stored into PENDU

	/* File Close */
	fclose(Pendu->file); // Close the file

}



// 	PenduList PenduList;

// 	PenduList.Game = Pendu;

// 	/* File Open */
// 	Pendu->file = fopen("PenduList.txt", "r"); // Open the PenduList.txt file containing all words

// 	/* File check */
// 	if (!Pendu->file) { // If file doesn't exists

// 		perror("Error opening file");
// 		printf("errno = %d\n", errno);

// 		if (errno == ENOENT) {
// 			perror("File not found\n");
// 		}
// 		else if (errno == EACCES) {
// 			perror("Permission denied\n");
// 		}
// 		else {
// 			perror("Unknown error\n");
// 		}
        
// 		exit(EXIT_FAILURE);	// Exit program as failure state
// 	}


// 	/* Line/Words number */
// 	char wordTmp[PENDU_MAX_WORD];	// Buffer that'll store the line content (word)
// 	unsigned short nb_lines = 0;	// Line Counter

// 	while (fgets(wordTmp, 30, Pendu->file) != NULL) {	// While not at the end
// 		nb_lines++;										// Increment lines counter
// 	}

// 	/* Random */
// 	srand(time(NULL));						// Start random
// 	int randomNumber = rand() %nb_lines;	// Get a random number (0 -> max line number)

// 	/* Rewind */
// 	rewind(Pendu->file); // Set file pointer back to SOF

// 	/* Init PENDU */
// 	*Pendu->PENDU = ""; // Init PENDU word to find (allow assignments)
	
// 	/* Get random word */
// 	for (int randomCpt = 0; randomCpt < randomNumber; randomCpt++) { // WHile not at the random line
// 		fscanf(Pendu->file, "%s", Pendu->PENDU); // Assign the word into the PENDU word to find
// 	}

// 	// At this moment, the loop stopped at the random word
// 	// The word is stored into PENDU

// 	/* File Close */
// 	fclose(Pendu->file); // Close the file

// }
