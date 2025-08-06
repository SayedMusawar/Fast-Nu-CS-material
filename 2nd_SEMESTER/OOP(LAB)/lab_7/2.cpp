#include<iostream>
using namespace std;
const int MAX_SIZE = 100;
class Hospital{
    private:
    string patient_name;
    int age;
    static int patient_count;
    public:
    // Hospital();
    void setData() {
        string n;
        int a;
        cin >> n;
        patient_name = n;
        cin >> a;
        age = a;
        patient_count++;
    }

    static void showPatient() {
        cout<<"there are "<<patient_count<<" patients"<<endl;
    }

};
int Hospital::patient_count = 0;
int main() {
    int size = 0;
    char choice;
    Hospital *a = new Hospital[size + 1];
    if(size < MAX_SIZE) {
        do {
            cout<<" Enter name and age of patient: "<<endl;
            a[size].setData();
            cout<<"Do you want to add another patient (y/n)?"<<endl; 
            cin >> choice;
        } while(choice == 'y' || choice == 'Y');
    } else cout<<"Cannot enter more patients today"<<endl;
    
        
    a->showPatient();

    // for(int i = 0; i < size; i++ )delete a[i].;

    return 0;
}