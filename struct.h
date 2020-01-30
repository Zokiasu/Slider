typedef struct WALL{
	int A,B,C; //Pos X,Y,Orientation
}WALL;

struct slider{
	int L,H; // Largeur et hauteur de la grille
	int I,J; // position joueur
	int Z,X; // position sortie
	int K; //Nombre de mur
	WALL *wall; //position et direction mur
};

typedef struct slider SLIDER;

typedef struct pile
{
    int data;
    struct pile *prev;

} Pile;
