#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	//Line class definitions 

	Line::operator const char* () const {
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}

	//Textfile class definitions

	void TextFile::setEmpty()
	{
		delete[] m_textLines;
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		if (!isCopy)
		{
			delete[] m_filename;
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
		else {
			delete[] m_filename;
			m_filename = new char[strLen(fname) + 3];
			strCpy(m_filename, "C_");
			strCat(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines()
	{
		ifstream fileIn(m_filename);
		char c;
		int count = 0;
		if (!fileIn.is_open()) {
			//cout << "error occured" << endl;
			m_noOfLines = count;
		}
		else {
			c = fileIn.get();
			while (c != EOF)
			{
				c = fileIn.get();
				if (c == '\n') count++;
			}
			count++;
		}
		if (count > 0) m_noOfLines = count + 1;
		else {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}

	void TextFile::loadText()
	{
		if (*this)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			m_textLines = new Line[m_noOfLines];
			std::string local;
			ifstream fileIn;
			fileIn.open(m_filename);
			bool notEnd = true;
			for (unsigned i = 0; i < m_noOfLines && notEnd; i++)
			{
				getline(fileIn, local);
				m_textLines[i] = (char*)(local.c_str());
				if (fileIn.eof()) {
					notEnd = false;
					m_noOfLines = i + 1;
				}
			}
		}
	}

	void TextFile::saveAs(const char* fileName)const
	{
		ofstream local;
		local.open(fileName);

		for (unsigned i = 0; i < m_noOfLines; i++)
		{
			local << m_textLines[i];
			local << endl;
		}
	}


	TextFile::TextFile(unsigned pageSize)
	{
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize)
	{
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;
		if (filename) {
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile& TextFile::copyAs(const TextFile& copy)
	{
		ofstream des;
		des.open(m_filename, fstream::out);
		m_noOfLines = copy.m_noOfLines;
		for (int i = 0; i < m_noOfLines; i++)
		{
			des << copy.m_textLines[i];
			des << endl;
		}
		return *this;
	}

	TextFile::TextFile(const TextFile& copy)
	{
		m_pageSize = copy.m_pageSize;
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;

		if (copy.m_filename && copy.m_noOfLines > 0) {
			setFilename(copy.m_filename, true);
			copyAs(copy);
			loadText();

		}
	}

	TextFile& TextFile::operator=(const TextFile& copy)
	{
		if (strCmp(copy.m_filename, m_filename)) {
			delete[] m_textLines;
			m_textLines = nullptr;
			copyAs(copy);
			loadText();
		}
		return *this;
	}

	TextFile::~TextFile()
	{
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
	}

	std::ostream& TextFile::view(std::ostream& ostr)const
	{
		if (*this) {
			ostr << m_filename << endl;
			int len = strLen(m_filename);
			for (auto i = 0; i < len; i++)
			{
				ostr << "=";
			}
			ostr << endl;
			for (int i = 0, j = 1; i < m_noOfLines; i++)
			{
				ostr << m_textLines[i].m_value << endl;
				if (i == j * m_pageSize) {
					j++;
					char c;
					ostr << "Hit ENTER to continue...";
					cin.get(c);
				}
			}
		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr)
	{
		string local;
		istr >> local;
		istr.clear();
		istr.ignore(1000, '\n');
		setFilename(local.c_str());
		setNoOfLines();
		loadText();
		return istr;
	}

	TextFile::operator bool()const
	{
		return m_filename && m_noOfLines > 0;
	}

	unsigned TextFile::lines()const
	{
		return m_noOfLines;
	}

	const char* TextFile::name()const
	{
		return m_filename;
	}

	const char* TextFile::operator[](unsigned index)const
	{
		char* ret;
		if (*this)
		{
			ret = m_textLines[index % m_noOfLines].m_value;
		}
		else ret = nullptr;
		return ret;
	}
	std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
	{
		return text.view(ostr);
	}
	std::istream& operator>>(std::istream& istr, TextFile& text)
	{
		return text.getFile(istr);
	}

}