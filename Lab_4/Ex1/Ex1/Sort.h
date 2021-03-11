#pragma once

#define MAX_SIZE 600

#include <iostream>
#include <stdarg.h>
#include <string>
#include <time.h>

using namespace std;

class Sort
{
    int myList[MAX_SIZE] = {};
    int size = 0;
    int Partition(int low, int high, bool isAscendent);
    void InternalQuickSort(int low, int high, bool isAscendent);    
public:
    Sort(int n, int min, int max);
    Sort(int a0, int a1, int a2, int a3);
    Sort(int a0, int a1, int a2, int a3, int a4);
    Sort(int* arr, int n);
    Sort(int n, ...);
    Sort(const char* str);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};