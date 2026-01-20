#include <iostream>
#include <stdexcept>
using namespace std;
//  Q1
class DynamicArray {
private:
    int *data;
    int capacity;
    int sz;

    void resize(int newCap) {
        int *newData = new int[newCap];
        for (int i = 0; i < sz; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    DynamicArray(int initialCap = 4) {
        if (initialCap <= 0) initialCap = 4;
        data = new int[initialCap];
        capacity = initialCap;
        sz = 0;
    }

    ~DynamicArray() { delete[] data; }

    int size() const { return sz; }

    int get(int idx) const {
        if (idx < 0 || idx >= sz) throw out_of_range("Index out of range");
        return data[idx];
    }

    void pushBack(int value) {
        if (sz == capacity) resize(capacity * 2);
        data[sz++] = value;
    }

    // Insert at position idx (0..sz). If idx == sz -> append.
    void insertAt(int idx, int value) {
        if (idx < 0 || idx > sz) throw out_of_range("Index out of range");
        if (sz == capacity) resize(capacity * 2);
        // shift right
        for (int i = sz; i > idx; --i) data[i] = data[i-1];
        data[idx] = value;
        ++sz;
    }

    void removeAt(int idx) {
        if (idx < 0 || idx >= sz) throw out_of_range("Index out of range");
        for (int i = idx; i < sz-1; ++i) data[i] = data[i+1];
        --sz;
        if (sz > 0 && sz <= capacity/4) resize(capacity/2);
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < sz; ++i) {
            cout << data[i];
            if (i+1 < sz) cout << ", ";
        }
        cout << "]\n";
    }
};
// Q2
void insertionSort(DynamicArray &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr.get(i);
        int j = i - 1;
        // shift elements to the right until correct position for key found
        while (j >= 0 && arr.get(j) > key) {
            // emulate arr[j+1] = arr[j]
            // we can't set by index directly, implement via remove/insert?
            // but to be efficient, we create a small temporary buffer:
            // Since DynamicArray lacks set(), add a private-friendly approach:
            // We'll workaround by reconstructing values via remove/insert.
            // Simpler: add a set method (below).
            break;
        }
    }
}

void insertionSortUsingTempArray(DynamicArray &arr) {
    int n = arr.size();
    // copy into native array
    int *A = new int[n];
    for (int i = 0; i < n; ++i) A[i] = arr.get(i);

    for (int i = 1; i < n; ++i) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            --j;
        }
        A[j+1] = key;
    }
    while (arr.size() > 0) arr.removeAt(0);
    for (int i = 0; i < n; ++i) arr.pushBack(A[i]);
    delete[] A;
}

// Q3
class Stack {
private:
    DynamicArray arr;
public:
    Stack(): arr(4) {}
    void push(int v) { arr.pushBack(v); }
    int pop() {
        if (isEmpty()) throw runtime_error("Stack underflow");
        int val = arr.get(arr.size()-1);
        arr.removeAt(arr.size()-1);
        return val;
    }
    int top() const {
        if (isEmpty()) throw runtime_error("Stack empty");
        return arr.get(arr.size()-1);
    }
    bool isEmpty() const { return arr.size() == 0; }
    void print() const { arr.print(); }
};
// Q4
class Queue {
private:
    int *data;
    int capacity;
    int head;   // index of front element
    int tail;   // index one past last element
    int sz;

    void grow() {
        int newCap = capacity * 2;
        if (newCap < 4) newCap = 4;
        int *newData = new int[newCap];
        // copy current elements in order
        for (int i = 0; i < sz; ++i)
            newData[i] = data[(head + i) % capacity];
        delete[] data;
        data = newData;
        capacity = newCap;
        head = 0;
        tail = sz;
    }

public:
    Queue(int initCap = 8) {
        if (initCap < 4) initCap = 4;
        data = new int[initCap];
        capacity = initCap;
        head = 0;
        tail = 0;
        sz = 0;
    }

    ~Queue() { delete[] data; }

    void enqueue(int v) {
        if (sz == capacity) grow();
        data[tail] = v;
        tail = (tail + 1) % capacity;
        ++sz;
    }

    int dequeue() {
        if (isEmpty()) throw runtime_error("Queue underflow");
        int v = data[head];
        head = (head + 1) % capacity;
        --sz;
        return v;
    }

    int front() const {
        if (isEmpty()) throw runtime_error("Queue empty");
        return data[head];
    }

    bool isEmpty() const { return sz == 0; }
    int size() const { return sz; }

    void print() const {
        cout << "Queue[";
        for (int i = 0; i < sz; ++i) {
            cout << data[(head + i) % capacity];
            if (i+1 < sz) cout << ", ";
        }
        cout << "]\n";
    }
};

