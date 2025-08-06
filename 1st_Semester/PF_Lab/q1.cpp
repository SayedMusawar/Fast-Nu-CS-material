#include<iostream>
using namespace std;
int main()
{
	int i,j,com_diff;
	int num[]= {10,20,30,40,50,1000};
	com_diff = num[1]-num[0];
	com_diff = num[2]-num[1];
	com_diff = num[3]-num[2];
	com_diff = num[4]-num[3];
	com_diff = num[5]-num[4];
	cout<<com_diff<<endl;
//	for (i = 0,j = i + 1 ; i < j; i++,j++) {
//		com_diff = num[j] - num[i];
//		cout<<"Comman difference is"<< com_diff<<endl;
//	}
//	
	return 0;
}