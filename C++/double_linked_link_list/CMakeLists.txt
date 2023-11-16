cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fprofile-arcs -ftest-coverage -lgtest -fPIC")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)


message("NOTE:Binary will be generated in the 'bin' directory of build location, run ./bin/dl_ll to execute")

project(DoubleLinkedList)

include_directories(
    dl_src
)

add_executable(
    dl_ll
    dl_main.cpp
)
