// Workshop 9:
// ReadWrite.h
// 2021-03-26
// Version: 1.0 
// Author: Fardad Soleimanloo
/////////////////////////////////////////////
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
using namespace std;
namespace sdds {
    /*
     search must be able to:
        1. operator == that accepts a const char* and return a bool
        2. ability to add an array element of a the type and return the new object
    */
    template<typename T1, typename T2>
    bool search(Collection<T1>& colRef, const T1 colArr[], int noOfElements, const T2 value)
    {
        bool found = false;
        for (int i = 0; i < noOfElements; i++)
        {
            if (colArr[i] == value) {
                colRef.add(colArr[i]);
                found = true;
            }
        }
        return found;
    }
    /*
    listArrayElements must be able to:
        1. must contain << operator to display and must return ostream&
        2. display function
    */
    template<typename T1>
    void listArrayElements(const char* title, const T1 arr[], int noOfElements)
    {
        cout << title << endl;
        for (int i = 0; i < noOfElements; i++)
        {
                cout << i + 1 << ": " << arr[i] << endl;
        }
    }
}
#endif // !SDDS_SEARCHNLIST_H_

