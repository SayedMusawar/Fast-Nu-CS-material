#include<iostream>
using namespace std;
class PaymentMethod {
public:
    string name;
    float amount;
    PaymentMethod(float amt) : amount(amt) {}
    virtual void processPayment(float amt)  {
        amt = 0;
    }
    virtual void show() {
        cout<<"["<<name<<"] paid $"<<amount<<" successfully"<<endl;
    }
    virtual ~PaymentMethod() {}
};
class CreditCardPayment : public PaymentMethod {
public:
    CreditCardPayment() : PaymentMethod(amount) {}
    void processPayment(float amt) override {
        amount = amt;
        name = "Credit Card";
    }
    void show() override {
        cout<<"["<<name<<"] paid $"<<amount<<" successfully"<<endl;
    }
};
class PayPalPayment : public PaymentMethod {
public:
    PayPalPayment() : PaymentMethod(amount) {}
    void processPayment(float amt) override {
        amount = amt;
        name = "Paypal";
    }
    void show() override {
        cout<<"["<<name<<"] paid $"<<amount<<" successfully"<<endl;
    }
};
class BankTransferPayment : public PaymentMethod {
public:
    BankTransferPayment() : PaymentMethod(amount) {}
    void processPayment(float amt) override {
        amount = amt;
        name = "Bank Transfer";
    }
    void show() override {
        cout<<"["<<name<<"] paid $"<<amount<<" successfully"<<endl;
    }
};
int main() {
    PaymentMethod* payment = nullptr;
    int count = 0;
    int ch,choice,amount;
    do {
        cout<<"Choose one option"<<endl;
        cout<<"1. Add payment"<<endl;
        cout<<"2. Delete payment"<<endl;
        cout<<"3. Edit payment"<<endl;
        cout<<"4. View payments"<<endl;
        cout<<">"<<endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout<<"Enter the amount you want to add"<<endl;
                cin >> amount;
                cout<<"Choose payment method"<<endl;
                cout<<"1. Credit Card"<<endl;
                cout<<"2. PayPal Payment"<<endl;
                cout<<"3. Bank Transfer"<<endl;
                cout<<">"<<endl;
                cin >> choice;
                switch(choice) {
                    case 1:
                        payment = new CreditCardPayment;
                        // 
                    break;
                    case 2:
                        payment = new PayPalPayment();
                    break;
                    case 3:
                        payment = new BankTransferPayment();
                    break;
                }         
                payment->processPayment(amount);
                payment->show();
            break;
            case2:
                delete payment;
                payment = nullptr;
                cout<<"Payment deleted"<<endl;
            break;
            case 3:
                cout<<"Enter the updated amount"<<endl;
                cin >> amount;
                cout<<"Choose payment method"<<endl;
                cout<<"1. Credit Card"<<endl;
                cout<<"2. PayPal Payment"<<endl;
                cout<<"3. Bank Transfer"<<endl;
                cout<<">"<<endl;
                cin >> choice;
                switch(choice) {
                    case 1:
                        payment = new CreditCardPayment;
                        // 
                    break;
                    case 2:
                        payment = new PayPalPayment();
                    break;
                    case 3:
                        payment = new BankTransferPayment();
                    break;
                }         
                payment->processPayment(amount);
                payment->show();
            break;
            case 4:
                payment->show();
            break;
        }
        
    } while (ch > 5);
    return 0;
}