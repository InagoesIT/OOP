#include <iostream>
#include <exception>
using namespace std;


class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};



//Exceptions

class exception1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Index out of bounds!";
	}
};

class exception2 : public exception
{
	virtual const char* what() const throw()
	{
		return "Array capacity exceeded!";
	}
};

exception1 index_out_of_bounds;
exception2 capacity_exceeded;


// ARRAY ITERATOR

template <typename T>
class ArrayIterator
{
	T* elem;
	int count;
	int index;

public:
	ArrayIterator(T* _e, int _count, int _index) : elem(_e), count(_count), index(_index) { }
	bool operator!=(const ArrayIterator<T>& obj) { return index != obj.index; }
	ArrayIterator& operator++() { index++; return *this; }
	T operator*() { return elem[index]; }
};


// ARRAY

template<class T>
class Array
{
private:
	T* List; // lista cu pointeri la obiecte de tipul T
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:
	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T>& otherArray); // constructor de copiere

	T& operator[] (int index); // arunca exceptie daca index este out of range

	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator=(const Array<T>& otherArray);

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator
	int GetSize();
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
};

// function definitions
template <class T>
Array<T>::Array()
{
	this->Capacity = 0;
	this->Size = 0;
}

template <class T>
Array<T>::~Array()
{
	this->Capacity = 0;
	this->Size = 0;
	delete[] this->List;
	delete this->List;
}

template <class T>
Array<T>::Array(int capacity)
{
	this->Capacity = capacity;
	this->Size = 0;
	this->List = new T [capacity];
}

template <class T>
Array<T>::Array(const Array<T>& otherArray)
{
	this->Capacity = otherArray.GetCapacity();
	this->Size = otherArray.GetSize();
	for (int i = 0; i < otherArray.GetSize(); ++i)
		this->List[i] = otherArray.List[i];
}

template <class T>
T& Array<T>::operator[] (int index)
{
	if (index < 0 || index >= Size)
		throw index_out_of_bounds;

	return this->List[index];
}

template <class T>
const Array<T>& Array<T>::operator+=(const T& newElem)
{
	if (Size == Capacity)
		throw capacity_exceeded;

	this->List[Size] = newElem;
	Size++;
	return *this;
}

template <class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	if (index < 0 || index >= Size)
		throw index_out_of_bounds;

	for (int i = Size; i > index; --i)
		this->List[i] = this->List[i - 1];

	this->List[index] = newElem;
	return this;
}

template <class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	if (index < 0 || index >= Size)
		throw index_out_of_bounds;
	if (Size + otherArray.GetSize() > Capacity)
		throw capacity_exceeded;

	int i, j;
	i = j = 0;
	int othArrSize = otherArray.GetSize();

	for (i = Size - 1; i >= index; --i)
		this->List[i + othArrSize] = this->List[i];

	i = index;
	while (j < othArrSize)
		this->List[i++] = otherArray.List[j++];
	this->Size = Size + othArrSize;

	return this;
}

template <class T>
const Array<T>& Array<T>::Delete(int index)
{
	if (index < 0 || index >= Size)
		throw index_out_of_bounds;

	for (int i = index; i < Size; ++i)
		this->List[i] = this->List[i + 1];
	Size--;

	return this;
}

template <class T>
bool Array<T>::operator=(const Array<T>& otherArray)
{
	if (this->Capacity < otherArray.GetSize())
		return false;

	this->Size = otherArray.GetSize();
	for (int i = 0; i < Size; ++i)
		List[i] = otherArray[i];

	return true;
}

template <class T>
void Array<T>::Sort()
{
	for (int i = 1, j = i; i < this->Size; ++i, j = i)
	{
		while (j > 0 && this->List[j - 1] > this->List[j])
		{
			swap(this->List[j - 1], this->List[j]);
			--j;
		}
	}
}

template <class T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
	for (int i = 1, j = i; i < this->Size; ++i, j = i)
	{
		while (j > 0 && compare(this->List[j - 1], this->List[j]))
		{
			swap(this->List[j - 1], this->List[j]);
			--j;
		}
	}
}

template <class T>
void Array<T>::Sort(Compare* comparator)
{
	for (int i = 1, j = i; i < this->Size; ++i, j = i)
	{
		while (j > 0 && comparator->CompareElements(this->List[j - 1], this->List[j]))
		{
			swap(this->List[j - 1], this->List[j]);
			--j;
		}
	}
}

template <class T>
int Array<T>::BinarySearch(const T& elem)
{
	int low = 0, high = Size - 1, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (elem == List[mid]) 
			return mid;
		else if (elem < List[mid]) 
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return -1;
}

template <class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	int low = 0, high = Size - 1, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (compare(elem, List[mid]) == 0)
			return mid;
		else if (compare(elem, List[mid]) == -1)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

template <class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	int low = 0, high = Size - 1, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (comparator->CompareElements(elem, List[mid]) == 0)
			return mid;
		else if (comparator->CompareElements(elem, List[mid]) == -1)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

template <class T>
int Array<T>::Find(const T& elem)
{
	for (int i = 0; i < Size; ++i)
		if (elem == List[i])
			return i;
	return -1;
}

template <class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	for (int i = 0; i < Size; ++i)
		if (compare(elem, List[i]) == 0)
			return i;
	return -1;
}

template <class T>
int Array<T>::Find(const T& elem, Compare* comparator)
{
	for (int i = 0; i < Size; ++i)
		if (comparator->CompareElements(elem, List[i]) == 0)
			return i;
	return -1;
}

template <class T>
int Array<T>::GetSize()
{
	return this->Size;
}

template <class T>
int Array<T>::GetCapacity()
{
	return this->Capacity;
}

template <class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
	return ArrayIterator<T>(List, Size, 0);
}

template <class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
	return ArrayIterator<T>(List, Size, Size - 1);
}

int main()
{
	Array<int> arr(2);
	int a = 3;
	int* p = &a;
	arr+= a;
	try		
	{
		arr += a;
		arr += a;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "HIIII";
	return 0;
}