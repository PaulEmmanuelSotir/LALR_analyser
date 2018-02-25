#ifndef LEXER_H
#define LEXER_H
#include <string>
#include "symbol.h"
#include "automate.h"

// TODO: fusionner autommate et lexer
class Lexer
{
public:
	Lexer(std::string s) : stream(s){};
	Symbol Consult();
	void Forward();

protected:
	std::string stream;
	size_t head = 0;
	Symbol buffer = Symbol(Symbols::ERROR);
	bool readbuffer = true;
	Automate automate;
};

#endif
