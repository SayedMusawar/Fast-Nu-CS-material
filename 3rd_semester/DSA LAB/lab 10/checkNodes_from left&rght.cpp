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
    int countNodes(Node* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
public:
    Tree() : root(nullptr) {}
    void insert(int val) {
        root = insertRec(root,val);
    }
    
    void checkBalance() {
        if(root == nullptr) {
            cout<<"Tree is empty."<<endl;
            return;
        }

        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);

        if(leftCount > rightCount) cout<<"The tree has more nodes on the left side."<<endl;
        else if(rightCount > leftCount) cout<<"The tree has more nodes on the right side."<<endl;

        else cout<<"The tree has equal nodes on both sides."<<endl;
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

    t1.display();

    t1.checkBalance();
    return 0;
}