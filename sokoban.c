///////////////////////////////
//    NOM : JACQUET          //
//    PRENOM : Julien        //
//    NUMERO ET : 21400579   //
///////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "creationNiveau.h"
#include "lecture.h"
#include "affichage.h"

SOKOBAN initialiser_sokoban(char *str, SOKOBAN S)
{
	return lire(str, S);
}

int main(int argc, char *argv[])
{
	SOKOBAN S;
	LEVEL P;
	ACTION A;
	A.mode = IDLE;		//evite une fuite de memoire (valgrind)
	int niveau = 1;
	char *str;
	char *strCreation;

	if (argc < 2) {
		printf("Trop peut d'arguments\n");
		printf("utilisations : \n");
		printf("sokoban ficin.xsb   (premier niveau par defaut)\n");
		printf("sokoban -n num ficin.xsb  (niveau choisi)\n");
		printf("sokoban -c ficout.xsb   (creation de niveau)\n");
		exit(EXIT_FAILURE);
	}

	if (argc == 2) {
		str = argv[1];
	}

	if (argc == 4) {

		if ((strcmp(argv[1], "-n")) == 0) {
			niveau = atoi(argv[2]);
			str = argv[3];
		}

		else if (strcmp(argv[1], "-c") == 0) {
			printf("creation non fonctionnelle..");
			A.mode = CREATION;
			strCreation = argv[2];
		}

		else {
			printf("utilisations : \n");
			printf("utilisations : \n");
			printf
			    ("sokoban ficin.xsb   (premier niveau par defaut)\n");
			printf("sokoban -n num ficin.xsb  (niveau choisi)\n");
			printf
			    ("sokoban -c ficout.xsb   (creation de niveau)\n");
			exit(EXIT_FAILURE);
		}
	}

	if (A.mode != CREATION) {
		int LARG;
		int HAUT;
		int count = 0;
		P = preprocess(str);
		LARG = P.largeur_max_level;
		HAUT = P.hauteur_max_level;
		initialiser_affichage(LARG, HAUT);
		S.niveau = niveau;
		S = cleanup(S);
		S = initialiser_sokoban(str, S);
		afficher_sokoban(S, LARG, HAUT, str, A, count);
		do {
			A = recuperer_action(LARG, HAUT, A);
			A = test_victoire(S, A);
			S = modifier_sokoban_action(S, A, str);
			count++;
			afficher_sokoban(S, LARG, HAUT, str, A, count);
		}
		while (mode_action(A) != QUIT);
		S = cleanup(S);
	} else {
		initialiser_affichageCreation();
		do {
			creation_niveau(strCreation);
		}
		while (A.mode != QUIT);
	}
	return 0;
}
