#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include <iostream>
#include "book.h"
using namespace std;

class Library{

    friend class Borrower;
    int maxBooks;
    Book* bookArray;
    int currentAmountOfBooks;

    public:
        Library();
        Library(int);
        ~Library();
        void AddBook(Book*);
        void ShowAllBooks();
        Book GetBookInfo(int);
};

#endif // LIBRARY_H_INCLUDED
