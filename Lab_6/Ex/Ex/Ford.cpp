#include "Ford.h"

Ford::Ford()
{
	this->fuelCapacity = 40;
	this->fuelConsumption = 8;
	this->avgSpeedRain = 40;
	this->avgSpeedSunny = 70;
	this->avgSpeedSnow = 35;
}

const char* Ford::GetName()
{
	return "Ford";
}