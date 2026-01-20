#include<iostream>
using namespace std;
class MinHeap{
private:
    int size, capacity, *data;
public:
    MinHeap(int cap) : capacity(cap), size(0) {
        data =  new int[capacity];
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    bool isEmpty() {return size == 0;}
    bool isFull() {return size == capacity;}

    int getParent(int i) {return (i - 1)/ 2;}
    int getLeftChild(int i) {return (i * 2) + 1;}
    int getRightChild(int i) {return (i * 2) + 2;}


};


















class MaxHeap{
private:
    int size, capacity, *data;

public:
    MaxHeap(int cap) : capacity(cap) , size(-1) {
        data = new int[capacity];
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    bool isEmpty() {return size == -1;}
    bool isFull() {return size == capacity -1;}

    int getParent(int i) {return (i - 1)/ 2;}
    int getLeftChild(int i) {return (i * 2) + 1;}
    int getRightChild(int i) {return (i * 2) + 2;}

    void heapifyUp(int i) {
        while(i != 0 && data[i] > data[getParent(i)]) {
            swap(data[i],data[getParent(i)]);
            i = getParent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int leftChild = getLeftChild(i);
        int rightChild = getRightChild(i);

        if(leftChild < size && data[leftChild] > data[largest]) largest = leftChild;
        if(rightChild < size && data[rightChild] > data[largest]) largest = rightChild;

        if(largest != i) {
            swap(data[i],data[largest]);
            heapifyDown(largest);
        }
    }

    void insertKey(int key) {
        if(isFull()) {
            cout<<"Heap is full"<<endl;
            return;
        }
        if(isEmpty()) size = 0;
        data[size] = key;
        size++;
        heapifyUp(size - 1);
    }

    int extractMax() {
        if(isEmpty()) {
            cout<<"Heap is empty"<<endl;
            return -1;
        }
        int max = data[0];
        data[0] = data[size - 1];
        size--;
        heapifyUp(size);
    }
    void search(int val) {
        int index = 0;
        for(int i = 0; i< size; i++) {
            if(data[i] == val) {
                index = i;
                break;
            }
        }
        cout<<"Value found at the index"<<index<<endl;
    }
};