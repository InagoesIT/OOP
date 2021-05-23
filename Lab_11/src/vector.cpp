#include <iostream>
#include <string>

#define Max_Size 6

using namespace std;

template <class T>
class Vector
{
	T vector[Max_Size];
	int count;
public:
	Vector() : count(0) {}
	T GetCount()
	{
		return count;
	}
	void Adauga(T value)
	{
		if (count < Max_Size)
			vector[count++] = value;
	}
	void Sterge(int index)
	{
		if (index <= count && index >= 0)
		{
			int i;
			for (int i = index; i < count - 1 && index <= count; i++)
			{
				vector[i] = vector[i + 1];
			}
			count--;
		}
		else
			cout << "indexul dat depaseste nr de elemente din vector";

	}
	void Sortare()
	{
		bool sorted;
		do
		{
			sorted = true;
			for (int i = 0; i < count - 1; i++)
			{
				if (vector[i] > vector[i + 1]) // increasing order, so >, not <
				{
					T aux; // no ; added and aux is of type T, not int
					aux = vector[i];
					vector[i] = vector[i + 1];
					vector[i + 1] = aux; // not a[i], but aux
					sorted = false; // sorted -> false, not true, to continue sorting in while
				}
			}
		} while (!sorted);
	}
	void Print()
	{
		for (int i = 0; i < count; i++)
			cout << vector[i] << " ";
	}
	string GetArrayString()
	{
		string rez = "";
		for (int i = 0; i < count; ++i)
			rez += to_string(vector[i]) + " ";
		return rez;
	}
};