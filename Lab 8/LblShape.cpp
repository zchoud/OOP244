//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Shape.h"
#include "LblShape.h"
using namespace std;
namespace sdds {
    char* LblShape::label() const
    {
        return m_label;
    }

    LblShape::LblShape()
    {
        m_label = nullptr;
    }

    LblShape::LblShape(const char* label)
    {
        m_label = nullptr;
        if (label) {
            cout << "creating a label" << endl;
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    void LblShape::getSpecs(std::istream& istr)
    {
        string label;
        getline(istr, label, ',');
        m_label = nullptr;
        if (!istr.fail()) {
            m_label = new char[strlen(label.c_str()) + 1];
            strcpy(m_label, label.c_str());
        }
        else {
            istr.clear();
            istr.ignore(1000);
        }
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
        m_label = nullptr;
    }
}