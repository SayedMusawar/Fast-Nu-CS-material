#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val = 0): data(val), next(NULL) {}
};
class LinkedList{
private:
    int val, afterVal;
    Node *Head, *Tail;
    bool isEmpty() {
        return (Head == NULL);
    }

public:
    LinkedList(int val = 0) : Head(NULL) , Tail(NULL) {}

    void insertAtBegining() {
        cout<<"Enter the value to enter"<<endl;
        cin >> val;
        Node *newNode = new Node(val);
        if(isEmpty()) {
            Head = Tail = newNode;
            return;
        }
        newNode->next = Head;
        Head = newNode;
    }

    void insertAtEnd() {
        cout<<"Enter the value to enter"<<endl;
        cin >> val;
        Node *newNode = new Node(val);
        if(isEmpty()) {
            Head = Tail = newNode;
            return;
        }

        Tail->next = newNode;
        Tail = newNode;
    }

    void insertAfterVal() {
        if(isEmpty()) {
            cout<<"List is empty can insert after a value"<<endl;
            return;
        }
        cout<<"Enter the value after which you want to insert the value"<<endl;
        cin >> afterVal;
        Node *temp = Head;
        while(temp != NULL && temp->data != afterVal) temp = temp->next; 

        if(temp == NULL) {
            cout<<"Value not found"<<endl;
            return;
        }

        cout<<"Enter the value you want"<<endl;
        cin >> val;
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if(temp == Tail) Tail = newNode;
    }

    void deletion() {
        if(isEmpty()) {
            cout<<"List is already empty... Can't delete a value"<<endl;
            return;
        }
        cout<<"Enter the value to delete it"<<endl;
        cin >> val;
        
        if(Head->data == val) {
            Node *temp = Head;
            Head = Head->next;
            if(Head == NULL) Tail = NULL;
            delete temp;
            return;
        }

        Node *CN = Head;
        Node *PN = NULL;

        while(CN != NULL && CN->data != val) {
            PN = CN;
            CN = CN->next;
        }
        if(CN == NULL) {
            cout<<"Value not found"<<endl;
            return;
        }
        PN->next = CN->next;
        if(CN == Tail) Tail = PN;

        delete CN;
        cout<<"Value deleted succesfully"<<endl;
    }

    void search() {
        if(isEmpty()) {
            cout<<"List is already empty... Can't search a value"<<endl;
            return;
        }
        cout<<"Enter the value to search it"<<endl;
        int count = 0;
        cin >> val;
        Node *temp = Head;
        while(temp != NULL && temp->data != val) {
            count++;
            temp = temp->next;
        }

        if(temp == NULL) cout<<"Value not found"<<endl;
        else if(temp->data == val) cout<<"Value found at the "<<count<<"th index"<<endl;
    }

    void reverse() {
        if(Head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *pN = NULL;
        Node *cN = Head;
        Node *nN = NULL;

        while(cN != NULL) {
            nN = cN->next;
            cN->next = pN;
            pN = cN;
            cN = nN;
        }
        Head = pN;

    }

    void convertToCircular() {
        if(isEmpty()) {
            cout<<"The list is empty"<<endl;
            return;
        }
        if(Tail->next = Head) {
            cout<<"List is already circular"<<endl;
            return;
        }
        Tail->next = Head;
    }

    void display() {
        cout<<"The elements are: ";
        Node *temp = Head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<endl;
    }

    ~LinkedList() {
        if(Head == NULL) return;

        Node *curr = Head;
        Node * nextNode = NULL;

        bool isCircular = (Tail != NULL && Tail->next == Head);
        if(isCircular) {
            Tail->next = NULL;
        }
        while(curr != NULL) {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        Head = Tail = NULL;
    }
};

int main() {
    LinkedList L1;

    L1.insertAtEnd();
    L1.insertAtEnd();
    L1.insertAtEnd();

    L1.insertAfterVal();
    L1.display();

    L1.reverse();
    L1.display();
}