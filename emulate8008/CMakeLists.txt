cmake_minimum_required(VERSION 3.15)
project(noname)

set(CPP_TEST_OPTIONS -std=c++20 -W -Wall -Wextra -Wpedantic)
set(CPP_COMPILE_OPTIONS ${CPP_TEST_OPTIONS} -Werror)

add_executable(emulator src/emulator.cpp
                        src/scelbi.cpp
                        src/intel8008.cpp)
target_include_directories(emulator PRIVATE inc)
target_compile_options(emulator PRIVATE ${CPP_COMPILE_OPTIONS})

add_executable(test src/intel8008.cpp
                    src/scelbi.cpp
                    test/testCpu.cpp)
target_include_directories(test PRIVATE doctest/doctest inc)
target_compile_options(test PRIVATE ${CPP_TEST_OPTIONS})