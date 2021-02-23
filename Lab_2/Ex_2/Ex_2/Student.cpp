#include "Student.h"
#include <string>

Student::Student()
{
	name[0] = 0;
	mathGrade = 0;
	enGrade = 0;
	histGrade = 0;
}

void Student::setName(const char * name)
{
	strcpy(this->name, name);
}

const char * Student::getName() const
{
	return this->name;
}

bool Student::setEnGrade(float grade)
{
	if (grade >= 1 && grade <= 10)
	{
		this->enGrade = grade;
		return true;
	}
	return false;
}

const float Student::getEnGrade() const
{
	return this->enGrade;
}

bool Student::setMathGrade(float grade)
{
	if (grade >= 1 && grade <= 10)
	{
		this->mathGrade = grade;
		return true;
	}
	return false;
}

const float Student::getMathGrade() const
{
	return this->mathGrade;
}

bool Student::setHistGrade(float grade)
{
	if (grade >= 1 && grade <= 10)
	{
		this->histGrade = grade;
		return true;
	}
	return false;
}

const float Student::getHistGrade() const
{
	return this->histGrade;
}

const float Student::getAverageGrade() const
{
	return (enGrade + mathGrade + histGrade) / 3;
}