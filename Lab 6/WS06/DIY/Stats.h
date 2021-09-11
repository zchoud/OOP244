#include <iostream>
namespace sdds {
	class Stats {
	private:
		char* m_file;
		double* m_allRecords;
		unsigned m_columnwidth = 15;
		unsigned m_noOfColumns = 4;
		unsigned m_precision = 2;
		unsigned m_noOfRecords = 0;
		double value = 0;
	public:
		Stats(unsigned columnWidth = 15,
			unsigned noOfColumns = 4,
			unsigned precision = 2);

		Stats(const char* filename,
			unsigned columnWidth = 15,
			unsigned noOfColumns = 4,
			unsigned precision = 2);
		void setFilename(const char* fname, bool isCopy = false);
		void loadNumbers();
		operator bool()const;
		void countRecords();
		Stats(const Stats& copy);
		Stats& operator=(const Stats& copy);
		double& operator[](unsigned idx);
		double operator[](unsigned idx)const;
		void sort(bool ascending);
		unsigned size()const;
		unsigned colSize()const;
		const char* name()const;
		unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
		void setEmpty();
		int prec()const;
		Stats& copyAs(const Stats& copy);
		~Stats();
	};

	std::ostream& operator<<(std::ostream& ostr, const Stats &right);
	std::istream& operator >>(std::istream& istr, Stats &right);
}
