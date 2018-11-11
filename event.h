#ifndef PO_PROJEKT_EVENT_H
#define PO_PROJEKT_EVENT_H

#include "entry.h"
#include <ctime>

class Event : public Entry
{
private:
    tm *date;
public:
    Event(std::string name):Entry(name){
        time_t temp=0;
        date = localtime(&temp);
    }
    void showDate();
    void addDate(int min,int hour, int day, int month, int year);
    time_t showTime();
    void showStatistics();
};


#endif //PO_PROJEKT_EVENT_H
