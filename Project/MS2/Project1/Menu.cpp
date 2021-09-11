#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {

	sdds::Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = nullptr;
		m_noOfSel = NoOfSelections;
		if (MenuContent) {
			m_text = new char[strlen(MenuContent) + 1];
			strcpy(m_text, MenuContent);
		}
	}

	Menu::Menu(const Menu& copy)
	{
		m_text = nullptr;
		m_noOfSel = copy.m_noOfSel;
		if (copy.m_text) {
			m_text = new char[strlen(copy.m_text) + 1];
			strcpy(m_text, copy.m_text);
		}
	}

	Menu& Menu::operator=(const Menu& copy)
	{
		if (copy.m_text && strcmp(copy.m_text, m_text)) {
			delete[] m_text;
			m_text = nullptr;
			m_text = new char[strlen(copy.m_text) + 1];
			strcpy(m_text, copy.m_text);
			m_noOfSel = copy.m_noOfSel;
		}
		return *this;
	}

	void sdds::Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	sdds::Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	int& sdds::Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ","Invalid option ", true);
		return Selection;
	}
}
