#ifndef ___CONSTANTES_H
#define ___CONSTANTES_H

#define N 14

#define TAILLE_CASE 28
#define LARGEUR_BOUTON ((N*TAILLE_CASE)/6)
#define HAUTEUR_BOUTON (TAILLE_CASE)
#define LARG_FENETRE (N*TAILLE_CASE)
#define HAUT_FENETRE (N*TAILLE_CASE + HAUTEUR_BOUTON)
#define TAILLE_POLICE 18

#define VIDE 0

#define UNDO 1
#define REDO 2
#define INIT 3
#define PREC 4
#define SUIV 5
#define QUIT 6
#define JOUER 7

#define COUL_BORD cadetblue
#define COUL_FOND darkslategray

#define STACK_MAX 1000
#define IS_EMPTY -1
#define IS_FULL 1
#define NOR_EMPTY_NOR_FULL 0
#endif
