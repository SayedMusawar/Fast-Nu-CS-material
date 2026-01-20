#include<iostream>
using namespace std;
class Node{
// private:
public:
    int data;
    Node *next;

    Node(int val = 0) : data(val) , next(NULL) {}
};
class LinkedList{
// private:
public:
    Node *head1, *head2;

    LinkedList() { head1 = NULL; head2 = NULL;}

    void insert1(int val) {
        Node *newNode = new Node(val);
        if(head1 == NULL) {
            head1 = newNode;
            head1->next = head1;
        }
        Node *temp = head1;
        while(temp->next != head1) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next =head1;
    }

    void insert2(int val) {
        Node *newNode = new Node(val);
        if(head2 == NULL) {
            head2 = newNode;
            head2->next = head2;
        }
        Node *temp = head2;
        while(temp->next != head2) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next =head2;
    }

    void checkCommon() {
        int count = 0;

        Node *i = head1;
        do{
            Node *j = head2;
            do{
                if(i->data == j->data) {
                    cout<<"common values: "<<i->data<<endl;
                    count++;
                }
                j = j->next;
            } while(j != head2);
            i = i->next;
        } while( i != head1);

        // for (Node *i = head1; i->next != head1; i = i->next) {
        //     for(Node *j = head2 ; j->next != head2; j = j->next) {
        //         if(i->data == j->data) {
        //             cout<<"common values: "<<i->data<<endl;
        //             count++;
        //         }
        //     }
        // }
        cout<<"total common elements are: "<<count<<endl;
    }
};
int main() {
    LinkedList l1;
    l1.insert1(10);
    l1.insert1(20);
    l1.insert1(30);
    l1.insert1(40);
    l1.insert1(50);

    l1.insert2(30);
    l1.insert2(50);
    l1.insert2(70);
    l1.insert2(90);

    l1.checkCommon();
}