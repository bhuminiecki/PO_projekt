//
// Created by Wombat on 11/11/2018.
//

#ifndef PO_PROJEKT_SERIES_H
#define PO_PROJEKT_SERIES_H

#include "entry.h"

class Series : public Entry{
private:
    int numberOfEpisodes;
public:
    using Entry::Entry;
    void setEpisodes(int a);
    int showEpisodes();
};


#endif //PO_PROJEKT_SERIES_H
