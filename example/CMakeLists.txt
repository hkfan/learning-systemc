cmake_minimum_required(VERSION 3.20)
project(counter_systemc CXX)
 
set(CMAKE_CXX_STANDARD 17)
find_package(SystemCLanguage CONFIG REQUIRED)
 
add_executable(hello_systemc hello_systemc.cpp)
target_link_libraries(hello_systemc SystemC::systemc)

add_executable(hello_module hello_module.cpp)
target_link_libraries(hello_module SystemC::systemc)

add_executable(clocked_counter clocked_counter.cpp)
target_link_libraries(clocked_counter SystemC::systemc)

add_executable(producer_consumer producer_consumer.cpp)
target_link_libraries(producer_consumer SystemC::systemc)
