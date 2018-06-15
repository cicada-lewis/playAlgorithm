cmake_minimum_required(VERSION 3.7)
project(Selection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SelectionSort.h SortCommon.h)
add_executable(Selection ${SOURCE_FILES})