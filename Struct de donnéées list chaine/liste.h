// Déclaration du type abstrait liste
#ifndef liste_h
#define liste_h
#include <stdbool.h>
#include "maillon.h"

// Tout ce qui n'est pas dans liste.h est encapsulé : liste est un type abstrait de données,
// défini uniquement par son nom et les opérations que l'on peut lui appliquer

// Déclaration du type liste : encapsultation => on ne l'implante pas ici
typedef struct liste liste;

// création d'une liste vide
liste * lcCreerListe(void);

// indique si la liste l est vide (true) ou non (false)
bool lcEstVide(liste * l);

// libérer la mémoire occupée par la liste l
void lcFreeListe(liste * l);

// affiche le contenu de la liste l dans l'ordre croissant
void lcParcourir(liste * l);

// Indique si la cle recherchée existe dans la liste l
bool lcContient(liste * l, type_cle cle);

// Insère la valeur cle dans la liste l à un emplacement respectant l'ordre alphabétique
void lcInsererOrdonne(liste * l, type_cle cle);

// Si la valeur de cle est présente dans la liste l, supprime cette valeur de la liste l
// et renvoie vrai, sinon renvoie false
bool lcSupprimerCle(liste * l, type_cle cle);

#endif /* liste_h */
