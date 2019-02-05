#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED
using namespace std;
#include "library.h"
#include "book.h"
#include <iostream>

class Human{
    protected:
        string Name;
    public:
        Human(string);
        Human();
        ~Human();
        string getName() const{return Name;}
};

class Borrower: public Human{
    protected:
        int memberID;
        int booksBorrowed;
        int maxBooksAllowed;
        Book* bookList;
    public:
        static int uniqueMemberID;
        Borrower(string);
        Borrower();
        ~Borrower();
        Borrower(const Borrower&) = delete;
        Borrower& operator= (const Borrower&) = delete;
        int getID() {return memberID;}
        void getBookList ();
        void borrowBook (Library& , int);
        void returnBook (Library& , int);
};
#endif // HUMAN_H_INCLUDED
