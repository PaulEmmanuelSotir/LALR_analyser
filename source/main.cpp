#include <iostream>
#include <cstdlib>
#include <string>

#include "lexer.h"
 
int main(void)
{
	Lexer l("(1+34)*123");

	Symbol s = l.Consult();
	while (static_cast<Symbols>(s) != Symbols::END)
	{
		s.Print();
		std::cout << std::endl;
		l.Forward();
		s = l.Consult();
	}
	return EXIT_SUCCESS;
}
