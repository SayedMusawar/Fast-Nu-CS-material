#include<iostream>
using namespace std;
class StringHolder{
    private:
    char* a;
    public:
    StringHolder() {
        a = new char;
    }
    ~StringHolder() {
        delete a;
        cout<<"StringHolder Destroyed"<<endl;
    }
};
int main() {
    return 0;
}