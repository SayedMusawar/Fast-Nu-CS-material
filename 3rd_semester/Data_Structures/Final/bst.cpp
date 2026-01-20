#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class Tree{
private:
    Node *root;

    Node *insertion(Node *root,int val) {
        if(root == nullptr) return new Node(val);
        if(val < root->data) root->left = insertion(root->left,val);
        else if(val > root->data) root->right = insertion(root->right,val);
        return root;
    }

    Node *findMin(Node *node) {
        while(node != nullptr && node->left != nullptr) node = node->left;
        return node;
    }
    
    Node *findMax(Node *node) {
        while(node != nullptr && node->right != nullptr) node = node->right;
        return node;
    }

    Node *deletion(Node *node,int val) {
        if(node == nullptr) return nullptr;
        if(val < node->data) node->left = deletion(node->left,val);
        else if(val > node->data) node->right = deletion(node->right,val);
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
        return node;
    }

    void inOrder(Node *root) {
        if(root == nullptr) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void preOrder(Node *root) {
        if(root == nullptr) return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node *root) {
        if(root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    int countNodes(Node *node) {
        if(node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
    int maxHeight(Node *node) {
        if(node == nullptr) return 0;
        int leftHeight = maxHeight(node->left);
        int rightHeight = maxHeight(node->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
    int countLeafNodes(Node *node) {
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }
    int countNonLeaf(Node *node) {
        if(node == nullptr || (node->left == nullptr && node->right == nullptr)) return 0;
        return 1 + countNonLeaf(node->left) + countNonLeaf(node->right);
    }

public:
    Tree() : root(nullptr) {}


    void levelOrderTraversal() {
        queue <Node *> q;
        q.push(root);
        while(!q.empty()) {
            Node *temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
    }


    void insertion(int val) {
        root = insertion(root,val);
    }

    void deletion(int val) {
        root = deletion(root,val);
    }

    void countLeafNodes() {
        int leafNodes = countLeafNodes(root);
        cout<<"Leaf nodes are: "<<leafNodes<<endl;
    }

    void countNonLeaf() {
        int nonLeafNodes = countNonLeaf(root);
        cout<<"Non leaf nodes are: "<<nonLeafNodes<<endl;
    }


    void display() {
        inOrder(root);
    }
};
int main() {
    Tree t;
    t.insertion(50);
    t.insertion(40);
    t.insertion(30);
    t.insertion(45);
    t.insertion(65);

    t.display();

    t.countLeafNodes();

    t.countNonLeaf();

    t.levelOrderTraversal();
    return 0;
}