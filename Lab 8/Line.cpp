//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Shape.h"
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line()
	{
		m_length = 0;
	}

	Line::Line(const char* label, int length) :LblShape(label) {
		m_length = length;
	}

	void Line::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		int length;
		if (!(istr >>length)) cout << "not a length value" << endl;
		istr.ignore(1000, '\n');
		m_length = length;
	}

	void Line::draw(std::ostream& ostr) const
	{
		if (m_length > 0 && label())
		{
			ostr << label() << endl;
			ostr << "=" << setw(m_length - 1) << setfill('=') << "=";
		}
	}
}