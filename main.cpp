#include "menu.h"

int main() {
    Pool pool = Pool();
    pool.load();
    Menu menu = Menu();
    menu.displayMenu(pool);
    return 0;
}