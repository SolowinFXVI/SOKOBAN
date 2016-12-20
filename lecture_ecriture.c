#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"
#include "constantes.h"
#include <string.h>
#include <time.h>


int largeur_niveau(){
return 100;
}

int hauteur_niveau(){
  return 100;
}

SOKOBAN lire(char* str){
  SOKOBAN S;
  int x,y;
  /*char texte[8];
  sprintf(texte, "%d", S.une_case[x][y].val);
*/
  FILE *fic = fopen(str ,"r");

  if (fic == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }

	S.mode = JOUER;
  for(y = N-1; y>=0;y--){
    for(x = 0; x < N; x++){
      fgets(&S.une_case[x][y].val, 50,fic);
      //fscanf(fic, "%s ", k);
      //printf("%s",&S.une_case[x][y].val);
      //printf("%s",S.une_case[x][y].val);
    }
  }
  /*while(k[i] != ';'){
    printf("pass =%d\n",i);
    i++;
  }*/

  //fclose(fic);
  return S;
}
