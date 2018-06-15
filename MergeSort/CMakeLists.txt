cmake_minimum_required(VERSION 3.7)
project(MergeSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MergeSort.h)
add_executable(MergeSort ${SOURCE_FILES})