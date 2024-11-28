cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

add_library(allocator_lib STATIC allocator.cpp)
target_include_directories(allocator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})