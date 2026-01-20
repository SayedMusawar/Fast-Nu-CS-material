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
        if (node == NULL) return -1; 
        return node->height;
    }

    void updateHeight(Node *node){
        int leftH = height(node->left);
        int rightH = height(node->right);

        if (leftH > rightH) node->height = 1 + leftH;
        else node->height = 1 + rightH;
    }

    int getBalance(Node *node){
        if (node == NULL) return 0;
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

    // Q4 Perform All four Rotation (LL, RR, LR, Rl)
    Node *balance(Node *node){
        updateHeight(node);
        int bf = getBalance(node);

        // LL case
        if (bf > 1 && getBalance(node->left) >= 0) return rotateRight(node);
        // LR case
        if (bf > 1 && getBalance(node->left) < 0) {
            node->left = rotateleft(node->left);
            return rotateRight(node);
        }
        // RR case
        if (bf < -1 && getBalance(node->right) <= 0) return rotateleft(node);
        //Rl case
        if (bf < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateleft(node);
        }
        return node;
    }

    Node *findMin(Node *root){
        while (root && root->left != NULL) root = root->left;
        return root;
    }

    Node *findMax(Node *root){
        while (root && root->right != NULL) root = root->right;
        return root;
    }

    // Q1 implement insertion in an AVL Tree
    Node *insertNode(Node *root, int key){
        if (root == NULL) return new Node(key);
        if (key > root->data ) root->right = insertNode(root->right , key);
        else if (key < root->data) root->left = insertNode(root->left, key);
        return balance(root);
    }

    // Q2 Implement Deletion in an AVL
    Node *deleteNode(Node *node, int key){
        if (node == NULL) return node;
        if (key < node->data) node->left = deleteNode(node->left, key);
        else if (key > node->data) node->right = deleteNode(node->right, key);
        else{
            if (node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
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

    // Q3 Find Balance Factor of every node
    void printBalanceFactors(Node *node){
        if (node == NULL) return;
        printBalanceFactors(node->left);
        cout << " Node " << node->data << " BF = " << getBalance(node) << endl;
        printBalanceFactors(node->right);
    }
    bool isAVL(Node *root){
        if (root == NULL) return true;
        int bf = getBalance(root);
        if (bf > 1 || bf < -1) return false;

        return isAVL(root->left) && isAVL(root->right);
        
    }
    Node *arrayToAVL(int arr[], int s, int e){
        if (s > e) return NULL;
        int middle = (s + e) / 2;

        Node *node = new Node(arr[middle]);
        node->left = arrayToAVL(arr, s, middle - 1);
        node->right = arrayToAVL(arr, middle + 1, e);

        updateHeight(node);
        return node;
    }
    public:
    AVL() :root(NULL) {}
    void insert(int val){
        root = insertNode(root, val);
    }

    void deleteNode(int val){
        root = deleteNode(root, val);
    }

    void printBalance(){
        printBalanceFactors(root);
    }

    bool isAVL(){
        return isAVL(root);
    }

    void SortedArrayList(int arr[], int n) {
        root = arrayToAVL(arr, 0, n - 1);
    }
};

void displayMenu() {
    cout<<"===== AVL MENU ====="<<endl;
    cout<<"1. Insert Node"<<endl;
    cout<<"2. Find minimum value"<<endl;
    cout<<"3. Find maximum value"<<endl;
    cout<<"4. Traversal (Display)"<<endl;
    cout<<"5. Delete Node"<<endl;
    cout<<"6. Update height"<<endl;
    cout<<"7. Get balance factor"<<endl;
    cout<<"8. Rotate Tree"<<endl;
    cout<<"9. Balance a node"<<endl;
    cout<<"10. Convert an array to tree"<<endl;
    cout<<"11. Check if a tree is AVL tree"<<endl;
    cout<<"12. Display values"<<endl;
    cout<<"0. Exit"<<endl;
}

int main(){
    AVL tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(40);
    tree.deleteNode(10);
    tree.printBalance();
    if (tree.isAVL())
    {
        cout << "Tree is AVL balanced " << endl;
    }
    else{
        cout << "Not balanced " << endl;
    }

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    tree.SortedArrayList(arr, n);
    
}