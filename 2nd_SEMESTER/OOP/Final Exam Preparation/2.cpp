#include <iostream>
using namespace std;

class Vector {
    int x, y;
public:
    Vector(int a, int b) : x(a), y(b) {}
    Vector operator+(Vector v) {
        return Vector(x + v.x, y + v.y);
    }
    void print() { cout << x << ", " << y << endl; }
};

int main() {
    Vector v1(1, 2), v2(3, 4);
    Vector v3 = v1 + v2;
    v3.print();
    return 0;
}