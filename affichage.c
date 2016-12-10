#include <uvsqgraphics.h>
#include "affichage.h"
#include "constantes.h"
#incude "sokoban.h"


void initialiser_affichage(){
  init_graphics(LARGEUR_FENETRE, HAUTEUR_FENETRE);
  affiche_auto_off();
}

void afficher_case(SOKOBAN S, int x,int y){
  POINT bg,hd,centre;
  bg.x = x * TAILLE_CASE;
  bg.y = y * TAILLE_CASE;
  hd.x = bg.x + TAILLE_CASE;
  hd.y = bg.y + TAILLE_CASE;
  centre.x = (bg.x + hd.x) / 2;
  centre.y = (bg.y + hd.y) / 2;
  draw_fill_rectangle(bg, hd, COUL_FOND);
  draw_rectangle(bg, hd, COUL_BORD);
  
  /*
  
  AFFICHAGE CONTENU CASE
  
  
  */
}


void affiche_separation_blocks(){
  
  /*        */
  
}

void affiche_niveau(SOKOBAN S){
  
  int x, y;
  for(x = 0; x < N; x++){
    for(y = 0; y < N; y++){
      afficher_case(S, x, y);
      
    affiche_separation_blocks()
  
}
