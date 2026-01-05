#include<iostream>
using namespace std;

// Define a structure to hold student information
struct Student {
    int id;         // Student ID
    char *name;     // Student name (pointer to a character array)
    int age;        // Student age
    float gpa;      // Student GPA
    int credits;    // Number of credits completed by the student
};

// Function to add student records
void AddStudentRecord(Student *students, int size) {
    Student *stu = students;
    for(int i = 0; i < size; i++) {
        
        cout << "Enter id of student " << i + 1 << ": ";
        cin >> stu->id;
        cin.ignore();  // Ignore the newline character left in the input buffer

        cout << "Enter name of student " << i + 1 << ": ";
        cin >> stu->name;  // Input the student's name

        cout << "Enter age of student " << i + 1 << ": ";
        cin >> stu->age;  // Input the student's age

        cout << "Enter gpa of student " << i + 1 << ": ";
        cin >> stu->gpa;  // Input the student's GPA

        cout << "Enter credits of student " << i + 1 << ": ";
        cin >> stu->credits;  // Input the student's credits
        cout << endl << endl;
    }
}

// Function to display all student records
void DisplayAllRecords(const Student *students, int size) {
    const Student *stu = students;
    for(int i = 0; i < size; i++) {
        cout << "Id of " << i+1 << "th student is: " << stu->id << endl;
        cout << "Name of " << i+1 << "th student is: " << stu->name << endl;
        cout << "Age of " << i+1 << "th student is: " << stu->age << endl;
        cout << "GPA of " << i+1 << "th student is: " << stu->gpa << endl;
        cout << "Credits of " << i+1 << "th student is: " << stu->credits << endl;
        cout << endl << endl;
    }
}

// Function to find the top-performing student based on GPA
void topPerformance(Student *students, int size) {
    int top = 0;  // Assume the first student is the top performer
    for(int i = 0; i < size; i++) {
        if(students[i].gpa > students[top].gpa) {
            top = i;  // Update the top performer index
        }
    }
    cout << "TOP PERFORMANCE STUDENT: " << endl;
    cout << "ID: " << students[top].id << endl;
    cout << "NAME: " << students[top].name << endl;
    cout << "AGE: " << students[top].age << endl;
    cout << "GPA: " << students[top].gpa << endl;
    cout << "Credits: " << students[top].credits << endl;
}

// Function to sort student records by credits in descending order
void sortRecords(Student *students, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(students[j].credits < students[j+1].credits) {
                // Swap the students if the current student has fewer credits than the next
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    cout << "In descending order" << endl;
    Student *stu = students;
    for(int i = 0; i < size; i++) {
        cout << "Id of " << stu->id << endl;
        cout << "Name: " << stu->name << endl;
        cout << "Age:  " << stu->age << endl;
        cout << "GPA: " << stu->gpa << endl;
        cout << "Credits: " << stu->credits << endl;
        cout << endl;
    }
}

// Function to search for a student by ID
void searchStudent(Student *students, int size) {
    int search_id;
    cout << "Enter the student's id you want to search" << endl;
    cin >> search_id;
    bool id_found = false;
    Student *stu = students;
    for(int i = 0; i < size; i++) {
        if(search_id == students[i].id) {
            cout << "Record found" << endl;
            cout << "ID: " << stu->id << endl;
            cout << "NAME: " << stu->name << endl;
            cout << "AGE: " << stu->age << endl;
            cout << "GPA: " << stu->gpa << endl;
            cout << "Credits: " << stu->credits << endl;
            id_found = true;
            break;
        }
    }
    if(!id_found) cout << "Record not found" << endl;
}

// Function to update a student's GPA by ID
void updateRecord(Student *students, int size) {
    int update_id;
    cout << "Enter the student's id to update their record" << endl;
    cin >> update_id;
    bool stu_found = false;
    for(int i = 0; i < size; i++) {
        if(update_id == students[i].id) {
            cout << "Enter student's updated gpa" << endl;
            cin >> students[i].gpa;
            cout << "Record updated successfully" << endl;
            stu_found = true;
            break;
        }
    }
    if(!stu_found) cout << "Student id not found" << endl;
}

// Function to delete a student record by ID
void deleteRecord(Student *students, int &size) {
    int delete_id;
    cout << "Enter the id you want to delete" << endl;
    cin >> delete_id;
    int j = -1;
    for(int i = 0; i < size; i++) {
        if(students[i].id == delete_id) {
            j = i;  // Find the index of the student to delete
            break;
        }
    }
    if(j == -1) {
        cout << "Record not found" << endl;
        return;
    }
    delete[] students[j].name;  // Free the memory allocated for the student's name

    // Shift the remaining elements to fill the gap
    for(int i = j; i < size - 1; i++) {
        students[i] = students[i+1];
    }
    size--;  // Decrease the size of the array
    cout << "Record deleted successfully" << endl;
}

int main() {
    cout << "How many number of students you want to add in the system?" << endl;
    int no;
    cin >> no;

    // Dynamically allocate memory for the array of students
    Student *students = new Student[no];
    for(int i = 0; i < no; i++) {
        students[i].name = new char[100];  // Allocate memory for each student's name
    }

    AddStudentRecord(students, no);

    int choice;
    cout << "****MENU****" << endl;
    cout << "1.Display all records" << endl;
    cout << "2.Find Top Performer" << endl;
    cout << "3.Sort Records by Credits" << endl;
    cout << "4.Search for a student by ID" << endl;
    cout << "5.Update Record" << endl;
    cout << "6.Delete Student Record" << endl;
    cout << "7.Exit" << endl;
    cin >> choice;

    // Loop to handle user choices
    while(choice != 7) {
        switch(choice) {
            case 1:
                DisplayAllRecords(students, no);
                break;
            case 2:
                topPerformance(students, no);
                break;
            case 3:
                sortRecords(students, no);
                break;
            case 4:
                searchStudent(students, no);
                break;
            case 5:
                updateRecord(students, no);
                break;
            case 6:
                deleteRecord(students, no);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        cout << "****MENU****" << endl;
        cout << "1.Display all records" << endl;
        cout << "2.Find Top Performer" << endl;
        cout << "3.Sort Records by Credits" << endl;
        cout << "4.Search for a student by ID" << endl;
        cout << "5.Update Record" << endl;
        cout << "6.Delete Student Record" << endl;
        cout << "7.Exit" << endl;
        cin >> choice;
    }
    if(choice == 7) cout << "Exiting..." << endl;

    // Free the dynamically allocated memory
    for (int i = 0; i < no; i++) {
        delete[] students[i].name;
    }
    delete[] students;

    return 0;
}