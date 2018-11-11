#include <iostream>
#include "entry.h"

int main() {
    Entry obiekt("twoja stara");
    obiekt.setLenght(60);
    obiekt.setRating(2.5);
    obiekt.addTag("haha");
    obiekt.addTag("hehe");
    obiekt.showStatistics();
    obiekt.removeTag("huhu");
    obiekt.removeTag("haha");
    obiekt.showStatistics();
    return 0;
}