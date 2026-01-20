#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList;
class LinkedList{
private:
    Node *head, *tail;
    bool isEmpty() {return head == nullptr;}
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBegining(int val) {
        Node *newNode = new Node(val);

        if(isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);

        if(isEmpty()) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertAfterVal(int val, int afterVal) {
        Node *newNode = new Node(val);

        Node *temp = head;
        while(temp != nullptr && temp->data != afterVal) temp = temp->next;

        if(temp == nullptr) {
            cout<<"Value not found"<<endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteVal(int val) {
        if(isEmpty()) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while(temp != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == nullptr) {
            cout<<"Value not found"<<endl;
            return;
        }
        if(temp == head) head = head->next;
        if(temp == tail) {
            tail = prev;
            prev->next = temp->next;
        } else prev->next = temp->next;
        delete temp;
    }

    void display() {
        for(Node* i = head; i != nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }
};

class HashTable{
private:
    LinkedList *table;
    int size;
public:
    HashTable(int s) : size(s) {
        table = new LinkedList[size];
    }
    int hashFunction(int key) {
        return key % size;
    }
    int insertKey(int key) {
        int index  = hashFunction(key);
        table[index].insertAtEnd(key);
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout<<"Index "<<i<<": ";
            table[i].display();
        }
    }
};

int main() {
    LinkedList l1;
    l1.insertAtBegining(10);
    l1.insertAtBegining(5);
    l1.insertAtEnd(12);
    l1.insertAfterVal(13,12);

    l1.display();
    l1.deleteVal(10);

    l1.display();

}