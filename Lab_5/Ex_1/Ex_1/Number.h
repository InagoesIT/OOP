#pragma once
#include <iostream>
#define MAX_SIZE 300
using namespace std;

int intEqInBase10(char* value);
void nrFromBase10ToN(char* value, int base);
void nrFromBaseNTo10(char* value, int base);
int intEqToLetterIn16(char charac);
void nrFromBase2To2n(char* value, int newBase);

class Number
{
	char value[MAX_SIZE];
	int base;

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(int nr);

	Number    operator+ (Number& n2);
	Number    operator- (Number& n2);
	Number    operator-- (int value);
	void      operator-- ();
	void      operator= (Number& n2);
	void      operator= (int nr);
	void      operator= (const char* strVal);
	void      operator+= (Number& n2);
	char      operator[] (int index);
	bool      operator>(Number& n2);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
