#include "constantes.h"

#ifndef ___SOKOBAN_H
#define ___SOKOBAN_H

struct une_case{
   int val;
  };

typedef struct une_case CASE;

struct sokoban{
  int mode;
  CASE plateau[N/*largeur_niveau()*/][N/*hauteur_niveau()*/];
  };

 typedef struct sokoban SOKOBAN;

#endif
