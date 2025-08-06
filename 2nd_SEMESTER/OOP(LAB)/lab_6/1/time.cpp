#include <iostream>
#include "time.h"
using namespace std;

TimeHandler::TimeHandler() {
    timeHours = 0;
    timeMinutes = 0;
    timeSeconds = 0;
}

bool TimeHandler::updateTime(int hrs, int mins, int secs) {
    bool isValid = (hrs >= 0 && hrs <= 23) && 
                   (mins >= 0 && mins <= 59) && 
                   (secs >= 0 && secs <= 59);
    
    if (isValid) {
        timeHours = hrs;
        timeMinutes = mins;
        timeSeconds = secs;
        return true;
    }
    
    cout << "Error: Invalid time values entered!" << endl;
    return false;
}

void TimeHandler::display24Hour() {
    cout << (timeHours < 10 ? "0" : "") << timeHours << "-"
         << (timeMinutes < 10 ? "0" : "") << timeMinutes << "-"
         << (timeSeconds < 10 ? "0" : "") << timeSeconds << endl;
}

void TimeHandler::display12Hour() {
    int hour12 = timeHours;
    string period = "AM";
    
    if (hour12 >= 12) {
        period = "PM";
        if (hour12 > 12) hour12 -= 12;
    }
    if (hour12 == 0) hour12 = 12;

    cout << (hour12 < 10 ? "0" : "") << hour12 << "-"
         << (timeMinutes < 10 ? "0" : "") << timeMinutes << "-"
         << (timeSeconds < 10 ? "0" : "") << timeSeconds
         << " " << period << endl;
}