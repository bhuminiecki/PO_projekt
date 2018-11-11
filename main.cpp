#include "menu.h"

int main() {
    Pool pool = Pool();
    pool.load();
    Menu menu = Menu();
    while (menu.displayMenu(pool));
    return 0;
}