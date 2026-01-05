#include <iostream>
using namespace std;

class Theta {
public:
    int *p;

    Theta() {
        p = new int(5);
        cout << "Start\t" << *p << endl;
    }

    Theta(int x) {
        p = new int(x * 2);
        cout << "Param Start\t" << *p << endl;
    }

    void alterValue() {
        *p = *p - 3;
        cout << "Modify\t" << *p << endl;
    }

    void show() {
        cout << "Show\t" << *p << endl;
    }

    ~Theta() {
        cout << "Destroy\t" << *p << endl;
        delete p;
    }
};

int main() {
    Theta obj1, obj2(7);
    obj1.alterValue();
    obj2.alterValue();

    Theta *obj3 = new Theta(*obj1.p);
    obj3->alterValue();

    obj1.show();
    obj2.show();
    obj3->show();

    delete obj3;
    return 0;
}