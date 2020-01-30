#include <uvsqgraphics.h>

#include "struct.h"
#include "display.h"
#include "message.h"
#include "undo.h"

void player_display(int I, int J)
{
	POINT jo;
	jo.x = 25 + I * 50; jo.y = 25 + J * 50;
	draw_fill_circle(jo, 20, blue);
}

void exit_display(int Z, int X)
{
	POINT so;
	so.x = 25 + Z * 50; so.y = 25 + X * 50;
	draw_fill_circle(so, 20, green);
}

void draw_wall(int G, int H, SLIDER S)
{
	POINT p1, p2;
	switch (G) {
	case 273:
		p1.x = 50 * S.wall[H].A; p1.y = 50 * S.wall[H].B + 50;
		p2.x = 50 * S.wall[H].A + 50; p2.y = 50 * S.wall[H].B + 50;
		draw_fill_rectangle(p1, p2, red);
		break;
	case 274:
		p1.x = 50 * S.wall[H].A; p1.y = 50 * S.wall[H].B;
		p2.x = 50 * S.wall[H].A + 50; p2.y = 50 * S.wall[H].B;
		draw_fill_rectangle(p1, p2, red);
		break;
	case 275:
		p1.x = 50 * S.wall[H].A + 50; p1.y = 50 * S.wall[H].B;
		p2.x = 50 * S.wall[H].A + 50; p2.y = 50 * S.wall[H].B + 50;
		draw_fill_rectangle(p1, p2, red);
		break;
	case 276:
		p1.x = 50 * S.wall[H].A; p1.y = 50 * S.wall[H].B;
		p2.x = 50 * S.wall[H].A; p2.y = 50 * S.wall[H].B + 50;
		draw_fill_rectangle(p1, p2, red);
		break;
	case -1:
		break;
	}
}

void clean_wall(SLIDER S, int A, int B, int G)
{
	POINT p1, p2;
	switch (G) {
		case 273:
			p1.x = 50 * A; p1.y = 50 * B + 50;
			p2.x = 50 * A + 50; p2.y = 50 * B + 50;
			draw_fill_rectangle(p1, p2, white);
			break;
		case 274:
			p1.x = 50 * A; p1.y = 50 * B;
			p2.x = 50 * A + 50; p2.y = 50 * B;
			draw_fill_rectangle(p1, p2, white);
			break;
		case 275:
			p1.x = 50 * A + 50; p1.y = 50 * B;
			p2.x = 50 * A + 50; p2.y = 50 * B + 50;
			draw_fill_rectangle(p1, p2, white);
			break;
		case 276:
			p1.x = 50 * A; p1.y = 50 * B;
			p2.x = 50 * A; p2.y = 50 * B + 50;
			draw_fill_rectangle(p1, p2, white);
			break;
		case -1:
			break;
	}
}

void select_player(char **name, SLIDER S)
{
	FILE *file;

	file = fopen(*name, "a");

	POINT P;
	int I = -1, J = -1;

	P = wait_clic();
	if ((P.y > (S.H * 50)) || (P.x > (S.L * 50))) {
		impossible_click(S);
		message_select_player(S);
		select_player(name, S);
	} else {
		I = P.x / 50; J = P.y / 50;
		player_display(I, J);
		fprintf(file, "%d %d\n", I, J);
	}
	fclose(file);
}

void select_exit(char **name, SLIDER S)
{
	FILE *file;

	file = fopen(*name, "a");

	POINT P;
	int Z = -1, X = -1;

	P = wait_clic();
	if ((P.y > (S.H * 50)) || (P.x > (S.L * 50))) {
		impossible_click(S);
		message_select_exit(S);
		select_exit(name, S);
	} else {
		Z = P.x / 50; X = P.y / 50;
		exit_display(Z, X);
		fprintf(file, "%d %d\n", Z, X);
	}

	fclose(file);
}

