//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/16/2021
#include <iostream>
#include <iomanip>
#include "Truck.h"
#include "cstring.h"
using namespace std;
namespace sdds{
	Truck::Truck(const char* license, int year, double capacity, const char* address)
		:MotorVehicle(license, year)
	{
		m_load = 0.0;
		m_capacity = capacity;
		Truck::moveTo(address);
	}
	bool Truck::addCargo(double cargo)
	{
		bool added = false;
		if (m_capacity != m_load) {
			if (m_capacity >= (m_load + cargo)) m_load = m_load + cargo;
			else m_load = m_capacity;
			added = true;
		}
		return added;
	}
	bool Truck::unloadCargo()
	{
		bool dumped= false;
		if (m_load > 0) {
			m_load = 0.0;
			dumped = true;
		}
		return dumped;
	}
	std::ostream& Truck::write(std::ostream& os)const
	{
		MotorVehicle::write(os);
		os << " | " << m_load << "/" << m_capacity;
		return os;
	}
	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		in.ignore(1000, '\n');
		cout << "Cargo: ";
		in >> m_load;
		in.ignore(1000, '\n');
		return in;
	}
	std::ostream& operator<<(std::ostream& ostr, const Truck& truck)
	{
		return truck.write(ostr);
	}
	istream& operator>>(istream& istr, Truck& truck)
	{
		return truck.read(istr);
	}
}