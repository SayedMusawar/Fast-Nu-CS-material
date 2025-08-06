#include<iostream>
using namespace std;
int main()
{
	int sumFirst=0, sumSec = 0;
	int arr[2][2];
	for(int i = 0; i <2; i++) {
		for(int j=0 ; j<2; j++) {
			cin>>arr[i][j];
		}
	}
	for(int i=0; i <2; i++) {
		for (int j = 0; j <2; j++){
			if (i==0) {
				sumFirst += arr[i][j];
			}
			if(i==1) {
				sumSec +=arr[i][j];
			}
		}
	}
	cout<<sumFirst<<endl;
	cout<<sumSec<<endl;
}