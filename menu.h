//
// Created by Wombat on 11/11/2018.
//

#ifndef PO_PROJEKT_MENU_H
#define PO_PROJEKT_MENU_H

#include <string>
#include <iostream>
#include "pool.h"
#include "handler.h"


class Menu {
private:
public:
    float calculateFitness(std::string name);
    void creationMenu();
    void removeMenu();
    void displayMenu();
};


#endif //PO_PROJEKT_MENU_H
