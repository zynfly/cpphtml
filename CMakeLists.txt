cmake_minimum_required(VERSION 3.9)
project(cpphtml)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES main.cpp)
add_executable(cpphtml ${SOURCE_FILES})