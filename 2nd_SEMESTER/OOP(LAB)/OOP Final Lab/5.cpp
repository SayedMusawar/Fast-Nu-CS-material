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