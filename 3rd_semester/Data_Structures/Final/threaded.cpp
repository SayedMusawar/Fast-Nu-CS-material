#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left, *right;
    bool isThread;
    Node(int val) : data(val), left(nullptr), right(nullptr), isThread(false) {}
};
class ThreadedTree{
private:
    Node *root;
    Node* insert(Node* root,int val) {
        Node *parent = nullptr;
        Node *curr  = root;

        while(curr != nullptr) {
            parent = curr;

            if(val < curr->data) curr = curr->left;
            else if(val > curr->data) {
                if(curr->isThread == false) curr = curr->right;
                else break;
            } else {
                cout<<"Duplicate values not allowed"<<endl;
                return root;
            }
        }

        Node *newNode = new Node(val);

        if(parent == nullptr) {
            root = newNode;
            return root;
        }
        
        if(val < parent->data) {
            parent->left = newNode;
            newNode->right = parent;
            newNode->isThread = true;
        } else {
            newNode->right = parent->right;
            newNode->isThread = parent->isThread;
            parent->right = newNode;
            parent->isThread = false;
        }
        return root;
    }
    Node *LeftMost(Node *node) {
        if(node == nullptr) return nullptr;

        while(node->left != nullptr) node = node->left;

        return node;
    }

    void inOrderTraversal(Node *node) {
        Node *curr = LeftMost(node);

        while(curr != nullptr) {

            cout<<curr->data<<" ";
            if(curr->isThread) curr = curr->right;
            else curr = LeftMost(curr->right);
        }
    }
public:
    ThreadedTree() : root(nullptr) {}

    void insertion(int val) {
        root = insert(root,val);
    }
    void display() {
        inOrderTraversal(root);
    }
};
int main() {
    ThreadedTree t;
    t.insertion(50);
    t.insertion(30);
    t.insertion(70);
    t.insertion(20);
    t.insertion(40);
    t.insertion(60);
    t.insertion(80);

    t.display();
    return 0;
}