#include<iostream>
using namespace std;
int main() {
	string name;
	cin>>name;
	int count = 1;
	int max_count = 1;
	char prev = name[0];
	
	for(int i = 1; i < name.length() ;i++){
		
		
		if(prev == name[i]){
			count ++;
		}else count = 1;
		prev = name[i];
		
		if(count > max_count)max_count = count;
		
	}
	cout<<max_count;
	
	
	
	return 0;
}