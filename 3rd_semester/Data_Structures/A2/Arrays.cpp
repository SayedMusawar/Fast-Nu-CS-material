#include<iostream>
#include<conio.h>
using namespace std;
const int EXIT=0, SHOWDATA=1, SHOWSIZE=2, SHOWCAPACITY=3, INCREASECAPACITY=4, INSERTDATA=5, DELETEDATA=6,
SEARCHDATA=7, SORTDATA = 8;
class List {
public:
    // Pure virtual functions = must be implemented in derived class
    virtual void insertion() = 0;
    virtual void deletion() = 0;
    virtual void search() = 0;
    virtual void increaseCapacity() = 0;
    virtual void displayData() = 0;
    virtual void showCapacity() = 0;
    virtual void showSize() = 0;
    virtual void sort() = 0;
    virtual void swapLists() = 0;
    virtual void reverseList() = 0;
    virtual void mergeLists() = 0;
    // Virtual destructor (important for base abstract classes)
    virtual ~List() {}
};

class ArrayList: public List{
private:
    int *data, size, capacity;

    int insertion(int index, int value) {
        if ( data[index] != 0 ){
            for (int i=size; i>=index; i--)
                data[i+1] = data[i];
        }else if ( (index != 0) && (data[index-1] == 0) ){ // (index != 0) to stop accessing the location data[-1].
            index = size + 1;
            cout<<"\n to maintain linearity/sequence in the list changing index to: "<<index;
        }
        data[index] = value;
        ++size;
        return index;
    }

    int deletion(int index) {
        int value = data[index];
        data[index] =  0;      // hypothetical deletion: using zero as a sentinel number, showing absence of data.
        for (int i=index; i<size; i++)
            data[i] = data[i+1];
        data[size] = 0; //to remove copy of the data from the last location.
        --size;
        return value;
    }

