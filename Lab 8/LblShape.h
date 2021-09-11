//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021
#ifndef _LAB_LBLSHAPE_H
#define _LAB_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
namespace sdds {
    class LblShape :
        public Shape
    {
    private:
        char* m_label = nullptr;
    protected:
        char* label()const;
    public:
        LblShape();
        LblShape(const char* label);
        virtual void getSpecs(std::istream& istr);
        virtual ~LblShape();
        LblShape(const LblShape& copy) = delete;
        LblShape& operator=(const LblShape& copy) = delete;
    };
}
#endif // _LAB_LBLSHAPE_H
