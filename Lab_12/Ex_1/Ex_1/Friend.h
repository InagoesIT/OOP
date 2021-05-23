#ifndef FRIEND_H
#define FRIEND_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Contact.h"

using namespace std;

class Friend : public Contact
{
public:
	string birthDate;
	string phoneNr;
	string adress;

	Friend(string name, string birthDate, string phoneNr, string adress);
};

#endif