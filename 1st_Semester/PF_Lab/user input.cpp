#include<stdio.h>
#include<stdbool.h>

int main() {
	float num1;
	float num2;
	float result;
	
	int Num1;
	int Num2;
	int Result;
	
	printf("Enter your 1st float number\n");
	scanf("%f",&num1);
	printf("Enter your 2nd float number\n");
	scanf("%f",&num2);
	result = num1 + num2;
	printf("Sum of two float numbers is: %f \n", result);
	
	printf("\n\n\n ************ \n\n\n");

	printf("Enter your 1st integer number\n");
	scanf("%d",&Num1);
	printf("Enter your 2nd integer number\n");
	scanf("%d",&Num2);
	Result = Num1 - Num2;
	printf("Subtraction of two integer numbers is: %d", Result);

	return 0;
}