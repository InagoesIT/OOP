#include "Toyota.h"

Toyota::Toyota()
{
	this->fuelCapacity = 95;
	this->fuelConsumption = 5;
	this->avgSpeedRain = 70;
	this->avgSpeedSunny = 90;
	this->avgSpeedSnow = 60;
}

const char* Toyota::GetName()
{
	return "Toyota";
}