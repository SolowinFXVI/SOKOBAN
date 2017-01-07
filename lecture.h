
SOKOBAN lire(char* str,SOKOBAN S);

struct level{
  int largeur_max_level;
  int hauteur_max_level;
  int debut; //debut S.niveau
  int fin;  //fin S.niveau
};

typedef struct level LEVEL;

LEVEL preprocess(char* str);
