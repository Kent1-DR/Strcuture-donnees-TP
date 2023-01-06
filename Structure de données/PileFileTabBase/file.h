#ifndef file_h
#define file_h
#include <stdbool.h> // pour le type bool

// Déclaration du type file correspondant à une structure str_file
typedef struct str_file file;
// Déclaration du type element = unsigned char
typedef unsigned char type_element_file;

// Primitives
file * creerFile(void);
void enfiler(file *, type_element_file);
type_element_file defiler(file *);
type_element_file premier(file *);
bool fileVide(file *);
int tailleFile(file *);

#endif /* file_h */
