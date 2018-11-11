#ifndef PO_PROJEKT_POOL_H
#define PO_PROJEKT_POOL_H

using namespace std;

class Movie {
public:
    Movie(string& name)
    {
        cout << "Created a Movie: " << name << endl;
    }

};

class Series {
public:
    Series(string& name)
    {
        cout << "Created a Series: " << name << endl;
    }
};

class Event {
public:
    Event(string& name)
    {
        cout << "Created an Event: " << name << endl;
    }
};

template<class T>
class Handler {
    private:
        T* object;
    public:
        Handler(string name) {
            object = new T(name);
        }

        ~Handler() {
            delete object;
        }
};

class Menu {
public:
    static void creationMenu();
};


#endif //PO_PROJEKT_POOL_H