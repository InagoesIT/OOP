#include "Dacia.h"

Dacia::Dacia()
{
	this->fuelCapacity = 50;
	this->fuelConsumption = 4;
	this->avgSpeedRain = 55;
	this->avgSpeedSunny = 80;
	this->avgSpeedSnow = 45;
}

const char* Dacia::GetName()
{
	return "Dacia";
}