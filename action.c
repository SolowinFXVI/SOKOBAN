#include <uvsqgraphics.h>
#include "constantes.h"
#include "sokoban.h"
#include "action.h"


ACTION clic_action(ACTION A, POINT P,int LARG,int HAUT){
  if(P.y > (HAUT*TAILLE_CASE)){
    if (P.x < 1 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = UNDO;
      return A;
    }
    if (P.x < 2 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = REDO;
      return A;
    }
    if (P.x < 3 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = INIT;
      return A;
    }
    if (P.x < 4 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = PREC;
      return A;
    }
    if (P.x < 5 * ((LARG*TAILLE_CASE)/6)) {
      A.mode = SUIV;
      return A;
    }
    A.mode = QUIT;
    return A;

  }

  return A;
}

ACTION clavier_action(ACTION A, char touche){

  if(touche == ('U')){
    A.mode = UNDO;
    return A;
  }

  if(touche == ('R')){
    A.mode = REDO;
    return A;
  }

  if(touche == ('I')){
    A.mode = INIT;
    return A;
  }

  if(touche == ('P')){
    A.mode = PREC;
    return A;
  }

  if(touche == ('S')){
    A.mode = SUIV;
    return A;
  }

  if(touche == ('Q')){
    A.mode = QUIT;
    return A;
  }

  return A;
}

ACTION fleche_action(ACTION A,int fleche){
  A.mode=JOUER;
  A.fleche=fleche;
  return A;
}

ACTION recuperer_action(int LARG, int HAUT, ACTION A){

  if(A.mode == CREATION){

    return A;
  }

  POINT P = get_clic();
  char touche = get_key();
  int fleche = touche;

  char type = wait_key_arrow_clic(&touche, &fleche, &P); //contre-intuitif... le 1er renvoi 2, le deuxieme 1,le 3eme 3.. simple..........
  printf("type=%d",type);

  if(type == 1){ //fleche
    printf("fleche=%d\n", fleche);
    return fleche_action(A,fleche);
  }

  if(type == 2){ //touche
    printf("touche=%c\n", touche);
    return clavier_action(A,touche);
  }

  if(type == 3){ //clic
    return clic_action(A,P,LARG,HAUT);
  }

  return A;
}

SOKOBAN cleanup(SOKOBAN S){ //nettoye la structure SOKOBAN
  int x = 100;
  int y = 100;
  for(x = 0; x < 100; x++){
    for(y = 0; y < 100; y++){
      S.une_case[x][y].val = 0;
    }
  }
  return S;
}

int mode_action(ACTION A){ //uniquement utilisé pour quitter
  return A.mode;
}

void sauvegarder(SOKOBAN S){
  push(S);
}

SOKOBAN undo(SOKOBAN S){
  S = cleanup(S);
  S = pop();
  return S;
}

SOKOBAN redo(SOKOBAN S){
  return S;
}

SOKOBAN init(SOKOBAN S,char* str){
  S = cleanup(S);
  S = initialiser_sokoban(str,S);
  return S;
}

SOKOBAN prec(SOKOBAN S,char* str){
  if (S.niveau > 1) {
    S = cleanup(S);
    S.niveau--;
    S = initialiser_sokoban(str,S);
    return S;
  }
  return S;
}

SOKOBAN suiv(SOKOBAN S,char* str){
  if(S.niveau < 50){
    S = cleanup(S);
    S.niveau++;
    printf(" niveau =%d\n",S.niveau);
    return initialiser_sokoban(str,S);
  }
    return S;
}

COORD parcourir(SOKOBAN S){
  int x;
  int y;
  COORD C;
  for(x = 0; x < 100; x++){
    for( y = 0; y < 100; y++){
      if(S.une_case[x][y].val == 64){ //dans la plupart des cas
        C.x = x;
        C.y = y;
      }
      if(S.une_case[x][y].val == 43){//dans le cas ou le personnage est sur une case
        C.x=x;
        C.y=y;
      }
    }
  }
  return C;
}

