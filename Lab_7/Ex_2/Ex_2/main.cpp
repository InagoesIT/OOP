#include <iostream>
using namespace std;
template <class T>
class Vector
{
	typedef bool(__stdcall* CompareFunction)(const T, const T);

	T* list;
	int size;
	int nr;

	void resize()
	{
		T* temp = new T[(this->size) * 2];
		memcpy(temp, list, (nr - 1) * sizeof(T));
		list = new T[(this->size) * 2];
		memcpy(list, temp, (nr - 1) * sizeof(T));
		this->size *= 2;
		
	}

public:
	Vector()
	{
		list = new T[1];
		nr = 0;
		size = 1;
	}

	void push(T elem)
	{
		if (size < ++nr)
			resize();
		list[nr - 1] = elem;
	}

	T pop()
	{
		return list[--nr];
	}

	void remove(int index)
	{
		int i = index;

		while (i < this->nr)
		{
			list[i] = list[i + 1];
			++i;
		}
			
		--nr;
	}

	void insert(int index, T elem)
	{
		if (index == nr)
			push(elem);		
		else if (index < nr)
		{
			if (size < ++nr)
				resize();

			T temp = list[index];
			list[index] = elem;
			int i = nr - 1;

			while (i > index + 1)
			{
				list[i] = list[i - 1];
				i--;
			}

			list[index + 1] = temp;
		}
	}

	void sort(bool (*cmpCallback)(T, T))
	{
		if (cmpCallback)
		{
			for (int i = 0, j; i < this->nr; ++i)
			{
				j = i;
				while (j > 0 && cmpCallback(list[j], list[j - 1]))
				{
					T temp = list[j];
					list[j] = list[j - 1];
					list[j - 1] = temp;
					j--;
				}
			}
		}

		else
		{
			for (int i = 0, j; i < this->nr; ++i)
			{
				j = i;
				while (j > 0 && list[j] < list[j - 1])
				{
					T temp = list[j];
					list[j] = list[j - 1];
					list[j - 1] = temp;
					j--;
				}
			}
		}
	}

	const T& get(int index)
	{
		return list[index];
	}

	void set(int index, T elem)
	{
		if (index <= this->nr)
		{
			list[index] = elem;
			if (index == this->nr)
				++nr;
		}
	}

	int count()
	{
		return nr;
	}

	int firstIndexOf(T elem, bool (*cmpCallback)(T, T))
	{
		if (cmpCallback)
		{
			for (int i = 0; i < this->nr; ++i)
			{
				if (cmpCallback(list[i], elem))
					return i;
			}
		}

		else
		{
			for (int i = 0; i < this->nr; ++i)
			{
				if (list[i] == elem)
					return i;
			}
		}
	}
};

int main()
{
	Vector<int> v1;
	v1.push(3);
	v1.push(5);
	v1.push(1);
	v1.push(2);
	v1.insert(1, 88);
	cout << v1.get(0) << " " << v1.get(1) << " " << v1.get(2) << " " << v1.get(3) << " " << v1.get(4) << endl;
	v1.sort(nullptr);
	cout << "sorted: " << v1.get(0) << " " << v1.get(1) << " " << v1.get(2) << " " << v1.get(3) << " " << v1.get(4) << endl;
	v1.remove(2);
	cout << "elem with index 2 removed: " << v1.get(0) << " " << v1.get(1) << " " << v1.get(2) << " " << v1.get(3) << endl;
	cout << "popped elem: " << v1.pop() << endl;
	cout << "list after popping: " << v1.get(0) << " " << v1.get(1) << " " << v1.get(2) << endl;
	v1.set(3, 1);
	cout << "elem with index 3 is 1: " << v1.get(0) << " " << v1.get(1) << " " << v1.get(2) << " " << v1.get(3) << endl;
	cout << "first occurence of 1: " << v1.firstIndexOf(1, nullptr);
	return 0;
};