struct stackRedo{ //pour redo
  SOKOBAN STRedo[STACK_MAX];
  int top;
}stRedo;

struct stackUndo{ //pour undo
  SOKOBAN STprec[STACK_MAX];
  int top;
}stUndo; 
