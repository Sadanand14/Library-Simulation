#include "library.h"
#include "book.h"

Library::Library(int XX){
    currentAmountOfBooks = 0;
    this->maxBooks = XX;
    this->bookArray = new Book[this->maxBooks];
}
Library::Library(){

}
Library::~Library(){
    delete[] this->bookArray;
}

void Library::AddBook(Book *X){
    if(this->currentAmountOfBooks == this->maxBooks){
        cout<<"Max capacity reached for this library already!!"<<endl;
    }
    else{
        this->bookArray[this->currentAmountOfBooks] = *X;
        cout<<"Book with ID "<<this->bookArray[this->currentAmountOfBooks].uniqueID<<" added."<<endl;
        //this->bookArray[this->currentAmountOfBooks].setID(X->getID());
        this->currentAmountOfBooks++;
    }
}

Book Library::GetBookInfo(int X){
    if(X<=this->maxBooks&&X>0){
        cout<<this->bookArray[X-1].getID()<<endl;
        cout<<this->bookArray[X-1].getTitle()<<endl;
        cout<<this->bookArray[X-1].getAuthor()<<endl;
        cout<<this->bookArray[X-1].getPublicationYear()<<endl;
        return this->bookArray[X-1];
    }
    else{
        cout << "parameter out of range. Returning 1st book instead."<<endl;
        cout<<this->bookArray[0].getID()<<endl;
        cout<<this->bookArray[0].getTitle()<<endl;
        cout<<this->bookArray[0].getAuthor()<<endl;
        cout<<this->bookArray[0].getPublicationYear()<<endl;
        return this->bookArray[0];
    }
}

void Library::ShowAllBooks(){
    if(this->currentAmountOfBooks==0){
        cout <<"This library does not have any books to be shown at the moment"<<endl;
    }
    else{
        for(int XX = 0; XX<currentAmountOfBooks; XX++){
            cout<<(XX+1)<<". "<<bookArray[XX].getTitle()<<endl;
        }
    }
}
