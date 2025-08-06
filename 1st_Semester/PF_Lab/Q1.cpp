#include<iostream>
using namespace std;
int main() {
	float num;
	int newNum,check,remainder,reverse;
	bool isFloat = 1;
	cout<<"Enter a number"<<endl;
	cin>>num;
	
	if (num <=0) {
		cout<<"!!!!!!!!ERROR!!!!!!!"<<endl;
	}
	if (isFloat) {
		newNum = (int) num;
		cout<<"int number is:" <<newNum<<endl;
		check = newNum;
	}
	if (num >0 ) {
		
		while (check !=0) {
			remainder = check % 10;
			reverse = reverse * 10 + remainder;
			check /= 10;
		}
		cout<<"Reversed num is: "<<reverse<<endl;
		if (newNum == reverse) 	
			cout<<"Palindrome"<<endl;
		else {
			cout<<"Not Palindrome"<<endl;
		}
	}
	return 0;
}