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
    int val, count, middle;
    Node *Head, *Tail;
    bool isEmpty() {
        if(Head == NULL) {
            return true;
        } else return false;
    }
public:
    linkedList() : val(0), count(0), middle(0), Head(NULL), Tail(NULL) {}


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

    void insertAtMiddle() {
        Node *temp = Head;
        Node *midd = Head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        middle = (count / 2) + 1;
        count = 0;
        while(midd != NULL) {
            count++;
            if(count == middle) {
                cout<<"The middle element is: "<<midd->data<<endl;
                return;
            }
            midd = midd->next;
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
    for(int i = 0; i < 5 ; i++) {
        L1.insertAtEnd();
    }
    L1.display();

    L1.insertAtMiddle();
    L1.display();
}