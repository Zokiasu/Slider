#include <uvsqgraphics.h>

#include "struct.h"
#include "display.h"
#include "message.h"
#include "undo.h"

int try_wall(SLIDER S, int G)
{
	int Z = 0;

	for (int p = 0; p < S.K; p++) {

		if (G == 273 || G == 274) {
			/*Test mur du Haut*/
			if ((G == 273) && (S.I == S.wall[p].A) &&
			    (((S.J == S.wall[p].B) && (S.wall[p].C == 12)) ||
			     ((S.J + 1 == S.wall[p].B) && (S.wall[p].C == 6)))) {
				Z = 1;
			}
			/*Test mur du Bas*/
			if ((G == 274) && (S.I == S.wall[p].A) &&
			    (((S.J == S.wall[p].B) && (S.wall[p].C == 6)) ||
			     ((S.J - 1 == S.wall[p].B) && (S.wall[p].C == 12)))) {
				Z = 2;
			}
		}

		if (G == 275 || G == 276) {
			/*Test mur du Droite*/
			if ((G == 275) && (S.J == S.wall[p].B) &&
			    (((S.I == S.wall[p].A) && (S.wall[p].C == 3)) ||
			     ((S.I + 1 == S.wall[p].A) && (S.wall[p].C == 9)))) {
				Z = 3;
			}
			/*Test mur du Gauche*/
			if ((G == 276) && (S.J == S.wall[p].B) &&
			    (((S.I == S.wall[p].A) && (S.wall[p].C == 9)) ||
			     ((S.I - 1 == S.wall[p].A) && (S.wall[p].C == 3)))) {
				Z = 4;
			}
		}
	}
	return Z;
}

void move_player(SLIDER S)
{
	int G = 0, I = S.I, J = S.J;
	Pile *X = NULL, *Y = NULL;

	while (S.I != S.Z || S.J != S.X) {
		G = get_key();
		switch (G) {
				
			case 273:	//Vers le haut
				pile_push(&X, S.I); pile_push(&Y, S.J);
				while ((S.I != S.Z || S.J != S.X) && S.J < S.H - 1
					   && try_wall(S, G) != 1) {
					attendre(50);
					clean_player(S);
					S.J += 1;
					display_player(S);
				}
				break;
			case 274:	//Vers le bas
				pile_push(&X, S.I); pile_push(&Y, S.J);
				while ((S.I != S.Z || S.J != S.X) && S.J > 0
					   && try_wall(S, G) != 2) {
					attendre(50);
					clean_player(S);
					S.J -= 1;
					display_player(S);
				}
				break;
			case 275:	//Vers la droite
				pile_push(&X, S.I); pile_push(&Y, S.J);
				while ((S.I != S.Z || S.J != S.X) && S.I < S.L - 1
					   && try_wall(S, G) != 3) {
					attendre(50);
					clean_player(S);
					S.I += 1;
					display_player(S);
				}
				break;
			case 276:	//Vers la gauche
				pile_push(&X, S.I); pile_push(&Y, S.J);
				while ((S.I != S.Z || S.J != S.X) && S.I > 0
					   && try_wall(S, G) != 4) {
					attendre(50);
					clean_player(S);
					S.I -= 1;
					display_player(S);
				}
				break;
			case 117:	//undo                        
				clean_player(S);
				if (S.I != I || S.J != J) {
					S.I = pile_pop(&X);
					S.J = pile_pop(&Y);
				}
				display_player(S);
				break;
			case -1:
				break;
			default:
				error_message(S);
				message_help(S);
				break;
		}
	}
	free(X);
	free(Y);
}
