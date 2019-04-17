/*
person(string lName, string fName, string ActiveS, int CId);
void setLastName(string lName);
string getLastName();
void setFirstName(string fName);
string getFirstName();
void setCardId(int CId);
int getCardId();
void setActiveStatus(string ActiveS);
string getActiveStatus();
*/
#include "person.h"
#include <iostream>

person::person(string lName, string fName, string ActiveS, int CId) {
	lastName = lName;
	firstName = fName;
	activeStatus = ActiveS;
	cardId = CId;
}

void person::setLastName(string lName) {

	lastName = lName;
}

string person::getLastName() {
	return lastName;
}

void person::setFirstName(string fName) {
	firstName = fName;
}

string person::getFirstName() {
	return firstName;
}

void person::setCardId(int CId) {
	cardId = CId;
}

int person::getCardId() {
	return cardId;
}

void person::setActiveStatus(string ActiveS) {
	activeStatus = ActiveS;
}

string person::getActiveStatus() {
	return activeStatus;
}