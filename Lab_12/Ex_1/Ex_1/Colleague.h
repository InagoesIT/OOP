#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <string>
#include <vector>
#include <list>
#include "Contact.h"
#include "ContactType.h"

using namespace std;

class Colleague : public Contact
{
public:
	string phoneNr;
	string adress;
	string firmName;

	Colleague(string name, string birthDate, string phoneNr, string adress);
};
#endif