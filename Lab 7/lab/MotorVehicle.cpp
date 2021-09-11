//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/16/2021
#include "MotorVehicle.h"
#include "cstring.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sdds{
	MotorVehicle::MotorVehicle(const char license[], int year)
	{
		strCpy(m_license, license);
		m_year = year;
		strCpy(m_address, "Factory");
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (address) {
			cout << "|" << setw(8) << right <<  m_license 
				<< "| |" << setw(20) << right << m_address 
				<< " ---> " << setw(20) << left << address << "|" << endl;
			strCpy(m_address, address);
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os)const
	{
		os << "| " << setw(4) << right << m_year
			<< " | " << right << m_license
			<< " | " << m_address;
		return os;
	}

	void MotorVehicle::checkBuffer(std::istream& in) {
		if (in.fail())
		{
			in.clear();
			in.ignore(1000, '\n');
		}
	}

	std::istream& MotorVehicle::read(std::istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		in.ignore(1000, '\n');
		cout << "License plate: ";
		in.getline(m_license, 9);
		checkBuffer(in);
		cout << "Current location: ";
		in.getline(m_address, 64);
		checkBuffer(in);
		return in;
	}
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& vehicle)
	{
		return vehicle.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, MotorVehicle& vehicle)
	{
		return vehicle.read(istr);
	}
}