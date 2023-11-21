cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fprofile-arcs -ftest-coverage -lgtest -fPIC")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)


message("NOTE:Binary will be generated in the 'bin' directory of build location, run ./bin/complex to execute")

project(ComplexNumbers)

include_directories(src)

add_executable(
    complex
    complex_main.cpp
    src/complex.cpp
)