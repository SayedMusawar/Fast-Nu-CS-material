#include<iostream>
using namespace std;
struct address {
    string city;
    string country;
};
struct contact_info {
    string name;
    long long phone_no;
    address addr;
};
int main() {
    contact_info p1;
    contact_info p2;

    p1.name = "Musawar";
    p1.phone_no = 03000000000LL;
    p1.addr.city ="XYZ";
    p1.addr.country = "Pakistan";

    p2.name = "John doe";
    p2.phone_no = 03000000000LL;
    p2.addr.city ="ABC";
    p2.addr.country = "Pakistan";

    cout<<"Person 1:"<<endl;
    cout<<"NAME: "<<p1.name<<endl;
    cout<<"Phone no: "<<p1.phone_no<<endl;
    cout<<"City: "<<p1.addr.city<<endl;
    cout<<"Country: "<<p1.addr.country<<endl;

    cout<<endl<<endl;

    cout<<"Person 2:"<<endl;
    cout<<"NAME: "<<p2.name<<endl;
    cout<<"Phone no: "<<p2.phone_no<<endl;
    cout<<"City: "<<p2.addr.city<<endl;
    cout<<"Country: "<<p2.addr.country<<endl;
    return 0;
}