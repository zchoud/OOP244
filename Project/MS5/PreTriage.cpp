//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/09/2021
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
#include <fstream> 
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
namespace sdds {
	PreTriage::PreTriage(const char* dataFilename):
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2),
		m_averCovidWait(15),
		m_averTriageWait(5)
	{
		if (dataFilename) {
			delete[] m_dataFilename;
			m_dataFilename = new char[strlen(dataFilename) + 1];
			strcpy(m_dataFilename, dataFilename);
			load();
		}
	}
	void PreTriage::reg()
	{
		if (m_lineupSize + 1 < maxNoOfPatients) {
			int selection;
			selection = m_pMenu.operator>>(selection);
			int admitInto = m_lineupSize;
			if (admitInto != -1) {
				if (selection == 1) {
					m_lineup[admitInto] = new CovidPatient;
				}
				else if (selection == 2) {
					m_lineup[admitInto] = new TriagePatient;
				}
				else {
					return;
				}
				m_lineup[admitInto]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[admitInto]->read(cin);
				cout << endl << "******************************************" << endl;
				m_lineup[admitInto]->write(cout);
				cout << "Estimated Wait Time: ";
				cout << this->getWaitTime(*m_lineup[admitInto]) << endl;
				cout << "******************************************" << endl << endl;
				m_lineupSize++;
			}
			else cout << "No Empty found" << endl;
		}
		else cout << "Line up full!" << endl;
	}
	void PreTriage::admit()
	{
		int selection = m_pMenu.operator>>(selection);
		int index;
		if (selection == 1) {
			index = this->indexOfFirstInLine('C');
		}
		else if (selection == 2) {
			index = this->indexOfFirstInLine('T');
		}
		else {
			return;
		}
		if(index == -1) return;
		cout << endl << "******************************************" << endl;
		m_lineup[index]->fileIO(false);
		cout << "Calling for " << *m_lineup[index];
		cout << "******************************************" << endl << endl;
		this->setAverageWaitTime(*m_lineup[index]);
		removePatientFromLineup(index);
	}
	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int noOfType = 0;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (*m_lineup[i] == p) {
				noOfType++;
			}
		}
		Time waitTime;
		waitTime = (p.type() == 'T') ? m_averTriageWait : m_averCovidWait;
		waitTime *= noOfType;
		return waitTime;
	}
	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		Time CT(getTime()), PTT((Time)p);
		int PTN = p.number();
		Time AWT;
		bool type = true; //true means covid, false triage
		if (p == 'T') {
			AWT = m_averTriageWait;
			type = false;
		}
		else AWT = m_averCovidWait;
		type ? m_averCovidWait : m_averTriageWait = ((CT - PTT) + (AWT *= (PTN - 1))) /= PTN;
	}
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}
	int PreTriage::indexOfFirstInLine(char type) const
	{
		bool found = false;
		int index = -1;
		for (int i = 0; i < m_lineupSize && !found; i++)
		{
			if (*m_lineup[i] == type) {
				found = true;
				index = i;
			}
		}
		return index;
	}
	void PreTriage::load()
	{
		cout << "Loading data..." << endl;
		fstream file(m_dataFilename);
		if (file.is_open()) {
			file >> m_averCovidWait;
			file.ignore();
			file >> m_averTriageWait;
			file.ignore();
			Patient* temp = nullptr;
			bool pass = true;
			char ch;
			m_lineupSize = 0;
			for (int i = 0; i < maxNoOfPatients && pass && file.peek() != EOF; i++, m_lineupSize = i) {
				pass = false;
				file >> ch;
				file.ignore();
				if (ch == 'C') {
					temp = new CovidPatient;
					pass = true;
				}
				else if (ch == 'T') {
					temp = new TriagePatient;
					pass = true;
				}
				if (pass) {
					temp->fileIO(true);
					temp->read(file);
					temp->fileIO(false);
					m_lineup[i] = temp;
				}
			}
			if (m_lineupSize >= 100 && file.peek() != EOF) cout << "Warning: number of records exceeded 100" << endl;
			if (m_lineupSize == 0) cout << "No data or bad data file!" << endl << endl;
			else cout << m_lineupSize<< " Records imported" << endl << endl;
		}
	}


	PreTriage::~PreTriage()
	{
		ofstream file(m_dataFilename);
		if (file.is_open()) {
			cout << "Saving Average Wait Times," << endl;
			cout << "COVID Test: " << m_averCovidWait << endl;
			cout << "Triage: " << m_averTriageWait << endl;
			file << m_averCovidWait << "," << m_averTriageWait << endl;
			for (int i = 0; i < m_lineupSize; i++) {
				if (m_lineup[i]->number() > 0) {
					m_lineup[i]->csvWrite(file);
					file << endl;
					cout << i + 1 << "- ";
					m_lineup[i]->csvWrite(cout);
					cout << endl;
				}
			}
		}
		for (int i = 0; i < m_lineupSize; i++) {
			delete m_lineup[i];
			m_lineup[i] = nullptr;
		}
		delete[] m_dataFilename;
		cout << "done!";
	}
	void PreTriage::run(void)
	{
		bool go = true;
		while (go) {
			int selection = m_appMenu.operator>>(selection);
			if (selection == 0) go = false;
			else if (selection == 1) reg();
			else if (selection == 2) admit();
		}
	}
}
