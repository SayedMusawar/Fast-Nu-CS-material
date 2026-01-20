#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val = 0 ) : data(val), left(nullptr), right(nullptr) {}
};
class BinaryTree{
private:
    Node *root;
    void preOrderTraversal(Node *root) {
        if(root == nullptr) return;
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void postOrderTraversal(Node *root) {
        if(root == nullptr) return;
        
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
    void InOrderTraversal(Node *root) {
        if(root == nullptr) return;
        InOrderTraversal(root->left);
        cout<<root->data<<" ";
        InOrderTraversal(root->right);
    }
    
    Node* findMin(Node* root) {
        while(root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
    
    Node* deleteNode(Node* root, int val) {
        if(root == nullptr) return root;
        
        // Search for the node to delete
        if(val < root->data) {
            root->left = deleteNode(root->left, val);
        }
        else if(val > root->data) {
            root->right = deleteNode(root->right, val);
        }
        else {
            // Node found - three cases:
            
            // Case 1: Node with no children (leaf node)
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            
            // Case 2: Node with one child
            else if(root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            
            // Case 3: Node with two children
            else {
                // Find inorder successor (smallest in right subtree)
                Node* temp = findMin(root->right);
                // Copy the inorder successor's data to this node
                root->data = temp->data;
                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->data);
            }
        }
        return root;
    }
    
public:
    BinaryTree() : root(nullptr) {}
    void Insertion(int val) {
        root = Insertion(root,val);
    }
    Node* Insertion(Node* root,int val) {
        if(root == nullptr) return new Node(val);
        if(val < root->data) root->left = Insertion(root->left,val);
        else if(val > root->data) root->right = Insertion(root->right,val);
        return root;
    }
    
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }
    
    
    void display() {
        cout<<"1. Inorder traversal"<<endl;
        cout<<"2. Pre-Order traversal"<<endl;
        cout<<"3. Post-Order traversal"<<endl;
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                InOrderTraversal(root);
            break;
            case 2:
                preOrderTraversal(root);
            break;
            case 3:
                postOrderTraversal(root);
            break;
            default:
                cout<<"invalid"<<endl;
            break;

        }
    }
};
int main() {
    BinaryTree t;
    t.Insertion(50);
    t.Insertion(40);
    t.Insertion(545);
    t.Insertion(14);
    t.Insertion(67);
    t.Insertion(37);
    t.Insertion(58);
    t.Insertion(100);
    t.Insertion(234);
    t.Insertion(643);
    t.Insertion(112);
    t.Insertion(522);

    t.display();
    return 0;
}