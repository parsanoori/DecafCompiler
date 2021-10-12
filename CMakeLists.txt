cmake_minimum_required(VERSION 3.21)

project(Compiler VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(preprocessor)

add_executable(compiler main.cpp)

target_link_libraries(compiler PUBLIC preprocessor) 
