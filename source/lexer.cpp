#include "lexer.h"

Symbol Lexer::Consult()
{
	if(readbuffer)
	{
		if(head != stream.length())
		{
			switch(stream[head])
			{
			case '(':
				buffer = Symbol(Symbols::OPENPAR);
				head++;
				break;
			case ')':
				buffer = Symbol(Symbols::CLOSEPAR);
				head++;
				break;
			case '*':
				buffer = Symbol(Symbols::MULT);
				head++;
				break;
			case '+':
				buffer = Symbol(Symbols::PLUS);
				head++;
				break;
			default:
				if(stream[head] <= '9' && stream[head] >= '0')
				{
					int resultat = stream[head] - '0';
					int i = 1;
					while (stream[head + i] <= '9' && stream[head + i] >= '0')
					{
						resultat = resultat * 10 + (stream[head + i] - '0');
						i++;
					}
					head = head + i;
					buffer = Symbol(Symbols::INT); // Integer(resultat); TODO: implement integer and expr classes?
				}
				else
					buffer = Symbol(Symbols::ERROR);
			}
		}
		else
			buffer = Symbol(Symbols::END);
		readbuffer = false;
	}
	return buffer;
}

bool Lexer::Forward()
{
	readbuffer = true;
	return transition(buffer);
}

void Lexer::shift(Symbol s, Etat *e)
{
	symbolstack.push(s);
	statestack.push(e);
}

bool Lexer::reduction(int n, Symbol s)
{
	for (int i = 0; i < n; i++)
	{
		delete(statestack.top());
		statestack.pop();
		symbolstack.pop();
	}
	transition(Symbol(Symbols::EXPR));
	return transition(s);
}

bool Lexer::transition(Symbol s)
{
	return statestack.top()->transition(*this, s);
}

void Lexer::print_stack()
{
	std::cout << std::endl << "#### Symbol stack ####" << std::endl; 
	while(!symbolstack.empty())
	{
		std::cout << ">\t" << symbolstack.top() << std::endl;
		symbolstack.pop();
	}
}
