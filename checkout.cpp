#include <iostream>
#include <vector>
#include <string>
#include "book.h"
#include "person.h"
#include <fstream>

//#include "person.h"
using namespace std;
void readData(vector<book> &p) {
	ifstream read("books.txt");
	int bookId;
	string title;
	string author;
	string category;
	int n = 0;
	while (! read.eof()) {
		read >> bookId;
		getline(cin, title);
		getline(cin, author);
		getline(cin, category);
		p.emplace_back(bookId, title,author,category);
		n++;
	}
	for (int i = 0; i < n; i++) {
		p[i].setbookId(bookId);
		p[i].setbookTitle(title);
		p[i].setAuthor(author);
		p[i].setCategory(category);


	}
}
void bookCheckout(vector<person> &p) {
	cout << "Please enter the card ID";

	cout << "Cardholder";

	cout << "Please enter the book ID";
	cout << "Title";
	cout << "Rental Completed";

}

int main() {

	vector<book *> books;
	vector<person *> cardholders;

	vector<book> p;
	vector<person> p2;
	ifstream readb("books.txt");
	int bookId;
	string title;
	string author;
	string category;
	string returnS;

	while (! readb.eof()) {
		readb >> bookId;
		readb.ignore(1, '\n');
		getline(readb, title);
		getline(readb, author);
		getline(readb, category);
		p.emplace_back(bookId, title, author, category);
	}

	for (int i = 0; i < p.size()-1; i++) {
		p[i].setbookId(bookId);
		p[i].setbookTitle(title);
		p[i].setAuthor(author);
		p[i].setCategory(category);


	}

	int cardId;
	string activeStatus;
	string CfirstName;
	string ClastName;
	ifstream readP("persons.txt");

	while (!readP.eof()) {
		readP >> cardId >> activeStatus >> CfirstName >> ClastName;

		p.emplace_back(ClastName, CfirstName, activeStatus, cardId);
	}

	for (int i = 0; i < p2.size() - 1; i++) {
		p2[i].setbookId(bookId);
		p2[i].setbookTitle(title);
		p2[i].setAuthor(author);
		p2[i].setCategory(category);


	}
}
