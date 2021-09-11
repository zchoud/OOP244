//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021
#ifndef _LAB_RECTANGLE_H
#define _LAB_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Rectangle :
		public LblShape
	{
	private:
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		virtual ~Rectangle() {};
		virtual void getSpecs(std::istream& istr);
		virtual void draw(std::ostream& ostr)const;
	};
}
#endif // _LAB_RECTANGLE_H