cmake_minimum_required(VERSION 3.15)
project(aes-cpp VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

add_library(aes
    src/main.cpp
)
target_include_directories(aes PUBLIC include)

add_executable(aes-test tests/main.cpp)
target_link_libraries(aes-test aes)


