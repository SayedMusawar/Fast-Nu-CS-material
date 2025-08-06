#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
int main() {
	char ch[26];
	char start,rand_Num,num;
	int i,j,k,comp_reward, user_reward;
	srand(time(0));
	cout<<"Enter 26 characters"<<endl;
	for(i = 0; i<26 ; i++) {
		cin>>ch[i];
	}
	cout<<"26 characters are:";
	for (i = 0 ; i <26 ;i++) {
		cout<<ch[i];
	}
	cout<<endl;
	
	cout<<"Do you want to start"<<endl;
	cin>>start;
	if(start == 'e'|| start == 'E') {
		cout<<"Exit";
		return 0;
	} else {
		cout<<"How many times do you want to play the game"<<endl;
		cin>>j;
		for(k=1 ; k< j; k++) {
			cout<<"Enter a number"<<endl;
			cin>>num;
			rand_Num = rand() % 10;
			if(rand_Num == ch[i]) {
				comp_reward++;
				cout<<"computer wins"<<endl;
				cout<<"Reward: "<<comp_reward<<endl;
			} else {
				user_reward++;
				cout<<"user wins"<<endl;
				cout<<"Reward is: "<<user_reward<<endl;
			}
		}
	}
}