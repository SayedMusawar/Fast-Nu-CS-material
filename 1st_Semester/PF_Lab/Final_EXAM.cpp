#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
/*
Question 1
void area(int s) {
	int area = s * s;
	cout<<"Area of Square: "<<area<<endl;
}

void area(int l ,int w) {
	int area = l * w;
	cout<<"Area of rectangle: "<<area<<endl;
}

int main() {
	int side;
	cout<<"Enter the side lenth of the square"<<endl;
	cin>>side;
	
	if(side < 0) {
		cout<<"Invalid input. Side length must be a positive number.Converting to positive"<<endl;
		side *= -1;
	}
	
	
	int length , width;
	cout<<"Enter the length and width of the length"<<endl;
	cin>>length >> width;
	
	
	
	if(length < 0) {
		cout<<"Invalid input. Length must be a positive number.Converting to positive"<<endl;
		length *= -1;
	}
	
	if(width < 0) {
		cout<<"Invalid input. Width must be a positive number.Converting to positive"<<endl;
		width *= -1;
	}
	area(side);
	area(length, width);
	return 0;
} */

/* Question 3
void symmetric(int arr[2][2]) {
	// Initialize array
	for (int i = 0; i < 2; i++) {
		for(int j = 0; j <2; j++) {
			cin>>arr[i][j];
		}
	}
	
	
	int trans[2][2] = {0};
	
	for (int i = 0; i < 2; i++) {
		for(int j = 0; j <2; j++) {
			if (i == j ) {
				trans[i][j] = arr[i][j];
			}
			if(i != j) {
				trans[i][j] = arr[j][i];
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if(arr[i][j] == trans[i][j]) {
				count++;
			}
		}
		cout<<endl;
	}	
	if(count == 4) cout<<"Symmetric Matrix"<<endl;
	else cout<<"Not Symmetric Matrix"<<endl;
	
}

int main () {
	
	int arr[2][2];
	symmetric(arr);
	
	return 0;
} */

// Q2
/*
void removech(char *ch) {
	for(int i = 0; i < 50 ; i++) {
		cin>>ch[i];
	}
	for(int i = 0, j = i +1; i < 50 , j < 50; i++,j++) {
		if(ch[i] == ch[j]) {
			
		}
	}
	if(ch == "") cout<<"Empty string"<<endl;
	cout<<ch;
}

int main() {
	char ch[50] = {0};
	// 97 123
	removech(ch);
	return 0;
} */

/*
void reverse(int arr[], int arr2[]) {
//	if (arr < 5) return 0;
	
	for (int i = 1,j = 3; j> 0,i < 5; j--,i+=2) {
		arr2[i] = arr[j];
	}
	for(int i = 0; i < 2; i++) {
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
	
	
}
int main() {
	int arr[5] = {5,10,30,0,2};
	int arr2[5];
	reverse(arr, arr2);
	return 0;
} */
/*
int main() {
	srand(time(0));
	char pass[] = "";
	char sp_ch[] = {'@','#','$','%','!','|','-','+'};
	char dig[] = {'1','2','3','4','5','6','7','8','9','0'};
	int user_otp,sp_ch_count = 0,dig_count = 0;
	char new_pass[] = "",confirm_pass[] = "" ;
	cout<<"Enter your old password"<<endl;
	cin>>pass;
	int otp = rand() % 10000;
	cout<<otp<<endl;
	cout<<"Please enter your 4 digits otp"<<endl;
	cin>>user_otp;
	
	if(user_otp == otp) {
		cout<<"Enter new password"<<endl;
		cin>>new_pass;
		
		for (int i = 0; i != '\0'; i++) {
				if(new_pass[i] == sp_ch[i]) sp_ch_count = 1;
				if(new_pass[i] == dig[i]) dig_count = 1;	
		if(sp_ch_count == 1 && dig_count== 1) {
			cout<<"Confirm your password"<<endl;
			cin>>confirm_pass;
			
			if(confirm_pass == new_pass) {
				cout<<"Your password is created successfully"<<endl;
			}
		}
	} else cout<<"OTP not same"<<endl;
	
	
} */








































