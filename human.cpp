#include "human.h"
#include "library.h"
#include "book.h"
#include <iostream>
using namespace std;


int Borrower::uniqueMemberID = 1 ;

Human::Human(string name){
    this->Name = name;
}
Human::Human(){
}
Human::~Human(){

}
Borrower::Borrower(string name):Human(name){
    this->memberID = Borrower::uniqueMemberID++;
    this->booksBorrowed = 0;
    this->maxBooksAllowed = 5;
    this->bookList = new Book[maxBooksAllowed];
}
Borrower::~Borrower(){
    delete[] bookList;
}
void Borrower::getBookList(){
    if(booksBorrowed==0){
        cout<<"This member currently has no books in possession that are the property of a library."<<endl;
    }
    else{
        for(int XX = 0; XX<booksBorrowed; XX++){
            cout <<"bookID : "<< bookList[XX].getID()<<endl;
            cout <<"Book Title : "<<bookList[XX].getTitle()<<endl;
            cout <<"Book Title : "<<bookList[XX].getAuthor()<<endl;
            cout <<"Book Title : "<<bookList[XX].getPublicationYear()<<endl<<endl;
        }
    }
}

void Borrower::borrowBook(Library& libraryInstance, int index){
    if(this->booksBorrowed>=this->maxBooksAllowed){
        cout<<"This member already possesses the maximum amount of library books allowed. He must return the previously borrowed books in order to borrow new ones"<<endl;
    }
    else{
        this->bookList[this->booksBorrowed] = libraryInstance.bookArray[index-1];
        this->bookList[this->booksBorrowed].setID(libraryInstance.bookArray[index-1].getID());
        cout<< "ID of the book borrowed : " <<  this->bookList[this->booksBorrowed].getID()<<endl;
        //this->libraryList[this->booksBorrowed] = libraryInstance;
        for(int XX=index-1; XX<libraryInstance.currentAmountOfBooks-1; XX++){
            libraryInstance.bookArray[XX] =  libraryInstance.bookArray[XX+1];
        }
        //libraryInstance.bookArray[libraryInstance.currentAmountOfBooks-1]* = nullptr;
        libraryInstance.currentAmountOfBooks--;
        this->booksBorrowed++;
    }
}

void Borrower::returnBook(Library& libraryReference,int BookNo){
    if(BookNo>this->booksBorrowed){
        cout<< "There is no book alloted space at this index in the book list"<<endl;
    }
    else{
        if(this->booksBorrowed==0){
            cout<<"This member does not posses any library owned books."<<endl;
        }
        else{
            libraryReference.AddBook(this->bookList+BookNo-1);
            for(int XX=BookNo-1;XX<this->booksBorrowed-1;XX++){
                  this->bookList[XX] = this->bookList[XX+1];
            }
            this->booksBorrowed--;
        }
    }
}
