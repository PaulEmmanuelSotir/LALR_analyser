#ifndef Symbol_H
#define Symbol_H
#include <string>

enum class Symbols { OPENPAR, CLOSEPAR, PLUS, MULT, INT, END, EXPR, ERROR }; 
const std::string Labels[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "END", "EXPR", "ERROR" };

class Symbol {
public:
	Symbol(Symbols id) : id(id) { }
	operator Symbols() const { return id; };
	void Print() const;

protected:
	Symbols id;
};

#endif