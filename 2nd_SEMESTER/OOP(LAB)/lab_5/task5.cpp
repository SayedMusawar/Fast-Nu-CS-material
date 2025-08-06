#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isBorrowed;
    string borrowerName;
public:
    Book() {
        bookID = 0;
        title = "";
        author = "";
        isBorrowed = false;
        borrowerName = "";
    }
    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        isBorrowed = false;
        borrowerName = "";
    }
    void borrowBook(string borrower) {
        if (!isBorrowed) {
            isBorrowed = true;
            borrowerName = borrower;
            cout<<"Book"<<title<<"' borrowed by " << borrower << "!"<<endl;
        } else {
            cout << "Sorry, the book '" << title << "' is already borrowed by " << borrowerName << "."<<endl;
        }
    }
    void returnBook() {
        if (isBorrowed) {
            cout << "Book '" << title << "' returned by " << borrowerName << "!"<<endl;
            isBorrowed = false;
            borrowerName = "";
        } else {
            cout << "This book is not currently borrowed.\n";
        }
    }
    void displayInfo() {
        cout << "Book ID: " << bookID << "\nTitle: " << title << "\nAuthor: " << author <<endl;
        if (isBorrowed)
            cout << "Status: Borrowed by " << borrowerName << endl;
        else
            cout << "Status: Available"<<endl;
        cout << "-----------------------\n";
    }
};

int main() {
    Book book1(101, "The Great Gatsby", "F. Scott Fitzgerald");
    Book book2(102, "1984", "George Orwell");
    Book book3; 
    book1.displayInfo();
    book2.displayInfo();
    book3.displayInfo();
    book1.borrowBook("Alice");
    book2.borrowBook("Bob");
    book1.borrowBook("Charlie");
    book1.returnBook();
    book1.returnBook();
    book1.displayInfo();
    book2.displayInfo();
    return 0;
}
