#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <stack>
#include "etat.h"
#include "symbol.h"

class Automate
{
  public:
	Automate() { statestack.push(new E0()); };
	void decalage(Symbol s, Etat *e);
	void reduction(int n, Symbol s);
	bool transition(Symbol s);
	void pushSymbol(Symbol s);
	Symbol popSymbol();

  private:
	std::stack<Symbol> symbolstack;
	std::stack<Etat*> statestack;
};

#endif
