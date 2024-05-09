cmake_minimum_required(VERSION 3.9)
project(EvolutionSim VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(CTest)

add_subdirectory(tests)
add_subdirectory(src)