SOKOBAN mouvement_gauche_boite(COORD C,SOKOBAN S){
  if((S.une_case[C.x-2][C.y].val == 35) || (S.une_case[C.x-2][C.y].val == 42) || (S.une_case[C.x-2][C.y].val == 36)){ //mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("obstacle a gauche de la boite\n");
    return S;
  }
  if(S.une_case[C.x-2][C.y].val == 46){//boite vers emplacement
    S.une_case[C.x-2][C.y].val = 42;
    S.une_case[C.x-1][C.y].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite vers vide
  printf("boite vers vide\n");
  S.une_case[C.x-2][C.y].val = 36;
  S.une_case[C.x-1][C.y].val = 64;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_gauche_boite_rangee(COORD C,SOKOBAN S){
  if((S.une_case[C.x-2][C.y].val == 35) || (S.une_case[C.x-2][C.y].val == 42) || (S.une_case[C.x-2][C.y].val == 36)){//mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("ya un mur a gauche de la boite rangée\n");
    return S;
  }
  if(S.une_case[C.x-2][C.y].val == 46){//boite rangée vers emplacement
    printf("emplacement a gauche de la boite rangée\n");
    S.une_case[C.x-2][C.y].val = 42;
    S.une_case[C.x-1][C.y].val = 43;//mainteant sur zone de charge
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite rangée vers vide
  printf("boite rangée vers vide\n");
  S.une_case[C.x-2][C.y].val = 36;
  S.une_case[C.x-1][C.y].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_gauche_zr(COORD C,SOKOBAN S){

  S.une_case[C.x-1][C.y].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_gauche(SOKOBAN S){
  COORD C;
  C = parcourir(S);
  switch(S.une_case[C.x-1][C.y].val) {
    case 35://mur #
    printf("ya un mur a gauche\n");
    break;
    case 36: //boite $
    printf("ya une boite a gauche\n");
    S=mouvement_gauche_boite(C,S);
    break;
    case 42://boite rangée
    printf("ya une boite rangée a gauche\n");
    S=mouvement_gauche_boite_rangee(C,S);
    break;
    case 46://zone de rangement
    S=mouvement_gauche_zr(C,S);
    break;
    default: //tous les autres cas
    S.une_case[C.x-1][C.y].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    break;
  }
  return S;
}

SOKOBAN mouvement_haut_boite(COORD C,SOKOBAN S){
  if((S.une_case[C.x][C.y+2].val == 35) || (S.une_case[C.x][C.y+2].val == 42) || (S.une_case[C.x][C.y+2].val == 36)){ //mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("obstacle en haut de la boite\n");
    return S;
  }
  if(S.une_case[C.x][C.y+2].val == 46){//boite vers emplacement
    S.une_case[C.x][C.y+2].val = 42;
    S.une_case[C.x][C.y+1].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite vers vide
  printf("boite vers vide\n");
  S.une_case[C.x][C.y+2].val = 36;
  S.une_case[C.x][C.y+1].val = 64;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_haut_boite_rangee(COORD C,SOKOBAN S){
  if((S.une_case[C.x][C.y+2].val == 35) || (S.une_case[C.x][C.y+2].val == 42) || (S.une_case[C.x][C.y+2].val == 36)){//mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("ya un mur en haut de la boite rangée\n");
    return S;
  }
  if(S.une_case[C.x][C.y+2].val == 46){//boite rangée vers emplacement
    printf("emplacement en haut de la boite rangée\n");
    S.une_case[C.x][C.y+2].val = 42;
    S.une_case[C.x][C.y+1].val = 43;//mainteant sur zone de charge
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite rangée vers vide
  printf("boite rangée vers vide\n");
  S.une_case[C.x][C.y+2].val = 36;
  S.une_case[C.x][C.y+1].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_haut_zr(COORD C,SOKOBAN S){

  S.une_case[C.x][C.y+1].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_haut(SOKOBAN S){
  COORD C;
  C = parcourir(S);
  switch(S.une_case[C.x][C.y+1].val) {
    case 35://mur #
    printf("ya un mur en haut\n");
    break;
    case 36: //boite $
    printf("ya une boite en haut\n");
    S=mouvement_haut_boite(C,S);
    break;
    case 42://boite rangée
    printf("ya une boite rangée en haut\n");
    S=mouvement_haut_boite_rangee(C,S);
    break;
    case 46://zone de rangement
    S=mouvement_haut_zr(C,S);
    break;
    default: //tous les autres cas
    S.une_case[C.x][C.y+1].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    break;
  }
  return S;
}
SOKOBAN mouvement_droit_boite(COORD C,SOKOBAN S){
  if((S.une_case[C.x+2][C.y].val == 35) || (S.une_case[C.x+2][C.y].val == 42) || (S.une_case[C.x+2][C.y].val == 36)){ //mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("obstacle a droite de la boite\n");
    return S;
  }
  if(S.une_case[C.x+2][C.y].val == 46){//boite vers emplacement
    S.une_case[C.x+2][C.y].val = 42;
    S.une_case[C.x+1][C.y].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite vers vide
  printf("boite vers vide\n");
  S.une_case[C.x+2][C.y].val = 36;
  S.une_case[C.x+1][C.y].val = 64;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_droit_boite_rangee(COORD C,SOKOBAN S){
  if((S.une_case[C.x+2][C.y].val == 35) || (S.une_case[C.x+2][C.y].val == 42) || (S.une_case[C.x+2][C.y].val == 36)){//mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("ya un mur a droite de la boite rangée\n");
    return S;
  }
  if(S.une_case[C.x+2][C.y].val == 46){//boite rangée vers emplacement
    printf("emplacement a droite de la boite rangée\n");
    S.une_case[C.x+2][C.y].val = 42;
    S.une_case[C.x+1][C.y].val = 43;//mainteant sur zone de charge
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite rangée vers vide
  printf("boite rangée vers vide\n");
  S.une_case[C.x+2][C.y].val = 36;
  S.une_case[C.x+1][C.y].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_droit_zr(COORD C,SOKOBAN S){

  S.une_case[C.x+1][C.y].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_droit(SOKOBAN S){
  COORD C;
  C = parcourir(S);
  switch(S.une_case[C.x+1][C.y].val) {
    case 35://mur #
    printf("ya un mur a droite\n");
    break;
    case 36: //boite $
    printf("ya une boite a droite\n");
    S=mouvement_droit_boite(C,S);
    break;
    case 42://boite rangée
    printf("ya une boite rangée a droite\n");
    S=mouvement_droit_boite_rangee(C,S);
    break;
    case 46://zone de rangement
    S=mouvement_droit_zr(C,S);
    break;
    default: //tous les autres cas
    S.une_case[C.x+1][C.y].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    break;
  }
  return S;
}

SOKOBAN mouvement_bas_boite(COORD C,SOKOBAN S){
  if((S.une_case[C.x][C.y-2].val == 35) || (S.une_case[C.x][C.y-2].val == 42) || (S.une_case[C.x][C.y-2].val == 36)){ //mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("obstacle en bas de la boite\n");
    return S;
  }
  if(S.une_case[C.x][C.y-2].val == 46){//boite vers emplacement
    S.une_case[C.x][C.y-2].val = 42;
    S.une_case[C.x][C.y-1].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite vers vide
  printf("boite vers vide\n");
  S.une_case[C.x][C.y-2].val = 36;
  S.une_case[C.x][C.y-1].val = 64;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_bas_boite_rangee(COORD C,SOKOBAN S){
  if((S.une_case[C.x][C.y-2].val == 35) || (S.une_case[C.x][C.y-2].val == 42) || (S.une_case[C.x][C.y-2].val == 36)){//mur ou boite ou boite rangée a gauche de la boite = mouvement impossible
    printf("ya un mur en bas de la boite rangée\n");
    return S;
  }
  if(S.une_case[C.x][C.y-2].val == 46){//boite rangée vers emplacement
    printf("emplacement en bas de la boite rangée\n");
    S.une_case[C.x][C.y-2].val = 42;
    S.une_case[C.x][C.y-1].val = 43;//mainteant sur zone de charge
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    return S;
  }
  //boite rangée vers vide
  printf("boite rangée vers vide\n");
  S.une_case[C.x][C.y-2].val = 36;
  S.une_case[C.x][C.y-1].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_bas_zr(COORD C,SOKOBAN S){

  S.une_case[C.x][C.y-1].val = 43;
  if(S.une_case[C.x][C.y].val == 43){
    S.une_case[C.x][C.y].val = 46;
  }
  else S.une_case[C.x][C.y].val = 0;
  return S;
}

SOKOBAN mouvement_bas(SOKOBAN S){
  COORD C;
  C = parcourir(S);
  switch(S.une_case[C.x][C.y-1].val) {
    case 35://mur #
    printf("ya un mur en bas\n");
    break;
    case 36: //boite $
    printf("ya une boite en bas\n");
    S=mouvement_bas_boite(C,S);
    break;
    case 42://boite rangée
    printf("ya une boite rangée en bas\n");
    S=mouvement_bas_boite_rangee(C,S);
    break;
    case 46://zone de rangement
    S=mouvement_bas_zr(C,S);
    break;
    default: //tous les autres cas
    S.une_case[C.x][C.y-1].val = 64;
    if(S.une_case[C.x][C.y].val == 43){
      S.une_case[C.x][C.y].val = 46;
    }
    else S.une_case[C.x][C.y].val = 0;
    break;
  }
  return S;
}

SOKOBAN jouer(ACTION A,SOKOBAN S){
  switch (A.fleche) {
    case 270:
    S = mouvement_gauche(S);
    break;
    case 0:
    S = mouvement_haut(S);
    break;
    case 90:
    S = mouvement_droit(S);
    break;
    case 180:
    S = mouvement_bas(S);
    break;
    default:
    break;
  }
  attendre(155); //pour eviter que le personnage ne traverse l'écran en une seconde
  return S;
}

ACTION test_victoire(SOKOBAN S, ACTION A){ //prends une action et un sokoban si le test est faut renvoi l'action inchangée
  /*int x;
  int y;
  int win = 1;

  for(x = 0; x < 100; x++){
    for( y = 0; y < 100; y++){
      if(S.une_case[x][y].val == 36){ //si il reste un caisse normale
        printf("pas win");
        win = 0;
      }
    }
  }

  if (win == 1) {
    printf("win");
    A.mode = VICTOIRE;
    return A;
  }
*/
return A;
}

SOKOBAN victoire(SOKOBAN S,char* str){
  if(S.niveau < 50){
    S.niveau++;
    S = cleanup(S);
    return initialiser_sokoban(str,S);
  }
  return S;
}

SOKOBAN modifier_sokoban_action(SOKOBAN S, ACTION A, char* str){

  if(A.mode == UNDO){
    S = undo(S);
    return S;
  }

  if(A.mode == REDO){
    return redo(S);
  }

  if(A.mode == INIT){
    sauvegarder(S);
    return init(S,str);
  }

  if(A.mode == PREC){
    sauvegarder(S);
    return prec(S,str);
  }

  if(A.mode == SUIV){
    sauvegarder(S);
    return suiv(S,str);
  }

  if(A.mode == JOUER){
    sauvegarder(S);
    return jouer(A,S);
  }

  if(A.mode == VICTOIRE){
    sauvegarder(S);
    return victoire(S,str);
  }

  return S;
}
