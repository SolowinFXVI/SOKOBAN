#include "sokoban.h"
#include "constantes.h"

struct stack{
  SOKOBAN STprec[STACK_MAX];
  int top;
}st;


int stfull();

void push(SOKOBAN S);

int stempty();

SOKOBAN pop();
