#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <string>

#include "lexer.h"
 
int main(int argc, char* argv[])
{
	std::string str_to_parse = argc <= 1 ? "(1+34)*123+" : std::string(argv[1]);
	Lexer l(str_to_parse);
	std::cout << "Parsing \'" << str_to_parse << "\'..." << std::endl << std::endl;

	try
	{
		while(true)
		{
			Symbol s = l.Consult();
			std::cout << "|> " << s << std::endl;
			if(l.Forward()) {
				std::cout << std::endl << "Valid algebric expression";
				break;
			}
		}
	}
	catch(const std::invalid_argument& e)
	{
		std::cout << std::endl << "Invalid argument: " << e.what();
		l.print_stack();
	}
	return EXIT_SUCCESS;
}
