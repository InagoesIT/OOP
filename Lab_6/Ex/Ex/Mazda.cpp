#include "Mazda.h"

Mazda::Mazda()
{
	this->fuelCapacity = 60;
	this->fuelConsumption = 7;
	this->avgSpeedRain = 50;
	this->avgSpeedSunny = 90;
	this->avgSpeedSnow = 48;
}

const char* Mazda::GetName()
{
	return "Mazda";
}