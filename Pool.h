//
// Created by Wombat on 11/11/2018.
//

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


class Pool {
private:
    std::vector <Entry *> entries;
public:
    Pool();
    ~Pool();
    void addEntry(Entry *entry);
    void removeEntry(std::string name);
    friend Pool operator+=(Pool x, Entry entry);
    friend Pool operator-=(Pool x, std::string name);
};


#endif //PO_PROJEKT_POOL_H
