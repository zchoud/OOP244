//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Shape.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape)
	{
		shape.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& shape)
	{
		shape.getSpecs(istr);
		return istr;
	}
}