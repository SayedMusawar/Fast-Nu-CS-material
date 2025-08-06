#include<iostream>
using namespace std;
class Dummy{
    private:
    int *ptr;
    public:
    Dummy() {
        ptr = new int;
        cout<<"Enter the value ";
        cin >> *ptr;
    }
    void showValue() {
        cout<<"The value is: "<<*ptr<<endl;
    }
    ~Dummy() {
        delete ptr;
    }
};
int main() {
    Dummy *a = new Dummy;
    a->showValue();
    return 0;
}