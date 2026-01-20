#include<iostream>
using namespace std;
const int SIZE = 100;
class Node{
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class StackLinked{
private:
    Node *top;
    
public:
    int size;
    StackLinked() : size(0), top(nullptr) {}

    bool isEmpty() {return top == nullptr;}

    void push(int val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        int val = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
        return val;
    }

    void insertAtBottom(int val) {
        if(isEmpty()) {
            push(val);
            return;
        }

        int topVal = pop();
        insertAtBottom(val);
        push(topVal);
    }

    // Q3 reverse a stack using recursion
    void reverseList() {
        if(isEmpty()) return;

        int val = pop();
        reverseList();
        insertAtBottom(val);
    }

    //  Q4 Sort a stack using recursion
    
    void insertSort(int val) {
        if(isEmpty() || val < top->data) {
            push(val);
            return;
        }
        int topVal = pop();
        insertSort(val);
        push(topVal);
    }

    void SortStack() {
        if(top->next == nullptr) return;

        int topVal = pop();
        SortStack();
        insertSort(topVal);
    }

    // Q5 Delete the middle of the Stack
    void delMiddle(int count,int mid) {
        if(count == mid) {
            pop();
            return;
        }
        int topVal = pop();
        delMiddle(count + 1,mid);
        push(topVal);
    }
    void deleteMiddle() {
        if(top == nullptr) return;

        int mid = size / 2;
        delMiddle(0,mid);
    }

    int peek() {
        if(isEmpty()) {
            cout<<"underflow"<<endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        Node *temp = top;
        while(temp != nullptr) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
// For question 6 valide parenthesis
class StackString{
private:
    char arr[SIZE];
    int top;
public:
    StackString() : top(-1) {}
    bool isEmpty() { return top == -1;}

    bool isFull() {return top == SIZE - 1;}

    void push(char x) {
        if(isFull()) {
            cout<<"Overflow"<<endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        top--;
    }
    char peek() {
        if(isEmpty()) {
            cout<<"Stack is empty()"<<endl;
            return ' ';
        }
        return arr[top];
    }

    // Q6 is valid parenthesis
    bool isValidParenthesis(string str) {
        top = -1;
        for(char c : str) {
            if(c == '(' || c == '{' || c == '[') {
                if(isFull()) {
                    cout<<"Stack overflow"<<endl;
                    return false;
                }
                push(c);
            } else if(c == ')' || c == '}' || c == ']') {
                if(isEmpty()) return false;

                char topChar = peek();
                if((c == ')' && topChar != '(') || (c == '}' && topChar != '{') || (c == ']' && topChar != '[')) {
                    return false;
                }
                pop();
            }
        }
        return isEmpty();
    }

    void display() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        cout<<"Stack elements are: ";
        for(int i = top; i>= 0; i--) cout<<arr[i]<<" ";
        cout<<endl;
    }
};
// For question 7 next grater element
class StackInt{
private:
    int arr[SIZE];
    int top;
public:
    StackInt() : top(-1) {}

    bool isEmpty() {return top == -1;}
    bool isFull() {return top == SIZE-1;}

    void push(int x){
        if(isFull()){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow";
            return -1;
        }
        int x = arr[top--];
        return x;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    // Q7 Next greater element for each element
    void nextGreaterElement(int arr[], int n, int res[]) {
        StackInt st;

        for(int i =0; i<n; i++) res[i] = -1;

        for(int i =0; i <n ;i++) {
            while(!st.isEmpty() && arr[i] > arr[st.peek()]) {
                int index = st.pop();
                res[index] = arr[index];
            }
            st.push(i);
        }
    }
};

void displayMenu() {
    cout<<"===== STACK LIST MENU ====="<<endl;
    cout<<"1. push value"<<endl;
    cout<<"2. pop value"<<endl;
    cout<<"3. peek value"<<endl;
    cout<<"4. Reverse Stack"<<endl;
    cout<<"5. Sort stack"<<endl;
    cout<<"6. Delete middle value of a linked list"<<endl;
    cout<<"7. Check Palindrome"<<endl;
    cout<<"8. Next greater element for each element"<<endl;
    cout<<"9. Display values"<<endl;
    cout<<"0. Exit"<<endl;
}

int main() {
    StackInt s;
    int arr[] = {4,5,2,10};
    int n = 4;
    int res[4];
    s.nextGreaterElement(arr,n,res);
    for(int i = 0; i < n ;i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}