#include "Friend.h"

Friend::Friend(string name, string birthDate, string phoneNr, string adress)
{
	this->type = FRIEND;
	this->name = name;
	this->birthDate = birthDate;
	this->phoneNr = phoneNr;
	this->adress = adress;
}