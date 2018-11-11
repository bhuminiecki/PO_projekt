#ifndef PO_PROJEKT_HANDLER_H
#define PO_PROJEKT_HANDLER_H

#include <string>

using namespace std;

template<class T>
class Handler {
private:
    T *object;
public:
    explicit Handler(const string &name) {
        object = new T(name);
    }

    ~Handler() {
        delete object;
    }

    T *getObject() {
        return object;
    }
};

#endif