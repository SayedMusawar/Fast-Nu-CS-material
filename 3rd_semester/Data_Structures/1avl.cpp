#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int height;
    Node *left , *right;

    Node(int val) : data(val), height(0), left(NULL), right (NULL){};
};

class AVL{
    private:
    Node *root;

    int height(Node *node){
        if (node == NULL)
        {
            return -1;
        }
        return node->height;
    }
    void updateHeight(Node *node){
        int leftH = height(node->left);
        int rightH = height(node->right);

        if (leftH > rightH)
        {
            node->height = 1 + leftH;
        }
        else
            node->height = 1 + rightH;
    }

    int getBalance(Node *node){
        if (node == NULL)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node *rotateRight(Node *unbalanced){

        Node *elevate = unbalanced->left;
        Node *right = elevate->right;

        elevate->right = unbalanced;
        unbalanced->left = right;

        updateHeight(unbalanced);
        updateHeight(elevate);
        return elevate;
    }
    
    Node *rotateLeft(Node *unbalanced){

        Node *elevate = unbalanced->right;
        Node *left = elevate->left;

        elevate->left = unbalanced;
        unbalanced->right = left;

        updateHeight(unbalanced);
        updateHeight(elevate);
        return elevate;
    }

    Node *balance(Node *node){

        updateHeight(node);
        int bf = getBalance(node);;
        //LL Case
        if (bf > 1 && getBalance(node->left) >= 0)
        {
            return rotateRight(node);
        }
        // LR Case
        if (bf > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        // RR Case
        if (bf < -1 && getBalance(node->right) <= 0)
        {
            return rotateLeft(node);
        }
        // RL Case
        if (bf < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node *insertNode(Node *root,int key){
        if (root == NULL)
        {
            return new Node(key);
        }
        if (key < root->data)
        {
            root->left = insertNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insertNode(root->right, key);
        }
        
        return balance(root);
    }

    public:

    void insert(int val){
        root = insertNode(root, val);
    }
};

int main(){

    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    cout << "Tree is balanced insertion done in tree " << endl;
    
}