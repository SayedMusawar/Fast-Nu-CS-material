#include <iostream>
using namespace std;

// -----------------------------
// Node structure
// -----------------------------
struct Node {
    int data;
    Node* left;
    Node* right;
    bool rightThread;   // true → right pointer is a thread

    Node(int val) {
        data = val;
        left = right = NULL;
        rightThread = false;
    }
};

// -----------------------------
// Insert into Threaded Binary Tree
// -----------------------------
Node* insert(Node* root, int key) {
    Node* parent = NULL;
    Node* current = root;

    // Find the position to insert
    while (current != NULL) {
        parent = current;

        if (key < current->data) {
            current = current->left;
        }
        else if (key > current->data) {
            if (!current->rightThread)
                current = current->right;
            else
                break;
        }
        else {
            // Duplicate keys not allowed
            cout << "Duplicate key: " << key << endl;
            return root;
        }
    }

    // Create new node
    Node* newNode = new Node(key);

    // If tree was empty
    if (parent == NULL) {
        root = newNode;
        return root;
    }

    // Insert as left child
    if (key < parent->data) {
        parent->left = newNode;
        newNode->right = parent;   // thread to inorder successor
        newNode->rightThread = true;
    }
    // Insert as right child
    else {
        newNode->right = parent->right;       // copy parent’s thread
        newNode->rightThread = parent->rightThread;

        parent->right = newNode;
        parent->rightThread = false;          // now right is a real child
    }

    return root;
}

// -----------------------------
// Find the leftmost node
// -----------------------------
Node* leftMost(Node* node) {
    if (node == NULL) return NULL;

    while (node->left != NULL)
        node = node->left;

    return node;
}

// -----------------------------
// Inorder Traversal (using threads)
// -----------------------------
void inorder(Node* root) {
    Node* current = leftMost(root);

    while (current != NULL) {
        cout << current->data << " ";

        // If this node is threaded, follow the thread
        if (current->rightThread)
            current = current->right;
        else
            current = leftMost(current->right);
    }
}

// -----------------------------
// Main function
// -----------------------------
int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal (Threaded): ";
    inorder(root);

    return 0;
}
