set(CMAKE_CXX_STANDARD 17)

enable_testing()
add_executable(test main.cpp)

target_link_libraries(test allocator_lib gtest)
add_test(test test)