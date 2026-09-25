# SystemC Project

## Prerequsite
1. SystemC Reference Implementation 
- GitHub https://github.com/accellera-official/systemc
- Download Page https://www.accellera.org/downloads/standards/systemc
	
2. GTKWave - https://github.com/gtkwave/gtkwave

## Build module in the project

```
export CMAKE_PREFIX_PATH="/your/path/systemc:$CMAKE_PREFIX_PATH"
mkdir build && cd build
cmake ..
cmake --build .
```

## Hello SystemC

hello_systemc.cpp
It is just to test if the library and the compiler works.

## Hello Module

hello_module.cpp
It is the test for defining a module and instaniate it.

## A Clocked Counter

clocked_counter.cpp
It is a clocked counter to test the module instanition and signal IO

## Producer Consumer

producer_consumer.cpp
Modules to test module instantiation and connection.

## Method Thread Event

method_thread_event.cpp
Modules to demonstrate the different usage of SC_METHOD, SC_THREAD and sc_event
