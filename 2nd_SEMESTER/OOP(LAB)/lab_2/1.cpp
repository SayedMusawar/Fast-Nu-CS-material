#include<iostream>
using namespace std;
int main() {
    int rows, columns;
    cout<<"Enter number of rows and columns"<<endl;
    cin >> rows >> columns;

    int **arr = new int*[rows];
    for(int i = 0; i < rows; i++) arr[i] = new int[columns];

    for(int i = 0; i <rows; i++) {
        for(int j =0; j <columns; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i <rows; i++) {
        for(int j =0; j <columns; j++) {
            cout<< arr[i][j];
        }
    }

    //Calculating the sum of each row and columns

    for(int i = 0; i < rows; i++) {
        int sumRow = 0;
        for(int j = 0; j < columns; j++) {
            sumRow += arr[i][j];
        }
        cout<<"Sum of row "<<i+1<<" is: "<<sumRow<<endl;
    }
    
    for(int i = 0; i < rows; i++) {
        int sumcol = 0;
        for(int j = 0; j < columns; j++) {
            sumcol += arr[j][i];
        }
        cout<<"Sum of column "<<i+1<<" is: "<<sumcol<<endl;
    }

    for(int i = 0; i < rows; i++) delete[] arr[i];
    delete[] arr;
    return 0;
}