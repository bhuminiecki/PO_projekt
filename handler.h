#ifndef PO_PROJEKT_HANDLER_H
#define PO_PROJEKT_HANDLER_H

using namespace std;

template<class T>
class Handler {
    private:
        T* object;
    public:
        explicit Handler(string name) {
            object = new T(name);
        }

        ~Handler() {
            delete object;
        }
};

#endif