#ifndef LEXER_H
#define LEXER_H
#include <string>
#include "symbole.h"
#include "automate.h"

// TODO: fusionner autommate et lexer
class Lexer {
	public:
		Lexer(std::string s) : flux(s) { };
		Symbole Consulter();
		void Avancer();

	protected:
		std::string flux;
		int tete = 0;
		Symbole tampon = Symbole(ERREUR);
		bool readTampon = false;
		Automate automate;
};

#endif
