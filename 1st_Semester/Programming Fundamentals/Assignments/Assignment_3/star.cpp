#include <iostream>
using namespace std;

int main() {
//	freopen("2.in","r",stdin);
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int a[100], freq[100] = {0}, maxFreq = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        for (int i = 0; i < 100; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }
        
        cout << n - maxFreq << endl;
    }
    
    return 0;
}
