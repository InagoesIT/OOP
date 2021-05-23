#include "Acquantaince.h"
#include "Agenda.h"
#include "Colleague.h"
#include "Friend.h"
#include "Contact.h"

#include <iostream>

using namespace std;

int main()
{
	Friend fr1("Max", "19.02.2000", "+373889292", "str.Stelelor 2");
	Friend fr2("Emma", "22.10.2006", "+3736689292", "str.Luminii 33");

	Acquantaince aq1("Elly", "14555500");
	Acquantaince aq2("Astrid", "24445110");

	Colleague cg1("John", "23.04.2000", "+37666692", "Rokka");
	Colleague cg2("Daisy", "11.04.1998", "+3766666292", "AsIn");

	Agenda agenda;
	agenda.addContact(fr1); agenda.addContact(fr2);
	agenda.addContact(aq1); agenda.addContact(aq2);
	agenda.addContact(cg1); agenda.addContact(cg2);

	cout << agenda.findContact("Astrid").name << endl;
	cout << "Astrid is deleted = " << agenda.deleteContact("Astrid") << endl;
	cout << agenda.findContact("Astrid").name;
	cout << "Astrid is deleted = " << agenda.deleteContact("Astrid") << endl;

	list<Contact*> ctsList = agenda.getFriendsList();
	cout << "The list of friends" << endl;
	for (auto itr : ctsList)
		cout << "Name: " << itr->name << endl;

	return 0;
}