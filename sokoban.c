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
	ACTION A;
	int niveau = 1;
	initialiser_affichage();
	S = initialiser_sokoban("sasquatch1.xsb",niveau);
	afficher_sokoban(S);

do {
		A = recuperer_action();
		S = modifier_sokoban_action(S, A, niveau);
		afficher_sokoban(S);
	}
	while(mode_action(A) != QUIT );
	return 0;
}
