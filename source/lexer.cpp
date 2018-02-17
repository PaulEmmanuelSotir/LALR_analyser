#include "lexer.h"

Symbole Lexer::Consulter() {
	if (readTampon) {
		if (tete == flux.length())
			tampon = Symbole(FIN);
		else
		{
			switch (flux[tete]) {
				case '(':
					tampon = Symbole(OPENPAR);
					tete++;
					break;
				case ')':
					tampon = Symbole(CLOSEPAR);
					tete++;
					break;
				case '*':
					tampon = Symbole(MULT);
					tete++;
					break;
				case '+':
					tampon = Symbole(PLUS);
					tete++;
					break;
				default:
					if (flux[tete] <= '9' && flux[tete] >= '0') {
						int resultat = flux[tete] - '0';
						int i = 1;
						while (flux[tete+i] <= '9' && flux[tete+i] >= '0') {
							resultat = resultat * 10 + (flux[tete+i] - '0');
							i++;
						}
						tete = tete + i;
						tampon = Entier(resultat);
					}
					else {
						tampon = Symbole(ERREUR);
					}
			}
		}
	}
	return tampon;
}

void Lexer::Avancer() {
	automate.transition(tampon);
	readTampon = true;
}