int wall_direction(SLIDER S, int H)
{
	wall_direction_message(S);
	int G = -1;

	while (G == -1) {
		G = get_key();
		switch (G) {
		case 273:	//Vers le haut
			draw_wall(G, H, S);
			message_select_wall(S);
			return 12;
			break;
		case 274:	//Vers le bas
			draw_wall(G, H, S);
			message_select_wall(S);
			return 6;
			break;
		case 275:	//Vers la droite
			draw_wall(G, H, S);
			message_select_wall(S);
			return 3;
			break;
		case 276:	//Vers la gauche
			draw_wall(G, H, S);
			message_select_wall(S);
			return 9;
			break;
		}
	}
	return -1;
}

int delete_node(int A, int B, int C, int H, SLIDER S)
{
	for(int i = 0; i < H ; i++) {
		if(S.wall[i].A == A && S.wall[i].B == B && S.wall[i].C == C) {
			for (int j = i; j < H; j++) {
				S.wall[j].A = S.wall[j+1].A;
				S.wall[j].B = S.wall[j+1].B;
				S.wall[j].C = S.wall[j+1].C;
			}
			H-=1;
			i = H;
		}
	}
	return H;
}

int wall_direction_delete(SLIDER S, int A, int B)
{
	wall_direction_message(S);
	int G = -1;

	while (G == -1) {
		G = get_key();
		switch (G) {
		case 273:	//Vers le haut
			clean_wall(S,A,B,G);
			message_delete_wall(S);
			return 12;
			break;
		case 274:	//Vers le bas
			clean_wall(S,A,B,G);
			message_delete_wall(S);
			return 6;
			break;
		case 275:	//Vers la droite
			clean_wall(S,A,B,G);
			message_delete_wall(S);
			return 3;
			break;
		case 276:	//Vers la gauche
			clean_wall(S,A,B,G);
			message_delete_wall(S);
			return 9;
			break;
		}
	}
	return -1;
}

int delete_wall(char **name, SLIDER S, int H)
{
	message_delete_wall(S);
	POINT P; int fleche, V = 0, A = 0, B = 0, C = 0; char touche;
	do {
		V = wait_key_arrow_clic(&touche, &fleche, &P);
		if (V == EST_CLIC) {
			if ((P.y > (S.H * 50)) || (P.x > (S.L * 50))) {
				impossible_click(S);
				message_delete_wall(S);
			} else {
				/*Récupère les valeurs du mur à supprimer*/
				A = P.x / 50; B = P.y / 50;
				C = wall_direction_delete(S,A,B);
				/*Fonction de suppression de mur*/
				H = delete_node(A, B, C, H, S);
			}
		}
	} while (touche != 'V');
	return H;
}

void select_wall(char **name, SLIDER S)
{
	FILE *file;
	file = fopen(*name, "a");
	POINT P; int H = 0, fleche, V = 0; char touche;
	S.wall = malloc(((S.L*S.H)*2)*sizeof(WALL));
	do {
		V = wait_key_arrow_clic(&touche, &fleche, &P);
		if (V == EST_CLIC) {
			if ((P.y > (S.H * 50)) || (P.x > (S.L * 50))) {
				impossible_click(S);
				message_select_wall(S);
			} else {
				S.wall[H].A = P.x/50; //X
				S.wall[H].B = P.y/50; //Y
				S.wall[H].C = wall_direction(S,H); //Alignement
				H += 1;	/*Augmente le nombre de mur créer */
			}
		} else if (touche == 'A' && H != 0) {
			/*Lance le menu de suppression de mur*/
			H = delete_wall(name, S, H);
			message_select_wall(S);
		}
	} while (touche != 'S');
		
	fprintf(file, "%d\n", H);	/*Note le nombre de mur créer dans le fichier */
	
	if (H > 0) {
		int I = H-1;
		do {
			if(S.wall[I].C != -1){
				fprintf(file, "%d %d %d\n", S.wall[I].A, S.wall[I].B, S.wall[I].C);
			}
			H--; I--;
		} while (H != 0);
	}
	fclose(file);
	free(S.wall);
}

void lvl_custom(char *name, SLIDER S)
{
	message_select_player(S);
	select_player(&name, S);

	message_select_exit(S);
	select_exit(&name, S);

	message_select_wall(S);
	select_wall(&name, S);
	
	/*Efface tout les affichages temporaire */
	fill_screen(black);
	printf("\nFin mode édition\n");
}
