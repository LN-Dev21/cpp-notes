cmake_minimum_required(VERSION 3.31)
project(stack_queue)

set(CMAKE_CXX_STANDARD 11)

add_executable(stack_queue main.cpp
        stack.h
        queue.h
        priority_queue.h)
