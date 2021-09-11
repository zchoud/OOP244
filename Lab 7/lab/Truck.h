//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/16/2021
#include "MotorVehicle.h"
#ifndef _LAB_TRUCK_H
#define _LAB_TRUCK_H
namespace sdds {
	class Truck :
		public MotorVehicle
	{
	private:
		double m_capacity;
		double m_load;
	public:
		Truck(const char* license, int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& ostr, const Truck& truck);
	std::istream& operator>>(std::istream& istr, Truck& truck);
}
#endif // !_LAB_TRUCK_H
