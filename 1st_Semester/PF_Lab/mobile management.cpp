#include <iostream>
using namespace std;

int main() {
	string name,loginName;
	char mobile;
	int option,logPass,pass,price,available =3;
	cout<<"Select 1 for Signup and 2 for Sign In"<<endl;
	cin>>option;

	if (option == 1) {
		
		cout<<"Enter your username"<<endl;
		cin>>name;
		cout<<"Enter your password"<<endl;
		cin>>pass;
		while (pass <9999 || pass > 100000) {
			cout<<"Password must contain 5 digits"<<endl;
			cout<<"Set password again"<<endl;
			cin>>pass;
		}
		cout<<"Sign In successful"<<endl;
	}
	cout<<"Select 2 To sign in"<<endl;
	cin>>option;
	
	if(option == 2) {
		cout<<"Enter your username"<<endl;
		cin>>loginName;
		cout<<"Enter your password"<<endl;
		cin>>logPass;
		while (loginName != name || logPass != pass) {
			cout<<"Incorrect username or password... Try again"<<endl;
			cout<<"Enter username and password"<<endl;
			cin>>loginName>>logPass;
	}
		cout<<"Login successfull"<<endl;
		cout<<"*****MENU*****"<<endl;
		while (available > 2) {
			cout<<"N for nokia"<<endl;
			cout<<"A for android"<<endl;
			cout<<"a for APPLE"<<endl;
			cout<<"Enter the mobile you want to buy"<<endl;
			cin>>mobile;
			switch(mobile) {
				case 'a':
					price = 150000;
					cout<<"Price for APPLE is Rs. "<<price<<"/-"<<endl;
				break;
				case 'A':
					price = 50000;
					cout<<"Price for Android is Rs."<<price<<"/-"<<endl;
				break;
				case 'N':
					price = 25000;
					cout<<"Price for Nokia is Rs."<<price<<"/-"<<endl;
				break;
				default:
					cout<<"Enter correct input"<<endl;
				break;
			}
			cout<<"2 items remaining"<<endl;
			available--;
			while (available == 2) {
				cout<<"Remaining items is 2 "<<endl;
				if (mobile == 'N') {
					cout<<"Remaining mobiles are:"<<endl;
					cout<<"1. Android"<<endl<<"2. APPLE"<<endl;
				}
				else if (mobile == 'A') {
					cout<<"Remaining mobiles are:"<<endl;
					cout<<"1. Nokia"<<endl<<"2. APPLE"<<endl;
				} else if (mobile == 'a') {
					cout<<"Remaining mobiles are:"<<endl;
					cout<<"1. Nokia"<<endl<<"2. Android"<<endl;
				}
				available--;
			}
		}
	}
    return 0;
}