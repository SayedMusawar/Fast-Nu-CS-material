#include<iostream>
using namespace std;


void display_room() {
	int rooms[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<"Available rooms: ";
	for(int i = 0; i <10; i++) cout<<rooms[i]<<" ";
}

void book_room() {
	int num,count1 = 0,count2 = 0,count3 = 0,count4 = 0,count5 = 0,count6 = 0,count7 = 0,count8 = 0,count9 = 0,count10 = 0;
	cout<<"Enter room to book (1-10)"<<endl<<"Press 0 to exit"<<endl;
	cin>>num;
	while (num != 0) {
		switch(num) {
			case 1:
				if (count1 == 0) {
					cout<<"Room 1 has been successfully booked"<<endl;
					count1++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 2:
				if (count2 == 0) {
					cout<<"Room 2 has been successfully booked"<<endl;
					count2++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 3:
				if (count3 == 0) {
					cout<<"Room 3 has been successfully booked"<<endl;
					count3++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 4:
				if (count4 == 0) {
					cout<<"Room 4 has been successfully booked"<<endl;
					count4++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 5:
				if (count5 == 0) {
					cout<<"Room 5 has been successfully booked"<<endl;
					count5++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 6:
				if (count6 == 0) {
					cout<<"Room 6 has been successfully booked"<<endl;
					count6++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 7:
				if (count7 == 0) {
					cout<<"Room 7 has been successfully booked"<<endl;
					count7++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 8:
				if (count8 == 0) {
					cout<<"Room 8 has been successfully booked"<<endl;
					count8++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 9:
				if (count9 == 0) {
					cout<<"Room 9 has been successfully booked"<<endl;
					count9++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			case 10:
				if (count10 == 0) {
					cout<<"Room 10 has been successfully booked"<<endl;
					count10++;
				}
				else {
					cout<<"This room has already booked"<<endl;	
				}
			break;
			default:
				cout<<"Enter invalid Input"<<endl;
			break;
		}
		cout<<"Are you want to book another room"<<endl;
		cin>>num;
	}
	
}

int main () {
	int choice;
	cout<<"*****Room Booking Management System*****"<<endl;
	cout<<"1. Display Rooms"<<endl<<"2. Book Rooms"<<endl<<"3. Exit"<<endl;
	
	cout<<"Enter your choice:"<<endl;
	cin>>choice;
	
	if(choice == 1) display_room();
	else if (choice == 2) book_room();
	else if(choice == 3) cout<<"Thanks for booking our hotel rooms"<<endl;
	
	return 0;
}
