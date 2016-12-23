#ifndef __ACTIONS_H
#define __ACTIONS_H

struct action{
  int mode;
  int fleche;
};

typedef struct action ACTION;

ACTION recuperer_action();


int mode_action(ACTION A);

SOKOBAN modifier_sokoban_action(SOKOBAN S, ACTION A, int niveau);

#endif
