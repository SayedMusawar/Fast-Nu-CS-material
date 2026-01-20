#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST
{
private:
    Node *root;

    Node *findMin(Node *root)
    {
        while (root && root->left != nullptr)
            root = root->left;
        return root;
    }
    Node *findMax(Node *root)
    {
        while (root && root->right != nullptr)
            root = root->right;
        return root;
    }
    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    Node *insertNode(Node *root, int val)
    {
        if (root == NULL)
        {
            return new Node(val);
        }
        if (val < root->data)
        {
            root->left = insertNode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = insertNode(root->right, val);
        }
        return root;
    }
    // Q#01 Finding depth of a node
    int NodeDepth(Node *root, int key, int depth = 0)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->data == key)
        {
            return depth;
        }
        if (key < root->data)
        {
            return NodeDepth(root->left, key, depth + 1);
        }
        else
            return NodeDepth(root->right, key, depth + 1);
    }
    // Q#02 Counting nodes
    int countNodes(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    // Q#03 Counting leaf nodes
    int countleaf(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        return countleaf(root->left) + countleaf(root->right);
    }
    int countNonLeaf(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 0;
        return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
    }

    // Q#05 Diameter of a Binary Tree
    int diameter(Node *root, int &length)
    {
        if (root == NULL)
        {
            return -1;
        }

        int leftH = diameter(root->left, length);
        int rightH = diameter(root->right, length);

        int distance = leftH + rightH + 2;

        if (distance > length)
            length = distance;

        if (leftH > rightH)
            return leftH + 1;
        else
            return rightH + 1;
    }

    // Q#06 Check if a Binary Tree is a BST
    bool isBst(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->left != NULL && findMax(root->left)->data >= root->data)
        {
            return false;
        }
        if (root->right != NULL && findMin(root->right)->data <= root->data)
        {
            return false;
        }
        return isBst(root->left) && isBst(root->right);
    }
    // Q#07 Find Path from Root to a Given Node
    void printPath(Node *root, int val)
    {
        if (root == NULL)
        {
            cout << "Node not founded in the tree " << endl;
            return;
        }
        cout << root->data << " ";
        if (val < root->data)
        {
            printPath(root->left, val);
        }
        else if (val > root->data)
        {
            printPath(root->right, val);
        }
    }
    // Q#8  Sum of All Left Leaves
    int sumleftNodes(Node *root)
    {
        if (root == NULL)
            return 0;

        int sum = 0;

        if (root->left)
        {
            if (root->left->left == NULL && root->left->right == NULL)
                sum += root->left->data;
            else
                sum += sumleftNodes(root->left);
        }
        sum += sumleftNodes(root->right);
        return sum;
    }
    // Q#09
    bool printAncestors(Node *root, int key)
    {
        if (root == NULL)
            return false;

        if (root->data == key)
            return true;

        bool left = printAncestors(root->left, key);
        if (left)
        {
            cout << root->data << " ";
            return true;
        }

        // Check right subtree
        bool right = printAncestors(root->right, key);
        if (right)
        {
            cout << root->data << " ";
            return true;
        }

        return false;
    }
    // Q# 10
    Node *kthSmallest(Node *root, int k, int &count)
    {
        if (root == NULL)
            return NULL;

        Node *left = kthSmallest(root->left, k, count);
        if (left != nullptr)
            return left;

        count++;
        if (count == k)
            return root;

        return kthSmallest(root->right, k, count);
    }

public:
    BST() : root(NULL) {}
    void insert(int val)
    {
        root = insertNode(root, val);
    }
    int depth(int key)
    {
        return NodeDepth(root, key);
    }
    int countNodes()
    {
        return countNodes(root);
    }
    int countleaf()
    {
        return countleaf(root);
    }
    int countnonleafs()
    {
        return countNonLeaf(root);
    }
    int getDiameter()
    {
        int length = 0;
        diameter(root, length);
        return length;
    }
    void printPath(int val)
    {
        printPath(root, val);
        cout << endl;
    }
    int sum()
    {
        return sumleftNodes(root);
    }
    void printAncestors(int key)
    {
        if (printAncestors(root, key) == NULL)
            cout << "Root val does not exist " << endl;
        cout << endl;
    }
    int kthSmallest(int k)
    {
        int count = 0;
        Node *finalval = kthSmallest(root, k, count);
        if (finalval != NULL)
            return finalval->data;
        else
            return -1; 
    }

    // Question # 04 level order traversal
    void levelorder()
    {
        if (root == NULL)
        {
            return;
        }
        queue<Node *> q;
        q.push(root);
        while (q.empty() == NULL)
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << endl;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
};
int main()
{
    BST tree;

    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "Total nodes: " << tree.countNodes() << endl;
    cout << "Leaf nodes: " << tree.countleaf() << endl;
    cout << "Depth of node 15: " << tree.depth(15) << endl;
    cout << "Depth of node 30: " << tree.depth(30) << endl;
}