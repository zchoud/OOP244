//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021
#ifndef _LAB_LINE_H
#define _LAB_LINE_H
#include <iostream>
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Line :
		public LblShape
	{
	private:
		int m_length;
	public:
		Line();
		Line(const char* label, int length);
		virtual ~Line() {};
		virtual void getSpecs(std::istream& istr);
		virtual void draw(std::ostream& ostr)const;
	};
}
#endif // _LAB_LINE_H
