#include<iostream>
using namespace std;
class Queue{
private:
    int front, rear, size;
    int *arr;
public:
    Queue(int s = 0) : front(-1) , rear(-1), size(s) {
        arr = new int[size];
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return (rear == size - 1);
    }
    void enqueue(int val) {
        if(isFull()) {
            cout<<"List is already full... Can't add more elements"<<endl;
            return;
        }
        if(isEmpty()) {
            front = 0;
        }
        arr[++rear] = val;
    }
    void dequeue() {
        if(isEmpty()) {
            cout<<"List is already empty"<<endl;
            return;
        }
        if(front >= rear) front = rear = -1;
        else front++;
    }
    void display() {
        cout<<"Elements includes: ";
        for(int i = front; i <= rear; i++) {
            cout<<*(arr + i)<<" ";
        }
        cout<<endl;
    }
};
int main() {
    Queue q(5);
    q.enqueue(5);
    q.display();
    q.enqueue(10);
    q.enqueue(15);
    q.display();

    q.dequeue();
    q.display();
    return 0;
}