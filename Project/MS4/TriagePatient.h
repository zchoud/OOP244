//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/01/2021
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"
namespace sdds {
	class TriagePatient:
		public Patient {
	private:
		char* m_symptoms = nullptr;
	public:
		TriagePatient();
		virtual char type()const { return 'T'; };
		virtual std::istream& csvRead(std::istream& istr);
		virtual std::ostream& csvWrite(std::ostream& ostr)const;
		virtual std::ostream& write(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
		virtual ~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


