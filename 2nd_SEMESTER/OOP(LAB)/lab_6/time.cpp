#include<iostream>
#include "time.h"
using namespace std;

Time::Time() {
    hour = 0;
    minute = 0;
    second = 0;
}
void Time::setTime(int h, int m, int s) {
    hour = (h>=0 && h<24) ? h:0;
    minute = (m>=0 && m<60)? m:0;
    second = (s>=0 && s<60)?s:0;

}
void Time::printTime() {
    if( hour < 10) cout<<"0"<<hour<<":";
    else cout<<hour<<":";
    if( minute < 10) cout<<"0"<<minute<<":";
    else cout<<minute<<":";
    if( second < 10) cout<<"0"<<second<<":";
    else cout<<second<<":";
    cout<<endl;
}
void Time::showTime() {
    if (hour == 0 || hour == 12) {
        hour = 12;

        cout << hour << ":";
    }

    else {
        cout << hour % 12 << ":";
    }
    if (minute < 10) {
        cout << "0" << minute << ":";
    }
    else {
        cout << minute << ":";
    }
    if (second < 10) {
        cout << "0" << second << ":";
    }
    else {
        cout << second << ":";
    }
    if (hour < 12) {
        cout << "AM";
    }
    else {
        cout << "PM";
    }
}