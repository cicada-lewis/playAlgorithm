cmake_minimum_required(VERSION 3.7)
project(QuickSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp FirstQuickSort2.h FirstQuickSort.h RandomQuickSort.h TwoWayQuickSort.h ThreeWayQuickSort.h)
add_executable(QuickSort ${SOURCE_FILES})