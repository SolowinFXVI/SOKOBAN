#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"
#include "lecture_ecriture.h"
#include "constantes.h"



int largeur_niveau(){
return 100;
}

int hauteur_niveau(){
  return 100;
}

LEVEL initialiser_niveau(FILE *fic, int niveau,LEVEL L){
  int stop = 0;
  int c;
  int count_line = -1;
  int count_level = 0;

  while(((c = fgetc(fic)) != EOF)){

    switch(c){
      case 10 :
        count_line++;
        printf("line = %d\n",count_line);
        break;
      case 59 :
        count_level++;
        printf("level = %d\n",count_level);
        break;
    default :
    ;
    }

    if((count_level) == (niveau) && (stop == 0)){
      L.debut = count_line;
      stop = 1;
      printf("L.debut = %d\n",L.debut);
    }

    if((count_level) == (niveau+1)){
      L.fin = count_line;
      printf("L.fin =  %d\n",L.fin);
      return L;
    }
  }

  return L;
}

SOKOBAN lire_characteres_un_a_un(FILE *fic, SOKOBAN S, LEVEL L){
  int x = 0;
  int y = L.fin;
  int dep = 0;
  int c;
if(y > N){
  dep = ;
  while (((c = fgetc(fic)) != EOF) && (y >= L.debut)){ //lit séparement chaque characteres et les stoques
      if(c == 10){ //nouvelle ligne
        y--;
        dep --;
        printf("y=%d\n",y);
        x=0;
      }
      S.une_case[x][dep].val=c;
      x++;
    }
}
else{
  while (((c = fgetc(fic)) != EOF) && (y >= L.debut)){ //lit séparement chaque characteres et les stoques
      if(c == 10){ //nouvelle ligne
        y--;
        printf("y=%d\n",y);
        x=0;
      }
      S.une_case[x][y].val=c;
      x++;
      printf("y-N=%d\n",y-N);
    }
}
  return S;
}

SOKOBAN lire(char* str, int niveau){
  SOKOBAN S;
  LEVEL L;
  FILE *fic = fopen(str ,"r");

  if (fic == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }

  L = initialiser_niveau(fic,niveau,L);
    fclose(fic);


  FILE *ficd = fopen(str ,"r");
  if (ficd == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }
  S = lire_characteres_un_a_un(ficd,S,L);

  fclose(ficd);
  return S;
}
