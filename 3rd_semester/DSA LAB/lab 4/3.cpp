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
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }


    void removeNode(int target) {
        Node* cN = head;
        Node* pN = NULL;

        if(head->data == target) {
            if(head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            Node *temp1 = head;

            while (temp1->next != head) {
                temp1 = temp1->next;
            }
            Node *temp2 = head;
            head = head->next;
            temp2->next = head;
            delete temp2;
            return;
        }
        do {
            pN = cN;
            cN = cN->next;
            if(cN->data == target) {
                pN->next = cN->next;
                delete cN;
                return;
            }
        } while (cN != head);
    }

    void find() {
        if(!head) return;
        Node* i = head;
        do {
            Node* j = i->next;
            Node* prev = i;
            while(j != head) {
                if (j->data == i->data) {
                    prev->next = j->next;
                    delete j;
                    j = prev->next;
                } else {
                    prev = j;
                    j = j->next;
                }
            }
            i = i->next;
        } while ( i != head);
    }
    void display() {
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        }

    while (temp != head);
    }
};
int main() {
    LinkedList l1;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(20);
    l1.insert(40);
    l1.insert(30);

    l1.display();
    l1.find();
    // l1.find();~
    cout<<endl;
    l1.display();
}