#include <stdexcept>
#include "etat.h"
#include "symbol.h"
#include "lexer.h"


bool E0::transition(Lexer &lexer, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		lexer.shift(s, new E3);
		break;
	case Symbols::OPENPAR:
		lexer.shift(s, new E2);
		break;
	case Symbols::EXPR:
		lexer.shift(s, new E1);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E0 state");
	}
	return false;
}

bool E1::transition(Lexer &lexer, Symbol s) const
{
	switch (s)
	{
	case Symbols::PLUS:
		lexer.shift(s, new E4);
		break;
	case Symbols::MULT:
		lexer.shift(s, new E5);
		break;
	case Symbols::END:
		return true; // accepter
	default:
		throw std::invalid_argument("Bad symbol at E1 state");
	}
	return false;
}

bool E2::transition(Lexer &lexer, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		lexer.shift(s, new E3);
		break;
	case Symbols::OPENPAR:
		lexer.shift(s, new E2);
		break;
	case Symbols::EXPR:
		lexer.shift(s, new E6);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E2 state");
	}
	return false;
}

bool E3::transition(Lexer &lexer, Symbol s) const
{
	// Reduction 5
	return lexer.reduction(1, s);;
}

bool E4::transition(Lexer &lexer, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		lexer.shift(s, new E3);
		break;
	case Symbols::OPENPAR:
		lexer.shift(s, new E2);
		break;
	case Symbols::EXPR:
		lexer.shift(s, new E7);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E4 state");
	}
	return false;
}

bool E5::transition(Lexer &lexer, Symbol s) const
{
	switch (s)
	{
	case Symbols::INT:
		lexer.shift(s, new E3);
		break;
	case Symbols::OPENPAR:
		lexer.shift(s, new E2);
		break;
	case Symbols::EXPR:
		lexer.shift(s, new E8);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E5 state");
	}
	return false;
}

bool E6::transition(Lexer &lexer, Symbol s) const
{
	switch (s)
	{
	case Symbols::PLUS:
		lexer.shift(s, new E4);
		break;
	case Symbols::MULT:
		lexer.shift(s, new E5);
		break;
	case Symbols::CLOSEPAR:
		lexer.shift(s, new E9);
		break;
	default:
		throw std::invalid_argument("Bad symbol at E6 state");
	}
	return false;
}

bool E7::transition(Lexer &lexer, Symbol s) const
{
	switch (s)
	{
	case Symbols::MULT:
		lexer.shift(s, new E5);
		break;
	default:
		// Reduction 2
		return lexer.reduction(3, s);
	}
	return false;
}

bool E8::transition(Lexer &lexer, Symbol s) const
{
	// Reduction 3
	return lexer.reduction(3, s);
}

bool E9::transition(Lexer &lexer, Symbol s) const
{
	// Reduction 4
	return lexer.reduction(3, s);
}
