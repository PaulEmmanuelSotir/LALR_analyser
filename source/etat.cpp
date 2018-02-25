#include "etat.h"
#include "symbol.h"
#include "automate.h"

// TODO: surcharger << à la place
void print() {}

bool E0::transition(Automate &automate, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		automate.decalage(s, new E3);
		break;
	case Symbols::OPENPAR:
		automate.decalage(s, new E2);
		break;
	case Symbols::EXPR:
		automate.decalage(s, new E1);
		break;
	default:
		break;
	}
	return false;
}

bool E1::transition(Automate &automate, Symbol s) const
{
	switch (s)
	{
	case Symbols::PLUS:
		automate.decalage(s, new E4);
		break;
	case Symbols::MULT:
		automate.decalage(s, new E5);
		break;
	case Symbols::END:
		return true; // accepter
	default:
		break;
	}
	return false;
}

bool E2::transition(Automate &automate, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		automate.decalage(s, new E3);
		break;
	case Symbols::OPENPAR:
		automate.decalage(s, new E2);
		break;
	default:
		break;
	}
	return false;
}

bool E3::transition(Automate &automate, Symbol s) const
{
	// Reduction 5
	automate.pushSymbol(s); // LR(1), on ne consomme pas ce Symbol
	Symbol s1 = automate.popSymbol();
	automate.reduction(1, Symbol(Symbols::EXPR));
}

bool E4::transition(Automate &automate, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		automate.decalage(s, new E3);
		break;
	case Symbols::OPENPAR:
		automate.decalage(s, new E2);
		break;
	default:
		break;
	}
	return false;
}

bool E5::transition(Automate &automate, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		automate.decalage(s, new E3);
		break;
	case Symbols::OPENPAR:
		automate.decalage(s, new E2);
		break;
	default:
		break;
	}
	return false;
}

bool E6::transition(Automate &automate, Symbol s) const
{
	switch (s)
	{
	case Symbols::PLUS:
		automate.decalage(s, new E4);
		break;
	case Symbols::MULT:
		automate.decalage(s, new E5);
		break;
	case Symbols::CLOSEPAR:
		automate.decalage(s, new E9);
		break;
	default:
		break;
	}
	return false;
}

bool E7::transition(Automate &automate, Symbol s) const
{
	switch (s)
	{
	case Symbols::MULT:
		automate.decalage(s, new E5);
		break;
	default:
		// Reduction 2
		automate.pushSymbol(s); // LR(1), on ne consomme pas ce Symbol
		Symbol s1 = automate.popSymbol();
		automate.popSymbol();
		Symbol s2 = automate.popSymbol();
		automate.reduction(3, Symbol(Symbols::EXPR));
		break;
	}
	return false;
}

bool E8::transition(Automate &automate, Symbol s) const
{
	// Reduction 3
	automate.pushSymbol(s); // LR(1), on ne consomme pas ce Symbol
	Symbol s1 = automate.popSymbol();
	automate.popSymbol();
	Symbol s2 = automate.popSymbol();
	automate.reduction(3, Symbol(Symbols::EXPR));
	return false;
}

bool E9::transition(Automate &automate, Symbol s) const
{
	// Reduction 4
	automate.pushSymbol(s); // LR(1), on ne consomme pas ce Symbol
	automate.popSymbol();
	Symbol s1 = automate.popSymbol();
	automate.popSymbol();
	automate.reduction(3, Symbol(Symbols::EXPR));
	return false;
}
