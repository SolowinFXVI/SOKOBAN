#include "sokoban.h"

#define NBR_CASES 50

struct STRUCTURE_CREATION_NIVEAU{
  SOKOBAN C;
  int mode_creation;
};

typedef struct STRUCTURE_CREATION_NIVEAU STRUCTURE_CREATION_NIVEAU;


void initialiser_affichageCreation();

STRUCTURE_CREATION_NIVEAU creation_niveau(char *strCreation);

void affichage_creation();

void sauver(char* strCreation, SOKOBAN S);
