#include "automate.h"

void automate::decalage(Symbole s, Etat *e)
{
	symbolstack.push(s);
	statestack.push(e);
}

void automate::reduction(int n, Symbole s)
{
	for (int i = 0; i < n; i++)
	{
		delete (statestack.top());
		statestack.pop();
	}
	transition(s);
}

void automate::transition(Symbole s)
{
	statestack.top()->transition(*this, s);
}

void automate::pushSymbol(Symbole s)
{
	symbolstack.push(s);
}

Symbole automate::popSymbol()
{
	auto s = symbolstack.top();
	symbolstack.pop();
	return s;
}
