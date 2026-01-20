#include<iostream>
using namespace std;
class Records{
public:
    int roll;
    string name;
    float gpa;
    Records(int r,string n,float g) : roll(r), name(n), gpa(g) {}

    void display() {
        cout<<"Name: "<<name<<", Roll no: "<<roll<<", gpa: "<<gpa<<endl;
    }
};
class Node{
public:
    Records* records;
    Node *left, *right;
    Node(Records* val) : records(val),left(nullptr), right(nullptr) {}
};
class bst{
private:
    Node* root;

    Node* insert(Node *node, Records* rec) {
        if(node  == nullptr) return new Node(rec);
        if(rec->gpa < node->records->gpa) node->left = insert(node->left,rec);
        if(rec->gpa > node->records->gpa) node->right = insert(node->right,rec);

        return node;
    }
public:
    bst() : root(nullptr) {}

    void insertVal(int roll,string name,float gpa) {
        Records *newRecord = new Records(roll,name,gpa);
        root = insert(root,newRecord);
    }
    void inOrder(Node *root) {
        if(root == nullptr) return;
        inOrder(root->left);
        root->records->display();
        inOrder(root->right);
    }
    void display() {
        inOrder(root);
    }
};
int main() {
    bst b;
    b.insertVal(1,"mussi",2);
    b.insertVal(1,"mussi",3.55);
    b.insertVal(1,"mussi",2.5);
    b.insertVal(1,"mussi",4.0);
    b.insertVal(1,"mussi",1.5);

    b.display();

}
