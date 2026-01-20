#include<iostream>
using namespace std;

class Stack{
private:
    int *data;
    int top,size,cap;
public:
    Stack(int c = 0) : cap(c), top(-1), size(0) {
        data = new int[cap];
    }

    bool isEmpty() { return top == -1; }

    bool isFull() { return size == cap;}

    void push(int val) {
        if(isFull()) {
            cout<<"List is full can't add more elements"<<endl;
            return;
        }
        top++;
        data[top] = val;
        size++;
    }
    void pop() {
        if(isEmpty()) {
            cout<<"List is already empty... Can't remove more elements"<<endl;
            return;
        }
        top--;
        size--;
    }
    int peek() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        return data[top]; 
    }
};