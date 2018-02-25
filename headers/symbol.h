#ifndef Symbol_H
#define Symbol_H
#include <iostream>
#include <string>

enum class Symbols { OPENPAR, CLOSEPAR, PLUS, MULT, INT, END, EXPR, ERROR }; 
const std::string Labels[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "END", "EXPR", "ERROR" };

class Symbol {
public:
	Symbol(Symbols id) : id(id) { }
	operator Symbols() const { return id; };
	friend std::ostream& operator<<(std::ostream& os, const Symbol& s);

protected:
	Symbols id;
	
};

#endif