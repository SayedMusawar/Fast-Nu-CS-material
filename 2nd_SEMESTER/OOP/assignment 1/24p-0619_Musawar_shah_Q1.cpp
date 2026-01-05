#include<iostream>
using namespace std;
int main() {
    int rows; // initializing variable for rows
    cout<<"Enter the number of rows: ";
    cin >>  rows; // input number of rows
    int **ptr = new int*[rows]; // used double pointers to allocate memory for rows in 2d array
    int *col = new int[rows]; // used single pointer to store number of columns in each row using single array
    

    // this loop is to input number are columns for each row
    for(int i = 0 ; i < rows; i++) {
        cout<<"Enter the number of columns for "<<i+1<<"th row:";
        cin >> col[i];
    }

    // this loop is used to dynamically memory allocation of columns in each row
    for(int i = 0; i < rows; i++) ptr[i] = new int[col[i]];
    
    // this nested loop is used to input values to each column in each row
    for(int i = 0; i < rows; i++) {
        cout << "Taking Values for row " << i + 1  << " :"; 
       for(int j = 0; j < col[i]; j++) {
            cin >> ptr[i][j];
            
       }
       cout << endl;

    }


    // this loop is to display all the values that i stored in each column of each row
    for(int i = 0; i < rows; i++) {
        cout<<"Values for row"<<i+1<<" are:"<<endl;
        for(int j = 0; j < col[i]; j++) {
            cout << ptr[i][j]<<" ";
        }
        cout<<endl;
    }

    // deallocate the memory for rows
   for(int i = 0; i < rows; i++) delete[] ptr[i];

    // deallocate the memory for ptr
    delete[] ptr;
    ptr = nullptr;

    // deallocate the col array
    delete[] col;
    col = nullptr;
    
    return 0;
}
