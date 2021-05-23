#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Contact.h"
#include "Friend.h"

using namespace std;

class Agenda
{
private:
	list<Contact*> contactsList;

public:
	Contact& findContact(string name);
	list<Contact*> getFriendsList();
	bool deleteContact(string name);
	void addContact(Contact& contactNew);
};
#endif
