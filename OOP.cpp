#include <iostream>
#include "library.h"
#include "book.h"
#include "human.h"
using namespace std;

int main(){
    Book book1("AA","aa",1);// Creating a book instance.
    Book book2("BB","bb",2);// Creating a book instance.
    Book book3(book1);// copying a book as a way of reprinting it in a library.
    Library library1(4);// Creating a library instance with 4 books allowed which will dynamically allocate the memory acocording to the argument.
    Book book4("CC","cc",3);//Creating a book instance.

    library1.AddBook(&book1);//Adding books via reference so as to not initialize the copy constructor (caused by the "=" or assign sign).
    library1.AddBook(&book2);
    library1.AddBook(&book3);
    library1.AddBook(&book4);
    library1.GetBookInfo(1);// getting info on book at the index which has been input as the argument.
    Borrower member1("Sadanand Naik"); // Creating an instance of a derived class which will act as a customer/member of the library.
    cout<<member1.getID()<<". "<<member1.getName()<<endl;//checking if the derived class functions can call super class function.
    member1.getBookList();//checking books currently in possession before borrowing
    member1.borrowBook(library1,1);//borrowing one book.
    member1.borrowBook(library1,3);//borrowing another book.
    library1.ShowAllBooks();//checking books available in library after the borrowing.
    member1.getBookList();// checking books in possession of the member.
    member1.returnBook(library1,2);//returning one of the borrowed books to the library.
    library1.ShowAllBooks();//checking if the book is back in the library after the exchange
    return 0;
}
