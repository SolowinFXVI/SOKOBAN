#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stPrecFull(){
  if(stPrec.top >= STACK_MAX - 1){
    return 1;
  }
  else
    return 0;
}

void pushPrec(SOKOBAN S){
  if(stPrecFull()){
    printf("stack is full\n");
    exit(EXIT_FAILURE);
  }
  stPrec.top++;
  stPrec.STprec[stPrec.top] = S;
}

int stPrecEmpty(){
  if(stPrec.top <= 0){
    return 1;
  }
  else
  return 0;
}

SOKOBAN popPrec(SOKOBAN S){
  SOKOBAN P;
  printf("poped?");
  if(stPrecEmpty()){
    printf("pas de retour en arriere possible");
    return S;
  }
  else{
    P = stPrec.STprec[stPrec.top];
    stPrec.top--;
  return P;
  }
}


int stSuivFull(){
  if(stSuiv.top >= STACK_MAX - 1){
    return 1;
  }
  else
    return 0;
}

void pushSuiv(SOKOBAN S){
  if(stSuivFull()){
    printf("stack is full\n");
    exit(EXIT_FAILURE);
  }
  stSuiv.top++;
  stSuiv.STSuiv[stSuiv.top] = S;
}

int stSuivEmpty(){
  if(stSuiv.top <= 0){
    return 1;
  }
  else
  return 0;
}

SOKOBAN popSuiv(SOKOBAN S){
  SOKOBAN P;
  printf("poped?");
  if(stSuivEmpty()){
    printf("pas de retour en arriere possible");
    return S;
  }
  else{
    P = stSuiv.STSuiv[stSuiv.top];
    stSuiv.top--;
  return P;
  }
}
