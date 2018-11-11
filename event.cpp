#include "event.h"

using namespace std;

void Event::showDate() {
    cout << "Date: " << date->tm_hour << ":" << date->tm_min << " " << date->tm_mday << "/" << date->tm_mon + 1
         << date->tm_year + 1900 << endl;
}

void Event::addDate(int min, int hour, int day, int month, int year) {
    date->tm_year = year - 1900;
    date->tm_mon = month;
    date->tm_mday = day;
    date->tm_min = min;
    date->tm_hour = hour;
}

time_t Event::showTime() {
    time_t result = mktime(date);
    return result;
}

void Event::showStatistics() {
    Entry::showStatistics();
    this->showDate();
}
