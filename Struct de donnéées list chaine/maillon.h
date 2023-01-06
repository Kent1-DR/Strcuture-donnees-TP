// Déclaration du type abstrait maillon
#ifndef maillon_h
#define maillon_h

#include <stdbool.h>

// Tout ce qui n'est pas dans maillon.h est encapsulé : liste est un type abstrait de données.
// Déclaration du type maillon : encapsultation => on ne l'implante pas ici
typedef struct maillon maillon;

// Type des clés
typedef unsigned char type_cle;

// Constructeur d'un maillon sans spécifier la valeur de sa cle et qui sera son propre suivant
maillon * creerMaillonVide(void);

// Constructeur d'un maillon en indiquant son suivant et la valeur de sa clé
maillon * creerMaillon(maillon * suivant, type_cle cle);

// Insertion d'un nouveau maillon contenant la valeur cle, positionné aprés m,
// et renvoi de ce nouveau maillon
maillon * insererApres(maillon * m, type_cle cle);

// Suppression du maillon situé après m, renvoi de la valeur de sa clé et libération
// de la mémoire allouée au maillon supprimé
type_cle supprimerSuivant(maillon * m);

// Renvoie l'adresse du maillon suivant de m
maillon * getSuivant(maillon * m);

// Modifie le suivant de m : il prend la valeur de s
void setSuivant(maillon * m, maillon * s);

// Observateur de la valeur de la clé d'un maillon
type_cle getCle(maillon * m);

// Modifie la clé de m : elle prend la valeur de cle
void setCle(maillon * m, type_cle cle);

#endif /* maillon_h */
