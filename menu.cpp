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

    for (int i = 0; i < pool.entries.size(); i++) {
        if ((pool.entries[i]->showTitle()).compare(name) != 0) {
            try {
                pool -= name;
                return;
            } catch (const invalid_argument is) {
                cerr << "Invalid argument: " << is.what();
            }
        }
    }
    throw invalid_argument("there is no such entry");

}

void Menu::showMenu(Pool pool) {
    cout << "----------------------+DISPLAY+----------------------" << endl;
    cout << "type in the title you want to view" << endl;
    string name;
    cin >> name;

    for (int i = 0; i < pool.entries.size(); i++) {
        if (pool.entries[i]->showTitle().compare(name) != 0) {
            pool.entries[i]->showStatistics();
            return;
        }
    }
    throw invalid_argument("there is no such entry");

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

void Menu::editEntry(Pool pool) {
    cout << "----------------------+REMOVE+----------------------" << endl;
    cout << "type in the title you want to edit\n" << endl;
    string name;
    cin >> name;

    for (int i = 0; i < pool.entries.size(); i++) {
        if ((pool.entries[i]->showTitle()).compare(name) != 0) {
            string *tag;
            string temp;
            int n;
            cin >> n;
            tag = new string[n];
            for (int j = 0; j < n; j++) {
                cin >> temp;
                tag[j] = temp;
            }
            for (int j = 0; j < n; j++) {
                pool.entries[i]->addTag(tag[i]);
            }
            int tempLenght;
            cin >> tempLenght;
            pool.entries[i]->setLenght(tempLenght);
            float tempRating;
            cin >> tempRating;
            pool.entries[i]->setRating(tempRating);
            bool wasIt;
            cin >> wasIt;
            pool.entries[i]->setWatched(wasIt);
            return;
        }
    }
    throw invalid_argument("there is no such entry");

}


void Menu::suggest(Pool pool) {
    cout << "entries rated above 8.0" << endl;
    for (int i = 0; i <= pool.entries.size(); i++) {

        if (pool.entries[i]->showRating() >= 8.0) {
            cout << pool.entries[i]->showTitle() << endl;
        }
    }
}


bool Menu::displayMenu(Pool pool) {
    cout << "----------------------+MENU+----------------------" << endl;
    cout
            << "type in:\n1 - to add an entry\n2 - to remove an entry\n3 - to see an entry\n4 - show upcoming\n5 - edit entry\n6 - suggestions\n10 - close";
    int x;
    cin >> x;
    try {
        switch (x) {
            case 1:
                creationMenu(pool);

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
            case 5:

                editEntry(pool);
                break;

            case 6:
                suggest(pool);
                break;
            case 10:
                pool.save();
                return false;
            default:
                throw (invalid_argument("wrong option"));
                break;
        }
    } catch (const invalid_argument is) {
        cerr << "Invalid argument: " << is.what();
    }

    return true;
}

