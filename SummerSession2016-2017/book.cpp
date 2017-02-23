#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int SIZE = 100;

class Book {
public:   
    string title_, authorName_, genre_, ISBN_;
    int numOfPages_;
    double price_;

    void findBook();
    void initBook(string, string, string, string, int, double);
};

void Book::initBook(string title, string authorName, string genre, string ISBN, int numOfPages, double price) {
    numOfPages_ = numOfPages;
    price_ = price;
    title_ = title;
    authorName_ = authorName;
    genre_ = genre;
    ISBN_ = ISBN;
}

void Book::findBook () {
    cout << title_ << ", ";
    cout << authorName_ << ", ";
    cout << genre_ << ", ";
    cout << ISBN_ << ", ";
    cout << numOfPages_ << ", ";
    cout << price_ << endl;
}

int main() {
    Book book[30];
    int num;
    do {
        cout << "Num of books? (between 1 and 30): ";
        cin >> num;
    } while (num < 1 || num > 30);
    
    string title, author, genre, isbn;
    int numPage, price;
    for(int i = 0; i < num; i++) {
        cin.ignore(2,'\n');
        cout << "Title: ";
        getline(cin, title);
        
        cout << "Author: ";
        getline(cin, author);
        
        cout << "Genre: ";
        getline(cin, genre);
        
        cout << "ISBN: ";
        getline(cin, isbn);
        
        cout << "Number of Pages: ";
        cin >> numPage;
        
        cout << "Price: ";
        cin >> price;
        
        book[i].initBook(title, author, genre, isbn, numPage, price);
    }
    
    cin.ignore(1,'\n');
    string findThisBook;
    cout << "What book are you looking for? ";
    getline(cin, findThisBook);

    for(int i = 0; i < num; i++) {
        if ( book[i].title_ == findThisBook ) {
            book[i].findBook();
            break;
        }
    }

    return 0;
}
