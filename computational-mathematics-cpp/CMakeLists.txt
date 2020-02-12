cmake_minimum_required(VERSION 3.15)
project(computational_mathematics)

set(CMAKE_CXX_STANDARD 17)

add_executable(computational_mathematics Apollo/rkf45.h Apollo/rkf45.cpp lab3.cpp)