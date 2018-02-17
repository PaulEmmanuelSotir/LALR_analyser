#include <iostream>
#include <cstdlib>
#include <string>
#include "lexer.h"

int main(void) {
	Lexer l("(1+34)*123");

	Symbole s = l.Consulter();
	while(s != FIN) {
		s.Affiche();
		std::cout << std::endl;
		l.Avancer();
		Symbole s = l.Consulter();
	}
	return EXIT_SUCCESS;
}

