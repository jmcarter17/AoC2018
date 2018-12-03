cmake_minimum_required(VERSION 3.12)
project(AoC2018Solvers)

set(CMAKE_CXX_STANDARD 17)

include_directories(public )
set(Sources day1.cpp day2.cpp)
set(Headers day1.h day2.h)

add_library(Solvers ${Sources} ${Headers})
