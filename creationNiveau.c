///////////////////////////////
//    NOM : JACQUET          //
//    PRENOM : Julien        //
//    NUMERO ET : 21400579   //
///////////////////////////////

#include <uvsqgraphics.h>
#include "constantes.h"
#include "creationNiveau.h"

void initialiser_affichageCreation()
{
	init_graphics((NBR_CASES * TAILLE_CASE),
		      (NBR_CASES * TAILLE_CASE + HAUTEUR_BOUTON));
}

void dessine_contenu_case_creation(STRUCTURE_CREATION_NIVEAU C, int x, int y,
				   POINT centre, POINT bg, POINT hd)
{
	switch (C.C.une_case[x][y].val) {
	case 35:		//'#'
		draw_fill_rectangle(bg, hd, lightcoral);
		draw_line(bg, hd, black);
		draw_rectangle(bg, hd, black);
		bg.x += TAILLE_CASE;
		hd.x -= TAILLE_CASE;
		draw_line(bg, hd, black);
		break;
	case 36:		//'$'
		draw_fill_rectangle(bg, hd, marron);
		draw_line(bg, hd, black);
		bg.x += TAILLE_CASE;
		hd.x -= TAILLE_CASE;
		draw_line(bg, hd, black);
		break;
	case 42:		//'*'
		draw_fill_rectangle(bg, hd, yellow);
		draw_rectangle(bg, hd, indigo);
		break;
	case 43:		//'+'
		draw_fill_circle(centre, TAILLE_POLICE - 5, yellow);
		break;
	case 46:		//'.'
		draw_fill_rectangle(bg, hd, indigo);
		draw_rectangle(bg, hd, yellow);
		break;
	case 64:		//'@'
		draw_fill_circle(centre, TAILLE_POLICE - 5, blue);
		break;
	default:
		draw_fill_rectangle(bg, hd, COUL_FOND);
		draw_rectangle(bg, hd, COUL_BORD);
	}
}

void afficher_une_case_creation(STRUCTURE_CREATION_NIVEAU C, int x, int y)
{

	POINT bg, hd, centre;
	bg.x = x * TAILLE_CASE;
	bg.y = y * TAILLE_CASE;
	hd.x = bg.x + TAILLE_CASE;
	hd.y = bg.y + TAILLE_CASE;
	centre.x = (bg.x + hd.x) / 2;
	centre.y = (bg.y + hd.y) / 2;

	dessine_contenu_case_creation(C, x, y, centre, bg, hd);

}

void affiche_niveauCreation(STRUCTURE_CREATION_NIVEAU C)
{
	int x, y;

	for (x = 0; x < NBR_CASES; x++) {
		for (y = 0; y < NBR_CASES; y++) {
			afficher_une_case_creation(C, x, y);
		}
	}
}

void affiche_bouton_creation(int rang, char *texte, int etat)
{

	COULEUR coul_texte = ghostwhite;

	POINT bg, hd, centre;
	bg.x = rang * ((NBR_CASES * TAILLE_CASE) / 6);
	bg.y = (NBR_CASES * TAILLE_CASE + HAUTEUR_BOUTON) - HAUTEUR_BOUTON;
	hd.x = bg.x + ((NBR_CASES * TAILLE_CASE) / 6);
	hd.y = bg.y + HAUTEUR_BOUTON;
	centre.x = (bg.x + hd.x) / 2;
	centre.y = (bg.y + hd.y) / 2;

	draw_fill_rectangle(bg, hd, COUL_FOND);
	draw_rectangle(bg, hd, COUL_BORD);
	aff_pol_centre(texte, TAILLE_POLICE, centre, coul_texte);
}

void affiche_bouton_all_creation(STRUCTURE_CREATION_NIVEAU C)
{
	affiche_bouton_creation(0, "mur", C.mode_creation == MUR);
	affiche_bouton_creation(1, "caisse", C.mode_creation == CAISSE);
	affiche_bouton_creation(2, "personnage", C.mode_creation == PERSONNAGE);
	affiche_bouton_creation(3, "perso sur emplacement",
				C.mode_creation == PERSONNAGE_SUR_EMPLACEMENT);
	affiche_bouton_creation(4, "caisse sur emplacement",
				C.mode_creation == CAISSE_SUR_EMPLACEMENT);
	affiche_bouton_creation(5, "emplacement",
				C.mode_creation == EMPLACEMENT);
	affiche_bouton_creation(6, "Quit", C.mode_creation == QUIT);
}

void affichage_creation(STRUCTURE_CREATION_NIVEAU C)
{
	fill_screen(noir);
	affiche_auto_off();
	affiche_niveauCreation(C);
	affiche_bouton_all_creation(C);
	affiche_all();
}

STRUCTURE_CREATION_NIVEAU recuperer_mode_creation(STRUCTURE_CREATION_NIVEAU C)
{
	return C;
}

STRUCTURE_CREATION_NIVEAU creation_niveau(char *strCreation)
{
	STRUCTURE_CREATION_NIVEAU C;
	affichage_creation(C);
	recuperer_mode_creation(C);

	return C;
}
