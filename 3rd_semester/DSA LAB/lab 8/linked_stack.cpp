#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class Stack{
private:
    Node *top;
public:
    Stack() : top(nullptr) {}

    bool isEmpty() { return top == nullptr; }

    void push(int val) {
        Node *newNode = new Node(val);
        if(isEmpty()) top = newNode;
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        Node *temp  = top;
        top = top->next;
        delete temp;
    }

    void display() {
        for(Node *i = top; i != nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }
};
int main() {
    Stack S;
    S.push(44);
    S.display();

    S.push(222);
    S.display();

    S.push(234);
    S.display();

    S.push(1);
    S.display();

    S.pop();
    S.display();

    S.pop();
    S.display();

    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    return 0;
}