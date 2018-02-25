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

void Lexer::Forward()
{
	automate.transition(buffer);
	readbuffer = true;
}
