#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class person {
private:
	string lastName;
	string firstName;
	string activeStatus;
	int cardId;

public:
	person(string lName,string fName, string ActiveS, int CId);
	void setLastName(string lName);
	string getLastName();
	void setFirstName(string fName);
	string getFirstName();
	void setCardId(int CId);
	int getCardId();
	void setActiveStatus(string ActiveS);
	string getActiveStatus();




};

#endif


