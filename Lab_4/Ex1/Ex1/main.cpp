#include "Sort.h"

int main()
{
	// the CTORs will be called here in the order declared in .h

	Sort l1 = { 5, 23, 234 };
	Sort l2 = { 3, 1, 2, 4 };
	Sort l3 = { 5, 1, 4, 2, 3 };
	Sort l4 = { 9, 2, 3, 1, 8, 9, 5, 4, 6, 7 };
	Sort l5 = { "1,4,2,5,3,7,8,6" };

	cout << "l1 -> ";
	l1.Print();
	cout << "Elementul cu indexul 4: " << l1.GetElementFromIndex(4) << endl;
	cout << "---------------------------------------" << endl;
	cout << "l2 -> ";
	l2.Print();
	cout << "Insert Sort descending -> ";
	l2.InsertSort();
	l2.Print();
	l2.InsertSort(true);
	cout << "Insert Sort ascending -> ";
	l2.Print();
	cout << "---------------------------------------" << endl;
	cout << "l3 -> ";
	l3.Print();
	l3.QuickSort();
	cout << "Quick Sort descending -> ";
	l3.Print();
	l3.QuickSort(true);
	cout << "Quick Sort ascending -> ";
	l3.Print();
	cout << "---------------------------------------" << endl;
	cout << "l4 -> ";
	l4.Print();
	l4.BubbleSort();
	cout << "Bubble Sort descending -> ";
	l4.Print();
	l4.BubbleSort(true);
	cout << "Bubble Sort ascending -> ";
	l4.Print();
	cout << "---------------------------------------" << endl;
	cout << "l5 -> " << l5.GetElementsCount() << " elemente: ";
	l5.Print();
	return 0;
}