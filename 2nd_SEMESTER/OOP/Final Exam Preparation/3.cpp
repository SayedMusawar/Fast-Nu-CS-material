#include<iostream>
using namespace std;
class Time{
private:
    int hours,minutes,seconds;
public: 
    Time(int hours = 0,int minutes = 0,int seconds = 0) : hours(hours),minutes(minutes), seconds(seconds) {}

    Time operator+(Time &C) {
        return Time(hours + C.hours,minutes + C.minutes, seconds +  C.seconds);
    }
    friend ostream& operator<<(ostream& out,Time& C);
 };
 ostream& operator<<(ostream& out, Time& C) {
    out<<"Hours: "<<C.hours<<" Minutes: "<<C.minutes<<" seconds: "<<C.seconds<<endl;
    return out;
 }
int main() {
    Time t1(12,59,59);
    Time t2(4,40,1);
    Time t3;
    t3 = t1 + t2;
    cout<<t3;
}