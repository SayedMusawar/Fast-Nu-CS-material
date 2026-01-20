#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val = 0): data(val), next(nullptr) {}
};
class Queue {
private:
    Node *front,*rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}
    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node *newNode = new Node(val);
        if(isEmpty()) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
        }
        Node *temp  = front;
        front = front->next;
        delete temp;
    }

    void display() {
        for(Node *i = front; i != nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }
};
int main() {
    Queue q;
    q.enqueue(5);
    q.display();

    q.enqueue(4);
    q.display();

    q.enqueue(33);
    q.display();

    q.enqueue(111);
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    q.display();
    return 0;
}