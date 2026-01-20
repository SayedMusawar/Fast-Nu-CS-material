#include<iostream>
using namespace std;
const int SIZE = 5;
class Stack{
private:
    int arr[SIZE];
    int top;
public:
    Stack() : top(-1) {}

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
};
//  Q2 Linked list implementation of Queues refer to question 2 of the assignment
class Node{
public:
    int data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}
};
class QueueList{
private:
    Node *front, *rear;
    int size;
public:
    QueueList() :size(-1) ,front(nullptr), rear(nullptr) {}
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int val) {
        Node *newNode = new Node(val);

        if(isEmpty()) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
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
        } else return front->data;
    }
    void display() {
        for(Node *i = front; i != nullptr; i = i->next) cout<<i->data<<"-> ";
        cout<<endl;
    }
    // Q4 Reverse first K elements of the queue
    void reverseFirstK(int k) {
        if(isEmpty() || k<= 1) return;
        Node *curr = front;
        Node *prev = nullptr;
        Node *next = nullptr;

        int count = 0;

        while(curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        Node *oldFront = front;
        front = prev;
        oldFront->next = curr;

        if(curr == nullptr) rear = oldFront;
    }

    bool isPalindrome() {
        if(isEmpty() || front->next == nullptr) return true;
        Stack st;

        // Push all elements of queue in stack
        for(Node *curr = front; curr != nullptr; curr = curr->next) st.push(curr->data);

        // Compare queue elements with stack top
        for(Node *curr = front; curr != nullptr; curr = curr->next) 
            if(curr->data != st.pop()) return false;

        return true;
    }
};


// Q1 question 1 array implementation of queues
class QueueArr{
private:
    int *arr;
    int front, rear;
public:
    QueueArr() : front(-1), rear(-1) {
        arr = new int[SIZE];
    }

    bool isEmpty() {return front == -1;}

    bool isFull() {return rear == SIZE - 1;}

    void enqueue(int val) {
        if(isFull()) {
            cout<<"Overflow"<<endl;
            return;
        }
        if(isEmpty()) front = rear = 0;
        else rear++;

        arr[rear] = val;
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        if(front >= rear) front = rear = -1;
        else front++;
    }
    int peek() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        return arr[front];
    }
    void display() {
        for(int i = front; i <= rear; i++) cout<<*(arr+i)<<" ";
        cout<<endl;
    }
};
// Q3 Implementation of priority Queue using array
class PriorityQueue{
private:
    int *arr, *priorities;
    int front, rear;
public:
    PriorityQueue() : front(-1), rear(-1) {
        arr = new int[SIZE];
        priorities = new int[SIZE];
    }

    bool isEmpty() {return front == -1;}

    bool isFull() {return rear == SIZE - 1;}

    void enqueue(int val, int priority) {
        if(isFull()) {
            cout<<"Overflow"<<endl;
            return;
        }
        if(isEmpty()) {
            front = rear = 0;
            arr[0] = val;
            priorities[0] = priority;
            return;
        }
        int i;
        for(i = rear; i>= front && priorities[i] > priority; i--) {
            arr[i + 1] = arr[i];
            priorities[i + 1] = priorities[i];
        }
        arr[i + 1] = val;
        priorities[i + 1] = priority;
        rear++;
    }
    void dequeue() {
        if(isEmpty()) {
            cout<<"Underflow"<<endl;
            return;
        }
        if(front == rear) front = rear = -1;
        else front++;
    }
    int peek() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    void display() {
        if(isEmpty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i = front; i<= rear; i++) cout<<arr[i]<<"(priority: "<<priorities[i]<<")";
        cout<<endl;
    }
};
void displayMenu() {
    cout<<"===== QUEUE LIST MENU ====="<<endl;
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. peek value"<<endl;
    cout<<"4. Reverse First K elements"<<endl;
    cout<<"5. Check Palindrome"<<endl;
    cout<<"6. Display values"<<endl;
    cout<<"0. Exit"<<endl;
}
int main() {
    QueueList q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();
    q.reverseFirstK(3);
    q.display();
    return 0;
}