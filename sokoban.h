#include "constantes.h"

#ifndef ___SOKOBAN_H
#define ___SOKOBAN_H

struct une_case{
   int val;
  };

typedef struct une_case CASE;

struct sokoban{
  int mode;
  CASE une_case[100][100]; //ne devrais jamais dépasser 100*100 cases
  };

 typedef struct sokoban SOKOBAN;

#endif
