#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val) , prev(nullptr), next(nullptr) {}
};
class Doubly{
private:
    Node *head;
    Node *tail;

    bool isEmpty() {
        return (head == nullptr);
    }

    Node* mergeLists(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        
        Node* head = nullptr;
        Node* tail = nullptr;
        
        // Initialize head and tail
        if (head1->data <= head2->data) {
            head = tail = head1;
            head1 = head1->next;
        } else {
            head = tail = head2;
            head2 = head2->next;
        }
        
        // Set prev of head to nullptr
        head->prev = nullptr;
        
        // Merge the lists
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1->prev = tail;  // Set prev pointer
                tail = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2->prev = tail;  // Set prev pointer
                tail = head2;
                head2 = head2->next;
            }
        }
        
        // Attach remaining nodes
        if (head1) {
            tail->next = head1;
            head1->prev = tail;
        } else if (head2) {
            tail->next = head2;
            head2->prev = tail;
        }
        
        return head;
    }


public:
    Doubly() : head(nullptr), tail(nullptr) {}

    void insertAtBegining(int val) {
        Node *newNode = new Node(val);

        if(isEmpty()) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAfterVal(int val,int afterVal) {
        Node *temp = head;

        while(temp != nullptr && temp->data != afterVal) temp = temp->next;
        if(temp == nullptr) {
            cout<<"Value not found"<<endl;
            return;
        }
        Node *newNode = new Node(val);

        newNode->next = temp->next; 
        newNode->prev = temp;
        if(temp->next != nullptr) 
            temp->next->prev = newNode;
        else tail = newNode;
        temp->next = newNode;
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);

        if(isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deletion(int val) {
        if(head == nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node *temp = head;
        while(temp && temp->data != val) temp = temp->next;
        if(temp == nullptr) {
            cout<<"Value not found"<<endl;
            return;
        }
        if(temp == head && temp == tail) head = tail = nullptr;
        else if(temp == head) {
            head = temp->next;
            head->prev = nullptr;
        } else if(temp == tail) {
            tail = temp->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    bool search(int val) {
        Node *temp = head;
        while(temp->next != nullptr && temp->data != val) temp = temp->next;
        return ((temp->data == val) ? true : false);
    }

    int countNodes() {
        int count = 0;
        for(Node *i = head; i != nullptr; i = i->next) count++;
        return count;
    }

    void makeCircular() {
        if(isEmpty()) return;
        tail->next = head;
        head->prev = tail;
    }

    Node* reverseList() {
        Node *curr = head;
        Node *temp = nullptr;
        tail = head;
        while(curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if(temp != nullptr) head = temp->prev;
        return head;
    }

    // Q1 insert a value in sorted doubly linked list
    void sortList() {
        if(head == nullptr || head->next == nullptr) return;
        
        bool swapped;
        do {
            swapped = false;
            Node *temp = head;
            while(temp->next != nullptr) {
                if(temp->data > temp->next->data) {
                    int t = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = t;
                    swapped = true;
                }
                temp = temp->next;
            }

        } while(swapped);
    }
    void insertSort(int val) {
        sortList();
        Node *temp = head;
        while(temp != nullptr && temp->data < val) {
            temp = temp->next;
        }
        Node *newNode = new Node(val);
        if(temp == nullptr) {
            insertAtEnd(val);
        } else {
            newNode->next = temp;
            newNode->prev = temp->prev;
            if(temp != head) temp->prev->next = newNode;
            else head = newNode;
            temp->prev = newNode;
        }
    }

    // Q2 Delete all values of the key
    void deleteKey(int key) {
        Node *temp = head;
        while(temp != nullptr) {
            if(temp->data == key) {
                Node *del = temp;
                temp = temp->next;
                deletion(del->data);

            } else temp =  temp->next;
        }
    }

    // Q3 Find pairs with a given sum
    void findPairs(int key) {
        Node *temp1 = head;
        Node *temp2;
        int sum;
        while(temp1 != nullptr) {
            temp2 = tail;
            while(temp2 != temp1) {
                sum = temp1->data + temp2->data;
                if(sum == key) cout<<"("<<temp1->data<<","<<temp2->data<<")"<<", ";
                temp2 = temp2->prev;
            }
            temp1 = temp1->next;
        }
    }

    //  Q4 Rotate doubly linked list by n nodes
    Node* rotateDoublyList(Node *head, int n) {
        Node *temp = head;

        while(temp->next != nullptr) temp = temp->next;

        temp->next = head;
        head->prev = temp;

        for(int i = 0; i< n; i++) {
            head = head->next;
            temp = temp->next;
        }
        temp->next = nullptr;
        head->prev = nullptr;

        return head;
    }

    void rotateList(int n) {
        head = rotateDoublyList(head,n);
    }

    // Q5 Merge two sorted doubly linked list
    void mergeWith(Doubly &list2) {
        head = mergeLists(head,list2.head);
        list2.head = nullptr;
    }

    //  Q6 I think better to implement this in trees portion...

    //  Q7 Find triplets within the given sum in sorted doubly linked list
    void countTriplets(int x) {
        Node *temp1 = head;
        int sum = 0;
        while(temp1 != nullptr) {
                    Node *temp2  = temp1->next;
            while(temp2 != nullptr) {
                Node *temp3 = temp2->next;
                while(temp3 != nullptr) {
                    sum = temp1->data + temp2->data + temp3->data;
                    if(sum == x) cout<<"("<<temp1->data<<", "<<temp2->data<<", "<<temp3->data<<") ";
                    temp3 = temp3->next;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    } 
    // Q8  Reverse a doubly list in K groups

    // Q9 Split circular list into two halves
    void splitCircular(Node *head, Node **head1, Node **head2) {
        if(head == nullptr)return;
        Node *slow = head;
        Node *fast = head;

        while(fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next->next == head) fast = fast->next;

        *head1 = head;
        *head2 = slow->next;

        slow->next = *head1;
        (*head1)->prev = slow;

        fast->next = *head2;
        (*head2)->prev = fast;
    }

    void display() {
        for(Node *i = head; i !=nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }

    void displayMenu() {
        cout<<"===== DOUBLY LINKED LIST MENU ====="<<endl;
        cout<<"1. Insert a value in the beginning of the list"<<endl;
        cout<<"2. Insert a value after existing value in the list"<<endl;
        cout<<"3. Insert a value at the end of the list"<<endl;
        cout<<"4. Delete a value from the list"<<endl;
        cout<<"5. Search a value in the list"<<endl;
        cout<<"6. Count total values"<<endl;
        cout<<"7. Reverse a list"<<endl;
        cout<<"8. Make circular"<<endl;
        cout<<"9. Merge two sorted doubly linked list"<<endl;
        cout<<"10. Insert sort"<<endl;
        cout<<"11. Delete all values of given key"<<endl;
        cout<<"12. Find pairs within the given sum"<<endl;
        cout<<"13. Rotate doubly linked list by n nodes"<<endl;
        cout<<"14. Find triplets within the given sum"<<endl;
        cout<<"15. Reverse nodes in K groups"<<endl;
        cout<<"16. Split circular list into two halves"<<endl;
        cout<<"17. Display"<<endl;
        cout<<"0. Exit"<<endl;
    }
};
int main() {
    Doubly d1,d2;
    d1.insertAtEnd(1);
    d1.insertAtEnd(2);
    d1.insertAtEnd(4);
    d1.insertAtEnd(5);
    d1.insertAtEnd(6);
    d1.insertAtEnd(8);
    d1.insertAtEnd(9);
    d1.display();

    d1.countTriplets(17);

    return 0;
}