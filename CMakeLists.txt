cmake_minimum_required(VERSION 3.17)
project(task1)

add_subdirectory(Google_tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(Main main.cpp helpers.cpp LinkedList.cpp)
