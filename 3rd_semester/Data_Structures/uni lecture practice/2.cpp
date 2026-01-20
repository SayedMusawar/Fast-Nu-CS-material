#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void reverseUptoK(int k) {
        if (!head || k <= 1) return;

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        Node* lastNodeOfFirstPart = NULL; // before reversal part
        Node* lastNodeOfSubList = head;  // will become last after reversal

        int count = 0;
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Connect reversed part with remaining list
        head = prev;  // New head (first k reversed)
        lastNodeOfSubList->next = curr; // Attach remainder
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Example list: 1->2->3->4->5
    for (int i = 1; i <= 5; i++) {
        list.insertAtEnd(i);
    }

    cout << "Original list: ";
    list.display();

    int k = 2;
    list.reverseUptoK(k);

    cout << "List after reversing first " << k << " elements: ";
    list.display();

    return 0;
}
