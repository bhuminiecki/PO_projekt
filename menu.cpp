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

    transform(entryType.begin(), entryType.end(), entryType.begin(), ::tolower);
    if ((entryType != "movie") & (entryType != "series") & (entryType != "event")) {
        throw invalid_argument("wrong type");
        return;
    }


    cout << "Alright, so you want to create a " << entryType << ". What's it's name?" << endl;
    string title;
    getline(cin, title);
    getline(cin, title);

    if (entryType == "movie") {
        Handler <Movie> movieCreator = Handler<Movie>(title);
    } else if (entryType == "series") {
        Handler <Series> seriesCreator = Handler<Series>(title);
    } else if (entryType == "event") {
        Handler <Event> eventCreator = Handler<Event>(title);
    }

    string wait;
    cin >> wait;
}

void Menu::removeMenu(Pool pool) {
    cout << "----------------------+REMOVE+----------------------" << endl;
    cout << "type in the title you want to delete" << endl;
    string name;
    cin >> name;
    try {
        for (int i = 0; i < pool.entries.size(); i++) {
            if (pool.entries[i]->showTitle().compare(name) == true) {
                pool -= name;
                return;
            }
        }
        throw invalid_argument("there is no such entry");
    } catch (const invalid_argument is) {
        cerr << "Invalid argument: " << is.what();
    }
}

void Menu::showMenu(Pool pool) {
    cout << "----------------------+DISPLAY+----------------------" << endl;
    cout << "type in the title you want to view" << endl;
    string name;
    cin >> name;
    try {
        for (int i = 0; i < pool.entries.size(); i++) {
            if (pool.entries[i]->showTitle().compare(name) == true) {
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
    cout << "----------------------+MENU+----------------------" << endl;
    cout << "type in:\n1 - to add an entry\n2 - to remove an entry\n3 - to see an entry";
    int x;
    switch (x) {
        case 1:
            try {
                creationMenu(pool);
            } catch (const invalid_argument is) {
                cerr << "Invalid argument: " << is.what();
            }
            break;
        case 2:
            removeMenu(pool);
            break;
        case 3:
            showMenu(pool);
            break;

        default:
            throw (invalid_argument("wrong option"));
    }
}

void Menu::showUpcoming(Pool pool) {

}