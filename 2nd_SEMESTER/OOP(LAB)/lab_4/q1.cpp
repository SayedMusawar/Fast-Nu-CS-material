#include<iostream>
using namespace std;
int add;
struct Book {
    int book_id;
    string title;
    string author;
    int year;
    bool is_available;
};
void addBook(Book *b,int size,int &count ) {
    
    cout<<"Enter the number of books you want to add";
    cin >> add;
    
    if (add + count <= size) {
        for(int i = 0; i <add; i++) {
            cout<<"Enter data for book "<<i + count<<endl;
        
            cout<<"Please enter book id ";
            cin >> b[count].book_id;

            cout<<"Please enter book title ";
            getline(cin,b[count].title);

            cout<<"Please enter book author ";
            getline(cin,b[count].author);

            cout<<"Please enter year of publication ";
            cin >> b[count].year;

            cout<<"is the book available? ";
            cin >> b[count].is_available;
            count++;
        }
    } else cout<<"Not enough space to add "<<add<<" books."<<endl;
    
}
void displayBook(const Book *b,int count) {
    cout<<"Book details"<<endl;
    for(int i = 0; i < count; i++) {
        cout<<"ID:" <<b[i].book_id<<endl;
        cout<<"Title: "<<b[i].title<<endl;
        cout<<"Author: "<<b[i].author<<endl;
        cout<<"Year: "<<b[i].year<<endl;
        cout<<"Status ";
        if(b[i].is_available == true) cout<<"Available"<<endl;
        else cout<<"Not available"<<endl;
    }
}
bool searchBook(const Book books[], int count, Book & foundBook) {
    int search_id;
    cout<<"Enter book id to search: "<<endl;
    cin >> search_id;
    for(int i = 0; i < count;i++) {
        if(books[i].book_id == search_id) {
            foundBook = books[i];
            return true;
        }
    }
    return false;
}

void updateBook(Book &b) {
    int availability;
    cout<<"Do you want to update availability? Select 1 fo available, 0 for borrowed:";
    cin >> availability;
    b.is_available = availability;
    cout<<"Book status updated successfully!"<<endl;
}
int main() {
    int size;
    cout<<"Enter the space available for books to be placed"<<endl;
    cin >> size;
    int book_count = 0;

    Book *book_size = new Book[size];
    addBook(book_size, size, book_count);
    displayBook(book_size, book_count);
    // searchBook(book_size,)

    Book foundBook;
    if(searchBook(book_size, book_count,foundBook)) {
        cout << "Book found!" << endl;
        cout << "ID: " << foundBook.book_id << endl;
        cout << "Title: " << foundBook.title << endl;
        cout << "Author: " << foundBook.author << endl;
        cout << "Year: " << foundBook.year << endl;
        cout << "Status: " << (foundBook.is_available ? "Available" : "Borrowed") << endl;
    }

    updateBook(foundBook);
    cout << "Updated Book Details:" << endl;
    cout << "ID: " << foundBook.book_id << endl;
    cout << "Title: " << foundBook.title << endl;
    cout << "Author: " << foundBook.author << endl;
    cout << "Year: " << foundBook.year << endl;
    cout << "Status: " << (foundBook.is_available ? "Available" : "Borrowed") << endl;

    delete[] book_size;

    return 0;
}