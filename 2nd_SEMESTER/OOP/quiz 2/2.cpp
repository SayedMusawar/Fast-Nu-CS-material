#include <iostream>
using namespace std;

class A {
public:
    int x, y;
    int *ptr;

    A() {
        x = 3;
        y = 7;
        ptr = new int(x + y);
        cout << "Start\t" << x << "\t" << y << "\t" << *ptr << endl;
    }

    A(int a, int b) {
        x = a + 1;
        y = b - 1;
        ptr = new int(x + y);
        cout << "Param Start\t" << x << "\t" << y << "\t" << *ptr << endl;
    }

    void modify() {
        x += 5;
        y *= 2;
        *ptr += x;
        cout << "Modify\t" << x << "\t" << y << "\t" << *ptr << endl;
    }

    void show() {
        cout << "Show\t" << x << "\t" << y << "\t" << *ptr << endl;
    }
};

int main() {
    A obj1, obj2(5, 10);
    A obj3 = obj1;

    obj1.modify();
    obj2.modify();
    obj3.modify();

    A *obj4 = new A(obj2.y, obj1.x);
    obj4->modify();

    obj1.show();
    obj2.show();
    obj3.show();
    obj4->show();

    delete obj4;

    return 0;
}
