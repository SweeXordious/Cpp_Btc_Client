cmake_minimum_required(VERSION 3.15)
project(psychic-garbanzo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(psychic-garbanzo main.cpp src/functions.cpp test/functionsTest.cpp include/functions.h)