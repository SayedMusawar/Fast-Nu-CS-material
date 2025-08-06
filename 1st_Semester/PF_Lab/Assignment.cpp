#include<iostream>
using namespace std;
int main() {
	/*
		The expression a = b =c =d is evaluated from right to left due to right-associativily of the assignment operator (=)
		The final value will be 50.
		OUTPUT: "final value 50, a value 50, b value 50, c value 50, d value 50"
	*/
	
	int a = 10, b =20, c= 30, d = 50;
	int final_value =  a=b=c=d;
	cout<<"final value "<<final_value<<", a value "<<a<<", b value"<<b<<", c value"<<c<<", d value"<<d<<endl;
	
	return 0;
}