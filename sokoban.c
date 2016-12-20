#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"
#include "lecture_ecriture.h"
#include "action.h"
#include "affichage.h"

SOKOBAN initialiser_sokoban(char* str){
lire(str);
}

SOKOBAN initialiser_niveau(){
	;
}

SOKOBAN modifier_sokoban_action()
{
	;
}



int main(int argc, char *argv[]){
	SOKOBAN S;
	ACTION A;

	initialiser_affichage();
	S = initialiser_sokoban("sasquatch1.xsb");
	//S = initialiser_niveau(/*niveau*/);
	afficher_sokoban(S);

	do {
		A = recuperer_action();
		S = modifier_sokoban_action(S, A);
		afficher_sokoban(S);
	}
	while(mode_action(A) != QUIT );
	return 0;
}
