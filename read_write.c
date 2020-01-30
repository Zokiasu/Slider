#include <stdio.h>
#include <uvsqgraphics.h>

#include "struct.h"
#define MAX 100

SLIDER read_file(char *name)
{
	FILE *file;
	file = fopen(name, "r");

	int i = 7, z = 0, o = 0, *tab = 0;
	tab = malloc(MAX * sizeof(int));
	/*Récupère toute les valeurs du fichier et les stocks dans un tableau*/
	if (file != NULL) {
		do {
			z = fscanf(file, "%d", &tab[o]);
			o++;
		} while (z != -1);
		fclose(file);
	}

	SLIDER S;
	//taille de la fenêtre
	S.L = tab[0]; //X
	S.H = tab[1]; //Y

	//position joueur
	S.I = tab[2]; //X
	S.J = tab[3]; //Y

	//position sortie
	S.Z = tab[4]; //X
	S.X = tab[5]; //Y

	//position mur
	S.K = tab[6]; //nombre de mur
	S.wall = malloc(S.K*sizeof(WALL));
	
	for (int j = 0; j < S.K; j++) {
		S.wall[j].A = tab[i]; //X
		S.wall[j].B = tab[i + 1]; //Y
		S.wall[j].C = tab[i + 2]; //Alignement
		i += 3;
	}
	free(tab);
	return S;
}

void write_file(char *L, char *H, char *name)
{
	FILE *file;

	file = fopen(name, "w+");
	/*Note les dimensions de la fenêtre dans le fichier */
	fprintf(file, "%d %d\n", atoi(L), atoi(H));

	fclose(file);
}
