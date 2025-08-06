#include<iostream>
using namespace std;

class Complex{
private:
	int real,imag;
public:
	Complex(int real = 0,int imag = 0) {
		this->real = real;
		this->imag = imag;
	}
	Complex operator +(Complex &C) {
		return (real + C.real, imag + C.imag);
	}
	void display() {
		cout<<"Sum is: "<<real <<"+i"<<imag<<endl;
	}
};
int main() {
	Complex C1(5,6);
	Complex C2(5,4);
	Complex C3 = C1 + C2;
	C3.display();
    return 0;
}