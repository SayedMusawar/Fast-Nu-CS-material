#include<iostream>
using namespace std;
 void max(int[], int size);
 void min(int[], int size);
int main() {
    int size = 5;
    int *arr = new int[size];

    for(int i = 0; i < size; i++) cin >> *(arr+i);

    cout<<"Numbers are ";
    for(int i = 0; i < size; i++) cout<<arr[i]<<" ";

    cout<<endl;

    max(arr ,size);
    cout<<endl;
    min(arr, size);

    delete[] arr;
    return 0;
}
void max(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size;i++) {
        if(arr[i] > max) max = arr[i];
    }
    cout<<"Maximum value is: "<<max;
}

void min(int arr[], int size) {
    int min = arr[0];
    for(int i = 1; i < size;i++) {
        if(arr[i] < min) min = arr[i];
    }
    cout<<"Maximum value is: "<<min;
}