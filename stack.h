#ifndef __STACK_H
#define __STACK_H



struct stack{ //pile pour sauvegarder
  SOKOBAN data[STACK_MAX];
  int size;
};

typedef struct stack STACK;

int is_state(STACK *ST);

#endif
