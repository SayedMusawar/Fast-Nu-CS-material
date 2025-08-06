#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    int marks;
public:
    Student(string name,int rollNo,int marks) {
        this->name = name;
        this->rollNo = rollNo;
        this->marks = marks;
    }
    friend class ResultProcessor;
    friend void compute(Student s);
};

class ResultProcessor {
private:
    char grade;
public:
    ResultProcessor(Student a) {
        if(a.marks >= 85 && a.marks <=100) {
            grade = 'A';
        } else if(a.marks >= 70 && a.marks < 85) {
            grade = 'B';
        }
        else if(a.marks >=50 && a.marks < 70) {
            grade = 'C';
        } else if(a.marks < 50) {
            grade ='F';
        }
        cout<<"Name: "<<a.name<<endl;
        cout<<"Roll no."<<a.rollNo<<endl;
        cout<<"Marks"<<a.marks<<endl;
        cout<<"grade"<<grade<<endl;
    }
    friend void compute(string n,int r,int m) {
        
    }
};
int main() {
    Student a("name",123,70);
    Student b("Musawar",061,99);
    Student c("a",345,50);
    ResultProcessor d(a);
    ResultProcessor e(b);
    ResultProcessor f(c);
}