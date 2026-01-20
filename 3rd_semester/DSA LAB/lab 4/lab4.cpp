#include<iostream>
#include<string>  // Added for string
using namespace std;

class Student{
private:
    int ID;
    string name;
    float gpa;
public:
    Student(int id = 0, string n = "", float g = 0.0) : ID(id), name(n), gpa(g) {}

    Student(const Student &s) {
        ID = s.ID;
        name = s.name;
        gpa = s.gpa;
    }

    void setID(int id) {
        ID = id;
    }

    void setName(string n) {
        name = n;
    }

    void setGpa(float Gpa) {
        if(Gpa >= 0.0 && Gpa <= 4.0) {
            gpa = Gpa;
        } else {
            cout << "Invalid GPA. GPA must be between 0.0 & 4.0" << endl;
        }
    }

    int getID() const { return ID;}

    string getName() const {return name;}

    float getGpa() const { return gpa; }
};

class Node{
public:
    Student data;
    Node *next;
    Node(Student val) : data(val), next(NULL) {} 
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList() : head(NULL) {}

    void addStudent(const Student& s) {
        Node *newNode = new Node(s);
        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Student added successfully." << endl;
    }

    void removeStudent(int studentID) {
        if(head == NULL) {
            cout << "Student not found." << endl;
            return;
        }
        Node* cN = head;
        Node* pN = NULL;

        if(cN->data.getID() == studentID) {
            if(cN->next == head) {
                delete head;
                head = NULL;
                cout << "Student removed successfully." << endl;
                return;
            }

            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }

            head = head->next;
            temp->next = head;
            delete cN;
            cout << "Student removed successfully." << endl;
            return;
        }

        pN = cN;
        cN = cN->next;

        while(cN != head) {
            if(cN->data.getID() == studentID) {
                pN->next = cN->next;
                delete cN;
                cout << "Student removed successfully." << endl;
                return;
            }
            pN = cN;
            cN = cN->next;
        }
        cout << "Student not found." << endl;
    }

    void display() {
        if(head == NULL) {
            cout << "No records found." << endl;
            return;
        }

        cout << "Student Records:" << endl;
        Node* temp2 = head;
        do {
            cout << "ID: " << temp2->data.getID() << ", Name: " << temp2->data.getName() << ", GPA: " << temp2->data.getGpa() << endl;
            temp2 = temp2->next;
        } while(temp2 != head);
    }

    void searchStudent(int studentID) {
        if(head == NULL) {
            cout << "Student not found." << endl;
            return;
        }
        Node* temp = head;
        do {
            if(temp->data.getID() == studentID) {
                cout << "Student found:" << endl;
                cout << "ID: " << temp->data.getID() << ", Name: " << temp->data.getName() << ", GPA: " << temp->data.getGpa() << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Student not found." << endl;
    }

    float calculateAvgGpa() {
        if(head == NULL) {
            return 0.0;
        }
        float sum = 0.0;
        int count = 0;
        Node *temp = head;
        do {
            sum += temp->data.getGpa();
            count++;
            temp = temp->next;
        } while (temp != head);
        return sum / count;
    }
};

int main() {
    LinkedList l1;
    int choice;
    int id;
    string name;
    float gpa;
    cout << "Welcome to the Student Registration System!" << endl;
    cout << "1. Add a student" << endl;
    cout << "2. Remove a student" << endl;
    cout << "3. Search for student" << endl;
    cout << "4. Display all students" << endl;
    cout << "5. Calculate average GPA" << endl;
    cout << "6. Exit" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
            {
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter Student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student GPA: ";
                cin >> gpa;
                Student newStudent(id, name, gpa);
                l1.addStudent(newStudent);
                break;
            }
                
            case 2:
                cout << "Enter student ID to remove: ";
                cin >> id;
                l1.removeStudent(id);
                break;
            case 3:
                cout << "Enter student ID to search: ";
                cin >> id;
                l1.searchStudent(id);
                break;
            case 4:
                l1.display();
                break;
            case 5:
                cout << "Average GPA: " << l1.calculateAvgGpa() << endl;
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:   
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while(choice != 6);

    return 0;
}