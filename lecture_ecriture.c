#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"
#include "constantes.h"



int largeur_niveau(){
return 100;
}

int hauteur_niveau(){
  return 100;
}

SOKOBAN lire(char* str){
  SOKOBAN S;
  int x = 0;
  int y = N-1;
  int c;
  FILE *fic = fopen(str ,"r");

  if (fic == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }
  S.mode=JOUER;
  while (((c = fgetc(fic)) != EOF) && (x < N) && (y >= 0)){ //lit séparement chaque characteres et les stoques

      if(c == 10){ //nouvelle ligne
        y--;
        x=0;
      }
      S.une_case[x][y].val=c;
      x++;
    }

  fclose(fic);
  return S;
}
