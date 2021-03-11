#include "Sort.h"

Sort::Sort(int n, int min, int max)
{
	if (n && n <= MAX_SIZE)
	{
		srand(time(0));
		for (int i = 0; i < n; i++)
			this->myList[i] = rand() % max + min;
	}
	this->size = n;
}

Sort::Sort(int a0, int a1, int a2, int a3)
{
	this->myList[0] = a0;
	this->myList[1] = a1;
	this->myList[2] = a2;
	this->myList[3] = a3;
	this->size = 4;
}

Sort::Sort(int a0, int a1, int a2, int a3, int a4)
{
	this->myList[0] = a0;
	this->myList[1] = a1;
	this->myList[2] = a2;
	this->myList[3] = a3;
	this->myList[4] = a4;
	this->size = 5;
}

Sort::Sort(int* arr, int n)
{
	if (n && n <= MAX_SIZE)
		memcpy(this->myList, arr, sizeof(int) * n);
	this->size = n;
}

Sort::Sort(int n, ...)
{
	if (n && n <= MAX_SIZE)
	{
		va_list arr;
		va_start(arr, n);

		for (int i = 0; i < n; i++)
			this->myList[i] = va_arg(arr, int);

		va_end(arr);
		this->size = n;
	}
}

Sort::Sort(const char* str)
{
	char auxStr[MAX_SIZE * 10];
	memcpy(auxStr, str, strlen(str));
	char* token = strtok(auxStr, ",");
	int i = 0;

	while (token != NULL && i <= MAX_SIZE)
	{
		this->myList[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}

	this->size = i;
}

void Sort::InsertSort(bool ascendent)
{
	if (ascendent)
	{
		for (int i = 1, j = i; i < this->size; ++i, j = i)
		{
			while (j > 0 && this->myList[j - 1] > this->myList[j])
			{
				swap(this->myList[j - 1], this->myList[j]);
				--j;
			}
		}
	}
	else
	{
		for (int i = 1, j = i; i < this->size; ++i, j = i)
		{
			while (j > 0 && this->myList[j - 1] < this->myList[j])
			{
				swap(this->myList[j - 1], this->myList[j]);
				--j;
			}
		}
	}
	
}

int Sort::Partition(int low, int high, bool isAscendent)
{
	int pivot = this->myList[high];
	int i = low - 1;

	if (isAscendent)
	{
		for (int j = low; j <= high - 1; ++j)
		{
			if (this->myList[j] < pivot)
			{
				++i;
				swap(this->myList[i], this->myList[j]);
			}
		}
	}
	else
	{
		for (int j = low; j <= high - 1; ++j)
		{
			if (this->myList[j] > pivot)
			{
				++i;
				swap(this->myList[i], this->myList[j]);
			}
		}
	}
	
	swap(this->myList[i + 1], this->myList[high]);
	return i + 1;
}

void Sort::InternalQuickSort(int low, int high, bool isAscendent)
{
	if (low < high)
	{
		int partI = Partition(low, high, isAscendent);

		InternalQuickSort(low, partI - 1, isAscendent);
		InternalQuickSort(partI + 1, high, isAscendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	InternalQuickSort(0, this->size - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	if (ascendent)
	{
		for (int i = 0; i < this->size - 1; i++)
		{
			for (int j = 0; j < this->size - i - 1; j++)
			{
				if (this->myList[j] > this->myList[j + 1])
					swap(this->myList[j], this->myList[j + 1]);
			}
		}
	}
	else
	{
		for (int i = 0; i < this->size - 1; i++)
		{
			for (int j = 0; j < this->size - i - 1; j++)
			{
				if (this->myList[j] < this->myList[j + 1])
					swap(this->myList[j], this->myList[j + 1]);
			}
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->size; i++)
		cout << this->myList[i] << " ";
	cout << endl;
}

int Sort::GetElementsCount()
{
	return this->size;
}

int Sort::GetElementFromIndex(int index)
{
	if (index > -1 && index < this->size)
		return this->myList[index];
	return -1;
}