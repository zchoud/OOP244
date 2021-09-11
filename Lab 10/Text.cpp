#include <fstream>
#include <string>
#include <cstring>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	int Text::getFileLength() const {
		int len = 0;
		ifstream fin(m_filename);
		while (fin) {
			fin.get();
			len += !!fin;
		}
		return len;
	}

	const char& Text::operator[](int index) const
	{
		static char ch;
		ch = 0;
		if (m_filename) {
			if (index < getFileLength()) {
				ch = m_content[index];
			}
		}
		return ch;
	}

	Text::Text(const char* filename)
	{
		if (filename) {
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);
			read();
		}
	}

	Text::Text(const Text& t)
	{
		operator=(t);
	}

	Text& Text::operator=(const Text& t)
	{
		if (this != &t) {
			delete[] m_filename;
			m_filename = new char[strLen(t.m_filename) + 1];
			strCpy(m_filename, t.m_filename);
			read();
		}
		return *this;
	}

	void Text::read()
	{
		if (m_filename) {
			delete[] m_content;
			ifstream file(m_filename);
			int length = getFileLength();
			char ch;
			m_content = new char[length + 1];
			for (int i = 0; i < length && file.peek() != EOF; i++)
			{
				ch = file.get();
				m_content[i] = ch;
			}
			m_content[length] = '\0';
		}
		else {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}

	void Text::write(std::ostream& os) const
	{
		if (m_content) {
			os << m_content;
		}
	}

	Text::~Text()
	{
		delete[] m_filename;
		m_filename = nullptr;
		delete[] m_content;
		m_content = nullptr;
	}

	int Text::fileLength() const
	{
		return getFileLength();
	}

	std::ostream& operator<<(std::ostream& ostr, const Text& t)
	{
		t.write(ostr);
		return ostr;
	}

}