#include "Circuit.h"

Circuit::Circuit()
{
	this->weather = Weather::Sunny;
	this->carsNr = 0;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::SetLength(int len)
{
	this->length = len;
}

void Circuit::AddCar(Car* car)
{
	this->carsList[carsNr] = car;
	++carsNr;
}

float Circuit::ComputeFinishTime(Car& car)
{
	if (length / 100 * car.fuelConsumption <= car.fuelCapacity)
	{
		if (this->weather == Weather::Rain)
			return this->length / car.avgSpeedRain;
		else if (this->weather == Weather::Sunny)
			return this->length / car.avgSpeedSunny;
		else
			return this->length / car.avgSpeedSnow;
	}
	return OUT_OF_FUEL;
}

void Circuit::Race()
{
	int j;

	for (int i = 1; i < carsNr; i++)
	{
		j = i;
		while (j > 0 && ComputeFinishTime(*carsList[j - 1]) > ComputeFinishTime(*carsList[j]))
		{
			Car* temp = carsList[j - 1];
			carsList[j - 1] = carsList[j];
			carsList[j] = temp;
			j--;
		}
	}
}

void Circuit::ShowFinalRanks()
{
	cout << "Cars that finished the race successfully are: " << endl;
	float time; 

	for (int i = 0; i < carsNr; ++i)
	{
		if ((time = ComputeFinishTime(*carsList[i])) != OUT_OF_FUEL)
			cout << "  < " << carsList[i]->GetName() << " : " << time << endl;
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	float time;
	int firstNotFinished = 1;

	for (int i = 0; i < carsNr; ++i)
	{
		if ((time = ComputeFinishTime(*carsList[i])) == OUT_OF_FUEL)
		{
			if (firstNotFinished)
			{
				cout << "Cars that didn't have enough fuel to finish the race:" << endl;
				firstNotFinished = 0;
			}
			cout << "  < " << carsList[i]->GetName() << " : " << time << endl;
		}
	}

	if (firstNotFinished)
		cout << "All cars had enough fuel to finish the race." << endl;
}