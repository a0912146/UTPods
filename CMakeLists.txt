cmake_minimum_required(VERSION 3.12)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp
        UTPod.h
        Song.h
        UTPod.cpp
        Song.cpp UTPod.h Song.cpp Song.h UTPod.cpp)