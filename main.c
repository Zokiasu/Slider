#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "struct.h"
#include "read_write.h"
#include "display.h"
#include "message.h"
#include "custom.h"
#include "undo.h"

int main(int argc, char *argv[])
{
	SLIDER S;
	printf("Debut du jeu\n");

	if ((argc < 2) || (argc > 5) || (argc == 3) || (argc == 4)) {
		/*Envoie un message d'erreur si la commande est fausse */
		argument_error();
		printf("Fin du jeu\n");
		exit(0);
	} else if (!strcmp(argv[1], "-c")) {	/*éditeur de niveau*/
		/*Ecris dans le fichier */
		char s1[50] = "";
		strcat(s1, "dir_slider/");
		strcat(s1, argv[4]);
		write_file(argv[2], argv[3], s1);
		S = read_file(s1);
		display_game(S);
		/*Renvoie les valeurs et les lis */
		lvl_custom(s1, S);
		S = read_file(s1);
		play_game(S);
	} else {
		char s2[20] = "", s3[11] = "";
		int i = 1,T = 0;
		strcat(s3, "dir_slider");
		while (T != 1) {
			char s[100] = "";
			/*Test si le joueur veut lancer tout les niveaux */
			if (strcmp(argv[1], s3) == 0) {
				strcat(s, argv[1]);
				strcat(s, "/niveau");
				sprintf(s2, "_%d.slider", i);
				strcat(s, s2);
				/*Si le fichier existe lance le niveau */
				if (fopen(s, "r") != NULL) {
					printf("Vous avez lancer %s\n", s);
					S = read_file(s);
					play_game(S);
					i++;
				} else {	/*Si le fichier n'existe pas met fin au jeu */
					printf("Le niveau %d n'existe pas\n", i);
					T = 1;
				}
			} 
			/*Sinon le joueur lance un niveau précis */
			else {	
				strcat(s, "dir_slider/");
				strcat(s, argv[1]);
				printf("Vous avez lancer %s\n", s);
				if (fopen(s, "r") != NULL) {
					S = read_file(s);
					play_game(S);
					T = 1;
				} else {	/*Si le fichier n'existe pas met fin au jeu */
					printf("Le niveau %s n'existe pas\n", argv[1]);
					T = 1;
				}
			}
		}
	}
	end_display(S);
	printf("Fin du jeu\n");
	exit(0);
}
