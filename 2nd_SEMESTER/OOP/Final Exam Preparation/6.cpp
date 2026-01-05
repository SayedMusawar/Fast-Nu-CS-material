#include <iostream>
using namespace std;

class A {
public:
    A() { cout << 'A'; }
    ~A() { cout << "A1\n"; }
    void display() {}
};

class B : public A {
public:
    B() { cout << 'B'; }
    ~B() { cout << "B1\n"; }
    void display() {}
};

class C : public A {
public:
    C() { cout << 'C'; }
    ~C() { cout << "C1\n"; }
};

int main() {
    A* ptrA[4];

    for (int i = 0; i < 4; ++i) {
        if (i < 2)
            ptrA[i] = new B;
        else
            ptrA[i] = new C;
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete ptrA[i];
    }

    return 0;
}
