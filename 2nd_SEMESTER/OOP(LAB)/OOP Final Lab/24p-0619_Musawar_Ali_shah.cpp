#include<iostream>
using namespace std;
/*Q1
class PaymentMethod{

public:
	virtual void processPayment(float amount, float tranAmount) = 0;
};

class CreditCardPayment : public PaymentMethod{
private:
	float amount;
public:
	void processPayment(float amount, float tranAmount) override {
		// cout<<"Enter the transection amount"<<endl;
		// cin >> tranAmount;
		float tax = tranAmount * 0.02;
        float remainingAmount = amount - tranAmount - tax;
        cout << "Payment successful with 2% tax deduction." << endl;
        cout << "Remaining balance: Rs. " << remainingAmount << endl;
	}
};

class PayPalPayment: public PaymentMethod{
private:
	float amount;
public:
	void processPayment(float amount, float tranAmount) override {
		// cout<<"Enter the transection amount"<<endl;
		// cin >> tranAmount;
		float remainingAmount = amount - tranAmount - 200;
		cout<<"Payment success with tax deduction of Rs.200 :"<<endl;
		cout<<"Remaining balance is: "<<remainingAmount<<endl;
	}
};

class BankTransferPayment: public PaymentMethod {
private:
	float amount;
public:
	void processPayment(float amount, float tranAmount) override {
		// cout<<"Enter the transection amount"<<endl;
		// cin >> tranAmount;
		float remainingAmount = amount - tranAmount - 200;
		cout<<"Payment success"<<endl;
	}	
};

int main() {
    PaymentMethod *p;
    int choice;
    float userBalance = 5000, transactionAmount;

    cout << "Please select a payment method:\n";
    cout << "1. Credit Card Payment\n";
    cout << "2. PayPal Payment\n";
    cout << "3. Bank Transfer Payment\n";
    cin >> choice;

    cout << "Enter the transaction amount: ";
    cin >> transactionAmount;
	if(transactionAmount > 0) {
		switch(choice) {
			case 1:
				p = new CreditCardPayment();
				break;
			case 2:
				p = new PayPalPayment();
				break;
			case 3:
				p = new BankTransferPayment();
				break;
			default:
				cout << "Invalid choice.\n";
			break;
		}
	}

    p->processPayment(userBalance, transactionAmount);
    delete p;

    return 0;
} */

/*
Q2
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
		delete id;
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

*/

/*
Q3
#include<iostream>
using namespace std;

class Complex{
private:
	int real,imag;
public:
	Complex(int real = 0,int imag = 0) {
		this->real = real;
		this->imag = imag;
	}
	Complex operator +(Complex &C) {
		return (real + C.real, imag + C.imag);
	}
	void display() {
		cout<<"Sum is: "<<real <<"+i"<<imag<<endl;
	}
};
int main() {
	Complex C1(5,6);
	Complex C2(5,4);
	Complex C3 = C1 + C2;
	C3.display();
    return 0;
}
*/

/*
Q4
#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    int marks;
public:
    Student(string name,int rollNo,int marks) {
        this->name = name;
        this->rollNo = rollNo;
        this->marks = marks;
    }
    friend class ResultProcessor;
    friend void compute(Student s);
};

class ResultProcessor {
private:
    char grade;
public:
    ResultProcessor(Student a) {
        if(a.marks >= 85 && a.marks <=100) {
            grade = 'A';
        } else if(a.marks >= 70 && a.marks < 85) {
            grade = 'B';
        }
        else if(a.marks >=50 && a.marks < 70) {
            grade = 'C';
        } else if(a.marks < 50) {
            grade ='F';
        }
        cout<<"Name: "<<a.name<<endl;
        cout<<"Roll no."<<a.rollNo<<endl;
        cout<<"Marks"<<a.marks<<endl;
        cout<<"grade"<<grade<<endl;
    }
    friend void compute(string n,int r,int m) {
        
    }
};
int main() {
    Student a("name",123,70);
    Student b("Musawar",061,99);
    Student c("a",345,50);
    ResultProcessor d(a);
    ResultProcessor e(b);
    ResultProcessor f(c);
}
*/

/*
Q5
#include<iostream>
using namespace std;
class Engine{
private:
    string type;
    bool status;
public:
    Engine(string type = "", bool status = false) {
        this->type = type;
        this->status = status;
    }
    void Start() {
        if(status == false) {
            cout<<"Engine starts now"<<endl;
            status = true;
        } else cout<<"Engine is already started"<<endl;
    }
};

class Car{
private:
    Engine engine;
public:
    Car(Engine a) : engine(a) {
        engine.Start();
    }


};
int main() {
    Engine a("Corrolla",false);
    Car b(a);
    
    return 0;
}
*/