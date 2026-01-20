#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *right;
    Node *left;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Tree{
private:
    Node *root;
    
    Node* insertion(Node *node, int val) {
        if(node == nullptr) return new Node(val);

        if(val < node->data) node->left = insertion(node->left,val);
        else if(val > node->data) node->right = insertion(node->right,val);

        return node;
    }
    
    Node* deletion(Node *root,int val) {
        if(root == nullptr) return root;
        if(val < root->data) root->left = deletion(root->left,val);
        else if(val > root->data) root->right = deletion(root->right, val);
        else {
            if(root->left == nullptr) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
                Node* temp = findMinimum(root->right);
                root->data = temp->data;
                root->right = deletion(root->right,temp->data);
        }
        return root;
    }

    int findHeight(Node* root) {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return 1 + ((leftHeight > rightHeight)? leftHeight : rightHeight);
    }

    bool search(Node* root,int key) {
        if(root == nullptr) return false;
        if(key == root->data) return true
        if(key < root->data) return search(root->left,key);
        if(key > root->data) return search(root->right, key);
    }


    Node* findMinimum(Node *node) {
        while(node != nullptr && node->left != nullptr) node = node->left;

        return node;
    }

    Node* findMaximum(Node *node) {
        while(node != nullptr && node->right != nullptr) node = node->right;

        return node;
    }
                
    int countNodes(Node* root) {
        if(root == nullptr) return 0;

        return 1 + findHeight(root->left) + findHeight(root->right);
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

public:
    Tree() : root(nullptr) {}

    void insertion(int val) {
        root = insertion(root,val);
    }

    void deletion(int val) {
        root = deletion(root, val);
    }

    // void display() {
    //     cout<<"1. Pre-Order Traversal"<<endl;
    //     cout<<"2. In-Order Traversal"<<endl;
    //     cout<<"3. Post-Order Traversal"<<endl;
    //     int choice; cin >> choice;
    //     switch(choice) {
    //         case 1:
    //             preOrder(root);
    //         break;
    //         case 2:
    //             inOrder(root);
    //         break;
    //         case 3:
    //             postOrder(root);
    //         break;
    //         default:
    //             cout<<"Invalid choice, Can't displayed values"<<endl;
    //             return;
    //     }

    //     cout<<endl;
    // }

    void display() {
        inOrder(root);
        cout<<endl;
    }
};
int main() {
    Tree bst;
    bst.insertion(50);
    bst.insertion(25);
    bst.insertion(75);
    bst.insertion(20);
    bst.insertion(30);
    bst.insertion(60);
    bst.insertion(80);
    bst.insertion(35);

    bst.display();


    bst.deletion(30);
    bst.display();


    bst.deletion(75);
    bst.display();

    return 0;
}