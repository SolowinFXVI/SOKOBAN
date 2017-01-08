#ifndef ___SOKOBAN_H
#define ___SOKOBAN_H

#include "constantes.h"
struct une_case{
   int val;
  };

typedef struct une_case CASE;

struct sokoban{
  int mode;
  CASE une_case[100][100]; //ne devrais jamais dépasser 100*100 cases
  int niveau;
  };

 typedef struct sokoban SOKOBAN;

SOKOBAN initialiser_sokoban(char* str, SOKOBAN S);

#endif
