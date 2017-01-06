#include "sokoban.h"

#define STACK_MAX 10000 //devrais etre suffisant --> implique 10000 clics de touches...

//les deux structures et leurs fonctions sont identiques, simplement pour les différentier
struct stackPrec{ //pour undo
  SOKOBAN STprec[STACK_MAX];
  int top;
}stPrec;


int stPrecFull();

void pushPrec(SOKOBAN S);

int stPrecEmpty();

SOKOBAN popPrec(SOKOBAN S);

struct stackSuiv{ //pour redo
  SOKOBAN STSuiv[STACK_MAX];
  int top;
}stSuiv;

int stSuivFull();

void pushSuiv(SOKOBAN S);

int stSuivEmpty();

SOKOBAN popSuiv(SOKOBAN S);
