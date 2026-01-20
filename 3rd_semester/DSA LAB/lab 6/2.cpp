#include<iostream>
using namespace std;
class Queue{
private:
    string *patient;
    int size, front, rear, elements;
public:
    Queue(int s) {
        size = s;
        patient = new string[size];
        front = -1;
        rear = -1;
        elements = 0;
    }
    bool isFull() {
        return elements = size;
    }
    bool isEmpty() {
        return elements == 0;
    }

    void enqueue(string name) {
        if(isFull()) {
            cout<<"Waiting area is full"<<endl;
            return;
        }
        if(isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        patient[rear] = name;
        elements++;
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"No patient available"<<endl;
            return;
        }
        front = (front + 1) % size;
        elements--;
        if(elements == 0) {
            front = -1;
            rear = -1;
        }
    }

    string getNextPatient() {
        if(isEmpty()) {
            cout<<"No patient present"<<endl;
            return;
        }
        return patient[front];
    }

    void display() {
        if(isEmpty()) {
            cout<<"No patients available"<<endl;
            return;
        }
        for(int i = front; i == rear;i = (i + 1) % size) cout<<patient[i]<<" ";
        cout<<endl;
    }

    ~Queue() {
        delete[] patient;
    }
};
int main() {
    int seats;
    cout<<"Enter the seats available for patients"<<endl;
    cin >> seats;

    Queue q(seats);

    int choice;
    string patientName;

    do {
        cout << "\nDoctor's Office Queue Management" << endl;
        cout << "1. Add Patient to Queue" << endl;
        cout << "2. Send next patient to doctor" << endl;
        cout << "3. See who's next" << endl;
        cout << "4. Display patient queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                getline(cin, patientName);
                q.enqueue(patientName);
                break;
            case 2:
                if (!q.isEmpty()) {
                    cout << "Sending " << q.getNextPatient() << " to the doctor." << endl;
                    q.dequeue();
                }
                break;
            case 3:
                cout << "Next patient: " << q.getNextPatient() << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting system..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}