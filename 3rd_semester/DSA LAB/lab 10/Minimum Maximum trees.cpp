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

    int findMinimum(Node* root) {
        while(root != nullptr && root->left != nullptr) root = root->left;

        return root->data;
    }

    int findMaximum(Node* root) {
        while(root != nullptr && root->right != nullptr) root = root->right;

        return root->data;
    }
public:
    Tree() : root(nullptr) {}
    void insert(int val) {
        root = insertRec(root,val);
    }

    void display() {
        inOrder(root);
        cout<<endl;
    }

    void getMinimum() { cout<<findMinimum(root)<<endl;}
    void getMaximum() { cout<<findMaximum(root)<<endl;}
};
int main() {
    Tree t1;

    t1.insert(50);
    t1.insert(60);
    t1.insert(30);
    t1.insert(55);
    t1.insert(35);
    t1.insert(10);
    t1.insert(65);

    t1.display();

    t1.getMinimum();
    t1.getMaximum();


    // cout<<"Maximum Value is: "<<t1.getMaximum()<<endl;
    
    return 0;
}