#include<iostream>
#include<conio.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val = 0) : data(val), next(nullptr) {}
};
class SinglyList{
private:
    Node *head;

    bool isEmpty() {
        return !head ? true:false;
    }

    void insertAtBeginning(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAfterVal(int val,int afterVal) {
        Node *temp = head;
        while(temp->next != nullptr && temp->data != afterVal) temp = temp->next;

        if(temp == nullptr) {
            cout<<"Value not found!!... Unable to insert the value"<<endl;
            return;
        }
        Node *newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtEnd(int val) {
        Node *newNode = new Node(val);
        Node *temp = head;
        if(isEmpty()) {
            newNode->next = head;
            head = newNode;
            return;
        }
        while(temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    void deletion(int val) {
        Node *temp = head;
        Node *prev = nullptr;
        while(temp->next != nullptr && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == nullptr) {
            cout<<"Value doesn't found. Unable to delete it"<<endl;
            return;
        }
        if(temp == head) head = head->next;
        else prev->next = temp->next;
        delete temp;
    }

    bool search(int val) {
        Node *temp = head;
        while(temp->next != nullptr && temp->data != val) temp = temp->next;
        return ((temp->data == val) ? true : false);
    }

    // 1. Reverse a linked list
    Node* reverseList(Node* head) {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // 2. Merge with sorted list
    Node* mergeLists(Node* head1, Node* head2) {
        if(!head1) return head2;
        if(!head2) return head1;

        Node *head = nullptr;
        Node *tail = nullptr;
        if(head1->data <= head2->data) {
            head = tail = head1;
            head1 = head1->next;
        } else {
            head = tail = head2;
            head2 = head2->next;
        }

        while(head1 != nullptr && head2 != nullptr) {
            if(head1->data <= head2->data) {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
        tail->next = (head1 ? head1 : head2);
        return head;
    }
    // 4. Remove nth node from the end
    void removeNthNode(int n) {
        Node *temp = head;
        int nodes = countNodes();
        int del = (nodes - n) + 1;
        int count = 1;
        while(count != del) {
            count++;
            temp = temp->next;
        }
        deletion(temp->data);
    }

    // 5. Cycle detection
    bool hasCycle(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) return true;
        }
        return false;
    }

    //  Q6 add two numbers
    Node* addTwoNum(Node* head1, Node* head2) {
        Node *temp = new Node();
        Node *curr= temp;
        int carry = 0;

        while(head1 != nullptr || head2 != nullptr || carry != 0) {
            int sum = carry;

            if(head1 != nullptr) {
                sum += head1->data;
                head1 = head1->next;
            }
            if(head2 != nullptr) {
                sum += head2->data;
                head2 = head2->next;
            }
            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }
        return temp->next;
    }

    // Q9 reverse in k groups
    Node* reverseInKGroups(Node* head,int k) {
        Node *curr = head;
        int count = 0;
        while(count < k) {
            if(curr == nullptr) return head;
            curr = curr->next;
            count++;
        }

        Node* prev = reverseInKGroups(curr,k);

        curr = head;
        count = 0;
        while(count < k) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        return prev;
    }
public:
    SinglyList() : head(nullptr) {}

    void insertAtBeginning() {
        cout<<"Enter the value you want to insert"<<endl;
        int val;
        cin >> val;
        insertAtBeginning(val);
    }

    void insertAtEnd() {
        cout<<"Enter the value you want to add in the list"<<endl;
        int val; cin >> val;
        insertAtEnd(val);
    }


    void insertAfterVal() {
        int afterVal;
        cout<<"Enter the value after which you want to add the value"<<endl;
        cin >> afterVal;
        int val;
        cout<<"Enter the value which you want to add in the list"<<endl;
        cin >> val;
        insertAfterVal(val,afterVal);
    }

    void deletion() {
        cout<<"Enter the value to delete it from the list"<<endl;
        int val; cin >> val;
        deletion(val);
    }

    void search() {
        cout<<"Enter the value to search it"<<endl;
        int val; cin >> val;
        if(search(val)) cout<<"value found"<<endl;
        else cout<<"Value not found"<<endl;
    }

    int countNodes() {
        int count = 0;
        for(Node *i = head; i != nullptr; i = i->next) count++;
        return count;
    }

    // 1. reverse a linked list
    void reverseList() {
        head = reverseList(head);
        cout<<"Reversed successfully"<<endl;
    }

    // 2 Merge with sorted list
    void mergeWith(SinglyList &list2) {
        head = mergeLists(head,list2.head);
        list2.head = nullptr;
    }

    // 3. Middle of the linked list
    void findMiddleElement() {
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<"middle element of the list is: "<<slow->data<<endl;
    }
    //  4. remove nth node
    void removeNthNode() {
        cout<<"provide me the number of node which you want to delete from the end"<<endl;
        int n; cin >> n;
        removeNthNode(n);
    }
    //  5. cycle detection
    void checkCycle() {
        if(hasCycle(head)) cout<<"Cycle exist"<<endl;
        else cout<<"no cycle exist"<<endl;
    }

    //  Q6 Add two numbers
    void addTwoNumbers(SinglyList &list2) {
        head = addTwoNum(head,list2.head);
        list2.head = nullptr;
    }

    // Q7Reorder list
    void reorder() {
        reOrderList(head);
    }
    void reOrderList(Node *head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

        Node* temp = head;
        while(temp->next->next != nullptr) temp = temp->next;
        temp->next->next = head->next;
        head->next = temp->next;
        temp->next = nullptr;
        reOrderList(head->next->next);
    }

    // Q8 Remove duplicates from a sorted linked list
    void removeDuplicates() {
        Node *temp = head;
        while(temp->next != nullptr) {
            if(temp->data > temp->next->data) {
                cout<<"List is not sorted"<<endl;
                return;
            }
            else if(temp->data == temp->next->data) {
                Node *del = temp;
                temp = temp->next;
                deletion(temp->data);
            } else temp = temp->next;
        }
        
    }

    // Q9 reverse list in K groups
    void reverseNodesK(int k) {
        head = reverseInKGroups(head,k);
    }

    void display() {
        for(Node *i = head; i != nullptr; i = i->next) cout<<i->data<<" ";
        cout<<endl;
    }

};
void displayMenu() {
    cout<<"===== SINGLY LINKED LIST MENU ====="<<endl;
    cout<<"1. Insert a value in the beginning of the list"<<endl;
    cout<<"2. Insert a value after existing value in the list"<<endl;
    cout<<"3. Insert a value at the end of the list"<<endl;
    cout<<"4. Delete a value from the list"<<endl;
    cout<<"5. Search a value in the list"<<endl;
    cout<<"6. Count total values"<<endl;
    cout<<"7. Reverse a list"<<endl;
    cout<<"8. Merge two lists"<<endl;
    cout<<"9. Find Middle element from a list"<<endl;
    cout<<"10. Remove nth node from the end of the list"<<endl;
    cout<<"11. Cycle detection"<<endl;
    cout<<"12. Add two numbers and return the sum as linked list"<<endl;
    cout<<"13. Reorder the linked list"<<endl;
    cout<<"14. Remove duplicates from the sorted list"<<endl;
    cout<<"15. Reverse nodes in K groups"<<endl;
    cout<<"16. Display"<<endl;
    cout<<"0. Exit"<<endl;
}
int main() {
    SinglyList List1, List2;

    int choice, selectList;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 0:
                cout<<"Exited"<<endl;
                return 0;
            break;
            case 1:
                cout<<"1. Insertion in list 1"<<endl;
                cout<<"2. Insertion in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.insertAtBeginning();
                        cout<<"Value inserted successfully"<<endl;
                    break;
                    case 2:
                        List2.insertAtBeginning();
                        cout<<"value inserted successfully"<<endl;
                    break;
                    default:
                        cout<<"Invalid option selected!! Can't inserted the value"<<endl;
                    break;
                }
            break;

            case 2:
                cout<<"1. Insertion in list 1"<<endl;
                cout<<"2. Insertion in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.insertAfterVal();
                        cout<<"Value inserted successfully"<<endl;
                    break;
                    case 2:
                        List2.insertAfterVal();
                        cout<<"value inserted successfully"<<endl;
                    break;
                    default:
                        cout<<"Invalid option selected!! Can't inserted the value"<<endl;
                    break;
                }
            break;

            case 3:
                cout<<"1. Insertion in list 1"<<endl;
                cout<<"2. Insertion in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.insertAtEnd();
                        cout<<"Value inserted successfully"<<endl;
                    break;
                    case 2:
                        List2.insertAtEnd();
                        cout<<"value inserted successfully"<<endl;
                    break;
                    default:
                        cout<<"Invalid option selected!! Can't inserted the value"<<endl;
                    break;
                }
            break;

            case 4:
                cout<<"1. Deletion in list 1"<<endl;
                cout<<"2. Deletion in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.deletion();
                        cout<<"Value deleted successfully"<<endl;
                    break;
                    case 2:
                        List2.deletion();
                        cout<<"value deleted successfully"<<endl;
                    break;
                    default:
                        cout<<"Invalid option selected!! Can't deleted the value"<<endl;
                    break;
                }
            break;

            case 5:
                cout<<"1. Search in list 1"<<endl;
                cout<<"2. Search in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.search();
                    break;
                    case 2:
                        List2.search();
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;

            case 6:
                cout<<"1. Count number of values in list 1"<<endl;
                cout<<"2. Count number of values in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        cout<<"Total nodes are: "<<List1.countNodes();
                    break;
                    case 2:
                        cout<<"Total nodes are: "<<List2.countNodes();
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;

            case 7:
                cout<<"1. Reverse values in list 1"<<endl;
                cout<<"2. Reverse values in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.reverseList();
                    break;
                    case 2:
                        List2.reverseList();
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;

            case 8:
                List1.mergeWith(List2);
                cout<<"Listed merged in ascending order"<<endl;
            break;

            case 9:
                cout<<"1. Find middle value in list 1"<<endl;
                cout<<"2. Find middle value in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.findMiddleElement();
                    break;
                    case 2:
                        List2.findMiddleElement();
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;

            case 10:
                cout<<"1. Remove nth node from the end in list 1"<<endl;
                cout<<"2. Remove nth node from the end in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.removeNthNode();
                    break;
                    case 2:
                        List2.removeNthNode();
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;

            case 11:
                cout<<"1. Detect if there is cycle in list 1"<<endl;
                cout<<"2. Detect if there is cycle in list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.checkCycle();
                    break;
                    case 2:
                        List2.checkCycle();
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;
            case 12:
                List1.addTwoNumbers(List2);
                cout<<"List now contains sum of numbers"<<endl;
            break;

            case 13:
                cout<<"1. Reorder list 1"<<endl;
                cout<<"2. Reorder list 2"<<endl;
                cin >> selectList;
                switch(selectList) {
                    case 1:
                        List1.reorder();
                        cout<<"list reordered successfully"<<endl;
                    break;
                    case 2:
                        List2.reorder();
                        cout<<"list reordered successfully"<<endl;
                    break;
                }
            break;

            case 14:
                cout<<"1. Remove Duplicates from list 1"<<endl;
                cout<<"2. Remove Duplicates from list 2"<<endl;
                cin >> selectList;
                switch(selectList) {
                    case 1:
                        List1.removeDuplicates();
                        cout<<"Duplicates removed successfully"<<endl;
                    break;
                    case 2:
                        List2.removeDuplicates();
                        cout<<"Duplicates removed successfully"<<endl;
                    break;
                    default:
                        cout<<"Invalid option selected!! Can't remove duplicates"<<endl;
                    break;
                }
            break;

            case 15:
                cout<<"1. List 1"<<endl;
                cout<<"2. List 2"<<endl;
                cin >> selectList;
                cout<<"Enter the value of k"<<endl;
                int k; cin >> k;
                switch (selectList) {
                    case 1:
                        List1.reverseNodesK(k);
                    break;
                    case 2:
                        List2.reverseNodesK(k);
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;
            case 16:
                cout<<"1. Display list 1"<<endl;
                cout<<"2. Display list 2"<<endl;
                cin >> selectList;
                switch (selectList) {
                    case 1:
                        List1.display();
                    break;
                    case 2:
                        List2.display();
                    break;
                    default:
                        cout<<"Invalid option selected!!"<<endl;
                    break;
                }
            break;

            default:
                cout<<"Invalid choice"<<endl;
            break;
        }
        if(choice) {
            cout<<"\n press any key to continue";
            _getch();
            system("cls");
        }
    } while(choice);
    return 0;
}