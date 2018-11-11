#ifndef PO_PROJEKT_SERIES_H
#define PO_PROJEKT_SERIES_H

#include "entry.h"

class Series : public Entry{
private:
public:
    using Entry::Entry;

    void setEpisodes(int a);

    int showEpisodes();
};


#endif //PO_PROJEKT_SERIES_H
