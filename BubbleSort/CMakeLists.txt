cmake_minimum_required(VERSION 3.7)
project(BubbleSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BubbleSort.h)
add_executable(BubbleSort ${SOURCE_FILES})