///////////////////////////////
//    NOM : JACQUET          //
//    PRENOM : Julien        //
//    NUMERO ET : 21400579   //
///////////////////////////////

#ifndef __affichage_h
#define __affichage_h

#include "sokoban.h"
#include "action.h"


void initialiser_affichage();

void afficher_sokoban(SOKOBAN S, int LARG, int HAUT,char *str, ACTION A,int count);

#endif
