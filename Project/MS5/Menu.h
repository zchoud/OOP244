//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/09/2021
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
    class Menu {
        char* m_text; // holds the menu content dynamically
        int m_noOfSel;  // holds the number of options displayed in menu content
        void display()const;
    public:
        Menu();
        Menu(const char* MenuContent, int NoOfSelections);
        Menu(const Menu& copy);
        Menu& operator=(const Menu& copy);
        virtual ~Menu();
        int& operator>>(int& Selection);
        // add safe copying logic
    };
}
#endif // !SDDS_MENU_H