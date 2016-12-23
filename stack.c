#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "sokoban.h"
#include "stack.h"

void stack_init(STACK *ST){
  ST->size = 0;
}

int is_state(STACK *ST){
  if (ST->size == STACK_MAX){
    return IS_FULL;
  }

  if (ST->size == 0){
    return IS_EMPTY;
  }

  return NOR_EMPTY_NOR_FULL;
}

void push(STACK *ST, SOKOBAN S){
  if(ST->size < STACK_MAX){
    ST->data[ST->size++] = S;
  }
  else
    fprintf(stderr, "ERROR : stack full\n");
}

void pop(STACK *ST){
  if(ST->size == IS_EMPTY){
    fprintf(stderr, "ERROR : stack empty \n");
  }
  else
    ST->size--;
}
