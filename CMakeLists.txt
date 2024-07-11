cmake_minimum_required(VERSION 3.28)
project(ActivityRegister)

set(CMAKE_CXX_STANDARD 14)

add_executable(ActivityRegister main.cpp
        Activity.h
        Register.h
        Register.cpp)
