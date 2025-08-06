#include<iostream>
using namespace std;
int main() {
	int n,i,j,d1,d2;
	cout<<"Size of array is: "<<endl;
	cin>>n;
	int num[n];
	for (i = 0; i < n; i++) {
		cin>>num[i];
	}

	d1 = num[1] - num[0];
	for(i=1 , j = 2; i< n , j <  n; i++,j++) {
		d2 = num[j]- num[i];
	}
	if(d1 != d2) {
			cout<<num[n-1]<<" is different number in the series"<<endl;
		} else {
			cout<<"No different or outlier element is found in the array"<<endl;
		}
//	cout<<d1<<endl<<d2;
	return 0;
}