#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <iostream>
using namespace std;
class Book
{

    friend class Library;
    string Title;
    string author;
    int publicationYear;
    int uniqueID;

    public:
        static int bookID;
        Book(string,string, int);
        Book();
        ~Book();
        Book(Book&);
        void setID(int);
        string getTitle() {return this->Title;}
        string getAuthor() {return this->author;}
        int getPublicationYear() {return this->publicationYear;}
        int getID() const{return uniqueID;}
};

#endif // BOOK_H_INCLUDED
