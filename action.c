#include <uvsqgraphics.h>
#include "constantes.h"
#include "action.h"

ACTION clic_action(ACTION A,POINT P){
  printf("P.x=%d,P.y=%d\n",P.x,P.y);
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
}

ACTION clavier_action(ACTION A, char *asciikey){

  return A;
}

ACTION fleche_action(ACTION A,int key){

  return A;
}

ACTION recuperer_action(){

  ACTION A;
  char *asciikey;
  POINT P = get_clic();
  int key = get_key();
  asciikey = key;

  int type = wait_key_arrow_clic(&asciikey, &key, &P);
  printf("type=%d",type);

  if(type == 1){
    printf("asciikey=%c\n", &asciikey);
    return clavier_action(A,asciikey);
  }

  if(type == 2){
    printf("key=%d\n", key);
    return fleche_action(A,&key);
  }

  if(type == 3){
    return clic_action(A,P);
  }

}



int mode_action(ACTION A)
{
  return A.mode;
}
