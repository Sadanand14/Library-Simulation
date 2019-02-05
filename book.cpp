#include "book.h"
#include <iostream>;
using namespace std;

int Book::bookID = 0;
Book::Book(Book& BookToCopy){
    this->Title = BookToCopy.getTitle();
    this->author = BookToCopy.getAuthor();
    this->publicationYear = BookToCopy.getPublicationYear();
    this->uniqueID = Book::bookID++;
}

Book::Book(string Name,string Author, int year){
    this->uniqueID = Book::bookID++;
    cout<<"The unique ID number for this book is : "<<uniqueID<<endl;
    this->Title = Name;
    this->author = Author;
    this->publicationYear = year;
}
void Book::setID(int XX){
    this->uniqueID = XX;
}
Book::Book(){

}
Book::~Book(){

}


