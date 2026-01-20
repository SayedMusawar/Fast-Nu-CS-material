#include<iostream>
using namespace std;
const int SIZE = 50;
class Node{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class QueueLinked{
private:
    Node *front, *rear;
public:
    QueueLinked() : front(nullptr) {}
    bool isEmpty() { return front == nullptr;}
    void enqueue(int val) {
        Node *newNode = new Node(val);
        if(isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"Underflow condition"<<endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        for(Node *i = front; i != nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }
};

class NodeP{
public:
    int data, priority;
    NodeP *next;
    NodeP(int val, int pri) : data(val), priority(pri), next(nullptr) {}
};
class PriorityQueue{
private:
    NodeP *front;
public:
    PriorityQueue() {front == nullptr;}

    void enqueue(int val, int priority) {
        NodeP *newNode = new NodeP(val, priority);
        if(front == nullptr || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            NodeP *temp = front;
            while(temp->next != nullptr && temp->next->priority <= priority) temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if(front == nullptr) return;

        NodeP *temp = front;
        front = front->next;
        delete temp;
    }
};

class QueueArrCircular{
private:
    int *data;
    int front, rear;
public:
    QueueArrCircular() : front(-1), rear(-1) {
        data = new int[SIZE];
    }

    bool isFull() {
        return (rear + 1) % SIZE == front; 
    }
    bool isEmpty() {
        return front == -1;
    }
    void enqueue(int val) {
        if(isFull()) {cout<<"Overflow"<<endl; return;}

        if(isEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;

        data[rear] = val;
    }

    void dequeue() {
        if(isEmpty()) {cout<<"Underflow"<<endl; return;}

        if(front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }
    int peek() {
        if(isEmpty()) {
            cout<<"List is Empty"<<endl;
            return -1;
        }
        return data[front];
    }
    void display() {
        for(int i = front ; i == rear ; i = (i + 1)% SIZE) cout<<data[i]<<" ";
        cout<<endl;
    }
};

class QueueArr{
private:
    int *data;
    int front, rear;
public:
    QueueArr() : front(-1), rear(-1) {
        data = new int[SIZE];
    }

    bool isFull() {
        return rear == SIZE - 1; 
    }
    bool isEmpty() {
        return front == -1;
    }
    void enqueue(int val) {
        if(isFull()) {cout<<"Overflow"<<endl; return;}

        if(isEmpty()) front = rear = 0;
        else rear++;

        data[rear] = val;
    }

    void dequeue() {
        if(isEmpty()) {cout<<"Underflow"<<endl; return;}

        if(front >= rear) front = rear = -1;
        else front++;
    }
    int peek() {
        if(isEmpty()) {
            cout<<"List is Empty"<<endl;
            return -1;
        }
        return data[front];
    }
    void display() {
        for(int i = front ; i<= rear ; i++) cout<<data[i]<<" ";
        cout<<endl;
    }
};
int main() {
    QueueLinked a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);

    a.display();

}