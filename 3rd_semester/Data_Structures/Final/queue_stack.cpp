#include<iostream>
using namespace std;
class Stack{
private:
    int top,size,capacity;
    int *data;

    bool isEmpty() {
        
    }
public:
    Stack(int cap) : capacity(cap), size(0), top(-1) {
        data = new int[capacity];
    }
    void push() {}



};
class Queue{};
int main() {}