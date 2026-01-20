#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *prev, *next;
    Node(int val = 0) :  data(val), prev(NULL), next(NULL) {}
};
class Doubly{
private:
    int val, afterVal;
    Node *Head, *Tail;
public:
    Doubly() : Head(NULL), Tail(NULL) {}

    void insertAtBeginning() {
        cout<<"Enter the value to insert it in the list"<<endl;
        cin >> val;

        Node *newNode = new Node(val);

        if(Head == NULL) Head = Tail = newNode;
        else {
            newNode->next =Head;
            Head->prev = newNode;
            Head = newNode;
        } 
    }

    void insertAtEnd() {
        cout<<"Enter the value"<<endl;
        cin >> val;

        Node *newNode = new Node(val);

        if(Head == NULL) Head = Tail = newNode;
        else {
            Tail->next = newNode;
            newNode->prev = Tail;
            Tail = newNode;
        }
    }

    void insertAfterVal() {
        cout<<"Enter the value after which you want to enter the value"<<endl;
        cin >> afterVal;
        Node *temp = Head;
        while(temp != NULL && temp->data != afterVal) {
            temp = temp->next;
        }

        if(temp == NULL) {
            cout<<"value not found"<<endl;
            return;
        } 

        cout<<"Enter the value you want to insertt"<<endl;

        cin >> val;
        Node *newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next != NULL) temp->next->prev = newNode; 
        else Tail = newNode;

        temp->next = newNode;
    }

    void deletion() {
        cout<<"Enter the value you want to delete"<<endl;
        cin >> val;
        Node *temp = Head;

        while(temp != NULL && temp->data != val) temp = temp->next;
        if(temp == NULL) {
            cout<<"Value not found"<<endl;
            return;
        }
        if(Head == Tail) {
            Head = Tail = NULL;
            delete temp;
        } else if(temp == Head) {
            Head = temp->next;
            temp->next->prev = NULL;
            delete temp;
        } else if(temp == Tail) {
            temp->prev->next = NULL;
            Tail = temp->prev;
            delete temp;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }

    void reverse() {
        
    }

    int countNodes() {
        Node *temp = Head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        Node *temp = Head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main() {
    Doubly D1;

    D1.insertAtEnd();
    D1.insertAtEnd();
    cout<<endl;
    D1.insertAtEnd();
    cout<<endl;

    cout<<D1.countNodes();

    // D1.display();
    // cout<<endl;

    // D1.deletion();
    // D1.display();
    return 0;
}