#include<iostream>
using namespace std;
class Book{
    private:
    string title;
    int id;
    public:
    Book() {
        title = "";
        id = 0;
    }
    Book (string t, int ID) {
        title = t;
        id = ID;
    }
    void setBook() {
        cin >> title;
        cin >> id;
    }
    void show() {
        cout<<"TITLE "<<title<<" ID:"<<id;
    }
};
int main() {
    cout<<"Enter the number of books you want to add"<<endl;
    int size;
    cin >> size;
    Book *a = new Book[size];
    for(int i = 0; i < size; i++) {
        a[i].setBook();
    }
    for(int i = 0 ; i < size ; i++) {
        a[i].show();
        cout<<endl;
    }
    cout<<"Do you want to add more books (y/n)";
    string ask;
    cin >> ask;
    if(ask == "y") {
        cout<<"Enter how many books you want to add?"<<endl;
        int s;
        cin >> s;
        Book *b = new Book[size + s];
        for (int i = 0; i<size ; i++) {
            b[i] = a[i];
        }
        for(int i = size; i < size + s; i++) {
            b[i].setBook();
        }
        for(int i = 0; i< size + s; i++) {
            b[i].show();
             cout<<endl;
        }
        delete a;
        delete b;
    }
    
    return 0;
}