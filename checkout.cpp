#include <iostream>

#include <vector>

#include <string>

#include "book.h"

#include "person.h"

#include <fstream>





using namespace std;

void printMenu() {
	cout << "----------Library Book Rental System----------" << endl;
	cout << "1.  Book checkout" << endl;
	cout << "2.  Book return" << endl;
	cout << "3.  View all available books" << endl;
	cout << "4.  View all outstanding rentals" << endl;
	cout << "5.  View outstanding rentals for a cardholder" << endl;
	cout << "6.  Open new library card" << endl;
	cout << "7.  Close library card" << endl;
	cout << "8.  Exit system" << endl;
	cout << "Please enter a choice: ";
}

void readRentals(vector<book*> &b, vector<person*> &p) {
	int bookI = 0;
	int cardId = 0;
	int i = 0;
	
	
	ifstream readR("Rentals.txt");
	while (!readR.eof()) {
		readR >> bookI >> cardId;
		for (int n = 0; n < b.size()-1; n++) {
			if (bookI == b[n]->getbookId()) {
				b[n]->setreturnStatus("n");
			}
			else {
				b[n]->setreturnStatus("y");
			}
			i++;
		}
	}
	readR.close();

}
void readbooks(vector<book *> &b) {



	ifstream read("books.txt");

	int bookId;

	string title;

	string author;

	string category;


	string returnS;


	book* b1 = NULL;

	int i = 0;

	while (!read.eof()) {



		read >> bookId;

		read.ignore(1, '\n');

		getline(read, title);

		getline(read, author);

		getline(read, category);

		b1 = new book(bookId, title, author, category, returnS);







		b.push_back(b1);

		b[i]->setAuthor(author);

		b[i]->setbookId(bookId);

		b[i]->setbookTitle(title);

		b[i]->setCategory(category);





		i++;
		
	}









	read.close();

}
void readpersons(vector<person*> &p2) {
	string activeStatus;
	int cardId = 0;
	string CfirstName;

	string ClastName;

	ifstream readP("persons.txt");

	person* p1 = NULL;



	int j = 0;

	while (!readP.eof()) {

		readP >> cardId >> activeStatus >> CfirstName >> ClastName;



		p1 = new person(ClastName, CfirstName, activeStatus, cardId);

		p2.push_back(p1);

		p2[j]->setCardId(cardId);

		p2[j]->setActiveStatus(activeStatus);

		p2[j]->setFirstName(CfirstName);
		p2[j]->setLastName(ClastName);

		j++;

	}
}

void bookCheckout(vector <person*> p2, vector<book*> b2) {



	int cardId = 0;

	string activeStatus;

	string CfirstName;

	string ClastName;







	cout << "Please enter the card ID: ";

	cin >> cardId;

	cout << "Cardholder: ";

	for (int i = 0; i < 1; i++) {

		if (p2[i]->getCardId() == cardId) {

			cout << p2[i]->getFirstName() + " " + p2[i]->getLastName() << endl;

		}

		else
			cout << "Card Id not found";

	}

	cout << endl;

	//book(int bookI, string bookT, string Au, string Cate);
	int bookI = 0;
	string bookT;
	string Author;
	string category;

	cout << "Please enter the book ID: ";
	cin >> bookI;
	cout << endl;

	for (int i = 0; i < 1; i++) {
		if (b2[i]->getbookId() == bookI) {

			if (b2[i]->getreturnStatus() == "n") {
				cout << "book already checked out" << endl;
			}

			else if (b2[i]->getreturnStatus() == "y") {
				cout << "Title:";
				cout << b2[i]->getbookTitle() << endl;
				ofstream output;
				output.open("Rentals.txt");
				for (int i = 0; i < 1; i++) {
					output << bookI << " " << cardId << endl;
				}
				output.close();

				cout << "Rentals completed" << endl;

			}




		}
		else
			cout << "book Id not found";
	}

	cout << endl;


}

void Bookreturn(vector<book*> b2) {
	int bookId = 0;

	cout << "Please enter the book ID to return: ";
	cin >> bookId;
	for (int i = 0; i < 1; i++) {
		if (b2[i]->getbookId() == bookId) {
			cout << "Title:";
			cout << b2[i]->getbookTitle();
			ofstream output;
			output.open("Rentals.txt");
			for (int i = 0; i < b2.size(); i++) {
				output << " " << endl;
			}
			output.close();
			b2[i]->setreturnStatus("y");

			cout << "Return Completed";
		}
		else {
			cout << "Book ID not found";
		}
	}
	cout << endl;
}


