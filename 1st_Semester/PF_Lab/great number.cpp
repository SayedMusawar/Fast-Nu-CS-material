#include<iostream>
using namespace std;
int main() {
	int num, origNum,digit;
	int sum = 0;
	int fact = 1;
	cout<<"Enter a number"<<endl;
	cin>>num;
	origNum = num;
	
	while (num > 0) {
		digit = num % 10;
		
		fact = 1;
		for (int i = 2; i<=digit; ++i) {
			fact *= i;
		}
		sum +=fact;
		num /= 10;
	}
	if(sum == origNum) {
		cout<<origNum <<" is a great number"<<endl;
	} else {
		cout<<origNum<<" is not a great number"<<endl;
	}
	return 0;
}