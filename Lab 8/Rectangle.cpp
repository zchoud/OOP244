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
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height):LblShape(label){
		m_width = width;
		m_height = height;
		if (m_height < 3 || (unsigned)m_width < (strlen(LblShape::label()) + 2)) {
			m_height = 0;
			m_width = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);
		int width, height;
		if (!(istr >> width)) cout << "not a width value" << endl;
		if (istr.peek() == ',') istr.ignore();
		else cout << "not comma seperated" << endl;
		if (!(istr >> height)) cout << "not a height value" << endl;
		istr.ignore(1000, '\n');
		m_width = width;
		m_height = height;
		if (m_height < 3 || (unsigned)m_width < (strlen(LblShape::label()) + 2)) {
			m_height = 0;
			m_width = 0;
		}
	}

	void Rectangle::draw(std::ostream& ostr) const
	{
		int fillLen = m_width - 2;
		if (m_height > 0 && m_width > 0) {
			ostr << "+" << "-" << setw(fillLen) << setfill('-') << "+" << endl;
			ostr << "|" << setw(fillLen) << setfill(' ') << left << label() << "|" << endl;
			for (int i = 0; i < m_height - 3; i++)
			{
				ostr << "|" << " " << setfill(' ') << setw(fillLen) << right << "|" << endl;
			}
			ostr << "+" << "-" << setw(fillLen) << setfill('-') << "+";
		}
	}
}