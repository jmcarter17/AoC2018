cmake_minimum_required(VERSION 3.12)
project(AoC2018Tests)

set(CMAKE_CXX_STANDARD 17)

include_directories(../solvers)
set(Main main.cpp)
set(Sources
        day1.test.cpp
        day2.test.cpp
        day3.test.cpp
        day4.test.cpp
        day5.test.cpp
        day7.test.cpp
        day8.test.cpp
        day9.test.cpp
)

add_subdirectory(Vendor/Catch2)

add_executable(testSolvers ${Main} ${Sources})
target_link_libraries(testSolvers PRIVATE Catch2::Catch2)
target_link_libraries(testSolvers PRIVATE Solvers)