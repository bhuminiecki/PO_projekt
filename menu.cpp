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
        Handler<Movie> movieCreator = Handler<Movie>(title);
        pool.addEntry(movieCreator.getObject());
    } else if (entryType == "series") {
        Handler<Series> seriesCreator = Handler<Series>(title);
        pool.addEntry(seriesCreator.getObject());
    } else if (entryType == "event") {
        Handler<Event> eventCreator = Handler<Event>(title);
        pool.addEntry(eventCreator.getObject());

    }

}

void Menu::removeMenu(Pool pool) {
    cout << "----------------------+REMOVE+----------------------" << endl;
    cout << "type in the title you want to delete" << endl;
    string name;
    cin >> name;
    try {
        for (int i = 0; i < pool.entries.size(); i++) {
            if ((pool.entries[i]->showTitle()).compare(name) == true) {
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

void Menu::showUpcoming(Pool pool) {
    time_t now = time(0);
    cout << "There are following events in less than 3 days from now:" << endl;
    for (int i = 0; i <= pool.entries.size(); i++) {

        if (((pool.entries[i]->showTime() - now) >= 0) && ((pool.entries[i]->showTime() - now) < 259200)) {
            cout << pool.entries[i]->showTitle() << endl;
        }
    }
}



bool Menu::displayMenu(Pool pool) {
    cout << "----------------------+MENU+----------------------" << endl;
    cout << "type in:\n1 - to add an entry\n2 - to remove an entry\n3 - to see an entry\n4 - show upcoming\n 10- close";
    int x;
    cin >> x;
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
        case 4:
            showUpcoming(pool);
            break;

        case 10:
            pool.save();
            return false;
        default:
            throw (invalid_argument("wrong option"));
    }
    return true;
}

