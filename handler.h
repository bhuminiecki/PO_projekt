#ifndef PO_PROJEKT_POOL_H
#define PO_PROJEKT_POOL_H

#include <iostream>
#include <vector>
#include <string>

template<class T>
class Handler {
private:
    T object;
    std::string name;
public:
    Handler(std::string name) {
        object(name);
    }

    ~Handler() {
        delete object;
    }
};


#endif //PO_PROJEKT_POOL_H
