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

    if(((count_level) == (niveau)) && (stop == 0)){
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

int calcul_delta(LEVEL L){
  int delta;

  delta = L.fin - L.debut;

  return delta;
}

SOKOBAN lire_characteres_un_a_un(FILE *ficd, SOKOBAN S, LEVEL L, int delta){
  int count = 0;
  int start = 0;
  int x;
  int y;
  int c;

  while ((c = fgetc(ficd)) != EOF){

    if (c == 10){
      count++;
    }

    if(count == L.debut){
      start = 1;
      printf("initialized");
    }

    if((start >= 1) && (start <= delta)){

      if(c == 10){
        y--;
        x=0;
      }
      S.une_case[x][y].val = c;
      x++;
      start ++;
      printf("c = %d\n",c);
      printf("count = %d\n",count);
      printf("start = %d\n",start);
    }
  }



/*  while (((c = fgetc(fic)) != EOF) && (y >= L.debut)){ //lit séparement chaque characteres et les stoques
      if(c == 10){ //nouvelle ligne
        y--;
        printf("y=%d\n",y);
        x=0;
      }
      S.une_case[x][y-delta].val=c;
        printf("y - delta = %d\n",y-delta);
      x++;
    }

  while (((c = fgetc(fic)) != EOF) && (y >= L.debut)){ //lit séparement chaque characteres et les stoques
      if(c == 10){ //nouvelle ligne
        y--;
        printf("y=%d\n",y);
        x=0;
      }
      S.une_case[x][y-delta].val=c;
      x++;
      //printf("y-N=%d\n",y-N);
    }*/



  return S;
}

SOKOBAN lire(char* str, int niveau){
  SOKOBAN S;
  LEVEL L;
  int delta;
  FILE *fic = fopen(str ,"r");

  if (fic == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }

  L = initialiser_niveau(fic,niveau,L);
  printf("level initilized ");
  fclose(fic);

  delta = calcul_delta(L);
  printf("delta processed ");

  FILE *ficd = fopen(str ,"r");

  if (ficd == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }

  printf("before lire_characteres_un_a_un");
  S = lire_characteres_un_a_un(ficd,S,L,delta);
  printf("after lire_characteres_un_a_un");
  fclose(ficd);
  return S;
}
