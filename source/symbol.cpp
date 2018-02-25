#include <iostream>
#include "symbol.h"

void Symbol::Print() const
{
	std::cout << Labels[static_cast<int>(id)];
}
