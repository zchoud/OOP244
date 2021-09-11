//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title = nullptr;
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText& text);
      HtmlText& operator=(const HtmlText& text);
      virtual void write(std::ostream& os)const;
      virtual ~HtmlText();
   };
}
#endif // !SDDS_HTMLTEXT_H__
