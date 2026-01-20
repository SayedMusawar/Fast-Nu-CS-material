#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val = 0) : data(val) , next(NULL) {}
};
class linkedList{
private:
    int val,targetVal, count;
    Node *Head, *Tail;
    bool isEmpty() {
        if(Head == NULL) {
            return true;
        } else return false;
    }
public:
    linkedList() : val(0), targetVal(0), count(0), Head(NULL), Tail(NULL) {}


    void insertAtBeginning() {
        cout<<"Enter the value you want to add in the list"<<endl;
        cin >> val;
        Node *newNode = new Node(val);

        newNode->next = Head;
        Head = newNode;

        if(Tail == NULL) {
            Tail = newNode;
        }
    }

    void insertAtEnd() {
        cout<<"Enter the value you want to add in the list"<<endl;
        cin >> val;
        Node *newNode = new Node(val);
        if(isEmpty()) {
            Head = Tail = newNode;
        }
        Tail->next = newNode;
        Tail = newNode;
    }

    void insertAfterVal() {
        Node *temp = Head;
        cout<<"Enter the target value"<<endl;
        cin >> targetVal;
        while(temp != NULL) {
            if(temp->data == targetVal) {
                count++;
            }
            if(count == 3) {
                cout<<"Enter the value you want to add in the list"<<endl;
                cin >> val;
                Node *newNode = new Node(val);

                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void display() {
        Node *temp = Head;
        while (temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
int main() {
    linkedList L1;
    for(int i = 0; i < 9 ; i++) {
        L1.insertAtEnd();
    }
    L1.display();

    L1.insertAfterVal();
    L1.display();
}