#include <uvsqgraphics.h>

#include "struct.h"
#include "display.h"

void message_help(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (50 * S.L) / 6.8; T.y = (50 * S.H) + 75;
		aff_pol("Utiliser les fl" "\xe8" "ches pour vous d\xe9placez",
		(S.L * (1.8 + (S.L / 100))), T, red);

		T.x = (50 * S.L) / 6.5; T.y = (50 * S.H) + 50;
		aff_pol("et la touche U pour revenir en arri\xe8re",
		(S.L * (1.8 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 7.6; T.y = (50 * S.H) + 75;
		aff_pol("Utiliser les fl" "\xe8" "ches pour vous d\xe9placez",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
		T.x = (50 * S.L) / 7; T.y = (50 * S.H) + 50;
		aff_pol("et la touche U pour revenir en arri\xe8re",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
	}
}

void message_select_player(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (25 * S.L) / 8; T.y = (50 * S.H) + 60;
		aff_pol("Cliquez sur la case o\xf9 vous souhaitez placer le joueur",
		(S.L * (1.6 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 3.7; T.y = (50 * S.H) + 70;
		aff_pol("Cliquez sur la case o\xf9",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
		T.x = (50 * (S.L + (5 - S.L))) / 4.5; T.y = (50 * S.H) + 45;
		aff_pol("vous souhaitez placer le joueur",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
	}
}

void message_select_exit(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (25 * S.L) / 8; T.y = (50 * S.H) + 60;
		aff_pol
		("Cliquez sur la case o\xf9 vous souhaitez placer la sortie",
		(S.L * (1.6 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 3.7; T.y = (50 * S.H) + 70;
		aff_pol("Cliquez sur la case o\xf9",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T,red);
		T.x = (50 * (S.L + (5 - S.L))) / 4.5; T.y = (50 * S.H) + 45;
		aff_pol("vous souhaitez placer la sortie",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T,red);
	}
}

void message_select_wall(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (25 * S.L) / 6; T.y = (50 * S.H) + 70;
		aff_pol("Cliquez sur la case o\xf9 vous souhaitez placer le mur",
		(S.L * (1.6 + (S.L / 100))), T, red);
		T.x = (25 * (S.L + (5 - S.L))) / 15; T.y = (50 * S.H) + 20;
		aff_pol ("Pour terminer" " l'""\xe9""dition utilisez la touche S ou la touche A pour supprimer un mur.",
		(S.L * (1 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 3.7; T.y = (50 * S.H) + 80;
		aff_pol("Cliquez sur la case o\xf9",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))), T, red);
		T.x = (50 * (S.L + (5 - S.L))) / 4.5; T.y = (50 * S.H) + 55;
		aff_pol("vous souhaitez placer le mur",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))), T, red);
		T.x = (25 * (S.L + (5 - S.L))) / 15; T.y = (50 * S.H) + 25;
		aff_pol ("Pour terminer" " l'" "\xe9""dition utilisez la touche S",
		((S.L + (5 - S.L)) * (1.65 + ((S.L + (5 - S.L)) / 100))), T, red);
		T.x = (25 * (S.L + (5 - S.L))) / 15; T.y = (50 * S.H) + 15;
		aff_pol ("ou la touche A pour supprimer un mur",
		((S.L + (5 - S.L)) * (1.65 + ((S.L + (5 - S.L)) / 100))), T, red);
	}
}

void message_delete_wall(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (25 * S.L) / 6; T.y = (50 * S.H) + 65;
		aff_pol("Cliquez sur la case o\xf9 vous souhaitez supprimer le mur",
		(S.L * (1.6 + (S.L / 100))), T, red);
		T.x = (25 * (S.L + (5 - S.L))) / 15; T.y = (50 * S.H) + 20;
		aff_pol("Utiliser la touche V pour terminer la suppression",
		(S.L * (1 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 3.7; T.y = (50 * S.H) + 80;
		aff_pol("Cliquez sur la case o\xf9",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
		T.x = (50 * (S.L + (5 - S.L))) / 4.5; T.y = (50 * S.H) + 55;
		aff_pol("vous souhaitez supprimer le mur",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
		T.x = (25 * (S.L + (5 - S.L))) / 15; T.y = (50 * S.H) + 15;
		aff_pol("Utiliser la touche V pour terminer la suppression",
		((S.L + (5 - S.L)) * (1.65 + ((S.L + (5 - S.L)) / 100))),T, red);
	}
}

void wall_direction_message(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (50 * S.L) / 5.5; T.y = (50 * S.H) + 65;
		aff_pol("Maintenant utiliser les fl" "\xe8" "ches directionnel",
		(S.L * (1.6 + (S.L / 100))), T, red);
		T.x = (50 * S.L) / 3.3; T.y = (50 * S.H) + 40;
		aff_pol("pour l'orientation du mur",
		(S.L * (1.6 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 9; T.y = (50 * S.H) + 70;
		aff_pol("Maintenant utiliser les fl" "\xe8" "ches directionnel",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
		T.x = (50 * (S.L + (5 - S.L))) / 4; T.y = (50 * S.H) + 45;
		aff_pol("pour l'orientation du mur",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
	}
}

void error_message(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (50 * S.L) / 7; T.y = (50 * S.H) + 60;
		aff_pol("Vous ne pouvez utilisez cette touche !",
		(S.L * (1.8 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 8;
		aff_pol("Vous ne pouvez utilisez cette touche !",
		((S.L + (5 - S.L)) * (2 + ((S.L + (5 - S.L)) / 100))),T, red);
	}
	attendre(1000);
	message_space(S);
}

void impossible_click(SLIDER S)
{
	message_space(S);
	POINT T;
	if (S.L >= 6) {
		T.x = (50 * S.L) / 4; T.y = (50 * S.H) + 60;
		aff_pol("Vous ne pouvez cliquez dans cette zone !",
		(S.L * (1.5 + (S.L / 100))), T, red);
	} else {
		T.x = (50 * (S.L + (5 - S.L))) / 8; T.y = (50 * S.H) + 60;
		aff_pol("Vous ne pouvez cliquez dans cette zone !",
		((S.L + (5 - S.L)) * (1.8 + ((S.L + (5 - S.L)) / 100))),T, red);
	}
	attendre(1000);
	message_space(S);
}

void argument_error()
{
	printf("\n### MESSAGE ERREUR ###\n");
	printf
	    ("\nLe nombre d'argument est incorrect ! Merci de suivre les exemples.\n\n");
	printf
	    ("- Si vous souhaitez créer votre niveau utilisez la commande suivante :\n");
	printf
	    ("\t./slider L H test.slider (Avec H et L correspondant aux valeurs de la taille de la fenêtre)\n\n");
	printf
	    ("- Si vous souhaitez sélectionner un niveau précis utilisez la commande suivante :\n");
	printf("\t./slider niveau_01.slider\n\n");
	printf
	    ("- Si vous souhaitez exécuter tout les niveaux utilisez la commande suivante :\n");
	printf("\t./slider dir_slider\n");

	printf("\n### FIN MESSAGE ERREUR ###\n\n");
}
