#include<iostream>
using namespace std;
class DynamicVar{
private:
    int *ptr;
public:
    DynamicVar(int n = 0) {
        ptr = new int;
        *ptr = n;
    }
    ~DynamicVar() {
        delete ptr;
    }
    DynamicVar(DynamicVar &C) {
        ptr = new int;
        *ptr = *(C.ptr);
    }
    void display() {
        cout<<*ptr<<endl;
    }

};
int main() {
    DynamicVar D1(10);
    DynamicVar D2  = D1;
    DynamicVar D3,D4;
    D4 = D3 = D1;
    D1.display();
    D2.display();
    D3.display();
    D4.display();
    return 0;
}

