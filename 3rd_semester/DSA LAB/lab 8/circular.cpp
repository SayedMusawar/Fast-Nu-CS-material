#include<iostream>
using namespace std;
class CircularQueue{
private:
    int *data;
    int size, front, rear;
public:
    CircularQueue(int val = 0) : size(val), front(-1) , rear(-1) {
        data = new int[size];
    } 
    bool isEmpty() { return front == -1;}
    bool isFull() { return ((rear + 1) % size == front);}

    void enqueue(int val) {
        if(isFull()) {
            cout<<"Overflow"<<endl;
            return;
        }

        if(isEmpty()) front = rear = 0;
        else rear = (rear + 1) % size;
        data[rear] = val;
    }
    void dequeue() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        if(front == rear) front = rear = -1;
        else front = (front + 1) % size;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"no element found"<<endl;
            return -1;
        }
        return data[front];
    }

    void display() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        for(int i = front;  ; i = (i + 1) % size) {
            cout<<data[i]<<" ";
            if( i == rear) break;
        }    
        cout<<endl;
    }
};
int main() {
    CircularQueue q(5);

    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(99);
    q.display();

    q.enqueue(44);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(44);
    q.display();

    return 0;
}