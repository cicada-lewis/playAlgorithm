cmake_minimum_required(VERSION 3.8)
project(Graphic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h)
add_executable(Graphic ${SOURCE_FILES})