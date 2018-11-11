#ifndef PO_PROJEKT_MENU_H
#define PO_PROJEKT_MENU_H

#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include "InputExeption.h"
#include "pool.h"
#include "handler.h"


class Menu {
private:
public:
    float calculateFitness(std::string name);
    void creationMenu(Pool pool);
    void removeMenu(Pool pool);
    void showMenu(Pool pool);
    void displayMenu(Pool pool);
    void showUpcoming(Pool pool);
    void editEntry(Pool pool);
    void suggest(Pool pool);
};


#endif //PO_PROJEKT_MENU_H