    int search(int value,int searchType){
        int index = -1;
        if (!searchType){
            for (int i=0; i<=size; i++){
                if (data[i] == value){
                    index = i;
                    break;
                }
            }
        }
        else{
            int low=0, high=size,mid=0;
            while (low <= high){
                mid = (low + high)/2;
                if (data[mid] == value)
                    return mid;
                else if (data[mid]<value)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return index;
    }

    bool isFull(){
        if ( size == (capacity-1) ){
            cout<<"\n overflow: (array is full)";
            return true;
        }
        return false;
    }

    bool isEmpty(){
           if ( size < 0 ){
            cout<<"\n underflow: (array is empty)";
            return true;
        }
        return false;
    }

    void increaseCapacity(int newCapacity){
        int *newdata = new int[newCapacity];
        for (int i=0; i<=size; i++)
            newdata[i] = data[i];
        for (int i=size+1; i<newCapacity; i++) // initialize the remaining locations with zero to maintain logic.
            newdata[i] = 0;
        delete[] data;
        data = newdata;
        newdata = nullptr;
        capacity = newCapacity;
    }

    int findMinimum(int startingLocation){
        int index = startingLocation, smallest = data[startingLocation];
        for (int i = startingLocation + 1; i<=size; i++){
            if (data[i]<smallest){
                smallest = data[i];
                index = i;
            }
        }
        return index; // returns index of smallest value in the list under consideration.
    }

    int findMaximum(int startingLocation){
        int index = startingLocation, largest=data[startingLocation];
        for (int i = startingLocation + 1; i<=size; i++){
            if (data[i]>largest){
                largest = data[i];
                index = i;
            }
        }
        return index; // returns index of largest value in the list under consideration.
    }

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sort(int order){
        int index = -1;
        if (!order){
            for(int i=0; i<size; i++){
                index = findMinimum(i);
                swap(data[index],data[i]);
            }
        }else{
            for (int i=0; i<size; i++){
                index = findMaximum(i);
                swap(data[index],data[i]);
            }
        }
    }

public:
    int choice;
    ArrayList(int cap):size(-1),capacity(cap),choice(1){
        data = new int[capacity];
        for (int i=0; i<capacity; i++)
            data[i] = 0;
    }

    void insertion() override{
        if (isFull()) return;
        int index =-1, value =0;
        cout<<"\n enter index/position (0 to "<<capacity-1<<") for insertion = ";
        cin>>index;
        if (index < 0 || index >= capacity){
            cout<<"\n invalid index, please try again! ";
            return;
        }
        cout<<"\n enter value for insertion = "; cin>>value;
        if (value){
            index = insertion(index,value);
            cout<<"\n value inserted successfully at index: "<<index;
            cout<<"\n current size of array = "<<size + 1;
        }else {
            cout<<"\n zero cannot be part of data, please try again! ";
        }
    }

    void deletion()override{
        if ( isEmpty() ) return;
        int index = -1,value=0, choice=0;
        cout<<"\n\n enter choice for deletion: ( 1 by index ) or ( 2 by value ) = ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\n enter index [0 to "<<size<<"] = "; cin>>index;
                if ( index<0 || index>size ) {
                        cout <<"\n invalid index";
                        return;
                }
                value = deletion(index);
                break;
            case 2:
                cout<<"\n enter value for deletion: "; cin>>value;
                index = search(value,0); // passing zero for linear search
                if (index == -1) {cout<<"\n value not present in array. "; return;}
                value = deletion(index);
                break;
            default:
                cout<<"\n invalid choice, try again! "; return;
        }
        cout<<"\n value: "<<value<<" successfully deleted from index"<<index<<", new size of array =  "<<size+1;
    }

    void search()override{
        if (isEmpty()) return;
        int value = 0, searchType=0;
        cout<<"\n enter value for searching = "; cin>>value;
        cout<<"\n enter type of search: 0 for Linear Search, 1 for Binary Search = "; cin>>searchType;
        if (searchType){
            cout<<"\n sorting data in ascending for binary search (original indexes changed) ";
            sort(0); //we used zero for ascending order sorting in our logic.
        }
        int index = search(value,searchType);
        (index == -1) ? cout<<"\n\t value not found" : cout<<"\n\t value found at index = "<<index;
    }

    void increaseCapacity()override{
        int newCapacity = 0;
        cout<<"\n enter new capacity = "; cin>>newCapacity;
        if (newCapacity<=0 || newCapacity<=capacity){
            cout<<"\n enter a number larger than "<<capacity<<" to increase current capacity ";
            return;
        }
        increaseCapacity(newCapacity);
        cout<<"\n capacity successfully increased!";
    }

    void displayData()override{
        if (isEmpty()) return;
        cout<<"\n values in array = ";
        for (int i=0; i<=size; i++)
            cout<<data[i]<<" ";
    }

    void showCapacity()override{
        cout<<"\n current capacity of array = "<<capacity;
    }

    void showSize()override{
        if (isEmpty()) return;
        cout<<"\n current size of array = "<<size+1;
    }

    void sort() override{
        if (isEmpty()) return;
        int order = 0;
        cout<<"\n Enter 0 for Ascending Order, 1 for Descending Order = ";
        cin>>order;
        sort(order);
        if (!order)
            cout<<"\n data successfully sorted in Ascending Order";
        else
            cout<<"\n data successfully sorted in Descending Order";
    }

    ~ArrayList()override{
        delete[] data;
    }

    void swapLists()override{
        // write code for creating another list (not array) and swapping the values of the two lists.
    }

    void reverseList(){
        //write code for reversing the contents of the linear list.
    }

    void mergeLists()override{
        // write code for merging two lists and storing the result in a third list.
    }

    void displayMenu(){
        cout<<"\n *****************Linear/Array List (ADT)********************\n"
        <<SHOWDATA<<" for displaying data \n"<<SHOWSIZE<<" to view current size\n"
        <<SHOWCAPACITY<<" to view current capacity \n"<<INCREASECAPACITY<<" to increase capacity of array \n"
        <<INSERTDATA<<" for insertion in linear list \n"<<DELETEDATA<<" for deletion in linear list \n"
        <<SEARCHDATA<<" for searching in linear list \n"<<SORTDATA<<" for sorting data in linear list \n"
        <<EXIT<<" to exit from program \n"
        <<"\n enter your choice = ";
        cin>>choice;
    }

    void clearMenu(){
        cout<<"\n press any key to continue ";
        _getch();
        system("cls");
    }
};

int main(){
    ArrayList linearList1(5);
    do{
            linearList1.displayMenu();
            switch(linearList1.choice){
                case SHOWCAPACITY: linearList1.showCapacity();
                    break;
                case SHOWDATA: linearList1.displayData();
                    break;
                case SHOWSIZE: linearList1.showSize();
                    break;
                case INSERTDATA: linearList1.insertion();
                    break;
                case INCREASECAPACITY: linearList1.increaseCapacity();
                    break;
                case DELETEDATA: linearList1.deletion();
                    break;
                case SEARCHDATA: linearList1.search();
                    break;
                case SORTDATA: linearList1.sort();
                    break;
                case EXIT:
                    break;
                default:
                    cout<<"\n please enter appropriate choice ";
            }
            if (linearList1.choice)
                linearList1.clearMenu();
    }while(linearList1.choice);

cout<<endl<<endl;
return 0;
}
