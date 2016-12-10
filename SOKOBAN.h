#include "constantes.h"

#ifndef ___SOKOBAN_H
#define ___SOKOBAN_H

struct case{
   int val;
  };
  
typedef struct case CASE;
  
struct sokoban{
  int mode;
  CASE plateau[largeur_niveau()][hauteur_niveau()];
  };
  
 typedef struct sokoban SOKOBAN;

#endif
