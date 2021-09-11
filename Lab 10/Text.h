//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
      char* m_filename = nullptr;
      char* m_content = nullptr;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text& t);
      Text& operator=(const Text& t);
      void read();
      virtual void write(std::ostream& os)const;
      virtual ~Text();
      int fileLength()const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Text& t);
}
#endif // !SDDS_PERSON_H__

