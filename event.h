#ifndef PO_PROJEKT_EVENT_H
#define PO_PROJEKT_EVENT_H

#include "entry.h"
#include <ctime>
#include "InputExeption.h"

class Event : public Entry {
private:
public:
    using Entry::Entry;

    void showDate();

    void addDate(int min, int hour, int day, int month, int year);

    time_t showTime();

    void showStatistics();
};


#endif //PO_PROJEKT_EVENT_H
