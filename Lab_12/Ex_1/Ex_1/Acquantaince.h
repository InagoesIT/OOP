#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Contact.h"

using namespace std;

class Acquantaince : public Contact
{
public:
	string phoneNr;

	Acquantaince(string name, string phoneNr);
};