#include <iostream>
#include "symbol.h"

std::ostream& operator<<(std::ostream& os, const Symbol& s)
{
	os << Labels[static_cast<int>(s.id)];
	return os;
}
