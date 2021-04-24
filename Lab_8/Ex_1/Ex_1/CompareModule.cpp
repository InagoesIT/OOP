#include "CompareModule.h"

bool CompareModule::operator()(const pair <int, string>& pair1, const pair <int, string>& pair2) const
{
	if (pair1.first == pair2.first)
		return (pair1.second > pair2.second);
	else
		return (pair1.first < pair2.first);
}