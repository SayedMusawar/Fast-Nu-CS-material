#include<iostream>
using namespace std;
class Person {
    private:
        string name;
        int age;
    public:
        void setPersonDetails(string n,int a) {
            name = n;
            age = a;
        }
        void showPersonDetails() {
            cout<<"Name: "<<name<<"\n Age: "<<age<<endl;
        }
        int getAge() {return age;}
};
class AcademicRecord : public Person {
    private:
        float gpa;
        string Major;
    public:
        void setAcademicDetails(float g,string M) {
            gpa = g;
            Major = M;
        }
        void displayAcademicDetails() {
            cout<<"GPA: "<<gpa<<"\nMajor: "<<Major<<endl;
        }
        float getGpa() {return gpa;}

};
class Scholarship : public AcademicRecord {
    private:
        int scholarAmount;
    public:
        void EvaluateScholarship() {
            if(getGpa() >= 3.5 && getAge() < 25) scholarAmount = 50000; 
            else scholarAmount = 0;
        }
        void displayScholarshipDetails() {
            cout<<"Scholarship earned: "<<scholarAmount;
        }

};
int main() {
    Scholarship a1;
    a1.setPersonDetails("John",20);
    a1.setAcademicDetails(3.94,"CS");
    a1.EvaluateScholarship();
    a1.showPersonDetails();
    a1.displayAcademicDetails();
    a1.displayScholarshipDetails();

    return 0;
}