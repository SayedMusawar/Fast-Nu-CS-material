#include<iostream>
using namespace std;
int main()
{
	int correct_password = 1234;
	int password,attempts=3;
	cout<<"Enter your four digit password"<<endl;
	cin>>password;
	if (password == correct_password) {
		cout<<"Login successful"<<endl;
	}
	
	else {
		cout <<"Wrong password, please try again"<<endl;
		attempts = 2;
		cin>>password;
		
		if (password == correct_password) {
			cout<<"Login successful"<<endl;
		} 
		else{
			cout <<"Wrong password, please try again"<<endl;
			cin>>password;
			attempts = 1;	
			if (password == correct_password) {
				cout<<"Login successful"<<endl;
			}
			else {
				cout << "Unsuccessful login"<<endl;
			}
		}
	}
		
}