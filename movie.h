#ifndef PO_PROJEKT_MOVIE_H
#define PO_PROJEKT_MOVIE_H

#include "entry.h"

class Movie : public Entry
{
private:
    int ranking;
public:
    using Entry::Entry;
    void setRanking(int a);
    int showRanking();
    void showStatistics();
};


#endif //PO_PROJEKT_MOVIE_H
