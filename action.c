#include <uvsqgraphics.h>
#include "constantes.h"
#include "sokoban.h"
#include "action.h"
#include "stack.h"

ACTION clic_action(ACTION A, POINT P){
  if(P.y > (N*TAILLE_CASE)){
    if (P.x < LARGEUR_BOUTON) {
      A.mode = UNDO;
      return A;
    }
    if (P.x < 2 * LARGEUR_BOUTON) {
      A.mode = REDO;
      return A;
    }
    if (P.x < 3 * LARGEUR_BOUTON) {
      A.mode = INIT;
      return A;
    }
    if (P.x < 4 * LARGEUR_BOUTON) {
      A.mode = PREC;
      return A;
    }
    if (P.x < 5 * LARGEUR_BOUTON) {
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

ACTION recuperer_action(){

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
    return clic_action(A,P);
  }

  return A;
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
  return S;
}

SOKOBAN prec(SOKOBAN S, int niveau){
  return S;
}

SOKOBAN suiv(SOKOBAN S, int niveau){
  return S;
}

SOKOBAN modifier_sokoban_action(SOKOBAN S, ACTION A,int niveau){

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
    return prec(S,niveau);
  }

  if(A.mode == SUIV){
    sauvegarder(S);
    return suiv(S,niveau);
  }

  return S;
}
