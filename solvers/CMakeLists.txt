cmake_minimum_required(VERSION 3.12)
project(AoC2018Solvers)

set(CMAKE_CXX_STANDARD 17)

include_directories(public )
set(Sources
        day1.cpp
        day2.cpp
        day3.cpp
        day4.cpp
        day5.cpp
        day6.cpp
        day7.cpp
        day8.cpp
        day9.cpp
        day11.cpp
        day12.cpp
)

set(Headers
        day1.h
        day2.h
        day3.h
        day4.h
        day5.h
        day6.h
        day7.h
        day8.h
        day9.h
        day11.h
        day12.h
)

add_library(Solvers ${Sources} ${Headers})
