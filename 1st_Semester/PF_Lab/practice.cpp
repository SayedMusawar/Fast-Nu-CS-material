#include<iostream>
using namespace std;
int main()
{
    int start_num = 10, end_num = 50;
    int size = (end_num - start_num) / 2 + 1;
	int* flexible_array = new int[size];
	for (int i = 0, num = start_num; num <= end_num; i++) {
        flexible_array[i] = num;

	}

	for(int i = 0; i < size; i++) {
        cout<<flexible_array[i]<<" ";
	}


	delete[]flexible_array;
	flexible_array = nullptr;
	return 0;
}
