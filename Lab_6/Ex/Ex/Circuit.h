#pragma once
#include "Car.h"
#define MAX_CARS 200
#define OUT_OF_FUEL 0.0f

class Circuit
{
private:
	Weather weather;
	Car* carsList[MAX_CARS];
	int carsNr;
	int length;
	float ComputeFinishTime(Car& car);

public:
	Circuit();
	void SetLength(int len);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};