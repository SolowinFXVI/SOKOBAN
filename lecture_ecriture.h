
SOKOBAN lire(char* str,int niveau);

struct level{
  int largeur_max_level;
  int hauteur_max_level;
  int debut; //debut niveau
  int fin;  //fin niveau
};

typedef struct level LEVEL;

LEVEL preprocess(char* str);
