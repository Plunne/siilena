/* librairie standard ... */
#include <stdlib.h>
/* pour getopt */
#include <unistd.h>
/* déclaration des types de base */
#include <sys/types.h>
/* pour les entrées/sorties */
#include <stdio.h>
/* pour la gestion des erreurs */
#include <errno.h>

#include <string.h>

void main (int argc, char **argv)
{
	int c;
	extern char *optarg;
	extern int optind;

	int timer1_ms = 0; 
	int timer2_ms = 0; 
	int timer3_ms = 0;

	char message[256] = "";

	unsigned char messageLoopFlag = 0;

	unsigned char messageNumber = 0;

	while ((c = getopt(argc, argv, "t:n:bhm:s")) != -1) {
		switch (c) {
			// Message
			case 'm':
				if(strlen(optarg) > 256) {
					printf("Message trop long : %d caracteres (>256)\n", strlen(optarg));
					exit(2);
				} else {
					strcpy(message, optarg);
				}
				break;

			case 'b':
				messageLoopFlag |= (1 << 0);
                break;

			case 'n':
				messageLoopFlag |= (1 << 1);
				messageNumber = atoi(strtok(optarg, " "));
                break;

			// Timers
         	case 't':
				timer1_ms = atoi(strtok(optarg, " "));
				timer2_ms = atoi(strtok(NULL, " "));
				timer3_ms = atoi(strtok(NULL, " "));

				printf("Temps définis : court = %dms, moyen = %dms, long = %dms.\n", timer1_ms, timer2_ms, timer3_ms);

                		break;

			// Help
            		case 'h':
            		default:
				printf("Utilisation du programme :\n");
				printf("-h : affiche l'aide\n");
				printf("-s : stop le programme\n");
				printf("-m \"xxx\" : message à envoyer\n");
				printf("-t \"# # #\" : configure les timers avec les temps indiqués\n");
				printf("-b : message affiché en morse en boucle\n");
				printf("-n # : message affiché en morse n-fois\n");

				exit(1) ;
				break;
		}
	} 

	/* If message is empty */
	if (strcmp(message, "") == 0) {
		printf("Précisez un message '-m' ou envoyez la commande stop '-s'. Option '-h' pour l'aide.\n");
		exit(0);
	} else {

		/* Message : -m */
		printf("Message : %s\n", message);

		/* Option -b or -n */
		if ((messageLoopFlag & 1) && !(messageLoopFlag & 2)) {
			
			/* Loop : -b */
			while(1) {
				printf("%s\n", message);
				sleep(1);
			}

		} else if ((messageLoopFlag & 2) && !(messageLoopFlag & 1)) {
			
			/* Iterations : -n */			
			printf("Nombre d'interations : %d\n", messageNumber);
			while(messageNumber > 0) {
				printf("%s\n", message);
				messageNumber--;
			}
		}
	}

}

