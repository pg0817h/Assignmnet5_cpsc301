#include <iostream>
#include <vector>
#include <string>
#include "book.h"
#include "person.h"
#include <fstream>

//#include "person.h"
using namespace std;
/*
void readData(vector <book*> b, vector <person*> p) {
	ifstream read("books.txt");
	int bookId;
	string title;
	string author;
	string category;
	
	//vector<book> b;
	book* b1 = NULL;
	while (!read.eof()) { 
		read >> bookId;
		getline(cin, title);
		getline(cin, author);
		getline(cin, category);
		b1 = new book(bookId,title,author, category);

		//b.emplace_back(bookId, title, author, category);
		b.push_back(b1->setbookId);
		b.push_back(b1->setAuthor);
		b.push_back(b1->setCategory);
		b.push_back(b1->setbookTitle);
	}
	/*
	for (int i = 0; b.size()-1; i++) {
		b[i].setbookId(bookId);
		b[i].setbookTitle(title);
		b[i].setAuthor(author);
		b[i].setCategory(category);


	}
	
	read.close();

	int cardId;
	string activeStatus;
	string CfirstName;
	string ClastName;
	ifstream readP("persons.txt");
	person* p1 = NULL;
	//vector<person> p;
	//person(string lName, string fName, string ActiveS, int CId)
	p1 = new person(ClastName, CfirstName,activeStatus,cardId);
	while (!readP.eof()) {
		readP >> cardId >> activeStatus >> CfirstName >> ClastName;

		//p.emplace_back(ClastName, CfirstName, activeStatus, cardId);
		p.push_back(p1->setActiveStatus);
	}
	/*
	for (int i = 0; i < p.size() - 1; i++) {
		p[i].setCardId(cardId);
		p[i].setActiveStatus(activeStatus);
		p[i].setFirstName(CfirstName);
		p[i].setLastName(ClastName);


	}
	
}
void bookCheckout(vector<person> &p) {
	int cardi;

	cout << "Please enter the card ID";
	cin >> cardi;
	cout << "Cardholder";
	for (int i = 0; i < p.size() - 1; i++) {
		if (cardi == p[i].getCardId) {
			cout << p[i].getFirstName << " " << p[i].getLastName;
		}
	}
	cout << "Please enter the book ID";
	cout << "Title";
	cout << "Rental Completed";

}
*/
void readData(vector<book *> b) {

	ifstream read("books.txt");
	int bookId;
	string title;
	string author;
	string category;

	//vector<book> b;
	book* b1 = NULL;
	int i = 0;
	while (!read.eof()) {

		read >> bookId;
		read.ignore(1, '\n');
		getline(read, title);
		getline(read, author);
		getline(read, category);
		b1 = new book(bookId, title, author, category);


		//b.emplace_back(bookId, title, author, category);
		b.push_back(b1);
		b[i]->setAuthor(author);
		b[i]->setbookId(bookId);
		b[i]->setbookTitle(title);
		b[i]->setCategory(category);


		i++;
	}




	read.close();
}

void bookCheckout(vector <person*> p2) {
	
	int cardId = 0;
	string activeStatus;
	string CfirstName;
	string ClastName;
	

	
	cout << "Please enter the card ID";
	cin >> cardId;
	cout << "Cardholder";
	for (int i = 0; i < 1; i++) {
		if (p2[i]->getCardId() == cardId) {
			cout << p2[i]->getFirstName() + " " + p2[i]->getLastName();
		}
		
	}
	cout << endl;
	
	cout << "Please enter the book ID";
	cout << "Title";
	cout << "Rental Completed";

}

int main() {

	vector<book *> books;
	vector<person *> cardholders;
	
	ifstream read("books.txt");
	int bookId;
	string title;
	string author;
	string category;

	//vector<book> b;
	book* b1 = NULL;
	int i = 0;
	while (!read.eof()) {
		
		read >> bookId;
		read.ignore(1, '\n');
		getline(read, title);
		getline(read, author);
		getline(read, category);
		b1 = new book(bookId, title, author, category);


		//b.emplace_back(bookId, title, author, category);
		books.push_back(b1);
		books[i]->setAuthor(author);
		books[i]->setbookId(bookId);
		books[i]->setbookTitle(title);
		books[i]->setCategory(category);
			

			i++;
	}

		
	
	
	
	read.close();
	
	int cardId =0;
	string activeStatus;
	string CfirstName;
	string ClastName;
	ifstream readP("persons.txt");
	person* p1 = NULL;
	
	int j = 0;
	while (!readP.eof()) {
		readP >> cardId >> activeStatus >> CfirstName >> ClastName;

		p1 = new person(ClastName, CfirstName, activeStatus, cardId);
		cardholders.push_back(p1);
		cardholders[j]->setCardId(cardId);
		cardholders[j]->setActiveStatus(activeStatus);
		cardholders[j]->setFirstName(CfirstName);
		cardholders[j]->setLastName(ClastName);
		j++;
	}
	bookCheckout(cardholders);
	/*
	string cardholder;


	cout << "Please enter the card ID";
	cin >> cardId;
	cout << "Cardholder";
	for (int i = 0; i < cardholders.size(); i++) {
		if (cardholders[i]->getCardId() == cardId) {
			cardholder = cardholders[i]->getFirstName() + " " + cardholders[i]->getLastName();
			exit;
		}
		else
			cout << "No CardId found";
		
		
	}
	cout << cardholder;
	
	cout << "Please enter the book ID";
	cout << "Title";
	cout << "Rental Completed";
	*/
	system("pause");
}