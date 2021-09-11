//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//04/09/2021
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   int getInt(const char* prompt)
   {
       if (prompt) cout << prompt;
       int input = 0;
       bool valid = false;
       while (!valid)
       {
           cin >> input;
           if (cin.fail()) {
               cin.clear();
               cin.ignore(1000, '\n');
               cout << "Bad integer value, try again: ";
           }
           else if (cin.get() != '\n')
           {
               cin.clear();
               cin.ignore(1000, '\n');
               cout << "Enter only an integer, try again: ";
           }
            else valid = true;
       }
       return input;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       int input = 0;
       bool valid = false;
       input = getInt(prompt);
       while (!valid)
       {
           if (input < min || input > max) {
               if (errorMessage) cout << errorMessage;
               if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]" << ": ";
               input = getInt("");
           }
           else valid = true;
       }
       return input;
   }

   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
       if (prompt) cout << prompt;
       string cString = "";
       getline(istr, cString, delimiter);
       char* cstr = new char[cString.length() + 1];
       strcpy(cstr, cString.c_str());
       return cstr;
   }


}