#include <uvsqgraphics.h>
#include "affichage.h"
#include "lecture_ecriture.h"




void initialiser_affichage(int LARG, int HAUT){
  init_graphics(LARG*TAILLE_CASE, (HAUT*TAILLE_CASE+HAUTEUR_BOUTON));
}

void dessine_contenu_case(SOKOBAN S, int x, int y, POINT centre, POINT bg, POINT hd){

  switch(S.une_case[x][y].val){
    case 35: //'#'
        draw_fill_rectangle(bg, hd, lightcoral);
        draw_line(bg, hd, black);
        bg.x+=TAILLE_CASE;
        hd.x-=TAILLE_CASE;
        draw_line(bg, hd, black);
        break;
    case 36: //'$'
        draw_fill_rectangle(bg, hd, marron);
        draw_line(bg, hd, black);
        bg.x+=TAILLE_CASE;
        hd.x-=TAILLE_CASE;
        draw_line(bg, hd, black);
        break;
    case 46: //'.'
        draw_fill_rectangle(bg,hd,indigo);
        draw_rectangle(bg, hd, yellow);
        break;
    case 64: //'@'
        draw_fill_circle(centre, TAILLE_POLICE-5, blue);
        break;
    default :
    draw_fill_rectangle(bg, hd, COUL_FOND);
    draw_rectangle(bg, hd, COUL_BORD);
  }
}

void afficher_une_case(SOKOBAN S, int x,int y){

  POINT bg,hd,centre;
  bg.x = x * TAILLE_CASE;
  bg.y = y * TAILLE_CASE;
  hd.x = bg.x + TAILLE_CASE;
  hd.y = bg.y + TAILLE_CASE;
  centre.x = (bg.x + hd.x) / 2;
  centre.y = (bg.y + hd.y) / 2;

  dessine_contenu_case(S, x, y, centre, bg, hd);

}


void affiche_niveau(SOKOBAN S,int LARG,int HAUT){

  int x,y;

    for(x = 0; x < LARG; x++){
      for(y = 0; y < HAUT; y++){
      afficher_une_case(S, x, y);
    }
  }
}

void affiche_bouton(int rang, char *texte, int etat,int LARG, int HAUT){

  COULEUR coul_texte = ghostwhite;

    POINT bg, hd, centre;
    bg.x = rang * ((LARG*TAILLE_CASE)/6);
    bg.y = (HAUT*TAILLE_CASE+HAUTEUR_BOUTON) - HAUTEUR_BOUTON;
    hd.x = bg.x + ((LARG*TAILLE_CASE)/6);
    hd.y = bg.y + HAUTEUR_BOUTON;
    centre.x = (bg.x + hd.x) / 2;
    centre.y = (bg.y + hd.y) / 2;

    draw_fill_rectangle(bg, hd, COUL_FOND);
    draw_rectangle(bg, hd ,COUL_BORD);
    aff_pol_centre(texte, TAILLE_POLICE, centre, coul_texte);
}

void affiche_bouton_all(SOKOBAN S,int LARG, int HAUT)
{

  affiche_bouton(0,"Undo", S.mode == UNDO, LARG, HAUT);
  affiche_bouton(1,"Redo", S.mode == REDO, LARG, HAUT);
  affiche_bouton(2,"Init", S.mode == INIT, LARG, HAUT);
  affiche_bouton(3,"Precedent", S.mode == PREC, LARG, HAUT);
  affiche_bouton(4,"Suivant", S.mode == SUIV, LARG, HAUT);
  affiche_bouton(5,"Quit", S.mode == QUIT, LARG, HAUT);
}

void afficher_sokoban(SOKOBAN S,int LARG,int HAUT){
  fill_screen(noir);
  affiche_auto_off();
  affiche_niveau(S,LARG,HAUT);
  affiche_bouton_all(S,LARG,HAUT);
  affiche_all();
}
