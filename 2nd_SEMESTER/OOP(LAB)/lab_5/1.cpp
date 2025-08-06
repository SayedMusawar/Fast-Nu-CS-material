#include<iostream>
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
    void borrowBook(string borrower);
};
void Book::borrowBook(string) {

}
int main() {
    
    return 0;
}