#include <iostream>
using namespace std;

class MyClass {
public:  // All members are public
    int data;
    MyClass(int d = 0) : data(d) {}
};

// Non-friend, non-member function (since data is public)
ostream& operator<<(ostream& out, const MyClass& obj) {
    out << "Data: " << obj.data;  // Directly accessing public member
    return out;
}

// Non-friend, non-member function
istream& operator>>(istream& in, MyClass& obj) {
    in >> obj.data;  // Directly modifying public member
    return in;
}

int main() {
    MyClass obj;
    cout << "Enter data: ";
    cin >> obj;      // Uses operator>>(cin, obj)
    cout << obj;     // Uses operator<<(cout, obj)
    return 0;
}