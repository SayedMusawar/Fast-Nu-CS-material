#include<iostream>
using namespace std;

// Order class
class Order {
public:
    int id;
    int numberOfItems;
    double payment;
    
    Order(int i, int items, double pay) 
        : id(i), numberOfItems(items), payment(pay) {}
    
    void display() {
        cout << "ID: " << id << ", Items: " << numberOfItems 
             << ", Payment: $" << payment << endl;
    }
};

// Node for BST
class Node {
public:
    Order* order;
    Node* left;
    Node* right;
    
    Node(Order* ord) : order(ord), left(nullptr), right(nullptr) {}
};

// BST organized by numberOfItems
class OrderBST {
private:
    Node* root;
    
    // Insert based on numberOfItems
    Node* insert(Node* node, Order* order) {
        if(node == nullptr) {
            return new Node(order);
        }
        
        if(order->numberOfItems < node->order->numberOfItems) {
            node->left = insert(node->left, order);
        }
        else if(order->numberOfItems > node->order->numberOfItems) {
            node->right = insert(node->right, order);
        }
        else {
            // If numberOfItems is same, you can:
            // Option 1: Insert to right (allow duplicates)
            node->right = insert(node->right, order);
            // Option 2: Reject duplicate
            // cout << "Order with same items already exists!" << endl;
        }
        
        return node;
    }
    
    // Find node with minimum numberOfItems (leftmost)
    Node* findMin(Node* node) {
        while(node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // Delete by ID (searches entire tree)
    Node* deleteById(Node* node, int id, bool& found) {
        if(node == nullptr) {
            return nullptr;
        }
        
        // Check current node
        if(node->order->id == id) {
            found = true;
            
            // Case 1: Leaf node
            if(node->left == nullptr && node->right == nullptr) {
                delete node->order;
                delete node;
                return nullptr;
            }
            
            // Case 2: One child
            if(node->left == nullptr) {
                Node* temp = node->right;
                delete node->order;
                delete node;
                return temp;
            }
            if(node->right == nullptr) {
                Node* temp = node->left;
                delete node->order;
                delete node;
                return temp;
            }
            
            // Case 3: Two children
            Node* minRight = findMin(node->right);
            node->order = minRight->order;  // Copy data
            node->right = deleteById(node->right, minRight->order->id, found);
            return node;
        }
        
        // Search both subtrees
        node->left = deleteById(node->left, id, found);
        if(!found) {
            node->right = deleteById(node->right, id, found);
        }
        
        return node;
    }
    
    // Inorder traversal (sorted by numberOfItems)
    void inorder(Node* node) {
        if(node == nullptr) return;
        
        inorder(node->left);
        node->order->display();
        inorder(node->right);
    }
    
    // Search by ID (for verification)
    Order* searchById(Node* node, int id) {
        if(node == nullptr) return nullptr;
        
        if(node->order->id == id) return node->order;
        
        Order* leftResult = searchById(node->left, id);
        if(leftResult != nullptr) return leftResult;
        
        return searchById(node->right, id);
    }

public:
    OrderBST() : root(nullptr) {}
    
    void insertOrder(int id, int items, double payment) {
        Order* newOrder = new Order(id, items, payment);
        root = insert(root, newOrder);
    }
    
    void deleteOrder(int id) {
        bool found = false;
        root = deleteById(root, id, found);
        
        if(found) {
            cout << "Order with ID " << id << " deleted successfully.\n";
        } else {
            cout << "Order with ID " << id << " not found.\n";
        }
    }
    
    void displayOrders() {
        cout << "\n=== Orders (sorted by number of items) ===\n";
        inorder(root);
        cout << endl;
    }
    
    void findOrder(int id) {
        Order* order = searchById(root, id);
        if(order != nullptr) {
            cout << "Found: ";
            order->display();
        } else {
            cout << "Order with ID " << id << " not found.\n";
        }
    }
};

int main() {
    OrderBST bst;
    
    // Insert orders (organized by numberOfItems in BST)
    bst.insertOrder(101, 5, 250.50);
    bst.insertOrder(102, 3, 150.00);
    bst.insertOrder(103, 8, 400.75);
    bst.insertOrder(104, 1, 50.00);
    bst.insertOrder(105, 6, 300.25);
    bst.insertOrder(106, 3, 175.00);  // Duplicate items count
    
    // Display (sorted by numberOfItems)
    bst.displayOrders();
    
    // Search by ID
    bst.findOrder(103);
    
    // Delete by ID
    bst.deleteOrder(103);  // Delete order with 8 items
    bst.deleteOrder(102);  // Delete order with 3 items
    
    // Display after deletion
    bst.displayOrders();
    
    // Try deleting non-existent order
    bst.deleteOrder(999);
    
    return 0;
}
```

---

## 📊 Output
```
=== Orders (sorted by number of items) ===
ID: 104, Items: 1, Payment: $50
ID: 102, Items: 3, Payment: $150
ID: 106, Items: 3, Payment: $175
ID: 101, Items: 5, Payment: $250.5
ID: 105, Items: 6, Payment: $300.25
ID: 103, Items: 8, Payment: $400.75

Found: ID: 103, Items: 8, Payment: $400.75
Order with ID 103 deleted successfully.
Order with ID 102 deleted successfully.

=== Orders (sorted by number of items) ===
ID: 104, Items: 1, Payment: $50
ID: 106, Items: 3, Payment: $175
ID: 101, Items: 5, Payment: $250.5
ID: 105, Items: 6, Payment: $300.25

Order with ID 999 not found.