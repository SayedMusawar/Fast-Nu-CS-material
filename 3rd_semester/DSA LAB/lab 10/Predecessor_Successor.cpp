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

    Node* search(Node*root, int target) {
        if(root == nullptr || root->data == target) return root;
        if(target < root->data) return search(root->left, target);
        else if(target > root->data) return search(root->right,target);
    }

    Node* findPredecessor(int target) {
        Node *pred = nullptr;
        Node *curr = root;

        while(curr != nullptr) {
            if(target > curr->data) {
                pred = curr;
                curr = curr->right;
            } else curr = curr->left;
        }
        return pred;
    }

    Node* findSuccessor(int target) {
        Node *curr = root;
        Node* successor  = nullptr;

        while(curr != nullptr) {
            if(target < curr->data) {
                successor = curr;
                curr = curr->left;
            } else curr = curr->right;
        }
        return successor;
    }
public:
    Tree() : root(nullptr) {}
    void insert(int val) {
        root = insertRec(root,val);
    }

    void findPred_Succ(int target) {
        Node *pred = findPredecessor(target);
        if(!pred) cout<<"Predecessor not found"<<endl;
        else cout<<"predecessor = "<<pred->data<<endl;
        
        
        Node *suc = findSuccessor(target);
        if(!suc) cout<<"Successor not found"<<endl;
        else cout<<"Successor = "<<suc->data<<endl;
    }
    

    void display() {
        inOrder(root);
        cout<<endl;
    }

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
    t1.findPred_Succ(50);

    
    return 0;
}