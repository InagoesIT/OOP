#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Agenda.h"


Contact& Agenda::findContact(string name)
{
	for (auto const& contact : contactsList)
		if (contact->name == name)
			return *contact;

	return *(new Contact());
}

list<Contact*> Agenda::getFriendsList()
{
	list<Contact*> friendsList;
	for (auto const& contact : contactsList)
		if (contact->type == FRIEND)
			friendsList.push_back(contact);

	return friendsList;
}

bool Agenda::deleteContact(string name)
{
	for (auto const& contact : contactsList)
		if (contact->name == name)
		{
			contactsList.remove(contact);
			return true;
		}

	return false;
}

void Agenda::addContact(Contact& newContact)
{
	this->contactsList.push_back(&newContact);
}