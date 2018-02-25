#include <stdexcept>
#include "etat.h"
#include "symbol.h"
#include "automate.h"


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
		throw std::invalid_argument("Bad symbol at E0 state");
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
		throw std::invalid_argument("Bad symbol at E1 state");
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
	case Symbols::EXPR:
		automate.decalage(s, new E6);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E2 state");
	}
	return false;
}

bool E3::transition(Automate &automate, Symbol s) const
{
	// Reduction 5
	automate.reduction(1, s);
	return false;
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
	case Symbols::EXPR:
		automate.decalage(s, new E7);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E4 state");
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
	case Symbols::EXPR:
		automate.decalage(s, new E8);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E5 state");
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
		throw std::invalid_argument("Bad symbol at E6 state");
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
		automate.reduction(3, s);
		break;
	}
	return false;
}

bool E8::transition(Automate &automate, Symbol s) const
{
	// Reduction 3
	automate.reduction(3, s);
	return false;
}

bool E9::transition(Automate &automate, Symbol s) const
{
	// Reduction 4
	automate.reduction(3, s);
	return false;
}
