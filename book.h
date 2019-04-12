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

	//book(int bookI, string bookT, string Au,string Cate,string returnS);
	book(int bookI, string bookT, string Au, string Cate);
	void setbookId(int bookI);
	int getbookId();
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
