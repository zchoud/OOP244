//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/09/2021
#ifndef SDDS_IOAble_H
#define SDDS_IOAble_H
#include <fstream>
#include <iostream>
using namespace std;
namespace sdds {
	class IOAble
	{
	public:
		virtual std::ostream& csvWrite(std::ostream& ostr)const  = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr)const  = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& output);
	std::istream& operator>>(std::istream& istr, IOAble& input);
}
#endif // !SDDS_IOAble_H
