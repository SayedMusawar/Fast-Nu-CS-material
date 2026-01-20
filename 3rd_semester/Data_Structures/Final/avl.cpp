#include<iostream>
using namespace std;
class Node{
public:
    int data, height;
    Node *left;
    Node *right;
    Node(int val) : data(val), height(0), left(nullptr), right(nullptr) {}
};
class avl{
private:
    Node *root;

    int getHeight(Node *node) {
        return (node == nullptr ? -1 : node->height);
    }

    void updateHeight(Node *node) {
        if(node == nullptr) return;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

    int getBalance(Node *node) {
        return (getHeight(node->left) - getHeight(node->right));
    }

    Node* rotateRight(Node *unbalancedNode) {
        Node *ebr = unbalancedNode->left;
        Node *rst = ebr->right;

        ebr->right = unbalancedNode;
        unbalancedNode->left = rst;

        updateHeight(unbalancedNode);
        updateHeight(ebr);

        return ebr;
    }

    Node* rotateLeft(Node *unbalancedNode) {
        Node *ebr = unbalancedNode->right;
        Node *lst = ebr->left;

        ebr->left = unbalancedNode;
        unbalancedNode->right = lst;

        updateHeight(unbalancedNode);
        updateHeight(ebr);

        return ebr;
    }

    Node* balanceNode(Node *unbalancedNode) {
        updateHeight(unbalancedNode);
        int balance = getBalance(unbalancedNode);

        // LL case
        if(balance > 1 && getBalance(unbalancedNode->left) >= 0) return rotateRight(unbalancedNode);
        // LR
        if(balance > 1 && getBalance(unbalancedNode->left) < 0) {
            unbalancedNode->left = rotateLeft(unbalancedNode->left);
            return rotateRight(unbalancedNode);
        }
        // RR
        if(balance < -1 && getBalance(unbalancedNode->right) <= 0) return rotateLeft(unbalancedNode);

        // RL
        if(balance < -1 && getBalance(unbalancedNode->right) > 0) {
            unbalancedNode->right = rotateRight(unbalancedNode->right);
            return rotateLeft(unbalancedNode);
        }

        return unbalancedNode;
    }

    Node* insertion(Node *node,int key) {
        if(node == nullptr) return new Node(key);
        if(key < node->data) node->left = insertion(node->left,key);
        else if(key > node->data) node->right = insertion(node->right,key);

        updateHeight(node);
        node = balanceNode(node);

        return node;
    }

    Node* deletion(Node *node,int key) {
        if(node == nullptr) return nullptr;
        if(key < node->data) node->left = deletion(node->left,key);
        else if(key > node->data) node->right = deletion(node->right,key);
        else {
            if(node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if(node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deletion(node->right,temp->data);
        }
            node = balanceNode(node);
            return node;
    }

    Node* findMin(Node *node) {
        while(node != nullptr && node->left != nullptr) node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        while(node != nullptr && node->right != nullptr) node = node->right;
        return node;
    }
public:
    avl() : root(nullptr) {}

    void insertion(int val) {
        root = insertion(root,val);
    }
};
int main() {

    return 0;
}