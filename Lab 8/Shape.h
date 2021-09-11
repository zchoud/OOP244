//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021
#include <iostream>
#ifndef _LAB_SHAPE_H
#define _LAB_SHAPE_H
namespace sdds {
	class Shape
	{
	public:
		virtual void draw(std::ostream& ostr)const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual ~Shape() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& truck);
	std::istream& operator>>(std::istream& istr, Shape& truck);
}
#endif // !_LAB_SHAPE_H
