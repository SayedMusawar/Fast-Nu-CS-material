#include<iostream>
using namespace std;
class List{
private:
    int *data, size, cap, val;
    bool isFull() {
        if(size == cap) return true;
        else return false;
    }
    bool isEmpty() {
        if(size == 0) return true;
        else return false;
    }

    void insertAtIndex(int index,int val) {
        if(data[index - 1] == 0 && data[index] != 0) {
            index = size + 1;
            cout<<"Index changed to maintain linearity"<<endl;
        } else if(data[index] != 0) {
            for(int i = size; i >=0;i--) data[i+1] = data[i];
        }
        data[index] = val;
        size++;
    }
    int findMinimum(int startingLocation) {
        int index = startingLocation, smallest = data[startingLocation];
        for(int i = startingLocation + 1;i<=size; i++) {
            if(data[i] < smallest) {
                smallest = data[i];
                index = i;
            }
        }
        return index;
    }

    int findMaximum(int startingLocation) {
        int index = startingLocation, largest = data[startingLocation];
        for(int i = startingLocation + 1; i<=size; i++ ) {
            if(data[i] > largest) {
                largest = data[i];
                index = i;
            }
        }
        return index;
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void sort(int order) {
        int index = -1;
        if(order == 0) {
            for(int i = 0; i < size; i++) {
                index = findMinimum(i);
                swap(data[index], data[i]);
            }
        } else {
            for(int i = 0; i < size ; i++) {

                index = findMaximum(i);
                swap(data[index], data[i]);
            }
        }
    }
    int search(int value,int searchType) {
        int index = -1;
        if(searchType == 0 ) {
            for(int i = 0; i <= size; i++) {
                if(data[i] == val) {index = i; break;}
            }
        } else {
            int low = 0, high = size, mid = 0;
            while(low <= high) {
                mid = (low + high) / 2;
                if(data[mid] == value) return mid;
                else if(data[mid] < value) low = mid + 1;
                else high = mid - 1; 
            }
        }

        return index;
    }
public:
    List(int capacity = 0) : cap(capacity), size(0) {
        data = new int[cap];
        for(int i = 0; i < cap; i++) data[i] = 0;
    }

    void insertAtIndex() {
        if(isFull()) {
            cout<<"The list is Full... Can't add more elements"<<endl;
            return;
        }
        int index;
        cout<<"Enter the index at which you want to add the value"<<endl;
        cin >> index;
        index--;
        if(index < 0 || index > cap) {
            cout<<"Invalid index!!... Can't enter the value"<<endl;
            return;
        }
        cout<<"Enter the value to store in the list"<<endl;
        cin >> val;
        insertAtIndex(index,val);
    }

    void search() {
        if(isEmpty()) {
            cout<<"List is empty.. Can't search an element"<<endl;
            return;
        }
        int value = 0, searchType = 0;
        cout<<"\n Enter value for searching: "; 
        cin >> value;
        cout<<"Enter seach type: 0 for Linear Search, 1 for binary search"<<endl;

        cin >> searchType;

        if(searchType) {
            cout<<"\n sorting data in ascending order for binary search"<<endl;
            sort(0);
        }
        int index = search(value,searchType);
        if(index == -1) {
            cout<<"Value not found"<<endl;
        } else {
            cout<<"Value found at index"<<index;
        }
    }

    void sort() {
        if(isEmpty()) return;
        int order = 0;
        cout<<"Enter 0 for ascending sorting, 1 for descending sorting"<<endl;
        cin >> order;
        sort(order);

    }
};