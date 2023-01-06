#include "file.h"
#include <stdlib.h>
#include <stdio.h>

#define TAILLE_MAX_FILE 10
struct str_file {
    int premier;
    int dernier;
    type_element_file valeurs[TAILLE_MAX_FILE];
};

// Primitives
file * creerFile(void) {
    file * f = (file *) malloc(sizeof(file));
    f->premier = 0;
    f->dernier = 0;
    return f;
}
bool filePleine(file * f) {
    
    return true;
}
void enfiler(file * f, type_element_file e) {
//    ... A COMPLETER ...
}
type_element_file defiler(file * f) {
//    ... A MODIFIER ...
    return 'Z';
}
type_element_file premier(file * f ) {
//    ... A MODIFIER ...
    return 'Z';
}
bool fileVide(file * f) {
//    ... A MODIFIER ...
    return false;
}
int tailleFile(file * f ) {
//    ... A MODIFIER ...
    return -5;
}
