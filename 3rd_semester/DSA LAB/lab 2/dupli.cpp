#include<iostream>
using namespace std;
class Dupli{
private:
    int* arr;
    int n;
    int count; int maxCount;
public:
    Dupli() : count(0), maxCount(0) , n(12) {
        arr = new int[n];
        cout<<"Enter the values in array"<<endl;
        for(int i = 0; i < n; i++) cin >> *(arr + i);
    }

    void sortArr() {
        for(int i = 0; i< n ; i++) {
            for(int j = 0; j < n; j++) {
                if(*(arr + i) < *(arr + j)) {
                    int temp = *(arr+i);
                    *(arr+i) = *(arr+j);
                    *(arr+j) = temp;
                }
            }
        }
    }

    void findDuplicates() {
        for(int i = 0; i < n; i++) {
            if(*(arr + i) == *(arr + i + 1)) count++;
            else count  = 0;
            if(count > maxCount) maxCount = count;
        }
    }

    void display() {
        count = 1;
        for(int i = 0; i < n; i++) {
            if(*(arr + i) == *(arr + i + 1)) count++;
            else count  = 0;
            if(count == maxCount) {
                cout<< "The most repeated value is: "<<arr[i] <<" and it appears "<< maxCount + 1<<" times"<<endl;
            }
        }
    }
    
    // void dis() {
    //     for(int i = 0; i < n;i++)
    //     cout<<arr[i] <<" ";
    // }
};
int main() {
    Dupli D1;

    D1.sortArr();
    D1.findDuplicates();
    // D1.dis();
    D1.display();

    return 0;
}