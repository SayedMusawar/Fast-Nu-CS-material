#include <iostream>
using namespace std;


void foo(int);
void foo2(int&);
void foo3(int*);
void foo4(int*);
int main()
{


 int x = 10; //x = 10;
 cout << "Value of x is " << x << endl; // 10;
 int& y = x; // y = 10;

 cout << "Address of y is " << &y << endl; 
 cout << "Address of x is " << &x << endl;

 int* z; // z is a pointer
 z = &x; // z has address of x
 cout << "Value of z is " << z << endl; // address of a;

 cout << "Value pointed to z is " << *z << endl; // 10
  cout << *z++; // 10
 cout << "Value of x is " << x << endl; // 10
 // return 0;
 foo(x); // 10
 cout << "Afer pass by value, x is " << x << endl; // 10

 foo2(x);
 cout << "Afer pass by reference using aliases, x is " << x << endl;

 foo3(&x); // 10
 cout << "Afer pass by reference using pointers, x is " << x << endl; // 11

 int arr[3]={1,2,3};
 foo4(arr);
 for(int i=0;i<3;i++)
  cout << arr[i] << " ";
cout << endl;
 return 0;
}

void foo(int y)
{
 y++;
}
void foo2(int& y)
{
 y++; // 
}

void foo3(int* p)
{
 (*p)++;

}

void foo4(int* p)
{
 for(int i=0;i<3;i++)
  *(p+i) *= 2;

}