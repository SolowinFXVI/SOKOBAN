#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"
#include "constantes.h"
#include <string.h>


int largeur_niveau(){
return 100;
}

int hauteur_niveau(){
  return 100;
}

SOKOBAN lire(char* str){
  SOKOBAN S;
  int x,y,k;
  FILE* fic = fopen(str ,"r");

  if (fic == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }
  S.mode = JOUER;
  for (y = N-1; y >= 0; y--){
    for(x = 0; x < N; x++){
      fscanf(fic,"%s",&k);
      S.une_case[x][y].val=k;
    }
  }

  fclose(fic);
  return S;

}
