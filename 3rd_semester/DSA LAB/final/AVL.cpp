#include<iostream>
using namespace std;
class Node{
public:
    int data,height;
    Node *right;
    Node *left;
    Node(int val) : data(val),height(0), left(nullptr), right(nullptr) {}
};

// updateHeight
//  Get height
// get balance factor
//  rotations
// Balancing the tree
class AVL{
private:
    Node *root;
    int getHeight(Node *root) {
        return (root != nullptr)? root->height: -1;
    }

    int getBalance(Node *root) {
        if(root == nullptr) return 0;
        return ((root != nullptr) ? getHeight(root->left) - getHeight(root->right): 0);
    }

    void updateHeight(Node* root) {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        root->height =  1 + ((leftHeight > rightHeight)? leftHeight : rightHeight);
    }

    Node* leftRotate(Node *ubn) {
        Node *ebr = ubn->right;
        Node *lst = ebr->left;

        ebr->left = ubn;
        ubn->right = lst;

        updateHeight(ubn);
        updateHeight(ebr);
        return ebr;
    }

    Node* rightRotate(Node *ubn) {
        Node *ebr = ubn->left;
        Node *rst = ebr->right;

        ebr->right = ubn;
        ubn->left = rst;

        updateHeight(ubn);
        updateHeight(ebr);

        return ebr;
    }

    Node *balanceTree(Node *ubt) {
        updateHeight(ubt);
        int balance = getBalance(ubt);

        // LL
        if(balance > 1 && getBalance(ubt->left) >= 0) leftRotate(ubt);
        // RR
        else if(balance < 1 && getBalance(ubt->right) >= 0) rightRotate(ubt);
        // LR
        if(balance > 1 && getBalance(ubt->left) < 0) {
            ubt->left = rightRotate(ubt->left);
            leftRotate(ubt);
        }
        // RL
        if(balance < 1 && getBalance(ubt->right) < 0) {
            ubt->right = leftRotate(ubt->right);
            rightRotate(ubt);
        }
    }

    Node* insertion(Node *node, int val) {
        if(node == nullptr) return new Node(val);

        if(val < node->data) node->left = insertion(node->left,val);
        else if(val > node->data) node->right = insertion(node->right,val);

        return node;

        updateHeight(node);
        cout<<node->height<<endl;
    }

    void inOrder(Node* root) {
        if(root == nullptr) return;

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

public:
    AVL() : root(nullptr) {}

    void insertion(int val) {
        root = insertion(root,val);
    }

    void heigth() {
        cout<<root->height;
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
    AVL A;
    A.insertion(50);
    A.insertion(10);
    A.insertion(90);

    A.heigth();

    A.display();
    return 0;
}