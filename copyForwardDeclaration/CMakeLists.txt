cmake_minimum_required(VERSION 3.26)
project(copyForwardDeclaration)

set(CMAKE_CXX_STANDARD 17)

add_executable(copyForwardDeclaration main.cpp
        Employee.h
        Department.h
        Department.cpp
        Employee.cpp)
