//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/16/2021
#include <iostream>
#ifndef _LAB_MOTORVEHICLE_H
#define _LAB_MOTORVEHICLE_H
namespace sdds {
	class MotorVehicle
	{
	private:
		char m_license[9];
		char m_address[64];
		int m_year;
	protected:
		void checkBuffer(std::istream& in);
	public:
		MotorVehicle(const char license[], int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& istr, MotorVehicle& vehicle);
};
#endif // !_LAB_MOTORVEHICLE_H