// Q5
struct Node {
    int val;
    Node *next;
    Node(int v): val(v), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node *head;
    Node *tail;
    int sz;
public:
    SinglyLinkedList(): head(nullptr), tail(nullptr), sz(0) {}
    ~SinglyLinkedList() {
        Node *cur = head;
        while (cur) {
            Node *tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    int size() const { return sz; }

    void insertAtHead(int v) {
        Node *n = new Node(v);
        n->next = head;
        head = n;
        if (tail == nullptr) tail = n;
        ++sz;
    }

    void insertAtTail(int v) {
        Node *n = new Node(v);
        if (tail) tail->next = n;
        tail = n;
        if (head == nullptr) head = n;
        ++sz;
    }

    // insert at position idx (0..sz). idx == 0 => head, idx == sz => tail
    void insertAtPosition(int idx, int v) {
        if (idx < 0 || idx > sz) throw out_of_range("Index out of range");
        if (idx == 0) { insertAtHead(v); return; }
        if (idx == sz) { insertAtTail(v); return; }
        Node *cur = head;
        for (int i = 0; i < idx-1; ++i) cur = cur->next;
        Node *n = new Node(v);
        n->next = cur->next;
        cur->next = n;
        ++sz;
    }

    void print() const {
        Node *cur = head;
        cout << "LinkedList[";
        while (cur) {
            cout << cur->val;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << "]\n";
    }
};

// Q6
struct BSTNode {
    int val;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode *root;

    BSTNode* insertRec(BSTNode *node, int v) {
        if (!node) return new BSTNode(v);
        if (v < node->val) node->left = insertRec(node->left, v);
        else node->right = insertRec(node->right, v);
        return node;
    }

    void inorderRec(BSTNode *node) const {
        if (!node) return;
        inorderRec(node->left);
        cout << node->val << " ";
        inorderRec(node->right);
    }

    void destroy(BSTNode *node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST(): root(nullptr) {}
    ~BST() { destroy(root); }

    void insert(int v) { root = insertRec(root, v); }
    void inorder() const {
        cout << "BST inorder: ";
        inorderRec(root);
        cout << "\n";
    }
};

void demoProblem1_dynamicArray() {
    cout << "---- Problem 1: Dynamic Array and insertionAt(index) demo ----\n";
    DynamicArray a;
    a.pushBack(10);
    a.pushBack(20);
    a.pushBack(30);
    cout << "Initial array: "; a.print();
    cout << "Insert 15 at index 1\n";
    a.insertAt(1, 15);
    cout << "After insert: "; a.print();
    cout << "Insert 5 at index 0\n";
    a.insertAt(0, 5);
    cout << "After insert: "; a.print();
    cout << "Insert 100 at end\n";
    a.insertAt(a.size(), 100);
    cout << "After insert: "; a.print();
    cout << "Remove element at index 2\n";
    a.removeAt(2);
    cout << "After remove: "; a.print();
    cout << "\n";
}

void demoProblem2_insertionSort() {
    cout << "---- Problem 2: Insertion Sort demo (using temp array) ----\n";
    DynamicArray a;
    int arrVals[] = {29, 10, 14, 37, 13};
    for (int v : arrVals) a.pushBack(v);
    cout << "Before sort: "; a.print();
    insertionSortUsingTempArray(a);
    cout << "After insertion sort: "; a.print();
    cout << "\n";
}

void demoProblem3_stack() {
    cout << "---- Problem 3: Stack demo ----\n";
    Stack s;
    cout << "Push 1,2,3\n";
    s.push(1); s.push(2); s.push(3);
    cout << "Stack top: " << s.top() << "\n";
    cout << "Pop: " << s.pop() << "\n";
    cout << "Stack now: "; s.print();
    cout << "\n";
}

void demoProblem4_queue() {
    cout << "---- Problem 4: Queue demo ----\n";
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << "Queue: "; q.print();
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Front now: " << q.front() << "\n";
    cout << "Queue: "; q.print();
    cout << "\n";
}

void demoProblem5_linkedList() {
    cout << "---- Problem 5: Singly Linked List insertion demo ----\n";
    SinglyLinkedList L;
    L.insertAtHead(10);
    L.insertAtTail(30);
    L.insertAtPosition(1, 20); // middle
    cout << "After three inserts: "; L.print();
    L.insertAtPosition(0, 5);
    L.insertAtPosition(L.size(), 35);
    cout << "After head and tail inserts: "; L.print();
    cout << "\n";
}

void demoProblem6_bst() {
    cout << "---- Problem 6: BST insertion and inorder traversal ----\n";
    BST tree;
    int vals[] = {20, 10, 30, 5, 15, 25, 40};
    for (int v : vals) tree.insert(v);
    tree.inorder();
    cout << "\n";
}


int main() {
    cout << "Single-file DS insertion demos (no STL containers used)\n\n";
    demoProblem1_dynamicArray();   // Problem 1
    demoProblem2_insertionSort();  // Problem 2
    demoProblem3_stack();          // Problem 3
    demoProblem4_queue();          // Problem 4
    demoProblem5_linkedList();     // Problem 5
    demoProblem6_bst();            // Problem 6

    cout << "All demos finished.\n";
    return 0;
}
