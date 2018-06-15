cmake_minimum_required(VERSION 3.7)
project(InsertionSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp InsertionSort.h)
add_executable(InsertionSort ${SOURCE_FILES})