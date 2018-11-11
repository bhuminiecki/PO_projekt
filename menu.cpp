//
// Created by Wombat on 11/11/2018.
//

#include "menu.h"

using namespace std;

void Menu::creationMenu(Pool pool) {
    cout << "----------------------+CREATOR+----------------------" << endl;
    cout << "specify whether you'd like to create a 'movie','series' or 'event' entry" << endl;
    string entryType;
    cin >> entryType;
    Handler <Movie> movieCreator();

    //switch(stoi(entryType)){
    //case stoi("movie"):

}

void Menu::removeMenu(Pool pool) {
    cout << "----------------------+REMOVE+----------------------" << endl;
    cout << "type in the title you want to delete" << endl;
    string name;
    cin >> name;
    try {
        for (int i = 0; i < pool.entries.size(); i++) {
            if (pool.entries[i]->title.compare(name) == true) {
                pool-=name;
                return;
            }
        }
        throw invalid_argument("there is no such entry");
    } catch (const invalid_argument is) {
        cerr << "Invalid argument: " << is.what();
    }
}

void Menu::displayMenu(Pool pool) {
    cout << "----------------------+DISPLAY+----------------------" << endl;
    cout << "type in the title you want to view" << endl;
    string name;
    cin >> name;
    try {
        for (int i = 0; i < pool.entries.size(); i++) {
            if (pool.entries[i]->title.compare(name) == true) {
                pool.entries[i]->showStatistics();
                return;
            }
        }
        throw invalid_argument("there is no such entry");
    } catch (const invalid_argument is) {
        cerr << "Invalid argument: " << is.what();
    }
}

void Menu::displayMenu(Pool pool) {
    cout << "----------------------+REMOVE+----------------------" << endl;
    cout << "type in:\n1 - to add an entry\n2 - to remove an entry";
    int x;
    switch(x){
        case 1:
            creationMenu(pool);
            break;
        case 2:
            removeMenu(pool);
            break;
        default:
            throw(invalid_argument("wrong option"));
    }
}