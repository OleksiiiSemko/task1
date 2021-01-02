cmake_minimum_required(VERSION 3.17)
project(task1)

# 'lib' is the folder with Google Test sources
add_subdirectory(Google-tests/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(Google_Tests_run Tests/tests.cpp Tests/TestFixtures.cpp LinkedList.cpp)
add_executable(Main main.cpp helpers.cpp LinkedList.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
