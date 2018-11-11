#include "menu.h"

int main() {
    Pool pool = Pool();
    fstream file("baza");
    if (!file.good()) {
        file.open("baza", ios::trunc);
        file.close();
    }
    pool.load();
    Menu menu = Menu();
    while (menu.displayMenu(pool));
    return 0;
}