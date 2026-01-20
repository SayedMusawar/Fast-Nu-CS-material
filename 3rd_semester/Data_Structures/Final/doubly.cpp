#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *prev, *next;
    Node(int val) : data(val),prev(nullptr),next(nullptr) {}
};
class Doubly{
private:
    Node *head, *tail;
    bool isEmpty() {return head== nullptr;}
public: 
    Doubly() : head(nullptr), tail(nullptr) {}
    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        if(isEmpty()) head = tail = newNode;
        
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        if(isEmpty()) {head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAfterVal(int val,int afterVal) {
        Node *newNode = new Node(val);
        Node *temp = head;
        while(temp != nullptr && temp->data != afterVal) temp = temp->next;
        if(temp == nullptr) {
            cout<<"value not found"<<endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next != nullptr) temp->next->prev  =newNode;
        else tail = newNode;

        temp->next = newNode;
    }

    void deleteKey(int val) {

    }

    void reverseList() {
        Node *curr = head;
        Node *temp = nullptr;
        while(curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        temp = head;
        head = tail;
        tail = temp;
    }
    void display() {
        for(Node *i = head; i != nullptr ; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }
};
int main() {
    Doubly d;

    d.insertAtEnd(10);
    d.insertAtEnd(20);
    d.insertAtEnd(30);
    d.insertAtEnd(40);

    d.display();

    d.reverseList();
    d.display();
}