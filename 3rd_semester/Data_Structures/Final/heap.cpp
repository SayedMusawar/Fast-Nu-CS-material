#include<iostream>
using namespace std;
class MaxHeap{
private:
    int *data, size,capacity, *arr;
    int getParent(int i) {return (i-1)/2;}
    int getLeftChild(int i) {return 2 *i + 1;}
    int getRightChild(int i) {return 2*i + 2;}

    void swap(int &a, int &b) {
        int temp = a;
        a = b; 
        b= temp;
    }

    void heapifyUp(int i) {
        while(i != 0 && data[i] > data[getParent(i)]) {
            swap(data[i],data[getParent(i)]);
            i = getParent(i);
        }
    }

    void heapifyDown(int i) {
        int leftChild = getLeftChild(i);
        int rightChild = getRightChild(i);
        int largest = i;
        if(leftChild < size && data[leftChild] > data[largest]) largest = leftChild;
        if(rightChild < size && data[rightChild] > data[largest]) largest = rightChild;
        if(i != largest) {
            swap(data[i],data[largest]);
            heapifyDown(largest);
        }
    }
    void question() {
        // extract max and store in the array 
        arr = new int[size];
        int i = 0;
        int origSize = size;
        while(size != 0) {
            int max = extractMax();
            arr[i] = max;
            i++;
        }

        // Display the array
        for(int i = 0; i< size;i++) cout<<arr[i]<<" ";
        cout<<endl;

        // Maintain original heap
        for(int i =0; i<size;i++) {
            insert(arr[i]);
        }
    }
public:
    MaxHeap(int cap) : size(0), capacity(cap) {
        data = new int[capacity];
    }
    void insert(int key) {
        if(size == capacity) return;
        data[size] = key;
        size++;
        heapifyUp(size-1);
    }

    int extractMax() {
        int max = data[0];
        data[0] = data[size - 1];
        size--;
        heapifyDown(0);
        return max;
    }
    void display() {
        for(int i = 0; i < size; i++) cout<<data[i]<<" ";
        cout<<endl;
    }
};
int main() {}