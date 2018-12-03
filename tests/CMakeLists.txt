cmake_minimum_required(VERSION 3.12)
project(AoC2018Tests)

set(CMAKE_CXX_STANDARD 17)

include_directories(../solvers)
set(Main main.cpp)
set(Sources day1.test.cpp)

add_subdirectory(Vendor/Catch2)

add_executable(testSolvers ${Main} ${Sources})
target_link_libraries(testSolvers PRIVATE Catch2::Catch2)
target_link_libraries(testSolvers PRIVATE Solvers)