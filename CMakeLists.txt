cmake_minimum_required(VERSION 2.8.9)
project (eigen-one)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -std=c99 -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

include_directories("." "/usr/include/eigen3/")

add_executable(eigen-1 eigen-1.cpp)
add_executable(eigen2 eigen2.cpp)
