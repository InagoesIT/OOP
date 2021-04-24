#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include "CompareModule.h"

using namespace std;

class Phrase
{
	string text;
	priority_queue < pair <int, string>, vector<pair <int, string>>, CompareModule > pQueue;
	map<string, int> map;
	void count();
	void sort();
	void txtSplitToLower();

public:
	Phrase(string filename);
	void showWordOcc();
};