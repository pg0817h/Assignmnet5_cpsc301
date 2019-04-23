// Name
// Section #
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.h"
#include "book.h"
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

// You are not obligated to use these function declarations - they're just given as examples
void readBooks(vector<Book *> & myBooks) {
	ifstream read("books.txt");

	int bookId;

	string title;

	string author;

	string category;


	

	string line;
	Book* b1 = NULL;

	int i = 0;
	if (read.is_open()) {
		read >> bookId;
		while (!read.eof()) {



			getline(read,line);

			getline(read, title);

			getline(read, author);

			getline(read, category);
			//Book(int id, string bookName, string auth, string cat);

			b1 = new Book(bookId, title, author, category);







			myBooks.push_back(b1);





			read >> bookId;



		}






	}


	read.close();



}

int readPersons(vector<Person *> & myCardholders) {

	int activeStatus = 0;
	int cardId = 0;
	string CfirstName;

	string ClastName;

	ifstream readP("persons.txt");

	Person* p1 = NULL;



	int j = 0;

	while (!readP.eof()) {

		readP >> cardId >> activeStatus >> CfirstName >> ClastName;

		//Person(int cardNo, bool act, string fName, string lName);

		p1 = new Person(cardId, activeStatus, CfirstName, ClastName);

		myCardholders.push_back(p1);


	}
	return 0;
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
	int bookI = 0;
	int cardId = 0;
	int i = 0;
	
	Person* p1 = NULL;

	ifstream readR("rentals.txt");
	while (!readR.eof()) {
		readR >> bookI >> cardId;
		for (int i = 0; i < myCardholders.size(); i++) {
			if (myCardholders.at(i)->getId() == cardId) {
				p1 = new Person(cardId, myCardholders[i]->isActive(), myCardholders[i]->getFirstName(), myCardholders[i]->getLastName());
			}
		}
		for (int i = 0; i < myBooks.size(); i++) {
			if (bookI == myBooks[i]->getId()) {

				myBooks[i]->setPersonPtr(p1);
			}


		}
	}
	readR.close();



	for (int i = 0; i < myBooks.size(); i++) {
		if (myBooks[i]->getPersonPtr() != nullptr) {
			cout << myBooks[i]->getId() <<" "<< myBooks[i]->getPersonPtr()->getId() << endl;
		}
	}
}

void openCard(vector<Person *> & myCardholders, int nextID) {
	string newFname;
	string newLname;
	
	int size;
	size = myCardholders.size()-1;
	cout << "size" << size;
	cout << "Please enter the first name:";
	cin >> newFname;
	cout << "Please enter the last name:";
	cin >> newLname;

	
	cout << "Card Id " << nextID << " Active" << endl;

	//Person(int cardNo, bool act, string fName, string lName)
	Person* p1 = NULL;
	p1 = new Person(nextID, 1, newFname, newLname);

	myCardholders.push_back(p1);




	ofstream output;

	output.open("persons.txt",ios::app);
	
		output << myCardholders[size+1]->getId() << " " << myCardholders[size+1]->isActive() << " " << myCardholders[size+1]->getFirstName() << " " << myCardholders[size+1]->getLastName() << endl;

	output.close();

	cout << endl;
	return;
}

void closeCard(vector<Person *> & myCardholders) {
	int cardId;
	char ask;
	cout << "Please enter the card ID: ";
	cin >> cardId;
	
	for (int i = 0; i < myCardholders.size() - 1; i++) {
		if (cardId == myCardholders[i]->getId()) {
			cout << "Cardholder:" << myCardholders[i]->getFirstName() << " " << myCardholders[i]->getLastName();
			cout << "Are you sure you want to deactivate card (y/n)?";
			cin >> ask;
			if (ask == 'y') {
				if (myCardholders.at(i)->isActive() == false) {
					cout << "Card ID is already inactive";
				}
				else
				myCardholders.at(i)->setActive(0);
				ofstream output("persons.txt");
				for (int i = 0; i < myCardholders.size()-1; i++) {
					

						output << myCardholders.at(i)->getId() << " " << myCardholders.at(i)->isActive() << " " << myCardholders.at(i)->getFirstName() << " " << myCardholders.at(i)->getLastName() <<endl;
					
				}
			}

		}
		
	}
}
Book * searchBook(vector<Book *> myBooks, int id) {
	
	for (int i = 0; i < myBooks.size(); i++) {
		if (myBooks[i]->getId() == id) {
			return myBooks.at(i);
		}
		
	}
	return nullptr;
}
void availableBook(vector<Book *> myBooks) {
	for (int i = 0; i < myBooks.size(); i++) {
		if (myBooks[i]->getPersonPtr() == nullptr) {
			cout << myBooks[i]->getTitle() << endl;
		}

	}
}

