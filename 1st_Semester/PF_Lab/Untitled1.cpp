#include<iostream>
using namespace std;
void ass(int a[]) {
	for(int i = 0; i < 5; i ++) {
		for(int j = i + 1; j <5; j++) {
			if (a[j] < a[i]) {
				int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
			}
		}
	}
}
int min(int a[]) {
	int mini;
	for(int i = 0; i < 5; i++) {
		for(int j = i + 1;j <5; j++) {
			if(a[i] > a[j]) {
				mini = a[i];
			}
		}
	}
	return mini;
}
int main() {
	int a[5] = {3,6,1,2,0};
	ass(a);
	cout<<"Array in ascending order is:"<<endl;
	for (int i = 0; i < 5; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	cout<<" Minimum number is "<<min(a);
	
	return 0;
}