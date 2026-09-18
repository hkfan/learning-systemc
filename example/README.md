# SystemC Project

export CMAKE_PREFIX_PATH="/your/path/systemc:$CMAKE_PREFIX_PATH"
mkdir build && cd build
cmake ..
cmake --build .

## Hello SystemC

hello_systemc.cpp
It is just to test if the library and the compiler works.

## Hello Module

hello_module.cpp
It is the test for defining a module and instaniate it.

## A Clocked Counter

clocked_counter.cpp
It is a clocked counter to test the module instanition and signal IO