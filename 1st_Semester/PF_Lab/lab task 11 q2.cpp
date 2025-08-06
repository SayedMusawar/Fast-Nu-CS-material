#include<iostream>
using namespace std;
int main() 
{
	int mat[3][3];
	int diagonal = 0, non_diagonal = 0;
	cout<<"Enter the values in array"<<endl;
	for(int i = 0; i< 3; i++) {
		for (int j = 0; j <3; j++) {
			cin>>mat[i][j];
		}
	}
	for (int i = 0; i <3; i++) {
		for (int j = 0 ; j <3; j++) {
			if(i == j) {
				if (mat[i][j] == 1) {
					diagonal ++;
				} 
			}
			if (i != j) {
				if(mat[i][j] == 0)
				non_diagonal++;
			}
		}
	}
	if(diagonal == 3 && non_diagonal == 6) {
		cout<<"It is an identity matrix"<<endl;
	} else {
		cout<<"It is not an identity matrix"<<endl;
	}
	return 0;
}