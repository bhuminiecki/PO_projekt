#include <iostream>
/*#include "entry.h"
#include "event.h"
#include "movie.h"*/
#include "menu.h"
int main() {
    /*Event obiekt("tutaj");
    obiekt.setLenght(60);
    obiekt.setRating(2.5);
    obiekt.addTag("haha");
    obiekt.addTag("hehe");
    obiekt.showStatistics();
    obiekt.removeTag("huhu");
    obiekt.removeTag("haha");
    obiekt.showStatistics();*/

    Pool pool = Pool();
    Menu menu = Menu();
    while(menu.displayMenu(pool));
    return 0;
}