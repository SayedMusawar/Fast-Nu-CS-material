#include <iostream>
#include "time.h"
using namespace std;

int main() {
    TimeHandler* clock = new TimeHandler();
    
    clock->updateTime(15, 30, 45);

    cout << "24-hour clock: ";
    clock->display24Hour();
        
    cout << "12-hour clock: ";
    clock->display12Hour();
    
    delete clock;
    return 0;
}