///////////////////////////////
//    NOM : JACQUET          //
//    PRENOM : Julien        //
//    NUMERO ET : 21400579   //
///////////////////////////////

#ifndef __lecture_h
#define __lecture_h

struct level{
  int largeur_max_level;
  int hauteur_max_level;
  int debut; //debut S.niveau
  int fin;  //fin S.niveau
};

typedef struct level LEVEL;

SOKOBAN lire(char* str,SOKOBAN S);

LEVEL preprocess(char* str);

#endif
