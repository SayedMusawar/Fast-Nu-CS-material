#include<iostream>
using namespace std;
class Arr{
private:
    int size;
    int* arr;
public:
    Arr(int sz) {
        size  = sz;
        arr = new int[size];
        cout<<"enter values ";
        for(int i = 0; i< size; i++) cin >> arr[i];
    }

    ~Arr() {
        delete arr;
    }
    bool descending() {
        int count = 0;
        int* des = new int[size];
        for(int i = 0; i < size; i++) {
            des[i] = arr[i];
        }
        for(int i = 0; i< size ; i++) {
            for(int j = 0; j < size; j++) {
                if(*(des + i) > *(des + j)) {
                    int temp = *(des+i);
                    *(des+i) = *(des+j);
                    *(des+j) = temp;
                }
            }
        }
        for(int i = 0; i < size; i++) {
            if(arr[i] == des[i]) count++;
        }
        if(count == size) return true;
        else return false;
    }
    bool ascending() {
        int count = 0;
        int* aes = new int[size];
        for(int i = 0; i < size; i++) {
            aes[i] = arr[i];
        }
        for(int i = 0; i< size ; i++) {
            for(int j = 0; j < size; j++) {
                if(*(aes + i) < *(aes + j)) {
                    int temp = *(aes+i);
                    *(aes+i) = *(aes+j);
                    *(aes+j) = temp;
                }
            }
        }
        for(int i = 0; i < size; i++) {
            if(arr[i] == aes[i]) count++;
        }
        if(count == size) return true;
        else return false;
    }
};
int main() {
    Arr a1(5);
    if(a1.descending()) cout<<"it is in descending order"<<endl;
    else if(a1.ascending()) cout<<"It is in aescending order"<<endl;
    else cout<<"It is neither aescending nor descending"<<endl;
}