#include "Pool.h"

using namespace std;

void Pool::addEntry(Entry *entry) {
    entries.push_back(entry);
}

void Pool::removeEntry(string name) {
    try {
        for (int i = 0; i < entries.size(); i++) {
            string temp = entries[i]->showTitle();
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

Pool operator+=(Pool x, Entry *entry) {
    x.addEntry(entry);
}

Pool operator-=(Pool x, std::string name) {
    x.removeEntry(name);
}

Pool::~Pool() {
    entries.erase(entries.begin(),entries.end());
}

Pool::Pool() {}

void Pool::save() {
    ofstream file;
    file.open("baza", ios::binary | ios::trunc);
    for (int i = 0; i < entries.size(); i++) {
        file.write((char*)entries[i],sizeof(Entry)+8);
    }
    file.close();
}

void Pool::load() {
    ifstream file;
    Entry temp("temp");
    file.open("baza", ios::binary);
    while (!file.eof()) {
        file.read(temp,sizeof(Entry)+8);
        entries.push_back(&temp);
    }
    file.close();
}
