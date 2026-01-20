#include<iostream>
using namespace std;

class Queue {
private:
    int size,front,rear;
    int *items;
public:

    Queue(int s) : size(s), front(-1), rear(-1) {
        items = new int[size];
    }
    ~Queue() {
        delete[] items;
    }

    bool isFull() { return rear == size -1; }

    bool isEmpty() { return front == -1; }

    void enqueue(int val) {
        if(isFull()) {
            cout<<"Overflow"<<endl;
            return;
        }

        if(isEmpty()) front = rear = 0;
        else 
            rear++;
        items[rear] = val;
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"List is empty nothing to delete"<<endl;
            return;
        } 
        if(front == rear) front = rear = -1;
        else front++;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"no element found"<<endl;
            return -1;
        }
        return items[front];
    }

    void display() {
        if(isEmpty()) {
            cout<<"No element found"<<endl;
            return;
        }

        for(int i = front; i <= rear; i++) cout<<items[i]<<" ";
        cout<<endl;
    }
};



int main() {
    Queue q(5);
    q.enqueue(30); q.enqueue(3); q.enqueue(50); q.enqueue(20); q.enqueue(44);
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