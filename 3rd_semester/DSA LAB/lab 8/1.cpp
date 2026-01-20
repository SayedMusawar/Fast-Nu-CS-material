#include<iostream>
using namespace std;
class Stack{
private:
    char *ch;
    int top;
    int size;
public:
    Stack(int s) : top(-1), size(s) {
        ch = new char[s];
    }
    bool isFull() { return (top == size - 1); }

    bool isEmpty() { return top == -1; }

    void push(char n) {
        if(isFull()) {
            cout<<"Stack is full"<<endl;
            return;
        }
        ++top;
        ch[top] = n; 
    }

    void pop()  {
        if(isEmpty()) {
            cout<<"Stack is already empty"<<endl;
            return;
        }
        --top;
    }

    char peek() {
        if(isEmpty()) return '\0';
        return ch[top];
    }

    bool Palimdrone() {
        Stack S2(size);

        for(int i = 0; i <=top; i++) S2.push(ch[i]);

        for(int i = 0; i <= top; i++) {
            if(ch[i] != S2.peek()) return false;
            S2.pop();
        }
        return true;
    }
};
int main() {
    Stack S(5);
    S.push('M');
    S.push('W');
    S.push('E');
    S.push('A');
    S.push('M');

    if(S.Palimdrone()) cout<<"It is a palindrome"<<endl;
    else cout<<"It is not a palindrome"<<endl;

    return 0;
}