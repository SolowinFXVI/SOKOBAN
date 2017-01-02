#include <uvsqgraphics.h>
#include "constantes.h"
#include "sokoban.h"
#include "action.h"
#include "stack.h"

ACTION clic_action(ACTION A, POINT P,int LARG,int HAUT){
  if(P.y > (HAUT*TAILLE_CASE)){
    if (P.x < ((LARG*TAILLE_CASE)/6)) {
      A.mode = UNDO;
      return A;
    }
    if (P.x < 2 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = REDO;
      return A;
    }
    if (P.x < 3 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = INIT;
      return A;
    }
    if (P.x < 4 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = PREC;
      return A;
    }
    if (P.x < 5 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = SUIV;
      return A;
    }
    A.mode = QUIT;
    return A;

  }

  return A;
}

ACTION clavier_action(ACTION A, char touche){

  if(touche == ('U')){
    A.mode = UNDO;
    return A;
  }

  if(touche == ('R')){
    A.mode = REDO;
    return A;
  }

  if(touche == ('I')){
    A.mode = INIT;
    return A;
  }

  if(touche == ('P')){
    A.mode = PREC;
    return A;
  }

  if(touche == ('S')){
    A.mode = SUIV;
    return A;
  }

  if(touche == ('Q')){
    A.mode = QUIT;
    return A;
  }

  return A;
}

ACTION fleche_action(ACTION A,int fleche){
  A.mode=JOUER;
  A.fleche=fleche;
  return A;
}

ACTION recuperer_action(int LARG, int HAUT){

  ACTION A;
  POINT P = get_clic();
  char touche = get_key();
  int fleche = touche;

  char type = wait_key_arrow_clic(&touche, &fleche, &P); //contre-intuitif... le 1er renvoi 2, le deuxieme 1,le 3eme 3.. simple..........
  printf("type=%d",type);

  if(type == 1){ //fleche
    printf("fleche=%d\n", fleche);
    return fleche_action(A,fleche);
  }

  if(type == 2){ //touche
    printf("touche=%c\n", touche);
    return clavier_action(A,touche);
  }

  if(type == 3){ //clic
    return clic_action(A,P,LARG,HAUT);
  }

  return A;
}

SOKOBAN cleanup(SOKOBAN S){ //nettoye la structure SOKOBAN
  int x = 100;
  int y = 100;
  for(x = 0; x < 100; x++){
    for(y = 0; y < 100; y++){
      S.une_case[x][y].val = 0;
    }
  }
  return S;
}

int mode_action(ACTION A)
{
  return A.mode;
}

void sauvegarder(SOKOBAN S){
;
}

SOKOBAN undo(SOKOBAN S){
  return S;
}

SOKOBAN redo(SOKOBAN S){
  return S;
}

SOKOBAN init(SOKOBAN S){
  S = cleanup(S);
  S = initialiser_sokoban("sasquatch1.xsb",S);
  return S;
}

SOKOBAN prec(SOKOBAN S){
  if (S.niveau > 1) {
    S = cleanup(S);
    S.niveau--;
    S = initialiser_sokoban("sasquatch1.xsb",S);
return S;
}
  return S;
}

SOKOBAN suiv(SOKOBAN S){
  if(S.niveau < 50){
    S = cleanup(S);
    S.niveau++;
    printf(" niveau =%d\n",S.niveau);
    return initialiser_sokoban("sasquatch1.xsb",S);
  }
    return S;
}

SOKOBAN modifier_sokoban_action(SOKOBAN S, ACTION A){

  if(A.mode == UNDO){
    sauvegarder(S);
    return undo(S);
  }

  if(A.mode == REDO){
    sauvegarder(S);
    return redo(S);
  }

  if(A.mode == INIT){
    sauvegarder(S);
    return init(S);
  }

  if(A.mode == PREC){
    sauvegarder(S);
    return prec(S);
  }

  if(A.mode == SUIV){
    sauvegarder(S);
    return suiv(S);
  }

  return S;
}
