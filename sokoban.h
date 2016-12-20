#include "constantes.h"

#ifndef ___SOKOBAN_H
#define ___SOKOBAN_H

struct une_case{
   char val;
  };

typedef struct une_case CASE;

struct sokoban{
  int mode;
  CASE une_case[1000/*largeur_niveau()*/][1000/*hauteur_niveau()*/];
  };

 typedef struct sokoban SOKOBAN;

#endif
