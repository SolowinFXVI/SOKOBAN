#ifndef __action_h
#define __action_h

struct action{
  int mode;
  int fleche;
};

typedef struct action ACTION;

struct coord{
  int x;
  int y;
};

typedef struct coord COORD;

ACTION recuperer_action(int LARG, int LONG, ACTION A);


int mode_action(ACTION A);

SOKOBAN modifier_sokoban_action(SOKOBAN S, ACTION A, char* str);

SOKOBAN cleanup(SOKOBAN S);

ACTION test_victoire(SOKOBAN S, ACTION A);

#endif
