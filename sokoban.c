#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"
#include "lecture_ecriture.h"
#include "action.h"
#include "affichage.h"

SOKOBAN initialiser_sokoban(char* str,int niveau){
	return lire(str,niveau);
}
/*

SOKOBAN modifier_sokoban_action()
{
	;
}


*/
int main(int argc, char *argv[]){
	SOKOBAN S;
	LEVEL P;
	ACTION A;
	int niveau = 2;
	int LARG;
	int HAUT;
	P = preprocess("sasquatch1.xsb");
	LARG = P.largeur_max_level;
	HAUT = P.hauteur_max_level;
	initialiser_affichage(LARG,HAUT);
	S = initialiser_sokoban("sasquatch1.xsb",niveau);
	afficher_sokoban(S, LARG, HAUT);

do {
	A = recuperer_action(LARG,HAUT);
		S = modifier_sokoban_action(S, A, niveau);
		afficher_sokoban(S, LARG, HAUT);
	}
	while(mode_action(A) != QUIT );
	return 0;
}
