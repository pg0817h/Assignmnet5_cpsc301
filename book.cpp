#include "book.h"
#include <iostream>

book::book(int bookI, string bookT, string Au, string Cate,string returnS) {
	bookId = bookI;
	bookTitle = bookT;
	Author = Au;
	Category = Cate;
	returnStatus = returnS;
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