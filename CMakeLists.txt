cmake_minimum_required(VERSION 3.27)
project(transjp)

set(CMAKE_CXX_STANDARD 20)

add_executable(transjp main.cpp
        TransJP.cpp
        TransJP.h)
