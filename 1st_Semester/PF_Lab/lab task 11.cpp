#include<iostream>
using namespace std;
int main() 
{
	int arr[3][3] = {
						{1,2,3},
						{4,5,6},
						{7,8,9}
					};
	int sum_first = 0 , sum_sec = 0, sum_third = 0;
	for (int i =0 ; i<3; i++) {
		for (int j =0; j <3; j++) {
			if(i == 0) {
				sum_first += arr[i][j];
			}
			if(i == 1) {
				sum_sec += arr[i][j];
			}
			if(i == 2) {
				sum_third += arr[i][j];
			}
			
		}
	}
//	cout<<sum_first<<endl<<sum_sec<<endl<<sum_third<<endl;
	
	int arr2[3][4];
	
	for(int i =0 ; i <3; i++) {
		for(int j = 0; j <4; j++) {
			if (j < 3) {
				arr2[i][j]= arr[i][j];	
			} 
			if (i == 0 && j == 3 ) {
				arr2[i][j] = sum_first;
			}
			if (i == 1 && j == 3 ) {
				arr2[i][j] = sum_sec;
			}
			if (i == 2 && j == 3 ) {
				arr2[i][j] = sum_third;
			}						
			
			cout<<arr2[i][j]<<" ";	 
		}
	}
	return 0;
}