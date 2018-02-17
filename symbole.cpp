#include <iostream>
#include "symbole.h"

// TODO: surcharger << à la place

void Symbole::Affiche() {
   std::cout << Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   std::cout << "(" << valeur<< ")";
}

