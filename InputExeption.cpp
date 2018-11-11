//
// Created by Wombat on 11/11/2018.
//

#include "InputExeption.h"

InputExeption::InputExeption(char *msg) {
    info = msg;
}

const char *InputExeption::what() {
    return info;
}