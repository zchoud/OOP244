//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/27/2021
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
