#include<iostream>
using namespace std;

class UserSystem {
private:
	static int count;
	int *id;
public:
	UserSystem(int ID = 0) {
		id = new int(ID);
		cout<<"User login successfully"<<endl;
		count++;
		
	}
	UserSystem(UserSystem &a) {
		id = new int(*(a.id));
		        cout << "User copied successfully with ID: "<<endl;
		count++;
	}
	~UserSystem() {
		cout<<"User logout successfully"<<endl;
		count--;
	}
};
int UserSystem::count = 0;
int main() {
	UserSystem A1(90);
	UserSystem A2 = A1;
	UserSystem A3;
	UserSystem A4(A3);
    return 0;
}
