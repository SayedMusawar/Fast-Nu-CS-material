#include<iostream>
using namespace std;
class RemoveDupli{
private:
    int size;
    int* arr;
    int* newarr;
    int newSize;
public:
    RemoveDupli() : size(7), newSize(0) {
        arr = new int[size];
        newarr = new int[newSize];
        cout<<"Enter the values: ";
        for(int i = 0; i < size ; i++) cin >> *(arr + i);
    }

    void sortArr() {
        for(int i = 0; i < size; i++) {
            for(int j = i+1; j < size; j++) {
                if(*(arr+i) > *(arr+j)) {
                    int temp = *(arr+i);
                    *(arr+i) = *(arr+j);
                    *(arr+j) = temp;
                }
            }
        }
    }

    void removeDupli() {
        for(int i = 0; i < size; i++) {
            if (i == 0) *(newarr + newSize++) = *(arr +i) ;
            else if (*(arr+ i) != *(arr + i-1)) *(newarr + newSize++) = *(arr+ i);
        }
    }
    void display() {
        cout << "Updated sorted Array: ";
        for(int i = 0; i < newSize; i++) {
            cout << *(newarr+ i);
            if(i != newSize-1) cout << " ";
        }
    }
};

int main() {
    RemoveDupli R1;
    R1.sortArr();
    R1.removeDupli();
    R1.display();

    return 0;
}
