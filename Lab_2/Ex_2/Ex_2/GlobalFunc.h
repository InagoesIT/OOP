#pragma once

#include "Student.h"

int cmpNumbers(float n1, float n2);

int cmpName(const Student& a, const Student& b);

int cmpMathGrade(const Student& a, const Student& b);

int cmpEnGrade(const Student& a, const Student& b);

int cmpHistGrade(const Student& a, const Student& b);

int cmpAverageGrade(const Student& a, const Student& b);

void printCmpRes(const Student& a, const Student& b);