# Declare the project
# CXX means C++.
project(list CXX)


# Require make version 2.8 minimum
cmake_minimum_required(VERSION 2.8)


set(CMAKE_CXX_FLAGS "-Wall -std=c++11 ${SAN_FLAGS}")


# Declares the executable to be built from source files

add_executable(test main.cpp prim.cpp graph.cpp)

add_executable(advancedtest main2.cpp prim.cpp graph.cpp)


