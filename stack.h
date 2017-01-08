///////////////////////////////
//    NOM : JACQUET          //
//    PRENOM : Julien        //
//    NUMERO ET : 21400579   //
///////////////////////////////

#ifndef __stack_h
#define __stack_h

#include "sokoban.h"

#define STACK_MAX 20000 //devrais etre suffisant --> implique 20000 clics de touches...

//les deux structures et leurs fonctions sont identiques, simplement pour les différentier
struct stackUndo{ //pour undo
  SOKOBAN STprec[STACK_MAX];
  int top;
}stUndo;


int stUndoFull();

void pushUndo(SOKOBAN S);

int stUndoEmpty();

SOKOBAN popUndo(SOKOBAN S);

struct stackRedo{ //pour redo
  SOKOBAN STRedo[STACK_MAX];
  int top;
}stRedo;

int stRedoFull();

void pushRedo(SOKOBAN S);

int stRedoEmpty();

SOKOBAN popRedo(SOKOBAN S);

#endif
