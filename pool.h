#ifndef PO_PROJEKT_POOL_H
#define PO_PROJEKT_POOL_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "handler.h"
#include "entry.h"
#include "movie.h"
#include "event.h"
#include "series.h"
#include <fstream>

class Pool {
private:
public:
    std::vector <Entry *> entries;
    Pool();
    ~Pool();
    void addEntry(Entry *entry);
    void removeEntry(std::string name);
    friend Pool operator+=(Pool x, Entry *entry);
    friend Pool operator-=(Pool x, std::string name);
    void save();
    void load();
};


#endif //PO_PROJEKT_POOL_H
