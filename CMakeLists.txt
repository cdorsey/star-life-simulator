cmake_minimum_required(VERSION 3.3)
project(GalaxySimulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Main.cpp
    src/Star.h
    src/Turn.h)

add_executable(GalaxySimulator ${SOURCE_FILES})