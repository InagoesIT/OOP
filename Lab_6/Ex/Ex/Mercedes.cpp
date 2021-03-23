#include "Mercedes.h"

Mercedes::Mercedes()
{
	this->fuelCapacity = 100;
	this->fuelConsumption = 7;
	this->avgSpeedRain = 60;
	this->avgSpeedSunny = 100;
	this->avgSpeedSnow = 50;
}

const char* Mercedes::GetName()
{
	return "Mercedes";
}