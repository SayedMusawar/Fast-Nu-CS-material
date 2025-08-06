#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main() {
	char game;
	int num,randNum;
	srand(time(0));
	
	cout<<"Do you want to play the game. press N or n if you want to exit"<<endl;
	cin>>game;
	
	while(game != 'n'&& game != 'N') {
		cout<<"How many times you want to generate a number"<<endl;
		cin>>num;
		
		for (int i =1; i<= num; i++) {
			cout<<"how many numbers do you want to generate"<<endl;
			cin>>randNum;
			
			for (int j = 1; j<= randNum; j++) {
				cout<<rand() % 10<<endl;
			}
		}
		cout<<"do you want to play the game again"<<endl;
		cin>>game;
	}
	return 0;
}