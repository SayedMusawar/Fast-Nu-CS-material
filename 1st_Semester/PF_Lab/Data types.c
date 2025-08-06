#include<stdio.h>
#include<stdbool.h>

int main() {
	char c = 'A';
	int i = 45;
	bool option = true;
	short int si = 12345;
	long int li = 1234567890;
	float f = 3.141343;
	double d = 2.728484757388384;
	unsigned int ui = 255;
	signed int sc = -10;
	unsigned int uc = 200;
	
	printf("Option is %d \n",option);
	printf("char: %c \n",c);
	printf("int: %d \n",i);
	printf("short int %d \n",si);
	printf("long int %ld \n",li);
	printf("float: %f \n",f);
	printf("double: %lf \n",d);
	printf("unsigned int: %u \n",ui);
	printf("signed int: %d \n",sc);
	printf("unsigned int: %u \n",uc);
}