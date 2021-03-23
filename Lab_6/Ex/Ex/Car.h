#pragma once

#include "Weather.h"
#include <iostream>

using namespace std; 

class Car
{
public:
	float fuelCapacity;
	float fuelConsumption;
	float avgSpeedRain;
	float avgSpeedSunny;
	float avgSpeedSnow;
	virtual const char* GetName() = 0;
};