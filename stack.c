///////////////////////////////
//    NOM : JACQUET          //
//    PRENOM : Julien        //
//    NUMERO ET : 21400579   //
///////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stUndoFull() //test pile pleine
{
	if (stUndo.top >= STACK_MAX - 1) {
		return 1;
	} else
		return 0;
}

void pushUndo(SOKOBAN S) //push
{
	if (stUndoFull()) {
		printf("stack is full\n");
		exit(EXIT_FAILURE);
	}
	stUndo.top++;
	stUndo.STprec[stUndo.top] = S;
}

int stUndoEmpty() //test pile vide
{
	if (stUndo.top <= 0) {
		return 1;
	} else
		return 0;
}

SOKOBAN popUndo(SOKOBAN S)
{
	SOKOBAN P;
	if (stUndoEmpty()) {	//evite de tuer le programme
		printf("pas de retour en arriere possible");
		return S;
	} else {
		P = stUndo.STprec[stUndo.top];
		stUndo.top--;
		return P;
	}
}

int stRedoFull()
{
	if (stRedo.top >= STACK_MAX - 1) {
		return 1;
	} else
		return 0;
}

void pushRedo(SOKOBAN S)
{
	if (stRedoFull()) {
		printf("stack is full\n");
		exit(EXIT_FAILURE);
	}
	stRedo.top++;
	stRedo.STRedo[stRedo.top] = S;
}

int stRedoEmpty()
{
	if (stRedo.top <= 0) {
		return 1;
	} else
		return 0;
}

SOKOBAN popRedo(SOKOBAN S)
{
	SOKOBAN P;
	if (stRedoEmpty()) {	//evite de tuer le programme
		printf("pas de retour en arriere possible");
		return S;
	} else {
		P = stRedo.STRedo[stRedo.top];
		stRedo.top--;
		return P;
	}
}