void OutstandingBooks(vector<Book *> myBooks) {
	for (int i = 0; i < myBooks.size(); i++) {
		if (myBooks[i]->getPersonPtr() != nullptr) {
			cout << myBooks[i]->getTitle() << endl;
		}

	}
}


void viewOutstandingRentals(vector<Book*> b2, vector<Person*> p2) {
	int cardId = 0;


	cout << "Please enter the card ID:";
	cin >> cardId;
	for (int i = 0; i <p2.size(); i++) {
		if (b2[i]->getPersonPtr() != nullptr) {

			if (cardId == b2[i]->getPersonPtr()->getId()) {
				cout << "Cardholder: " << p2[i]->getFirstName() << " " << p2[i]->getLastName() << endl;
				cout << "Book Title:" << b2[i]->getTitle() << endl;



			}

		}
	}
}
void bookCheckout(vector <Person*> p2, vector<Book*> b2) {



	int cardId = 0;

	string activeStatus;

	string CfirstName;

	string ClastName;


	cout << "Please enter the card ID: ";

	cin >> cardId;

	string fullN;

	
		for (int i = 0; i < p2.size(); i++) {

			if (p2[i]->getId() == cardId) {
				fullN = p2[i]->getFirstName() + " " + p2[i]->getLastName();
			}
			

			

		}
		if (!fullN.empty()) {
			cout << "Cardholder: " << fullN;
		}
		if(fullN.empty()) {
			cout << "Card ID not found";
			return;
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

	for (int i = 0; i < b2.size(); i++) {
		if (b2[i]->getId() == bookI) {

			if (b2[i]->getPersonPtr() != NULL) {
				cout << "book already checked out" << endl;
			}

			else if (b2[i]->getPersonPtr() == NULL) {
				cout << "Title:";
				cout << b2[i]->getTitle() << endl;
				ofstream output("Rentals.txt", ios::app);
				
				
				
				output <<endl << bookI << " " << cardId;

				output.close();

				cout << "Rentals completed" << endl;

			}




		}
		
	}

	cout << endl;


}


void bookReturn(vector <Person*> p2, vector<Book*> b2) {
	int bookId = 0;
	string bookN;
	cout << "Please enter the book ID to return: ";
	cin >> bookId;
	//searchBook(b2,bookId);
	for (int i = 0; i < b2.size(); i++) {
		if (b2[i]->getId() == bookId) {
			cout << "Title:";
			bookN = b2[i]->getTitle();
			cout << b2[i]->getTitle();


			b2[i]->setPersonPtr(nullptr);
			cout << "Return Completed";
		}
	}
	if (bookN.empty()) {
		cout << "Book ID not found";
		return;
	}
	
	ofstream output("rentals.txt");
	for (int i = 0; i < b2.size(); i++) {
		
		if (b2[i]->getPersonPtr() != nullptr) {
			output << b2[i]->getId() << " " << b2[i]->getPersonPtr()->getId()<< endl;
		}
	}
			output.close();
		
		
	

	cout << endl;

}



int main()
{
	vector<Book *> books;
	vector<Person *> cardholders;
	int bookI = 0;
	int cardId = 0;
	int i = 0;
	int bookId1 = 0;
	//void     setPersonPtr(Person * ptr);
	//Person * getPersonPtr();
	readBooks(books);
	readPersons(cardholders);
	readRentals(books,cardholders);
	
	Person * p1 = NULL;
	int j = 0;
	int cardId2 = 0;
	
	int choice;
	do
	{
		// If you use cin anywhere, don't forget that you have to handle the <ENTER> key that 
		// the user pressed when entering a menu option. This is still in the input stream.
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			// Book checkout
			bookCheckout(cardholders, books);
			break;

		case 2:
			// Book return
			bookReturn(cardholders,books);

			break;

		case 3:
			// View all available books
			availableBook(books);
			break;

		case 4:
			// View all outstanding rentals
			OutstandingBooks(books);
			break;

		case 5:
			// View outstanding rentals for a cardholder
			//viewOutstandingRentals(books, cardholders);
			cout << "Please enter the card ID:";
			cin >> cardId2;
			for (int i = 0; i < books.size(); i++) {
				if (books.at(i)->getPersonPtr() != nullptr) {
					if (books.at(i)->getPersonPtr()->getId() == cardId2) {
						cout << books.at(i)->getTitle();
					}

				

			}
				}
			
			


			break;

		case 6:
			// Open new library card
			openCard(cardholders,cardholders[cardholders.size()-1]->getId()+1);
			break;

		case 7:
			// Close library card
			closeCard(cardholders);
			break;

		case 8:
			// Must update records in files here before exiting the program
			break;

		default:
			cout << "Invalid entry" << endl;
			break;
		}
		cout << endl;
	} while (choice != 8);
	return 0;
}