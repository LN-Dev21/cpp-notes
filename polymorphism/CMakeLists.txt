cmake_minimum_required(VERSION 3.31)
project(polymorphism)

set(CMAKE_CXX_STANDARD 11)

add_executable(polymorphism main.cpp
        animal.h
        buyTicket.h
        car.h)
