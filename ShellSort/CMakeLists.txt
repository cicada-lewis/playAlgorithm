cmake_minimum_required(VERSION 3.7)
project(ShellSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ShellSort.h)
add_executable(ShellSort ${SOURCE_FILES})