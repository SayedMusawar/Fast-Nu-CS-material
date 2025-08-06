#include <iostream>
using namespace std;
class Time
{
private:
    int hour, minute, second;

public:
    Time();
    void setTime(int h, int m, int s);

    void printTime();
    void showTime();
};