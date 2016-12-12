#include <uvsqgraphics.h>
#include "constantes.h"
#include "action.h"
ACTION recuperer_action(){

ACTION A;
POINT P = wait_clic();

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

int mode_action(ACTION A)
{
  return A.mode;
}
