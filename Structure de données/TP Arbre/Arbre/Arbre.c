#include "Arbre.h"
#include <stdlib.h>
#include <stdio.h>

struct arbre
{
	TypeElement valeur;
	struct arbre* filsgauche;
	struct arbre* filsdroit;
};

arbre* creerArbreVide(void) {

	arbre* ArbreVide = (arbre*)malloc(sizeof(struct arbre));
	ArbreVide->filsgauche = ArbreVide->filsdroit = ArbreVide;
	return ArbreVide;
}

arbre* creerArbre(arbre* filsgauche,TypeElement * valeur,arbre* filsdroit) {

	arbre* Arbre = (arbre*)malloc(sizeof(struct arbre));

	//on créé 2 arbres vide de chaque coté
	arbre* droite = creerArbreVide();
	arbre* gauche = creerArbreVide();

	//on définit la valeur de chaque coté 
	Arbre->filsdroit = droite;
	Arbre->filsgauche = gauche;
	return Arbre;
}

arbre* LectureFG(arbre* Arbre)
{
	arbre* gauche = Arbre->filsgauche;
	return gauche;
}


arbre* LectureFD(arbre* Arbre)
{
	arbre* droite = Arbre->filsdroit;
	return droite;
}

TypeElement LectureValeur(arbre* Arbre)
{
	TypeElement val = Arbre->valeur;
	return val;
}


bool EstVide(arbre* Arbre)
{
	Arbre->filsgauche = Arbre->filsdroit = Arbre;
	return true;
}



arbre* ParcourirLargeur(arbre* Arbre)
{

}


