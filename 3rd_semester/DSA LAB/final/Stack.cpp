#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class StackList{
private:
    Node *top;
public:
    StackList() : top(nullptr) {}

    bool isEmpty() {return top == nullptr;}

    void push(int val) {
        Node *newNode = new Node(val);
            newNode->next = top;
            top = newNode;
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        for(Node *i = top; i != nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }
};





























class StackArr{
private:
    int *data,top,size;

    bool isFull() {return top == size -1;}

    bool isEmpty() {return top == -1;}
public:
    StackArr(int s = 50) : size(s), top(-1) {
        data = new int[size];
    }
    void push(int val) {
        if(isFull()) {
            cout<<"OverFlow"<<endl;
            return;
        }
        top++;
        data[top] = val;
    }
    int pop() {
        if(isEmpty()) {
            cout<<"UnderFlow"<<endl;
            return;
        }
        int x = data[top--];
        return x;
    }
    int peek() {
        if(isEmpty()) {
            cout<<"UnderFlow"<<endl;
            return;
        }
        return data[top];
    }

    void display() {
        for(int i = top; i >= top; i--) cout<<data[i]<<"  ";
    }
};
int main() {
    StackArr a;
}