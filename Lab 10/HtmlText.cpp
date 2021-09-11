//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Text.h"
#include "cstring.h"
#include "HtmlText.h"
using namespace std;
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title):Text(filename)
	{
		if (title) {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	HtmlText::HtmlText(const HtmlText& text):Text(text)
	{
		operator=(text);
	}

	HtmlText& HtmlText::operator=(const HtmlText& text)
	{
		if (this != &text) {
			Text::operator=(text);
			if (text.m_title) {
				delete[] m_title;
				m_title = new char[strLen(text.m_title) + 1];
				strCpy(m_title, text.m_title);
			}
		}
		return *this;
	}

	void HtmlText::write(std::ostream& os) const
	{
		int length = fileLength();
		bool ms = false;
		char ch;
		os << "<html><head><title>" << (m_title ? m_title : "No Title") << "</title></head>\n<body>\n";
		os << "</title></head>\n<body>\n";
		if (m_title) os << "<h1>" << m_title << "</h1>\n";
		for (int i = 0; i < length; i++)
		{
			ch = this->operator[](i);
			if (ch == ' ') {
				if (ms) os << "&nbsp;";
				else {
					ms = true; 
					os << " "; 
				}
			}
			else {
				ms = false;
				if (ch == '<') os << "&lt";
				else if (ch == '>') os << "&gt";
				else if (ch == '\n') os << "<br />\n";
				else os << ch;
			}
		}
		os << "</body>\n</html>";
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}
}