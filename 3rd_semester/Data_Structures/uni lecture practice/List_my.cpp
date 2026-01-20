#include<iostream>
using namespace std;
class List{
private:
    int *data, size, cap; 

    bool isFull() {
        if(size == cap) return true;
        else return false;
    }
    bool isEmpty() {
        if (size == 0) return true;
        else return false;
    }

    void insertAtBeginning(int val) {
        if ( data[0] != 0 ) for (int i = size; i >= 0 ; i--) data[i+1] = data[i];
        data[0] = val;
        size++;
    }

    void insertAtIndex(int index, int val) {
        if(data[index - 1] == 0 && data[index] != 0) {
            index = size;
            cout<<"Index changed to maintain linearity. New index is: "<<index<<endl;
        } else if ( data[index] != 0 ) for (int i = size; i >= index ; i--) data[i+1] = data[i];
        data[index] = val;
        size++;
    }

    int search(int val) {
        int index = -1 ;
        for(int i = 0; i < size; i++) {
            if(data[i] == val) {
                index = i;
                break;
            }
        }
        return index;
    }

    int deletetion(int index) {
        int value = data[index];
        data[index] = 0;
        for(int i = index; i <= size ; i++) data[i] = data[i + 1];
        data[size] = 0;
        size--;
        return value;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int findMinimum(int first_Element) {
        int index = first_Element; int smallest = data[first_Element];
        for(int i = index; i < size; i++) {
            if(data[i] < smallest) {
                smallest = data[i];
                index = i;
            }
        }
        return index;
    }

    int findMaximum(int first_element) {
        int index = first_element; int largest = data[first_element];
        for(int i = index; i < size; i++) {
            if(data[i] > largest) {
                largest = data[i];
                index = i;
            }
        }
        return index;
    }
public:
    List(int capacity = 0) : size(0), cap(capacity) {
        data = new int[cap];
        for(int i = 0; i < cap; i++) data[i] = 0;
    }
    void insertAtBeginning() {
        if(isFull()) {
            cout<<"List is full... Cannot insert a new value"<<endl;
            return;
        }
        cout<<"Input a value to you want to add in the list"<<endl;
        int val;
        cin >> val;
        if(val == 0) {
            cout<<"Zero can't be stored in the list"<<endl;
            return;
        }
        insertAtBeginning(val);
    }

    void insertAtIndex() {
        if(isFull()) {
            cout<<"List is full... Cannot insert a new value"<<endl;
            return;
        }
        cout<<"Enter the index in which you want to add the value (start from 0)"<<endl;
        int index,val;
        cin >> index;
        if(index < 0 || index > cap) {
            cout<<"invalid index!! Can't entered value"<<endl;
            return;
        }
        cout<<"Enter the value to store in the list"<<endl;
        cin >> val;

        insertAtIndex(index,val);
    }

    void search() {
        if(isEmpty()) {
            cout<<"Error. The list is empty!!! Can't search the items"<<endl;
            return;
        }
        cout<<"Enter the number you want to search in the list"<<endl;
        int val,index = -1;
        cin >> val;

        index = search(val);

        if(index == -1) {
            cout<<"Value not found in the list..... Returning"<<endl;
            return;
        } else {
            cout<<"Value found at the index: "<<index + 1<<endl;
        }
    }

    void deletetion() {
        if(isEmpty()) {
            cout<<"List is already empty... Can't delete the element"<<endl;
            return;
        }
        cout<<"Which type of deletion you want to perform"<<endl;
        cout<<"0. Delete by index.\n1. Delete by value"<<endl;
        int choice, val, index = -1;
        cin >> choice;
        if(!choice) {
            cout<<"Enter the index from which you want to delete the value (starting form 0)"<<endl;
            cin >> index;
            if(index < 0 || index > size) {
                cout<<"Invalid index!!.... Can't delete the value"<<endl;
                return;
            }

            val = deletetion(index);
            
        } else {
            cout<<"Enter the value you want to delete from the list"<<endl;
            cin >> val;
            index = search(val);

            if(index == -1) {
                cout<<"Value not found in the list..... Returning"<<endl;
                return;
            }
            val = deletetion(index);
        }
        
        cout<<val <<"deleted successfully from the index "<<index<<" new size is: "<<size<<endl;
    }

    void sort() {
        int index = -1;
        int choice;
        cout<<"0. Assending order"<<endl<<"1. Descending order"<<endl;
        cin >> choice;
        if(!choice) {
            for(int i = 0; i < size ; i++) {
                index = findMinimum(i);
                swap(data[index],data[i]);
            }
        } else {
            for(int i = 0; i < size ; i++) {
                index = findMaximum(i);
                swap(data[index],data[i]);
            }
        }   
    }

    void increaseCapacity() {
        int newCap;
        cout<<"Enter new capacity"<<endl; cin >> newCap;
        if(newCap < 0 || newCap <= cap) {
            cout<<"Invalid capicty"<<endl;
            return;
        }
        data = new int[newCap];

        for(int i = 0; i < size ; i++) {
            
        }
    }

    void showCapacity() {
        cout<<"The current capacity is: "<<cap<<endl;
        return;
    }

    void showSize() {
        cout<<"Current size of the list is: "<<size<<endl;
    }
    void display() {
        for(int i = 0;i< size; i++) cout<<data[i]<<" ";
        cout<<endl;  
    }
};

int main() {
    List L1(5);

    L1.insertAtBeginning();
    L1.insertAtBeginning();
    L1.insertAtBeginning();
    L1.insertAtBeginning();
    L1.insertAtBeginning();

    // L1.insertAtIndex();
    L1.display();

    L1.sort();
    L1.display();

    L1.sort();
    L1.display();

    // L1.showCapacity();
    // L1.showSize();
    return 0;
}