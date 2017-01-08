#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sokoban.h"
#include "lecture.h"
#include "constantes.h"



LEVEL preprocess(char* str){ //analyse le fichier pour determiner la taille de la fenetre graphique
  LEVEL P;
  P.debut = 0;
  int c;
  int newlevel = 0;
  int newline = 0;
  int count_line = 0;
  int count_level = 1;
  int tmp = 0;
  int largest = 0;
  int longuest = 0;
  int delta = 0;
  FILE *fic1 = fopen(str ,"r");

  if (fic1 == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }

  while(((c = fgetc(fic1)) != EOF)){

    switch(c){
      case 10 : //nouvelle ligne
        count_line++;
        newline = 1;
        break;
      case 59 : // ';' marque de nouveau niveau
        count_level++;
        newlevel = 1;
        break;
    default :
    ;
    }

    if(newlevel == 1){
      P.fin = count_line;
      delta = P.fin - P.debut;
      if(delta > longuest){
        longuest = delta;
      }
      P.debut = P.fin;
      newlevel = 0;
    }

    if (newline == 1){
      if(tmp > largest){
          largest = tmp;
      }
      tmp = 0;
      newline = 0;
    }

    tmp++;


  }

  P.hauteur_max_level = longuest;
  P.largeur_max_level = largest;
  return P;
}

LEVEL initialiser_niveau(FILE *fic, SOKOBAN S,LEVEL L){ //determine le debut et la fin du niveau
  int stop = 0;
  int c;
  int count_line = -1;
  int count_level = 0;

  while(((c = fgetc(fic)) != EOF)){

    switch(c){
      case 10 :
        count_line++;
        break;
      case 59 :
        count_level++;
        break;
    default :
    ;
    }

    if(((count_level) == (S.niveau)) && (stop == 0)){
      L.debut = count_line;
      stop = 1;
    }

    if((count_level) == (S.niveau+1)){
      L.fin = count_line;
      return L;
    }
  }

  if(L.fin == 0){ //pour le dernier S.niveau du fichier
    L.fin = count_line;
  }
  return L;
}

SOKOBAN lire_characteres_un_a_un(FILE *fic2, SOKOBAN S, LEVEL L){
  int count = 0;
  int start = 0;
  int delta;
  delta = L.fin - L.debut;
  int x = 0;
  int y = L.fin-L.fin+delta;
  int c;

  while ((c = fgetc(fic2)) != EOF){

    if (c == 10){
      count++;
    }

    if(count == L.debut){
      start = 1;
    }

    if((start >= 1) && (start <= delta)){

      if(c == 10){
        y--;
        start ++;
        x=0;
      }
      S.une_case[x][y].val = c;
      x++;
    }
  }


  return S;
}

SOKOBAN lire(char* str,SOKOBAN S){
  LEVEL L; //initialisation
  L.hauteur_max_level = 0;
  L.largeur_max_level = 0;
  L.debut=0;
  L.fin=0;
  FILE *fic = fopen(str ,"r");

  if (fic == NULL){
    printf("echec ouverture fichier%s\n",str );
    exit(EXIT_FAILURE);
  }

  L = initialiser_niveau(fic,S,L);
  fclose(fic);


  FILE *fic2 = fopen(str ,"r");

  if (fic2 == NULL){
    exit(EXIT_FAILURE);
  }

  S = lire_characteres_un_a_un(fic2,S,L);

  fclose(fic2);
  return S;
}
