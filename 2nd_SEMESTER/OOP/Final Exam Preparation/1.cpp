#include<iostream>
using namespace std;
class Complex{
private:
    int real,imag;
public:
    Complex(int r = 0,int i = 0) : real(r) ,imag(i) {}

    Complex operator+(Complex &C) {
        return Complex(real + C.real, imag + C.imag);
    }

    Complex operator-(Complex &C) {
        return Complex(real - C.real, imag - C.imag);
    }

    Complex operator*(Complex &C) {
        return Complex((real * C.real) - (imag * C.imag),(real * C.imag) + (imag * C.real));
    }

    friend ostream& operator<<(ostream& out,const Complex& C);

};
ostream& operator<<(ostream& out,const Complex& C) {
    out<<C.real<<" + "<<C.imag<<"i"<<endl;
    return out;
}
int main() {
    Complex A1(3,5);
    Complex A2(1,4);
    Complex C1;
    C1 = A1 + A2;
    cout<<C1;
    C1 = A1 - A2;
    cout<<C1;
    C1 = A1 * A2;
    cout<<C1;
    return 0 ;
}