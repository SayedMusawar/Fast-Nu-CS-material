#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int val = 0) : data(val), next(NULL) {} 
};
class LinkedList{
private:
    int val,afterVal,count;
    Node *Head, *Tail;
    bool isEmpty() {
        if(Head == NULL) {
            return true;
        } else return false;
    }
public:
    LinkedList() : val(0), afterVal(0), count(0) , Head(NULL), Tail(NULL) {}

    void insertAtBeginning() {
        cout<<"Enter the value to insert"<<endl;
        cin >> val;
        Node *newNode = new Node(val);
        
        newNode->next = Head;
        Head = newNode;
        
        if(Tail == NULL) {
            Tail = newNode;
        } 
    }

    void insertAtEnd() {
        cout<<"Enter the value"<<endl;
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
        cout<<"Enter the targeted value"<<endl;
        cin >> afterVal;
        Node *temp = Head;
        while(temp != NULL) {
            if(temp->data == afterVal) {
                count++;
            }
            if(count == 3) {
                cout<<"Enter the value you want to add in the list"<<endl;
                cin >> val;
                Node *newNode = new Node(val);

                newNode->next = temp->next;
                temp->next = newNode;
                if(temp == Tail) {
                    Tail = newNode;
                }
                return;
            }
            temp = temp->next;
        }
    }
};
