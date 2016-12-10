#include <stdio.h>
#include <stdlib.h>

int EXIT(){
return 1;
}

int main(int argc, char *argv[]){
	
	while(!EXIT()){
		
		Lire_fichier(/* fichier*/);
		Interface_de_jeu(/**/);
		Interface_de_creation(/**/);
		Ligne_de_commande(/**/);
	
	
}
	return 0;
}
