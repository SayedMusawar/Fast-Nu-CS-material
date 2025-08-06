#include<iostream>
using namespace std;
int main() {
	int num[] = {10,20,20,30,30,30};
	int i,j,count=0,maxCount=1,max_element;
	for (i = 0; i < 6 ; i++) {
		for (j = i + 1; j< 6; j++) {
			if(num[i] == num[j]) {
				count++;
				max_element = num[j];
			}
		}
		if(count > maxCount) {
				maxCount = count;
				cout<<"most repeated element is: "<<max_element<<endl;
				break;
		}
	}
}