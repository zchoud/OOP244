//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/01/2021
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include <fstream>
#include <iostream>
#include "IOAble.h"
#include "Time.h"
#include "Ticket.h"
using namespace std;
namespace sdds {
    class Patient :
        public IOAble
    {
    private:
        Ticket m_ticket;
        char* m_patient;
        int m_ohip;
        bool m_flag;
    public:
        Patient(int ticket = 0, bool flag = false);
        virtual ~Patient();
        Patient(const Patient& copy) = delete;
        Patient& operator=(const Patient& copy) = delete;
        virtual char type()const = 0;
        bool fileIO()const;
        void fileIO(bool flag);
        bool operator==(char ch)const;
        bool operator==(const Patient& compare)const;
        void setArrivalTime();
        operator Time()const;
        int number()const;
        virtual std::ostream& csvWrite(std::ostream& ostr)const;
        virtual std::istream& csvRead(std::istream& istr);
        virtual std::ostream& write(std::ostream& ostr)const;
        virtual std::istream& read(std::istream& istr);
    };
}
#endif // !SDDS_PATIENT_H