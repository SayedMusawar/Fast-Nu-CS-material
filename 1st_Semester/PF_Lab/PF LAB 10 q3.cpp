#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main() {
	char ch[26],start;
	int i,play,random,Int_ch,comp_reward,user_reward;
	srand(time(0));
	for (i =  0; i < 26 ; i++) {
		ch[i]=65+i;
		Int_ch = (int)ch[i];
	}
	
	cout<<"Do you want to start"<<endl;
	cin>>start;
	while (start != 'e') {
		cout<<"How many times do you want to play?"<<endl;
		cin>>play;
		for (i = 1 ; i <=play ;i++) {
			random = rand() % 10;
			if(random == Int_ch) {
			comp_reward++;
			cout<<"Computer wins"<<endl;
		} else {
			user_reward++;
			cout<<"User wins"<<endl;
		}
		}
		cout<<"Do you want to play again"<<endl;
		cin>>start;
	}
	return 0;
}