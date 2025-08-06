#include <iostream>
#include <string>
using namespace std;

// Define the Book structure
struct Book {
    int book_id;
    string title;
    string author;
    int year;
    bool is_available;
};

// Function to add a book
void addBook(Book &b) {
    cout << "Enter Book ID: ";
    cin >> b.book_id;
    cin.ignore(); // To ignore the newline character left by cin
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter Year of Publication: ";
    cin >> b.year;
    cout << "Enter Availability (1 for available, 0 for borrowed): ";
    cin >> b.is_available;
}

// Function to display book details
void displayBook(const Book &b) {
    cout << "ID: " << b.book_id << endl;
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Year: " << b.year << endl;
    cout << "Status: " << (b.is_available ? "Available" : "Borrowed") << endl;
}

// Function to search for a book by ID
bool searchBook(const Book books[], int size, int id, Book &foundBook) {
    for (int i = 0; i < size; ++i) {
        if (books[i].book_id == id) {
            foundBook = books[i];
            return true;
        }
    }
    return false;
}

// Function to update book availability
void updateBook(Book &b) {
    int availability;
    cout << "Do you want to update availability? (1 for available, 0 for borrowed): ";
    cin >> availability;
    b.is_available = availability;
    cout << "Book status updated successfully!" << endl;
}

int main() {
    const int MAX_BOOKS = 100; // Maximum number of books
    Book books[MAX_BOOKS]; // Array to store books
    int bookCount = 0; // Counter for the number of books added

    // Add a book
    cout << "Enter details for book " << bookCount + 1 << ":" << endl;
    addBook(books[bookCount]);
    bookCount++;

    // Display the added book
    cout << "\nBook Details:" << endl;
    displayBook(books[0]);

    // Search for a book by ID
    int searchId;
    cout << "\nEnter book ID to search: ";
    cin >> searchId;

    Book foundBook;
    if (searchBook(books, bookCount, searchId, foundBook)) {
        cout << "Book found!" << endl;
        displayBook(foundBook);

        // Update book availability
        updateBook(foundBook);
        cout << "\nUpdated Book Details:" << endl;
        displayBook(foundBook);
    } else {
        cout << "Book not found!" << endl;
    }

    return 0;
}