#include<iostream>
using namespace std;
class TimeHandler {
private:
    int timeHours;
    int timeMinutes;
    int timeSeconds;

public:
    TimeHandler();
    bool updateTime(int hrs, int mins, int secs);
    void display24Hour();
    void display12Hour();
};