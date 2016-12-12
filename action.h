#ifndef __ACTIONS_H
#define __ACTIONS_H

struct action{
  int mode;
  int x, y;
};

typedef struct action ACTION;

ACTION recuperer_action();


int mode_action(ACTION A);


#endif
