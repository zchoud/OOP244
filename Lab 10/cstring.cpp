//Zian Choudhury
//131048209
//OOP244NJJ
//zchoudhury@myseneca.ca
//03/24/2021

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"

using namespace std;
using namespace sdds;

// Copies the srouce character string into the destination
void strCpy(char* des, const char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
}

// Copies the source character string into the destination upto "len"
// characters. The destination will be null terminated only if the number
// of the characters copied is less than "len"
void strnCpy(char* des, const char* src, int len)
{
	int i = 0;
	while (i < len)
	{
		if (src[i] == '\0')
		{
			if (len > i)
			{
				des[i] = '\0';
			}
			break;
		}
		else {
			des[i] = src[i];
		}
		i++;
	}
}

// Compares two C-strings 
// returns 0 i thare the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
int strCmp(const char* s1, const char* s2)
{
	int chk = 2, i = 0;
	do {
		if (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
			{
				chk = 0;
				break;
			}
			i++;
			continue;
		}
		else if (s1[i] > s2[i] || (s2[i] == '\0' && s1[i] != '\0'))
		{
			chk = 1;
			break;
		}
		else if (s1[i] < s2[i] || (s1[i] == '\0' && s2[i] != '\0'))
		{
			chk = -1;
			break;
		}
	} while (1);
	if (chk == 2)
	{
		cout << "Failed";
	}
	return chk;
}

// returns 0 i thare the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
int strnCmp(const char* s1, const char* s2, int len)
{
	int chk = 2;

	if (s1[len - 1] > s2[len - 1] && (s2[len - 1] != '\0' && s1[len - 1] != '\0'))
	{
		chk = 1;

	}
	else if (s1[len - 1] < s2[len - 1] && (s1[len - 1] != '\0' && s2[len - 1] != '\0'))
	{
		chk = -1;
	}
	else if (s1[len - 1] == s2[len - 1] && (s1[len - 1] != '\0' && s2[len - 1] != '\0'))
	{
		chk = 0;
	}
	else
	{
		cout << "Failed";
	}
	return chk;
}

// returns the lenght of the C-string in characters
int strLen(const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}

// returns the address of first occurance of "str2" in "str1"
// returns nullptr if no match is found
const char* strStr(const char* str1, const char* str2)
{
	int i = 0, j1 = 0, exit = 1;
	while (str1[i] != '\0' && exit)
	{
		j1 = 0;
		while (str1[i] == str2[j1] || str2[j1] == '\0')
		{
			if (j1 > 0 && str2[j1] == '\0')
			{
				exit = 0;
				break;
			}
			i++;
			j1++;
		}
		i++;
	}
	if (exit)
	{
		return nullptr;
	}
	return &str1[i - j1 - 1];
}

// Concantinates "src" C-string to the end of "des"
void strCat(char* des, const char* src)
{
	int i = 0, j = 0;
	while (des[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		des[i] = src[j];
		i++;
		j++;
	}
	des[i] = '\0';
}