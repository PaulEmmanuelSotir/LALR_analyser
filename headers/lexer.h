#ifndef LEXER_H
#define LEXER_H
#include <stack>
#include <string>
#include "symbol.h"
#include "etat.h"

// TODO: fusionner autommate et lexer
class Lexer
{
public:
	Lexer(std::string s) : stream(s) { statestack.push(new E0()); };
	Symbol Consult();
	bool Forward();
	void shift(Symbol s, Etat *e);
	bool reduction(int n, Symbol s);

private:
	bool transition(Symbol s);

	std::stack<Etat*> statestack;
	std::stack<Symbol> symbolstack;
	Symbol buffer = Symbol(Symbols::ERROR);
	bool readbuffer = true;
	std::string stream;
	size_t head = 0;
};

#endif
