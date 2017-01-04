#ifndef __ACTIONS_H
#define __ACTIONS_H

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
ACTION recuperer_action();


int mode_action(ACTION A);

SOKOBAN modifier_sokoban_action(SOKOBAN S, ACTION A);

SOKOBAN cleanup(SOKOBAN S);

#endif
