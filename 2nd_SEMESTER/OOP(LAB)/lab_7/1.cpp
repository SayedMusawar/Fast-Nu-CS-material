#include<iostream>
using namespace std;
class Quiz{
    private:
        string option_1,option_2,correct_option,user_option;
        static int marks;
    public:
        // Quiz();
        void setOption(string o1,string o2, string correct) {
            option_1 = o1;
            option_2 = o2;
            correct_option = correct;
            showOption(o1,o2);
        }
        void showOption(string o1, string o2) {
            cout<<"1. "<<o1<<endl;
            cout<<"2. "<<o2<<endl;
        }

        void question() {
            int choice;
            cin >> choice;
            if(choice == 1) user_option = option_1;
            else user_option = option_2;
            checkAnswer();
        }

        void checkAnswer() {
            if (user_option == correct_option) marks++;
        }

        static void showMarks() {
            cout<<"Total marks are "<<marks<<" out of 5"<<endl;
        }
        void result() {
            if (marks < 5/2) cout<<"FAILED"<<endl;
            else cout<<"PASSED"<<endl;
        }
};
int Quiz::marks = 0;
int main() {
    Quiz s1;
    cout<<"Which keyword is used to define a class in c++ Class or struct"<<endl;
    s1.setOption("Class","Struct","Class");
    s1.question();

    cout<<"What is the default access specifier for members of a class in c++ Private or Public"<<endl;
    s1.setOption("private","public","private");
    s1.question();

    cout<<"Which member function is used to free allocated memory before an object is destroyed? Constructor or destructor"<<endl;
    s1.setOption("Constructor","Destructor","Destructor");
    s1.question();

    cout<<"Which function is called automatically when an object is created constructor or destructor"<<endl;
    s1.setOption("Constructor","Destructor","Constructor");
    s1.question();

    cout<<"Which keyword is used to create an object of a class dynamically? new or malloc"<<endl;
    s1.setOption("new","malloc","new");
    s1.question();

    s1.showMarks();
    s1.result();

    return 0;
}