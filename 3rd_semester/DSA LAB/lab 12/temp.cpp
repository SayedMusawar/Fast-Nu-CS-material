#include<iostream>
#include<string>
using namespace std;

class Order {
private:
    string itemName;
    int price;
    int quantity;
    string custName;
    int priority;

public:
    // Constructor
    Order(string itName = "", int p = 0, int q = 0, string cName = "", int prior = 0) {
        itemName = itName;
        price = p;
        quantity = q;
        custName = cName;
        priority = prior;
    }

    // Get order details from user
    void getValues() {
        cout << "\nEnter item name: ";
        cin.ignore();
        getline(cin, itemName);
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, custName);
        cout << "Enter priority (higher = more urgent): ";
        cin >> priority;
    }

    // Display order details
    void display() const {
        cout << "Customer: " << custName 
             << " | Item: " << itemName 
             << " | Qty: " << quantity 
             << " | Price: $" << price 
             << " | Priority: " << priority << endl;
    }

    // Getter for priority (needed for heap operations)
    int getPriority() const {
        return priority;
    }

    // Check if order is empty
    bool isEmpty() const {
        return itemName.empty();
    }
};

class MaxHeap {
private:
    Order* heap;      // Array to store orders
    int capacity;     // Maximum capacity
    int size;         // Current number of orders

    // Get parent index
    int getParent(int index) {
        if (index == 0) return -1;
        return (index - 1) / 2;
    }

    // Get left child index
    int getLeft(int index) {
        int left = 2 * index + 1;
        return (left < size) ? left : -1;
    }

    // Get right child index
    int getRight(int index) {
        int right = 2 * index + 2;
        return (right < size) ? right : -1;
    }

    // Swap two orders
    void swap(Order& a, Order& b) {
        Order temp = a;
        a = b;
        b = temp;
    }

    // Heapify up (after insertion)
    void heapifyUp(int index) {
        if (index <= 0) return;
        
        int parent = getParent(index);
        if (parent >= 0 && heap[index].getPriority() > heap[parent].getPriority()) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Heapify down (after deletion)
    void heapifyDown(int index) {
        int largest = index;
        int left = getLeft(index);
        int right = getRight(index);

        // Find the largest among parent, left child, and right child
        if (left != -1 && heap[left].getPriority() > heap[largest].getPriority()) {
            largest = left;
        }
        if (right != -1 && heap[right].getPriority() > heap[largest].getPriority()) {
            largest = right;
        }

        // If largest is not the parent, swap and continue heapifying
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Constructor
    MaxHeap(int cap = 100) {
        capacity = cap;
        size = 0;
        heap = new Order[capacity];
    }

    // Destructor
    ~MaxHeap() {
        delete[] heap;
    }

    // Insert a new order
    void insert(Order newOrder) {
        if (size >= capacity) {
            cout << "\nHeap is full! Cannot insert more orders." << endl;
            return;
        }

        // Insert at the end
        heap[size] = newOrder;
        size++;

        // Fix the heap property by moving up
        heapifyUp(size - 1);
        
        cout << "\nOrder inserted successfully!" << endl;
    }

    // Serve (delete) the highest priority order
    void serveOrder() {
        if (size == 0) {
            cout << "\nNo orders to serve!" << endl;
            return;
        }

        cout << "\n--- Serving Order ---" << endl;
        heap[0].display();

        // Move last element to root
        heap[0] = heap[size - 1];
        size--;

        // Fix the heap property by moving down
        if (size > 0) {
            heapifyDown(0);
        }

        cout << "Order served successfully!" << endl;
    }

    // Display all orders
    void displayAll() {
        if (size == 0) {
            cout << "\nNo orders in the system!" << endl;
            return;
        }

        cout << "\n========== All Orders (Total: " << size << ") ==========" << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". ";
            heap[i].display();
        }
        cout << "===========================================" << endl;
    }

    // Check if heap is empty
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    MaxHeap restaurant(100);  // Create heap with capacity 100
    int choice;

    cout << "====================================" << endl;
    cout << "Restaurant Order Management System" << endl;
    cout << "====================================" << endl;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Insert new order" << endl;
        cout << "2. Serve highest priority order" << endl;
        cout << "3. Display all orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Order newOrder;
                newOrder.getValues();
                restaurant.insert(newOrder);
                break;
            }
            case 2:
                restaurant.serveOrder();
                break;
            case 3:
                restaurant.displayAll();
                break;
            case 4:
                cout << "\nExiting system. Thank you!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}