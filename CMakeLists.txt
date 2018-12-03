cmake_minimum_required(VERSION 3.12)
project(AoC2018)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(solvers)


set(Sources main.cpp)

add_executable(AoC2018 ${Sources})
target_link_libraries(AoC2018 PRIVATE Solvers)

add_subdirectory(tests)
