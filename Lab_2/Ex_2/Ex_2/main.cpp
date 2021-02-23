//cea mai simplista abordare a configurarii proprietatilor a 2 obiecte pu testare :)

#include "Student.h"
#include "GlobalFunc.h"

int main()
{
	Student s1;
	Student s2;

	s1.setName("Emily");
	s1.setEnGrade(5);
	s1.setHistGrade(8);
	s1.setMathGrade(10);

	s2.setName("Annie");
	s2.setEnGrade(9);
	s2.setHistGrade(7);
	s2.setMathGrade(8);

	printCmpRes(s1, s2);
}