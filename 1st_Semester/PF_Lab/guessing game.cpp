#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	srand(time(0));
	int num = rand() % 100;
	int guess;
	int attempts = 1;
	cout<<"Enter your guess between 0 and 99"<<endl<<"You have total 10 attempts"<<endl;
	cin>>guess;
	
	while (attempts < 10 && guess != num) {
		if (guess > num) {
			cout<<"Your Guess is higher"<<endl;
		}
		else {
			cout<<"Your guess is lower"<<endl;
		}
		cout<<"attempts made = "<<attempts<<endl;
		attempts++;
		
		
		cout<<"Enter your guess again"<<endl;
		cin>>guess;
			}
			if (guess == num) {
				cout<<"Congratulations!!! You guessed correctly"<<endl;
			} else if (attempts == 10) {
				cout<<"0 attempts left."<<endl;
				cout<<"You are unable to guess the correct number"<<endl;
				cout<<"The correct guess was "<<num<<endl;
			}

	return 0;
}