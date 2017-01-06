#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stfull(){
  if(st.top >= STACK_MAX - 1){
    return 1;
  }
  else
    return 0;
}

void push(SOKOBAN S){
  if(stfull()){
    printf("stack is full\n");
    exit(EXIT_FAILURE);
  }
  st.top++;
  st.STprec[st.top] = S;
}

int stempty(){
  if(st.top == 0){
    return 2;
  }
  if(st.top == -1){
    return 1;
  }
  else
  return 0;
}

SOKOBAN pop(){
  SOKOBAN P;
  printf("poped?");
  if(stempty()==2){
    printf("pas de retour en arriere possible");
    return P;
  }
  else if(stempty()==1){ //ne devrais jamais arriver
    printf("stack is empty\n");
    exit(EXIT_FAILURE);
  }
  else{
    P = st.STprec[st.top];
    st.top--;
  return P;
  }
}
