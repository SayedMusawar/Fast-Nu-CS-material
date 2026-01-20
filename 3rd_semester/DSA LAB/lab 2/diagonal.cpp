#include<iostream>
using namespace std;
class DiagonalSum{
private:
    int** arr;
    int mainSum;
    int SecSum;
    int size;
public:
    DiagonalSum() : size(3) , mainSum(0), SecSum(0) {
        arr = new int*[size];
        for(int i = 0 ; i < size ; i++) *(arr + i) = new int[size];

        cout<<"Enter the values";
        for(int i = 0 ; i < size ; i++) {
            int *a = *(arr + i);
            for(int j = 0  ; j< size ; j++) {
                cin >> *(a + j);
            }
        }
    }
    void sums() {
        mainSum = 0;
        SecSum = 0;
        for(int i = 0; i < size; i++) {
            int *a = *(arr + i);
            for(int j = 0; j < size; j++) {
                if(i == j) mainSum += *(a + j);
                if( i+ j == 2) SecSum += *(a + j);
            }
        }
    }
    void display() {
        cout<<"Main diagonal sum is: "<< mainSum<<endl;
        cout<<"Secondary diagonal sum: "<<SecSum<<endl;
    }
};
int main() {

    DiagonalSum S1;
    S1.sums();
    S1.display();
    return 0;
}