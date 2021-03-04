#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <string>
#include "Math.h"

int Math::Add(int x1, int x2)
{
	return x1 + x2;
}

int Math::Add(int x1, int x2, int x3)
{
	return x1 + x2 + x3;
}

int Math::Add(double x1, double x2)
{
	return x1 + x2;
}

int Math::Add(double x1, double x2, double x3)
{
	return x1 + x2 + x3;
}

int Math::Mul(int x1, int x2)
{
	return x1 * x2;
}

int Math::Mul(int x1, int x2, int x3)
{
	return x1 * x2 * x3;
}

int Math::Mul(double x1, double x2)
{
	return x1 * x2;
}

int Math::Mul(double x1, double x2, double x3)
{
	return x1 * x2 * x3;
}

int Math::Add(int count, ...)
{
    va_list arr;
    va_start(arr, count);

	int sum = 0;
	va_list vl;
	va_start(vl, count);

	for (int i = 0; i < count; i++)
		sum += va_arg(vl, int);

    va_end(arr);
	return sum;
}

char* Math::Add(const char* frst, const char* scnd)
{
	if (frst && scnd)
	{
		char * big = new char[strlen(frst) + strlen(scnd) + 1];
		strcpy(big, frst);
		strcat(big, scnd);

		return big;
	}

	return nullptr;
}