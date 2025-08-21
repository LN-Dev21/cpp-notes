cmake_minimum_required(VERSION 3.31)
project(template)

set(CMAKE_CXX_STANDARD 11)

add_executable(template main.cpp
        func.cpp
        func.h)
