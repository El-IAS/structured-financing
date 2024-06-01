cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        Currency.h
        Currency.cpp
        Entity.h
        Entity.cpp
        Facility.h
        Facility.cpp
        Part.h
        Part.cpp
        Portfolio.h
        Portfolio.cpp
        Deal.h
        Deal.cpp)
