#ifndef pile_h
#define pile_h
#include <stdbool.h> // pour le type bool

// Déclaration du type pile correspondant à une structure str_pile
typedef struct str_pile pile;
// Déclaration du type element = char
typedef unsigned char type_element_pile;

// Primitives
pile * creerPile(void);
void empiler(pile *, type_element_pile);
type_element_pile depiler(pile *);
type_element_pile sommet(pile *);
bool pileVide(pile *);
int taillePile(pile *);

#endif /* pile_h */
