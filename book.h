#pragma once
#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class book {
private:
	int bookId;
	string bookTitle;
	string Author;
	string Category;
	string returnStatus;
public:

	book(string bookI, string bookT, string Au,string Cate,string returnS);

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

};

#endif
