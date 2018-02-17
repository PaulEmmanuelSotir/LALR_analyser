#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <stack>
#include "etat.h"
#include "symbole.h"

class Automate {
	public:
		Automate()  { statestack.push(new E0()); };
		void decalage(Symbole s, Etat* e);
		void reduction(int n, Symbole s);
		void transition(Symbole s);
		void pushSymbol(Symbole s);
		Symbole popSymbol();
	private:
		std::stack<Symbole> symbolstack;
		std::stack<Etat*> statestack;
};

#endif
