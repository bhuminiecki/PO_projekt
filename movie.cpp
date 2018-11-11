#include "movie.h"

using namespace std;

void Movie::setRanking(int a) {
    ranking = a;
}

int Movie::showRanking() {
    return ranking;
}

void Movie::showStatistics() {
    Entry::showStatistics();
    cout << "Ranking: " << ranking << endl;
}