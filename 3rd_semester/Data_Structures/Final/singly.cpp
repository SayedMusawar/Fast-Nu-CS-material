#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val) : data(val),next(nullptr) {}
};
class SinglyLinkedList{
private:
    Node *head, *tail;

    bool isEmpty() {
        return (head == nullptr);
    }
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int key) {
        Node *newNode = new Node(key);
        if(isEmpty()) head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int key) {
        Node *newNode = new Node(key);
        if(isEmpty()) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfterVal(int key,int afterVal) {
        Node *newNode = new Node(key);
        Node *temp = head;
        while(temp != nullptr && temp->data != afterVal) temp = temp->next;
        if(temp == nullptr) {
            cout<<"Value not found"<<endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;

        if(temp == tail) tail = newNode;
    }

    void deleteKey(int key) {
        if(isEmpty()) {
            cout<<"List is Empty"<<endl;
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while(curr != nullptr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == nullptr) {
            cout<<"Value not found"<<endl;
            return;
        }
        if(curr == head) head = head->next;
        else {
            prev->next = curr->next;
            if(curr == tail) tail = prev;
        }
        delete curr;
    }

    bool searchKey(int key) {
        Node *temp = head;
        while(temp != nullptr && temp->data != key) temp = temp->next;

        if(temp == nullptr) return false;
        return true;
    }

    Node* reverseList() {
        Node *prev = nullptr;
        Node *curr  =head;
        Node *next  = nullptr;
        tail = head;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
        return prev;
    }

    void display() {
        for(Node *i = head; i != nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }
};
class Stack{};
class Queue{};

int main() {
    SinglyLinkedList s;
    s.insertAtBeginning(20);
    s.insertAtBeginning(10);
    s.insertAtEnd(40);
    s.insertAfterVal(30,20);

    s.display();

    s.reverseList();
    s.display();
}