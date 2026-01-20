#include<iostream>
using namespace std;
class MaxHeap{
private:
    int size, capacity, *data;
    int getParent(int i) {return (i - 1) / 2;}
    int getLeftChild(int i) {return (2 * i) + 1;}
    int getRightChild(int i) {return (2 * i) + 2;}

    bool isFull() {return (size == capacity);}

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while(index != 0 && data[index] > data[getParent(index)]) {
            swap(data[index],data[getParent(index)]);
            index = getParent(index);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = getLeftChild(i);
        int right = getRightChild(i);
        if(left < size && data[left] > data[largest]) largest = left;
        if(right < size && data[right] > data[largest]) largest = right;

        if(largest != i) {
            swap(data[i],data[largest]);
            heapifyDown(largest);
        }
    }
public:
    MaxHeap(int cap) : capacity(cap), size(0) {
        data = new int[capacity];
    }

    void insert(int val) {
        if(isFull()) {cout<<"Heap Overflow"<<endl; return;}

        data[size] = val;
        heapifyUp(size);
        size++;
    }

    int ExtractMax() {
        if(size == 0) {
            cout<<"Heap is Empty"<<endl;
            return -1;
        }
        int max = data[0];
        data[0] = data[size -1];
        size--;
        heapifyDown(0);
        return max;
    }
};