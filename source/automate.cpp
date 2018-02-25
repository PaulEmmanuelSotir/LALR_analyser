#include "automate.h"

void Automate::decalage(Symbol s, Etat *e)
{
	symbolstack.push(s);
	statestack.push(e);
}

void Automate::reduction(int n, Symbol s)
{
	for (int i = 0; i < n; i++)
	{
		delete(statestack.top());
		statestack.pop();
	}
	transition(s);
}

void Automate::transition(Symbol s)
{
	statestack.top()->transition(*this, s);
}

void Automate::pushSymbol(Symbol s)
{
	symbolstack.push(s);
}

Symbol Automate::popSymbol()
{
	auto s = symbolstack.top();
	symbolstack.pop();
	return s;
}
