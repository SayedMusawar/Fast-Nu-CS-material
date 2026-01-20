#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left, *right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};
class Tree{
private:
    Node *root;
    Node* insertRec(Node *root,int val) {
        if(root == nullptr) return new Node(val);
        if(val < root->data) root->left = insertRec(root->left, val);

        else if(val > root->data) root->right = insertRec(root->right,val);

        return root;
    }

    void inOrder(Node* root) {
        if(root == nullptr) return;

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
public:
    Tree() : root(nullptr) {}
    void insert(int val) {
        root = insertRec(root,val);
    }

    void insertAfterVal(int val, int newVal) {
        Node* curr = root;
        while(curr != nullptr) {
            if(curr->data == val) {
                Node* newNode = new Node(newVal);
                if(curr->right == nullptr) {
                    curr->right = newNode;
                } else {
                    newNode->right = curr->right;
                    curr->right = newNode;
                }
                return;
            } else if(val < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        cout<<"Value "<<val<<" not found in the tree."<<endl;
    }
    
    void display() {
        inOrder(root);
        cout<<endl;
    }

};
int main() {
    Tree t1;

    t1.insert(10);
    t1.insert(5);
    t1.insert(15);
    t1.insert(3);
    t1.insert(7);
    t1.insert(12);
    // t1.insert(18);
    // t1.insert(17);
    // t1.insert(20);

    t1.insertAfterVal(5, 8);

    t1.display();
    return 0;
}