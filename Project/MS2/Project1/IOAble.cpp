#include <iostream>
#include <fstream>
#include "IOAble.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const IOAble& output)
	{
		return output.write(ostr);
	};
	std::istream& operator>>(std::istream& istr, IOAble& input)
	{
		return input.read(istr);
	};
};
