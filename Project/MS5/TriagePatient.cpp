//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/09/2021
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "TriagePatient.h"

namespace sdds {
   int nextTriageTicket = 1;

   TriagePatient::TriagePatient():Patient(nextTriageTicket)
   {
	   m_symptoms = nullptr;
	   nextTriageTicket++;
   }

   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
	   delete[] m_symptoms;
	   Patient::csvRead(istr);
	   istr.ignore();
	   string symptom;
	   getline(istr, symptom, '\n');
	   m_symptoms = new char[symptom.length() + 1];
	   strcpy(m_symptoms, symptom.c_str());
	   nextTriageTicket = Patient::number() + 1;
	   return istr;
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
   {
	   Patient::csvWrite(ostr);
	   ostr << ',' << m_symptoms;
	   return ostr;
   }

   std::ostream& TriagePatient::write(std::ostream& ostr) const
   {
	   if (Patient::fileIO()) {
		   csvWrite(ostr);
	   }
	   else {
		   ostr << "TRIAGE" << endl;
		   Patient::write(ostr);
		   ostr << endl << "Symptoms: " << m_symptoms << endl;
	   }
	   return ostr;
   }

   std::istream& TriagePatient::read(std::istream& istr)
   {
	   if (Patient::fileIO()) {
		   this->csvRead(istr);
	   }
	   else {
		   delete[] m_symptoms;
		   Patient::read(istr);
		   cout << "Symptoms: ";
		   string symptom;
		   getline(istr, symptom, '\n');
		   m_symptoms = new char[symptom.length() + 1];
		   strcpy(m_symptoms, symptom.c_str());
	   }
	   return istr;
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }

}