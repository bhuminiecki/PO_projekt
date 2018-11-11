#ifndef PO_PROJEKT_INPUTEXEPTION_H
#define PO_PROJEKT_INPUTEXEPTION_H

#include <exception>

class InputExeption : public std::exception {
private:
    const char *info;
public:
    InputExeption(char *msg);

    const char *what();
};


#endif //PO_PROJEKT_INPUTEXEPTION_H
