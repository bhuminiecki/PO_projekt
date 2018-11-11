#include "InputExeption.h"

InputExeption::InputExeption(char *msg) {
    info = msg;
}

const char *InputExeption::what() {
    return info;
}