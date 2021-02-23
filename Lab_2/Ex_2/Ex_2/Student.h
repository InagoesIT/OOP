#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME_LEN 35

class Student
{
	char name[MAX_NAME_LEN];
	float mathGrade;
	float enGrade;
	float histGrade;

public:
	Student();
	void setName(const char * name);
	const char * getName() const;
	bool setMathGrade(float grade); // returns false if the grade isn't between 1 and 10
	const float getMathGrade() const;
	bool setEnGrade(float grade); // returns false if the grade isn't between 1 and 10
	const float getEnGrade() const;
	bool setHistGrade(float grade); // returns false if the grade isn't between 1 and 10
	const float getHistGrade() const;
	const float getAverageGrade() const;
};