#include<iostream>
#include<string>
using namespace std;
int main() {
    string a, b;
    cin>> a >> b;

    int count = 0;

    if (a.length() == b.length()) {
    int j = a.length() - 1;
        for(int i = 0; i < a.length(); i++) {
            if(a[i] == b[j]) count++;
            j--;
        }
    }

    if (count == a.length()) cout<<"Both strings are reverse of each other"<<endl;
    else {
        cout<<"Strings are not reverse of each other"<<endl;
    }
    
    return 0;
}