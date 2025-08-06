#include<iostream>
using namespace std;
int main() {
    int stu = 2;
    int sub = 2;

    int **score = new int*[stu];
    for(int i = 0; i < stu; i++) score[i] = new int[sub];

    for(int i = 0; i <stu; i++) {
        cout<<"Student: "<<i+1<<endl;
        for(int j = 0; j < sub; j++) {
            cout<<"Subject: "<<j+1<<endl;
            cin >> score[i][j];
        }
    }
    
    cout<<endl<<"Students score"<<endl;

    cout <<"Student \t" << "Subject 1 \t" << "Subject 2" << "\n";
    for (int i = 0; i < stu; ++i) {
        cout << i + 1<<"\t\t";
        for (int j = 0; j < sub; ++j) {
            cout << score[i][j]<<"\t\t";
        }
        cout << "\n";
    }

    for(int i = 0; i < stu; i++) {
        delete[] score[i];
    }
    delete[] score;
    return 0;
}