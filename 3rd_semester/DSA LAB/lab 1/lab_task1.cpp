#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

class Inventory{
private:
    int size;
    // float avg;
    int* arr;
public:
    Inventory() {
        cout<<"Enter the size";
        cin >> size;
        // size = sz;
        arr = new int[size];
        for(int i = 0; i < size; i++) {
            // *(arr + i) = (rand() % 100) + 1;
            *(arr + i) = i+1;
        }
    }

    float avg() {
        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += *(arr + i);
        }
        return sum / size;
    }

    int criticalProducts() {
        int count = 0;
        for(int i = 0; i < size; i++) {
            if(*(arr + i) < avg()) count++;
        }
        return count++;
    }

    int findTopSellingProduct() {
        int topSell = *arr;
        for(int i = 0 ; i < size; i++) {
            if(*(arr + i) < topSell) topSell = *(arr + i);
        }
        return topSell;
    }

    int findSecondBestSeller() {
        int top = findTopSellingProduct();
        int second = *arr;


        
        for(int i = 0; i < size; i++) {
            if(*(arr + i) < second && *(arr+i) < top) second = *(arr+i);
        }
        return second;
    }

    void sortByPopularity() {
        for(int i = 0; i< size ; i++) {
            for(int j = 0; j < size; j++) {
                if(*(arr + i) > *(arr + j)) {
                    int temp = *(arr+i);
                    *(arr+i) = *(arr+j);
                    *(arr+j) = temp;
                }
            }
        }
        cout<<"Sorted array is: "; 
        for(int i = 0; i < size; i++) {
            cout<<*(arr + i)<<" ";
        }
    }

    ~Inventory() {
        delete arr;
    }
};
int main() {
    srand(time(0));
    Inventory I1;
    cout<<"Average Stock level of inventory is: "<<I1.avg()<<endl;
    
    cout<<"Number of critical products are: "<<I1.criticalProducts()<<endl;

    cout<<"Top Selling product is: "<<I1.findTopSellingProduct()<<endl;

    cout<<"Second most top selling product is:" << I1.findSecondBestSeller()<<endl;

    I1.sortByPopularity();
}