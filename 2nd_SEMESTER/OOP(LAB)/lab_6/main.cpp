#include<iostream>
#include "time.h"
using namespace std;

int main() {
    Time *t1 = new Time();
    
    t1->setTime(13,45,39);

    cout<<"Time in 24 hour format ";
    t1->printTime();

    cout<<"Time in 12-hour format: ";
    t1->showTime();

    delete t1;
    return 0;
}