#include "Colleague.h"

Colleague::Colleague(string name, string firmName, string phoneNr, string adress)
{
	this->type = COLLEAGUE;
	this->name = name;
	this->firmName = firmName;
	this->phoneNr = phoneNr;
	this->adress = adress;
}