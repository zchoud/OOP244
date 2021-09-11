//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/09/2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include "Time.h"
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Patient::Patient(int ticket, bool flag): m_ticket(ticket)
    {
        m_flag = flag;
        m_patient = nullptr;
        m_ohip = 0;
    }
    Patient::~Patient()
    {
        delete[] m_patient;
        m_patient = nullptr;
    }
    bool Patient::fileIO()const
    {
        return m_flag;
    }
    void Patient::fileIO(bool flag)
    {
        m_flag = flag;
    }
    bool Patient::operator==(char ch)const
    {
        bool ret = false;
        if (this->type() == ch) {
            ret = true;
        }
        return ret;
    }
    bool Patient::operator==(const Patient& compare)const
    {
        bool ret = false;
        if (this != NULL) {
            if (this->type() == compare.type()) {
                ret = true;
            }
        }
        return ret;
    }
    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }
    Patient::operator Time()const
    {
        return (Time)m_ticket;
    }
    int Patient::number()const {
        return m_ticket.number();
    }
    std::ostream& Patient::csvWrite(std::ostream& ostr)const
    {
        ostr << this->type() << "," << this->m_patient << "," << m_ohip << ",";
        m_ticket.csvWrite(ostr);
        return ostr;
    }
    std::istream& Patient::csvRead(std::istream& istr)
    {
        string extract;
        delete[] m_patient;
        getline(istr, extract, ',');
        m_patient = new char[strlen(extract.c_str()) + 1];
        strcpy(m_patient, extract.c_str());
        istr >> m_ohip;
        istr.ignore();
        m_ticket.csvRead(istr);
        return istr;
    }
    std::ostream& Patient::write(std::ostream& ostr)const
    {
        char name_out[26];
        strncpy(name_out, m_patient, 25);
        name_out[25] = '\0';
        m_ticket.write(ostr);
        ostr << endl << name_out << ", OHIP: " << m_ohip;
        return ostr;
    }
    std::istream& Patient::read(std::istream& istr)
    {
        delete[] m_patient;
        cout << "Name: ";
        string name;
        getline(istr, name, '\n');
        m_patient = new char[strlen(name.c_str()) + 1];
        strcpy(m_patient, name.c_str());
        m_ohip = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
        return istr;
    }
}