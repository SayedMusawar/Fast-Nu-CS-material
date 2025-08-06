#include<iostream>
using namespace std;
int main() {
	int num,remainder,qoutient;
	cout<<"Enter a two digit number"<<endl;
	cin>>num;
	
	for(int i = 0;i <num ;i++) {
		remainder = num % 10;
		qoutient = num / 10;
	}
	if(qoutient < remainder){
		cout<<"Assending order"<<endl;
	} else if (qoutient > remainder) {
		cout<<"Decending order"<<endl;
	}
	return 0;
 }