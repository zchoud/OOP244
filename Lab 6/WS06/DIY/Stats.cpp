#include "Stats.h"
#include "cstring.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
namespace sdds {

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
	{
		m_allRecords = nullptr;
		m_file = nullptr;
		if (columnWidth && noOfColumns) {
			m_columnwidth = columnWidth;
			m_noOfColumns = noOfColumns;
			m_precision = precision;
		}
	}

	Stats::Stats(const char* filename,
		unsigned columnWidth,
		unsigned noOfColumns,
		unsigned precision) {
		m_file = nullptr;
		m_allRecords = nullptr;
		if (columnWidth && noOfColumns) {
			m_columnwidth = columnWidth;
			m_noOfColumns = noOfColumns;
			m_precision = precision;
		}
		if (filename) {
			ifstream fileptr;
			fileptr.open(filename);
			if (columnWidth > 0 && noOfColumns > 0 && fileptr.is_open()) {
				m_file = new char[strLen(filename) + 1];
				setFilename(filename);
				countRecords();
				loadNumbers();
			}
			else setEmpty();
		}
	}

	Stats::~Stats()
	{
		delete[] m_file;
		m_file = nullptr;
		delete[] m_allRecords;
		m_allRecords = nullptr;
	}

	Stats::Stats(const Stats& copy)
	{
		m_file = nullptr;
		m_allRecords = nullptr;
		m_columnwidth = copy.m_precision;
		m_noOfColumns = copy.m_noOfColumns;
		m_precision = copy.m_precision;
		m_noOfRecords = copy.m_noOfRecords;
		if (copy.m_file) {
			setFilename(copy.m_file, true);
			copyAs(copy);
			loadNumbers();
		}
		else setEmpty();
	}

	void Stats::setEmpty() {
		delete[] m_file;
		m_file = nullptr;
		delete[] m_allRecords;
		m_allRecords = nullptr;
		m_noOfRecords = 0;
	}

	int Stats::prec()const
	{
		return m_precision;
	}

	Stats& Stats::operator=(const Stats& copy)
	{
		if (copy.m_file) {
			setEmpty();
			m_file = new char[strLen(copy.m_file) + 1];
			strCpy(m_file, copy.m_file);
			m_columnwidth = copy.m_precision;
			m_noOfColumns = copy.m_noOfColumns;
			m_precision = copy.m_precision;
			m_noOfRecords = copy.m_noOfRecords;
			m_allRecords = new double[m_noOfRecords];
			for (unsigned i = 0; i < m_noOfRecords; i++) {
				m_allRecords[i] = copy.m_allRecords[i];
			}
		}
		return *this;
	}

	double& Stats::operator[](unsigned idx)
	{
		Stats dummy{};
		if (*this)
		{
			dummy.value = m_allRecords[idx % m_noOfRecords];
		}
		else dummy.value = 0.0;
		return dummy.value;
	}



	double Stats::operator[](unsigned idx)const
	{
		double ret;
		if (*this)
		{
			ret = m_allRecords[idx % m_noOfRecords];
		}
		else ret = 0.0;
		return ret;
	}


	void Stats::sort(bool ascending)
	{
		int i, j;
		double temp;
		if (ascending) {
			for (i = m_noOfRecords - 1; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (m_allRecords[j] > m_allRecords[j + 1]) {
						temp = m_allRecords[j];
						m_allRecords[j] = m_allRecords[j + 1];
						m_allRecords[j + 1] = temp;
					}
				}
			}
		}
		else {
			for (i = m_noOfRecords - 1; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (m_allRecords[j] < m_allRecords[j + 1]) {
						temp = m_allRecords[j];
						m_allRecords[j] = m_allRecords[j + 1];
						m_allRecords[j + 1] = temp;
					}
				}
			}
		}
	}

	unsigned Stats::size() const
	{
		return m_noOfRecords;
	}

	const char* Stats::name() const
	{
		return m_file;
	}

	unsigned Stats::colSize()const
	{
		return m_noOfColumns;
	}

	unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
	{
		unsigned int noOfOccurrences = 0, i = 0, col = 0;
		for (; i < m_noOfRecords; i++)
		{
			if (m_allRecords[i] <= max && m_allRecords[i] >= min) {
				if (col >= m_noOfColumns) {
					ostr << endl;
					col = 0;
				}
				ostr.width(10);
				ostr << m_allRecords[i];
				col++;
				noOfOccurrences++;
			}
		}
		ostr << endl << "Total of " << noOfOccurrences << " numbers are between - "
			<< min << " and " << max << endl;
		return noOfOccurrences;
	}

	Stats& Stats::copyAs(const Stats& copy)
	{
		ofstream des;
		des.open(m_file, fstream::out);
		m_noOfRecords = copy.m_noOfRecords;
		for (unsigned i = 0; i < m_noOfRecords; i++)
		{
			des << copy[i] << ",";
		}
		return *this;
	}

	void Stats::countRecords()
	{
		ifstream fileIn(m_file);
		string local = "";
		int count = 0;
		if (!fileIn.is_open()) {
			//cout << "error occured" << endl;
			m_noOfRecords = count;
			setEmpty();
		}
		else {
			while (getline(fileIn, local, ','))
			{
				count++;
			}
			m_noOfRecords = count;
		}
	}


	void Stats::setFilename(const char* fname, bool isCopy)
	{
		if (!isCopy)
		{
			delete[] m_file;
			m_file = new char[strLen(fname) + 1];
			strCpy(m_file, fname);
		}
		else {
			delete[] m_file;
			m_file = new char[strLen(fname) + 3];
			strCpy(m_file, "C_");
			strCat(m_file, fname);
		}
	}

	void Stats::loadNumbers()
	{
		if (*this)
		{
			delete[] m_allRecords;
			m_allRecords = nullptr;
			m_allRecords = new double[m_noOfRecords];
			std::string local;
			ifstream fileIn;
			fileIn.open(m_file);
			bool notEnd = true;
			if (fileIn.is_open()) {
				for (unsigned i = 0; i < m_noOfRecords && notEnd; i++)
				{
					getline(fileIn, local, ',');
					m_allRecords[i] = stod(local);
					if (fileIn.eof()) {
						notEnd = false;
					}
				}
			}
		}
		else setEmpty();
	}

	Stats::operator bool()const
	{
		return m_noOfRecords > 0 && m_file;
	}

	std::ostream& operator<<(std::ostream& ostr, const Stats& right)
	{
		unsigned int i = 0, col = 0;
		if (right.name()) {
			for (; i < right.size(); i++)
			{
				if (col >= right.colSize()) {
					ostr << endl;
					col = 0;
				}
				ostr.width(15);
				ostr << setprecision(right.prec()) << fixed << right[i];
				col++;
			}
		}
		ostr << endl;
		ostr << "Total of " << right.size() << " listed!" << endl;
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Stats& right)
	{
		string filename = "";
		istr >> filename;
		ifstream file(filename);
		if (file.is_open()) {
			right.setFilename(filename.c_str());
			right.countRecords();
			right.loadNumbers();
		}
		else right.setEmpty();
		return istr;
	}
}