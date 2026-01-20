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
    int val, count, evenCount, oddCount;
    Node *Head, *Tail;
    bool isEmpty() {
        if(Head == NULL) {
            return true;
        } else return false;
    }
public:
    linkedList() : val(0), count(0), evenCount(0), oddCount(0), Head(NULL), Tail(NULL) {}

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

    void indicesCount() {
        Node *temp =  Head;
        while(temp != NULL) {
            if(count % 2 == 0  && temp->data % 2 == 0) {
                evenCount++;
            } else if (count % 2 != 0 && temp->data % 2 != 0) {
                oddCount++;
            }
            count++;
            temp = temp->next;
        }
        cout<<"Even numbers at even indices: "<<evenCount<<endl;
        cout<<"Odd numbers at odd indices are: "<<oddCount<<endl;
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
    for(int i = 0; i < 8 ; i++) {
        L1.insertAtEnd();
    }
    L1.display();

    L1.indicesCount();
}