#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Tree{
private:
    Node *root;
    Node* insert(Node* root, int val) {
        if(root  == nullptr) return new Node(val);
        if(val < root->data) root->left = insert(root->left,val);
        else if(val > root->data) root->right = insert(root->right,val);
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if(root == nullptr) return root;
        if(key < root->data) root->left = deleteNode(root->left,key);
        if(key > root->data) root->right = deleteNode(root->right,key);
        else {
            if(root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = findMinimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);

        }
        return root;
    }

    Node* findMinimum(Node* root) {
        while(root != nullptr && root->left != nullptr) root = root->left;
        return root;
    }

    Node* findMaximum(Node* root) {
        while(root != nullptr && root->right != nullptr) root = root->right;
        return root;
    }

    void inOrder(Node* root) {
        if(root == nullptr) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void preOrder(Node* root) {
        if(root == nullptr) return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node* root) {
        if(root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
    bool search(Node* root, int val) {
        if(root == nullptr) return false;
        if(val == root->data) return true;
        if(val < root->data) return search(root->left,val);
        else return search(root->right, val);
    }

    int countNodes(Node* root) {
        if(root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

public:
    Tree() : root(nullptr) {}

    void insert(int val) {
        root = insert(root,val);
    }

    void deleteNode(int key) {
        root = deleteNode(root,key);
    }

    void displayInorder() {
        inOrder(root);
    }

    void displayPreOrder() {
        preOrder(root);
    }

    void displayPostOrder() {
        postOrder(root);
    }

    int findMin() {
        Node* temp = findMinimum(root);
        if(temp != nullptr) return temp->data;
        else return -1;
    }

    int findMax() {
        Node*temp = findMaximum(root);
        if(temp != nullptr) return temp->data;
        else return -1;
    }

    void SearchVal(int val) {
        if(search(root, val)) cout<<"value found in the tree"<<endl;
        else cout<<"Value not found"<<endl; 
    }
    void countNodes() {
        int count = countNodes(root);
        cout<<"Number of nodes are: "<<count<<endl;
    }

};
int main() {
    Tree t;
    t.insert(50);
    t.insert(40);
    t.insert(60);
    t.insert(35);
    t.insert(45);
    t.insert(55);
    t.insert(65);
    
    t.displayInorder();
    cout<<endl;
    t.displayPreOrder();
    cout<<endl;
    t.displayPostOrder();
    cout<<endl;

    cout<<"Minimum value is: "<<t.findMin();
    cout<<endl;

    cout<<"Maximum value is: "<<t.findMax();
    cout<<endl;

    t.SearchVal(35);
    cout<<endl;

    t.countNodes();
    return 0;
}
