#include<iostream>
using namespace std;
int main() {
	freopen("1.in","r",stdin);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		int operations = 0;
		for(int i = 0; i < n; i++) {
			cin>>arr[i];
		}
		while(n > 1) {
			bool is_equal_element = true;
			for(int i = 0; i < n ; i++) {
				if(arr[i] != arr[0]) {
					is_equal_element = false;
					break;
				}
			}
			if(is_equal_element) break;
			for(int i = 0; i < n; i++) {
				int m = (i + 1) % n;
				if(arr[i] <= arr[m]) {
					if(arr[i] < arr[m]) {
						for(int j = i; j < n - 1; j++) {
							arr[j] = arr[j + 1];
						}
					} else {
						for(int j = m; j < n - 1; j++ ) {
							arr[j] = arr[j + 1];
						}
					}
					n--;
					operations++;
					break;
				}
			}
		}	
		
		cout<<operations<<endl;
	}
	return 0;
}