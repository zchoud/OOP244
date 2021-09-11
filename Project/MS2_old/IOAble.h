//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/11/2021
#ifndef SDDS_IOAble_H
#define SDDS_IOAble_H
#include <iostream>
#include <fstream>	
using namespace std;
namespace sdds {
	class IOAble
	{
	public:
		virtual std::ofstream& csvWrite(const std::ofstream& write)const  = 0;
		virtual std::ifstream& csvRead(std::ifstream& read) = 0;
		virtual std::ostream& write(const std::ostream& write)const  = 0;
		virtual std::istream& read(std::istream& read) = 0;
		virtual ~IOAble() {};
	};
	std::ostream& operator<<(const std::ostream& out, const IOAble& output) { return output.write(out); };
	std::istream& operator>>(std::istream& in, IOAble& input) { return input.read(in); };
}
#endif // !SDDS_IOAble_H
