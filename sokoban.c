#include <stdio.h>
#include <stdlib.h>

int EXIT(){
return 1;
}

int main(int argc, char *argv[]){
	
	SOKOBAN S;
	ACTION A;
	
	initialiser_affichage();
	S = initialiser_SOKOBAN();
	S = initialiser_niveau(/*niveau*/);
	afficher_niveau();
	
	do {
		A = recuperer_action();
		S = modifier_sokoban_action(S, A);
		afficher_niveau(S);
		
		
		
	}
	while(!EXIT());
		
		
	
	
}
	return 0;
}