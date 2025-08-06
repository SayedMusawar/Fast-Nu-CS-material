#include<iostream>
using namespace std;
int main()
{
	char password[] = "1234#Labcd";
	char special_ch[] = "!@#$%^&*()<>?";
	int index = 0, level = 0;
	bool is_first_time = true, flag = false;
	char find;
	
	while (password[index] != '\0') {
		int second_index = 0;
		
		while (special_ch[second_index] != '\0') {
			
			if (is_first_time) {
				
				if (password[index] == special_ch[second_index]) {
					flag = true;
					is_first_time = false;
					find = special_ch[second_index];
				}
			}
			second_index++;
		}
		index++;
	}
	cout<<find<<endl;
	return 0;
}