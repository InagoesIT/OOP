#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count++] = x;
	return true;
}

void NumberList::Sort() //bubble sort
{
	bool isSorted;
	int aux;

	do
	{
		isSorted = true;
		for (int i = 0; i < count - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
				isSorted = false;
			}
		}
	} while (!isSorted);
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";

	cout << endl;
}