/*
* The emulator drives the CPU 
* */
#include <iostream>

#include "scelbi.hpp"

int main() {
    RAM ram{00,01,02,03,04,05,06,010};
    CPU intel8008;
    auto *scelbi = new Scelbi(intel8008, ram);
    scelbi->reset();
}