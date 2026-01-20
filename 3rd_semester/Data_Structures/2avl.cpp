#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int height;
    Node *left , *right;

    Node(int val) : data(val), height(0), left(NULL), right(NULL){} 
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

    Node *rotateleft(Node *unbalanced){
        Node *elevate = unbalanced->right;
        Node *left = elevate->left;

        elevate->left = unbalanced;
        unbalanced->right = left;

        updateHeight(unbalanced);
        updateHeight(elevate);

        return elevate;
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
    Node *balance(Node *node){

        updateHeight(node);
        int bf = getBalance(node);

        // LL case
        if (bf > 1 && getBalance(node->left) >= 0)
        {
            return rotateRight(node);
        }
        // LR case
        if (bf > 1 && getBalance(node->left) < 0)
        {
            node->left = rotateleft(node->left);
            return rotateRight(node);
        }
        // RR case
        if (bf < -1 && getBalance(node->right) <= 0)
        {
            return rotateleft(node);
        }
        //Rl case
        if (bf < -1 && getBalance(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateleft(node);
        }
        return node;
    }
    Node *findMin(Node *root){
        while (root && root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    Node *findMax(Node *root){
        while (root && root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }

    Node *insertNode(Node *root, int key){
        if (root == NULL)
        {
            return new Node(key);
        }
        if (key > root->data )
        {
            root->right = insertNode(root->right , key);
        }
        else if (key < root->data)
        {
            root->left = insertNode(root->left, key);
        }
        return balance(root);
    }
    Node *deleteNode(Node *node, int key){
        if (node == NULL)
        {
            return node;
        }
        if (key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else{
            if (node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return balance(node);
    }
    public:
    AVL() :root(NULL) {}
    void insert(int val){
        root = insertNode(root, val);
    }
    void deleteNode(int val){
        root = deleteNode(root, val);
    }

};

int main(){
    AVL tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(40);

    tree.deleteNode(10);

}