void viewAvailablebooks(vector<book*> b2) {
	for (int i = 0; i < b2.size() - 1; i++) {
		if (b2[i]->getreturnStatus() == "y") {
			cout << "Book ID:" << b2[i]->getbookId() << endl;
			cout << "Title:" << b2[i]->getbookTitle() << endl;
			cout << "Author:" << b2[i]->getAuthor() << endl;
			cout << "Category:" << b2[i]->getCategory() << endl;

		}
		else if(b2[i]->getreturnStatus() == "n")
		{
			cout << "No available books";
		}
	}
	cout << endl;
}
void viewRentals(vector<book*> b2) {
	for (int i = 0; i < b2.size() - 1; i++) {
		if (b2[i]->getreturnStatus() == "n") {
			cout << "Book ID:" << b2[i]->getbookId() << endl;
			cout << "Title:" << b2[i]->getbookTitle() << endl;
			cout << "Author:" << b2[i]->getAuthor() << endl;
			cout << "Category:" << b2[i]->getCategory() << endl;

		}
		else if (b2[i]->getreturnStatus() == "y") {
			cout << b2[i]->getreturnStatus();
			cout << "No rentals books";
		}
	}
	cout << endl;
}
void viewOutstandingRentals(vector<book*> b2, vector<person*> p2) {
	int cardId = 0;


	cout << "Please enter the card ID:";
	cin >> cardId;
	for (int i = 0; i < p2.size()-1; i++) {
		if (cardId == p2[i]->getCardId()) {
			cout << "Cardholder: " << p2[i]->getFirstName() << " " << p2[i]->getLastName() << endl;

			int bookI;
			int cardId2 = 0;
			int	j = 0;

			ifstream readR("Rentals.txt");
			while (!readR.eof()) {
				readR >> bookI >> cardId2;

				j++;





				if (cardId2 == cardId) {
					cout << "Book ID" << b2[i]->getbookId() << endl;
					if (bookI == b2[i]->getbookId()) {
						cout << b2[i]->getbookTitle() << endl;
						cout << b2[i]->getAuthor() << endl;
						cout << endl;
					}
				}
				else {
					cout << "No books currently checked out." << endl;

				}
			}
		}


	}
	cout << endl;
}

void OpenNewLibraryCard(vector<person*> p2) {
	string newFname;
	string newLname;
	int availableID;
	int size;
	size = p2.size() - 1;

	cout << "Please enter the first name:";
	cin >> newFname;
	cout << "Please enter the last name:";
	cin >> newLname;

	availableID = p2[size]->getCardId() + 1;
	cout << "Card Id " << availableID << " Active" << endl;


	person* p1 = NULL;
	p1 = new person(newLname, newFname, "active", availableID);

	p2.push_back(p1);
	p2[size + 1]->setCardId(availableID);
	p2[size + 1]->setActiveStatus("active");
	p2[size + 1]->setFirstName(newFname);
	p2[size + 1]->setLastName(newLname);



	ofstream output;

	output.open("persons.txt");
	for (int i = size; i < p2.size(); i++) {
		output << p2[i]->getCardId() << " " << p2[i]->getActiveStatus() << " " << p2[i]->getFirstName() << " " << p2[i]->getLastName() << endl;
	}
	output.close();

	cout << endl;
}

void closeLibraryCard(vector<person*> p2) {
	int cardId = 0;
	string answer;
	cout << "Please enter the card ID:";
	cin >> cardId;
	for (int i = 0; i < p2.size(); i++) {
		if (p2[i]->getCardId() == cardId) {

			cout << "CardHolder: " << p2[i]->getFirstName() << " " << p2[i]->getLastName() << endl;
			cout << "Are you sure you want to deactivate card (y/n)?";
			cin >> answer;
			if (answer == "y") {
				if (p2[i]->getActiveStatus() == "inactive") {
					cout << "Card Id is already inactive";
				}
				else
					p2[i]->setActiveStatus("inactive");
				ofstream output("persons.txt");
				output << p2[i]->getCardId() << " " << p2[i]->getActiveStatus() << " " << p2[i]->getFirstName() << " " << p2[i]->getLastName();
				output.close();
				cout << "Card Id deactivated";
			}
			else {
				exit;
			}


		}

		else {
			cout << "Card ID not found" << endl;
		}
	}
	cout << endl;

}
int main() {



	vector<book *> books;

	vector<person *> cardholders;




	int choice;
	do
	{
		// If you use cin anywhere, don't forget that you have to handle the <ENTER> key that
		// the user pressed when entering a menu option. This is still in the input stream.
		printMenu();
		readbooks(books);

		readpersons(cardholders);

		readRentals(books, cardholders);
		cin >> choice;
		switch (choice)
		{
		case 1:
			// Book checkout
			bookCheckout(cardholders, books);
			break;

		case 2:
			// Book return
			Bookreturn(books);
			break;

		case 3:
			// View all available books
			viewAvailablebooks(books);
			break;

		case 4:
			// View all outstanding rentals
			viewRentals(books);
			break;

		case 5:
			// View outstanding rentals for a cardholder
			viewOutstandingRentals(books, cardholders);
			break;

		case 6:
			// Open new library card
			OpenNewLibraryCard(cardholders);
			break;

		case 7:
			// Close library card
			closeLibraryCard(cardholders);
			break;

		case 8:
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
		cout << endl;
	} while (choice != 8);




	cout << endl;




	system("pause");

}