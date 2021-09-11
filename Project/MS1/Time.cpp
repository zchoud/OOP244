//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/11/2021
#include "Time.h"
#include "utils.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		this->m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int min) : m_min{ 0 }
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr << setw(2) << setfill('0') << trunc(m_min / 60) << ":" << setw(2) << trunc(m_min % 60);
		return ostr;
	}
	std::istream& Time::read(std::istream& istr)
	{
		int hours, mins;
		char c;
		istr >> hours >> c >> mins;
		bool overflow = istr.get() != '\n';
		istr.putback('\n');
		if (istr.fail() || overflow) {
			istr.setstate(ios::failbit);
		}
		else if (hours < 0 || mins < 0 || c != ':') {
			istr.setstate(ios::failbit);
		}
		else {
			m_min = hours * 60 + mins;
		}
		return istr;
	}
	Time& Time::operator-=(const Time& D)
	{
		int negitive = this->m_min - D.m_min;
		if (negitive < 0) {
			this->m_min = ((trunc(this->m_min / 60) - trunc(D.m_min / 60)) + ceil(trunc(D.m_min / 60) / 24) * 24) * 60 + (this->m_min + D.m_min) % 60;
		}
		else this->m_min = this->m_min - D.m_min;
		return *this;
	}
	Time Time::operator-(const Time& D) const
	{
		Time ret{ 0 };
		int negitive = this->m_min - D.m_min;
		if (negitive < 0) {
			ret.m_min = ((trunc(this->m_min / 60) - trunc(D.m_min / 60)) + ceil(trunc(D.m_min / 60) / 24) * 24) * 60 + (this->m_min + D.m_min) % 60;
		}
		else ret.m_min = this->m_min - D.m_min;
		return ret;
	}
	Time& Time::operator+=(const Time& D)
	{
		this->m_min = this->m_min + D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const
	{
		int ret = this->m_min + D.m_min;
		return ret;
	}
	Time& Time::operator=(unsigned int val)
	{
		this->m_min = val;
		return *this;
	}
	Time& Time::operator*=(unsigned int val)
	{
		this->m_min = this->m_min * val;
		return *this;
	}
	Time& Time::operator/=(unsigned int val)
	{
		this->m_min = this->m_min / val;
		return *this;
	}
	Time Time::operator*(unsigned int val) const
	{
		Time ret{ 0 };
		ret.m_min = this->m_min * val;
		return ret;
	}
	Time Time::operator/(unsigned int val) const
	{
		Time ret{ 0 };
		ret.m_min = this->m_min / val;
		return ret;
	}
	Time::operator unsigned int() const
	{
		return m_min;
	}
	Time::operator int() const
	{
		return m_min;
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}