#include<iostream>
using namespace std;

bool is_same_num(int, int,int);
void largest_digit(int , int, int);
int main() {
	int num1,num2,num3;
	cin>> num1 >> num2 >> num3;
	if (is_same_num(num1,num2,num3)) cout<<"All numbers are same"<<endl;
	else largest_digit(num1,num2,num3);
	return 0;
}

bool is_same_num(int a, int b,int c) {
	if(a == b && a == c) return true;
	else return 0;
}

void largest_digit(int x, int y, int z) {
	int count_x = 0,count_y = 0, count_z = 0, a = x , b =y ,c =z;
	while (x != 0) {
		x /= 10;
		count_x++;
	}
	while (y != 0) {
		y /= 10;
		count_y++;
	}
	while (z != 0) {
		z /= 10;
		count_z++;
	}
	if (x = 0) count_x = 1;
	if (y = 0) count_y = 1;	
	if (z = 0) count_z = 1;

	if (count_x > count_y && count_x > count_z) cout<<a<<" is the largest number"<<endl;
	if (count_y > count_z && count_y > count_x) cout<<b<<" is the largest number"<<endl;
	if (count_z > count_x && count_z > count_y) cout<<c<<" is the largest number"<<endl;		
	
	else cout<<"All numbers have same digit count"<<endl;
}