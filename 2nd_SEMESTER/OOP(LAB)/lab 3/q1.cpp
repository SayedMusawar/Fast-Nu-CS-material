#include <iostream>
using namespace std;

int main() {
    int rows = 2, columns = 2;
    int** marks = new int*[rows];
    for (int i=0;i<rows;i++) {
     marks[i] = new int[columns];
    }

    cout<<"Enter scores for 2 students in 2 subjects:\n";
    for (int i=0;i<rows;i++) {
    
	for (int j=0;j<columns;j++) {
    
	cin>>marks[i][j];
    }
    
	}

    cout<<"\nStudent Scores Table:\n";
    cout<<"Student\tSubject 1\tSubject 2\n";
    for (int i=0;i<rows;i++) {
    cout<<i + 1<<"\t";
    for (int j=0;j<columns;j++) {
    cout<<marks[i][j]<<"\t\t";
    }
    cout<<endl;
    }
    
    for (int i=0;i<rows;i++) {
    delete[] marks[i];
    }
    delete[] marks;


    return 0;
}