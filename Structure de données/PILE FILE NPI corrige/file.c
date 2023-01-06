#include "file.h"
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX_FILE 100
struct str_file {
    int premier;
    int dernier;
    type_element_file valeurs[TAILLE_MAX_FILE];
};





// Primitives
file * creerFile(void) {
   file * f = malloc(sizeof(*f));
    f->premier = 0;
    f->dernier = 0;
    return f;
}





bool filePleine(file * f) {
    return (f->premier == 0 && f->dernier == TAILLE_MAX_FILE - 1) || f->premier == f->dernier + 1;
}
void enfiler(file * f, type_element_file e) {
    if (!filePleine(f)) {
        f->valeurs[f->dernier++] = e;
        if (f->dernier == TAILLE_MAX_FILE) {
            f->dernier = 0;
        }
    } else {
        printf("ERREUR : dépassement de capacité de la file\n");
        exit(EXIT_FAILURE);
    }
}



type_element_file defiler(file * f) {
    if (!fileVide(f)) {
        type_element_file resultat = f->valeurs[f->premier++];
        if (f->premier == TAILLE_MAX_FILE) {
            f->premier = 0;
        }
        return resultat;
    } else {
        printf("ERREUR : défilement d'une file vide\n");
        exit(EXIT_FAILURE);
    }
}


type_element_file premier(file * f ) {
    if (!fileVide(f)) {
        return f->valeurs[f->premier];



    } else {
        printf("ERREUR : premier d'une file vide\n");
        exit(EXIT_FAILURE);
    }
}





bool fileVide(file * f) {
    return f->premier == f->dernier;
}
int tailleFile(file * f ) {
    if (f->premier<=f->dernier) {
        return f->dernier - f->premier;
    } else {
        return TAILLE_MAX_FILE + f->dernier - f->premier;
    }
}
