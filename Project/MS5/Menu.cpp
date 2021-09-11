//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/09/2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Menu::Menu()
	{
		m_text = nullptr;
		m_noOfSel = 0;
	}
	Menu::Menu(const char* MenuContent, int NoOfSelections)
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

	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ","Invalid option ", true);
		return Selection;
	}
}
