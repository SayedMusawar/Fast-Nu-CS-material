#include<iostream>
using namespace std;
struct Student {
    int id;
    char *name;
    int age;
    float gpa;
    int credits;
};
int main() {
    cout<<"How many number of students you want to add in the system?"<<endl;
    int no;
    cin >> no;

    Student *students = new Student[no];
    for(int i = 0 ; i < no; i++) {
        students[i].name = new char[100];
    
        cout<<"Enter id of student "<<i + 1 <<": ";
        cin >> students[i].id;

        cout<<"Enter name of student "<<i + 1 <<": ";
        cin >>  students[i].name;

        cout<<"Enter age of student "<<i + 1 <<": ";
        cin >> students[i].age;

        cout<<"Enter gpa of student "<<i + 1 <<": ";
        cin >> students[i].gpa;

        cout<<"Enter credits of student "<<i + 1 <<": ";
        cin >> students[i].credits;
        cout<<endl<<endl;
    }
        

    // for(int i = 0 ; i < no; i++) {
    //     cout<<"Id of "<<i+1<<"th student is: "<<students[i].id<<endl;

    //     cout<<"Name of "<<i+1<<"th student is: "<<students[i].name<<endl;

    //     cout<<"Age of "<<i+1<<"th student is: "<<students[i].age<<endl;

    //     cout<<"GPA of "<<i+1<<"th student is: "<<students[i].gpa<<endl;

    //     cout<<"Credits of "<<i+1<<"th student is: "<<students[i].credits<<endl;

    //     cout<<endl<<endl;

    // }
    int top = 0;
    for(int i = 0; i < no; i++) {
        if(students[i].gpa > students[top].gpa) {
            top = i;
        }
    }
    cout<<"ID: "<<students[top].id<<endl;
    cout<<"NAME: "<<students[top].name<<endl;
    cout<<"AGE: "<<students[top].age<<endl;
    cout<<"GPA: "<<students[top].gpa<<endl;
    cout<<"Credits: "<<students[top].credits<<endl;

    // for(int i = 0; i < no - 1; i++) {
    //     for(int j = 0 ; j < no - i - 1;j++) {
    //         if(students[j].credits < students[j+1].credits) {
    //             int temp = students[j].credits;
    //             students[j].credits = students[j+1].credits;
    //             students[j+1].credits = temp;
    //         }
    //     }
    // }
    // cout<<"In descending order"<<endl;
    // for(int i = 0 ; i < no; i++) {
    //     cout<<"Id of "<<students[i].id<<endl;

    //     cout<<"Name: "<<students[i].name<<endl;

    //     cout<<"Age:  "<<students[i].age<<endl;

    //     cout<<"GPA: "<<students[i].gpa<<endl;

    //     cout<<"Credits: "<<students[i].credits<<endl;

    //     cout<<endl<<endl;
    // }

    // int search_id;
    // cout<<"Enter the student's id you want to search"<<endl;
    // cin >> search_id;
    // for(int i = 0; i <no ; i++) {
    //     if(search_id == students[i].id) {
    //         cout<<"Record found"<<endl;
    //         cout<<"ID: "<<students[i].id<<endl;
    //         cout<<"NAME: "<<students[i].name<<endl;
    //         cout<<"AGE: "<<students[i].age<<endl;
    //         cout<<"GPA: "<<students[i].gpa<<endl;
    //         cout<<"Credits: "<<students[i].credits<<endl;
    //     } else cout<<"Record not found"<<endl;
    // }

    // int update_id;
    // cout<<"Enter the student's id to update their record"<<endl;
    // cin >> update_id;
    // for(int i = 0; i < no; i++) {
    //     if(update_id == students[i].id) {
    //         cout<<"Enter student's updated gpa"<<endl;
    //         cin >> students[i].gpa;
    //         cout<<"Record updated successfully"<<endl;
    //     } else cout<<"Student id not found"<<endl;
    // }
    return 0;
}