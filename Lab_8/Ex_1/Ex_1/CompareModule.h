#pragma once

#include <string>
#include <map>
#include <utility>
#include <iostream>

using namespace std;

class CompareModule
{
public:
	bool operator()(const pair <int, string>& pair1, const pair <int, string>& pair2) const;
};