#include "GlobalFunc.h"

#include <string>
#include <iostream>

using namespace std;

int cmpNumbers(float n1, float n2)
{
	if (n1 > n2)
		return 1;
	else if (n1 < n2)
		return -1;
	return 0;
}

int cmpName(const Student& s1, const Student& s2)
{
	return strcmp(s1.getName(), s2.getName());
}

int cmpEnGrade(const Student& s1, const Student& s2)
{
	return cmpNumbers(s1.getEnGrade(), s2.getEnGrade());
}

int cmpMathGrade(const Student& s1, const Student& s2)
{
	return cmpNumbers(s1.getMathGrade(), s2.getMathGrade());
}

int cmpHistGrade(const Student& s1, const Student& s2)
{
	return cmpNumbers(s1.getHistGrade(), s2.getHistGrade());
}

int cmpAverageGrade(const Student& s1, const Student& s2)
{
	return cmpNumbers(s1.getAverageGrade(), s2.getAverageGrade());
}

void printCmpRes(const Student& s1, const Student& s2)
{
	//cmpName
	if (cmpName(s1, s2) == -1)
		cout << s2.getName() << " is alphabetically bigger than " << s1.getName() << endl;
	else if (cmpName(s1, s2) == 1)
		cout << s1.getName() << " is alphabetically bigger than " << s2.getName() << endl;
	else
		cout << "The objects given have the same name: " << s1.getName() << endl;

	//cmpMathGrade
	if (cmpMathGrade(s1, s2) == -1)
		cout << s2.getName() << " has a bigger grade at Mathematics than " << s1.getName() << " "
			 << s2.getMathGrade() << ">" << s1.getMathGrade() << endl;
	else if (cmpMathGrade(s1, s2) == 1)
		cout << s1.getName() << " has a bigger grade at Mathematics than " << s2.getName() << " "
			 << s1.getMathGrade() << ">" << s2.getMathGrade() << endl;
	else
		cout << "The objects given have the same grade at Mathematics: " << s1.getMathGrade() << endl;

	//cmpEnGrade
	if (cmpEnGrade(s1, s2) == -1)
		cout << s2.getName() << " has a bigger grade at English than " << s1.getName() << " "
		<< s2.getEnGrade() << ">" << s1.getEnGrade() << endl;
	else if (cmpEnGrade(s1, s2) == 1)
		cout << s1.getName() << " has a bigger grade at English than " << s2.getName() << " "
		<< s1.getEnGrade() << ">" << s2.getEnGrade() << endl;
	else
		cout << "The objects given have the same grade at English: " << s1.getEnGrade() << endl;

	//cmpHistGrade
	if (cmpHistGrade(s1, s2) == -1)
		cout << s2.getName() << " has a bigger grade at History than " << s1.getName() << " "
		<< s2.getHistGrade() << ">" << s1.getHistGrade() << endl;
	else if (cmpHistGrade(s1, s2) == 1)
		cout << s1.getName() << " has a bigger grade at History than " << s2.getName() << " "
		<< s1.getHistGrade() << ">" << s2.getHistGrade() << endl;
	else
		cout << "The objects given have the same grade at History: " << s1.getHistGrade() << endl;

	//cmpAverageGrade
	if (cmpAverageGrade(s1, s2) == -1)
		cout << s2.getName() << " has a bigger average grade than " << s1.getName() << " "
		<< s2.getAverageGrade() << ">" << s1.getAverageGrade() << endl;
	else if (cmpAverageGrade(s1, s2) == 1)
		cout << s1.getName() << " has a bigger average grade than " << s2.getName() << " "
		<< s1.getAverageGrade() << ">" << s2.getAverageGrade() << endl;
	else
		cout << "The objects given have the same average grade: " << s1.getAverageGrade() << endl;
}
