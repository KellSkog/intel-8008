# intel-8008
An FPGA implementaton of 1972 Intel CPU: 8008.
Also a Linux emulator tested with Doctest, built by cmake_minimum_required(VERSION 3.15)
To build emulator project with Ninja: intel-8008/emulate8008>cmake -B build -GNinja
To build e.g. tests: intel-8008/emulate8008>cmake --build build -t test
To run tests: intel-8008/emulate8008>./build/test.