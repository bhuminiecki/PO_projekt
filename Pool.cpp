//
// Created by Wombat on 11/11/2018.
//

#include "Pool.h"

using namespace std;

void Pool::addEntry(Entry *entry) {
    entries.push_back(entry);
}

void Pool::removeEntry(string name) {
    try {
        for (int i = 0; i < entries.size(); i++) {
            string temp=entries[i]->showTitle();
            if (temp.compare(name) == true) {
                delete entries[i];
                entries.erase(entries.begin() + 1);
                return;
            }
        }
        throw invalid_argument("entry didn't match any of the current ones");
    } catch (const invalid_argument is) {
        cerr << "Invalid argument: " << is.what();
    }
}

Pool operator+=(Pool x, Entry entry) {
    x.addEntry(&entry);
}

Pool operator+=(Pool x, string name){
    x.removeEntry(name);
}