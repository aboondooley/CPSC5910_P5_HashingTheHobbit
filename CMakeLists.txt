cmake_minimum_required(VERSION 3.17)
project(P5_HashingTheHobbit)

set(CMAKE_CXX_STANDARD 14)

add_executable(P5_HashingTheHobbit p5.cpp WordCounter.cpp WordCounter.h
        English.cpp English.h LinkedList.cpp LinkedList.h )