#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        
        return node;
    }
    
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    Node* deleteNode(Node* node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (data < node->data) {
            node->left = deleteNode(node->left, data);
        } else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }
    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    
    void deletePrimes(Node*& node) {
        if (node == nullptr) return;
        
        deletePrimes(node->left);
        deletePrimes(node->right);
        
        if (isPrime(node->data)) {
            node = deleteNode(node, node->data);
        }
    }
    
public:
    BST() : root(nullptr) {}
    
    void insert(int data) {
        root = insert(root, data);
    }
    
    void deletePrimeNumbers() {
        deletePrimes(root);
    }
    
    void displayInorder() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int values[] = {10, 7, 13, 6, 9, 28, 29, 31};
    
    for (int val : values) tree.insert(val);
    tree.displayInorder();
    
    tree.deletePrimeNumbers();
    tree.displayInorder();
    
    return 0;
}