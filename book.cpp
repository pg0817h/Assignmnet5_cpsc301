#include "book.h"
#include <iostream>
/*

book(string bookI, string bookT, string Au, string Cate, string returnS);

void setbookId(string bookI);
string getbookId();
void setbookTitle(string bookT);
string getbookTitle();
void setAuthor(string Au);
string getAuthor();
void setCategory(string Cate);
string getCategory();

void setreturnStatus(string returnS);
string getreturnStatus();
*/
book::book(int bookI, string bookT, string Au, string Cate) {
	bookId = bookI;
	bookTitle = bookT;
	Author = Au;
	Category = Cate;
}

void book::setbookId(int bookI) {
	bookId = bookI;
}

int book::getbookId() {
	return bookId;
}
void book::setbookTitle(string bookT) {
	bookTitle = bookT;
}

string book::getbookTitle() {
	return bookTitle;
}

void book::setAuthor(string Au) {
	Author = Au;
}

string book::getAuthor() {
	return Author;
}

void book::setCategory(string Cate) {
	Category = Cate;
}

string book::getCategory() {

	return Category;
}

void book::setreturnStatus(string returnS) {
	returnStatus = returnS;
}

string book::getreturnStatus() {
	return returnStatus;
}
