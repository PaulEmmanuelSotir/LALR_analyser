#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>

#include "lexer.h"
 
int main(void)
{
	Lexer l("(1+34)*123");

	try
	{
		while(true)
		{
			Symbol s = l.Consult();
			std::cout << s << std::endl;
			if(l.Forward()) {
				std::cout << std::endl << "Valid algebric expression";
				break;
			}
		}
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << std::endl << "Invalid argument: " << e.what();
	}
	return EXIT_SUCCESS;
}
